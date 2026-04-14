#pragma once

// protobuf
#ifdef _DEBUG
    #pragma comment(lib, "libprotobufd")
#else
    #pragma comment(lib, "libprotobuf")
#endif
