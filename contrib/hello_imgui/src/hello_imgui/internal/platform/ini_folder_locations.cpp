#include "hello_imgui/internal/platform/ini_folder_locations.h"
#include "hello_imgui/internal/whereami/whereami_cpp.h"


#ifdef __MINGW32__
    // Specific implementation for MingW which doesn't have SHGetFolderPath

    #include <windows.h>
    #include <iostream>

    static std::string GetTempPath()
    {
        TCHAR tempPath[MAX_PATH];
        if (GetTempPath(MAX_PATH, tempPath) > 0)
            return std::string(tempPath);
        return "";
    }

    static std::string GetAppUserConfigFolder()
    {
        TCHAR appDataPath[MAX_PATH];
        if (GetEnvironmentVariable("APPDATA", appDataPath, MAX_PATH) > 0)
            return std::string(appDataPath);
        return "";
    }

    static std::string GetDocumentsPath()
    {
        TCHAR homeDrive[MAX_PATH];
        TCHAR homePath[MAX_PATH];
        if (GetEnvironmentVariable("HOMEDRIVE", homeDrive, MAX_PATH) > 0 &&
            GetEnvironmentVariable("HOMEPATH", homePath, MAX_PATH) > 0) {
            std::string documentsPath = std::string(homeDrive) + std::string(homePath) + "\\Documents";
            return documentsPath;
        }
        return "";
    }

    static std::string GetHomePath()
    {
        TCHAR homeDrive[MAX_PATH];
        TCHAR homePath[MAX_PATH];
        if (GetEnvironmentVariable("HOMEDRIVE", homeDrive, MAX_PATH) > 0 &&
            GetEnvironmentVariable("HOMEPATH", homePath, MAX_PATH) > 0) {
            std::string fullPath = std::string(homeDrive) + std::string(homePath);
            return fullPath;
        }
        return "";
    }

#elif defined(_WIN32)
    #include <windows.h>
    #include <ShlObj.h>
    #include <tchar.h>

#ifdef GetTempPath
#undef GetTempPath
#endif

    static std::string GetTempPath()
    {
        CHAR tempPath[MAX_PATH];
        if (GetTempPathA(MAX_PATH, tempPath) > 0)
            return std::string(tempPath);
        return "";
    }

    static std::string GetAppUserConfigFolder()
    {
        CHAR appDataPath[MAX_PATH];
        if (SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, appDataPath) == S_OK)
            return std::string(appDataPath);
        return "";
    }

    static std::string GetDocumentsPath()
    {
        CHAR documentsPath[MAX_PATH];
        if (SHGetFolderPathA(NULL, CSIDL_MYDOCUMENTS, NULL, SHGFP_TYPE_CURRENT, documentsPath) == S_OK)
            return std::string(documentsPath);
        return "";
    }

    static std::string GetHomePath()
    {
        CHAR homePath[MAX_PATH];
        if (SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, SHGFP_TYPE_CURRENT, homePath) == S_OK)
            return std::string(homePath);
        return "";
    }

#elif defined(__APPLE__)
    #include "hello_imgui/internal/platform/getAppleBundleResourcePath.h"
    using namespace AppleIniFolderLocations;

#elif defined(__ANDROID__) && defined(HELLOIMGUI_USE_SDL)
    #include "SDL.h"

    static std::string GetAppUserConfigFolder()
    {
        const char* orgName = "Dummy"; // SDL does not use this param under Android
        const char* appName = "YourAppName"; // SDL does not use this param under Android
        const char* prefPath = SDL_GetPrefPath(orgName, appName);
        return prefPath;
    }

    static std::string GetTempPath()
    {
        return GetAppUserConfigFolder() + "/cache";
    }

    static std::string GetDocumentsPath()
    {
        return GetAppUserConfigFolder();
    }

    static std::string GetHomePath()
    {
        return GetAppUserConfigFolder();
    }

#elif defined(__linux__)
    #include <cstdlib>
    #include <string>
    #include <unistd.h>
    #include <sys/types.h>
    #include <pwd.h>

    static std::string GetTempPath()
    {
        const char* tempPath = std::getenv("TMPDIR");
        return tempPath ? std::string(tempPath) : "/tmp";
    }

    static std::string GetAppUserConfigFolder()
    {
        const char* xdgConfigHome = std::getenv("XDG_CONFIG_HOME");
        if (xdgConfigHome)
            return std::string(xdgConfigHome); // Use XDG_CONFIG_HOME if it's set
        else
        {
            // Fallback to ~/.config
            const char* homeDir = std::getenv("HOME");
            if (!homeDir) {
                struct passwd *pw = getpwuid(getuid());
                homeDir = pw->pw_dir;
            }
            return std::string(homeDir) + "/.config";
        }
    }

    static std::string GetDocumentsPath()
    {
        const char* homeDir = std::getenv("HOME");
        if (!homeDir) {
            struct passwd *pw = getpwuid(getuid());
            homeDir = pw->pw_dir;
        }
        return std::string(homeDir) + "/Documents";
    }

    static std::string GetHomePath()
    {
        const char* homeDir = std::getenv("HOME");
        if (!homeDir) {
            struct passwd *pw = getpwuid(getuid());
            homeDir = pw->pw_dir;
        }
        return std::string(homeDir);
    }

#else
    static std::string GetTempPath() { throw std::runtime_error("Not implemented for this platform!"); }
    static std::string GetAppUserConfigFolder() { throw std::runtime_error("Not implemented for this platform!"); }
    static std::string GetDocumentsPath() { throw std::runtime_error("Not implemented for this platform!"); }
    static std::string GetHomePath() { throw std::runtime_error("Not implemented for this platform!"); }
#endif


namespace HelloImGui
{

    std::string IniFolderLocation(IniFolderType iniFolderType)
    {
#ifdef __EMSCRIPTEN__
        return "/";     // Emscripten uses a virtual file system, so we can't use any of the other paths
#else
        switch(iniFolderType)
        {
            case IniFolderType::CurrentFolder:
                return "";
            case IniFolderType::AppUserConfigFolder:
                return GetAppUserConfigFolder();
            case IniFolderType::DocumentsFolder:
                return GetDocumentsPath();
            case IniFolderType::HomeFolder:
                return GetHomePath();
            case IniFolderType::TempFolder:
                return GetTempPath();
            case IniFolderType::AppExecutableFolder:
                return wai_getExecutableFolder_string();
            default:
                return "";
        }
#endif
    }

}

