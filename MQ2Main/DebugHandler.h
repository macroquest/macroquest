#include <functional>
#include <excpt.h>
#pragma warning (disable : 4509)
//extern "C" { __declspec(dllexport) int MQ2ExceptionFilter(unsigned int code, struct _EXCEPTION_POINTERS* ep, const char * description, ...); }

#define MQ2Except() __except(MQ2ExceptionFilter(GetExceptionCode(), GetExceptionInformation(), __FUNCTION__))

namespace internal
{
	template <typename T>
	using IsVoid = std::is_same<std::result_of_t<T()>, void>;
}

// overload for expressions that return a type
template <typename T,
          typename std::enable_if<!internal::IsVoid<T>::value, void>::type* = nullptr>
auto Debug_TryExecute(const char* func_name, int line, const T& func) -> decltype(func())
{
	__try
	{
		return func();
	}
	__except(MQ2ExceptionFilter(GetExceptionCode(), GetExceptionInformation(),"%s: Line %i", func_name, line))
	{
		decltype(func()) v{};
		return v;
	}
}

// overload for expressions that return void
template <typename T,
	typename std::enable_if<internal::IsVoid<T>::value, void>::type* = nullptr>
void Debug_TryExecute(const char* func_name, int line, const T& func)
{
	__try {
		func();
	}
	__except (MQ2ExceptionFilter(GetExceptionCode(), GetExceptionInformation(),
		"%s: Line %i", func_name, line)) {
	}
}




// construct a lambda to wrap the exception filter call, this allows us to invoke the __try/__except block
// with a function scope in between, which will prevent error C2712: Cannot use __try in functions that require
// object unwinding.
#define DebugTryBegin() \
	Debug_TryExecute(__FUNCTION__, __LINE__, [&]() {
#define DebugTryEnd() \
	});

// use this pair of macros in combination with a block that returns, to forward that return value
// out of the function.
#define DebugTryBeginRet() \
	{ int result = Debug_TryExecute(__FUNCTION__, __LINE__, [&]() {
#define DebugTryEndRet() \
	}); return result; }


template <typename T>
void Debug_TryExecuteEx(const char* func_name, int line, const char* stmt, const T& func)
{
	__try {
		func();
	}
	__except (MQ2ExceptionFilter(GetExceptionCode(), GetExceptionInformation(),	"%s@%i: %s", func_name, line, stmt)) {
	}
}

#define DebugTryEx(x) \
	Debug_TryExecuteEx(__FUNCTION__, __LINE__, #x, [&]() { x; });