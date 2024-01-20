#ifdef HELLOIMGUI_USE_WIN32

#include "win32_window_helper.h"
#include "window_geometry_helper.h"
#include "win32_dpi_awareness.h"

namespace HelloImGui {
namespace BackendApi {

WindowPointer Win32WindowHelper::CreateWindow(AppWindowParams &appWindowParams, const BackendOptions& backendOptions)
{
	return nullptr;
}

} // namespace BackendApi
} // namespace HelloImGui

#endif // #ifdef HELLOIMGUI_USE_WIN32
