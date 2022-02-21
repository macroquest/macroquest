/******************************************************************************
 * mkplugin - MQ Plugin Template Quickstart Program
 * Original Author: Knightly
 ******************************************************************************
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <https://unlicense.org>
 ******************************************************************************/

#include <fstream>
#include <iostream>
#include <filesystem>
#include <cctype>
#include <functional>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

#include "resource.h"

/**
 * @fn str_equal_ci
 *
 * @brief Case Insensitive equal for two strings
 *
 * Determines if two strings are the same without regard to case.
 *
 * First makes sure the strings are the same size, then checks the
 * uppercase version of each character against the other.
 *
 * @param str1 The first string to Compare
 * @param str2 The second string to Compare
 *
 * @return bool Whether the two strings are case insensitive equal
 *
 **/
inline bool str_equal_ci(const std::string_view str1, const std::string_view str2)
{
    return str1.size() == str2.size() && std::equal(str1.begin(), str1.end(), str2.begin(),[](const char& c1, const char& c2){
        return (c1 == c2 || std::toupper(c1) == std::toupper(c2));
    });
}

/**
 * @fn str_equal
 *
 * @brief Case sensitive equal for two strings
 *
 * Determines if two strings are the same.
 *
 * First makes sure the strings are the same size, then checks
 * them against each other to make sure that they're the same
 *
 * @param str1 The first string to Compare
 * @param str2 The second string to Compare
 *
 * @return bool Whether the two strings are equal
 *
 **/
inline bool str_equal(const std::string_view str1, const std::string_view str2)
{
	return str1.size() == str2.size() && str1 == str2;
}

class Resource {
  public:
    struct Parameters {
        std::size_t size_bytes = 0;
        void* ptr = nullptr;
    };

  private:
    HRSRC hResource = nullptr;
    HGLOBAL hMemory = nullptr;

    Parameters p;

  public:
    Resource(int resource_id, const std::string& resource_class) {
        hResource = FindResourceA(nullptr, MAKEINTRESOURCEA(resource_id), resource_class.c_str());
        if (hResource != nullptr) {
            hMemory = LoadResource(nullptr, hResource);
            if (hMemory != nullptr) {
                p.size_bytes = SizeofResource(nullptr, hResource);
                p.ptr = LockResource(hMemory);
            }
        }
    }

    [[nodiscard]] auto& GetResource() const {
        return p;
    }

    [[nodiscard]] std::string_view GetResourceString() const {
        std::string_view dst;
        if (p.ptr != nullptr) {
            dst = std::string_view(static_cast<const char*>(p.ptr), p.size_bytes);
        }
        return dst;
    }
};

enum
{
    SAVE_RESULT_OK,
    SAVE_RESULT_ERR_RESOURCE_NULL,
    SAVE_RESULT_ERR_FILE_EXISTS,
    SAVE_RESULT_ERR_DIR_NOT_EXISTS,
    SAVE_RESULT_ERR_DIR_NOT_CREATED,
    SAVE_RESULT_ERR_FILE_NOT_WRITTEN,
    SAVE_RESULT_ERR_UNKNOWN
};

static int save_resource_to_file(int ResourceID, const std::string& ResourceClass, const std::filesystem::path& filePath, const bool createDirectories = true, const std::string& strFind = "", const std::string& strReplace = "")
{
    const Resource resourceData(ResourceID, ResourceClass);
    const std::string_view resourceString = resourceData.GetResourceString();
    std::error_code ec;
    if (resourceString.empty()) {
        return SAVE_RESULT_ERR_RESOURCE_NULL;
    }

    if(std::filesystem::exists(filePath, ec)) {
        return SAVE_RESULT_ERR_FILE_EXISTS;
    }

    if (!std::filesystem::exists(filePath.parent_path(), ec)) {
        if (!createDirectories) {
            return SAVE_RESULT_ERR_DIR_NOT_EXISTS;
        }

        if (!std::filesystem::create_directories(filePath.parent_path(), ec)) {
            return SAVE_RESULT_ERR_DIR_NOT_CREATED;
        }
    }

    std::ofstream outFile(filePath, std::ios::binary);
    if (!outFile) {
        return SAVE_RESULT_ERR_FILE_NOT_WRITTEN;
    }

    if (strFind.empty() && strReplace.empty()) {
        outFile << resourceString;
    }
    else {
        std::string strResourceString = std::string(resourceString.begin(), resourceString.end());
        size_t pos = strResourceString.find(strFind);
        while (pos != std::string::npos) {
            strResourceString.replace(pos, strFind.length(), strReplace);
            pos += strReplace.length();
            pos = strResourceString.find(strFind, pos);
        }
        outFile << strResourceString;
    }

    // Catch all check just to make sure everything went okay
    if (!std::filesystem::exists(filePath, ec)) {
        return SAVE_RESULT_ERR_UNKNOWN;
    }

    return SAVE_RESULT_OK;
}

static bool save_resource_to_file_with_output(int ResourceID, const std::string& ResourceClass, const std::filesystem::path& filePath, const bool createDirectories = true, const std::string& strFind = "", const std::string& strReplace = "", std::string friendlyName = "")
{
    const int iResult = save_resource_to_file(ResourceID, ResourceClass, filePath, createDirectories, strFind, strReplace);
    if (iResult != SAVE_RESULT_OK)
    {
        if (friendlyName.empty())
        {
            friendlyName = filePath.filename().string();
        }
        std::cerr << "ERROR: Could not create " << friendlyName << " :: ";
        switch(iResult)
        {
            case SAVE_RESULT_ERR_RESOURCE_NULL:
                std::cerr << "The resource was not found";
                break;
            case SAVE_RESULT_ERR_FILE_EXISTS:
                std::cerr << "The file already exists";
                break;
            case SAVE_RESULT_ERR_DIR_NOT_EXISTS:
                std::cerr << "The directory does not exist";
                break;
            case SAVE_RESULT_ERR_DIR_NOT_CREATED:
                std::cerr << "The directory could not be created";
                break;
            case SAVE_RESULT_ERR_FILE_NOT_WRITTEN:
                std::cerr << "The file could not be written";
                break;
            case SAVE_RESULT_ERR_UNKNOWN:
                std::cerr << "Unknown error";
                break;
            default:
                break;
        }
        std::cerr << std::endl;
        return false;
    }
    return true;
}

static std::string get_plugin_name(std::string pluginName)
{
    // append MQ if it doesn't exist
    if (pluginName.length() < 2 || !str_equal_ci("MQ", pluginName.substr(0, 2))) {
        pluginName = "MQ" + pluginName;
    }
    else {
        pluginName = "MQ" + pluginName.substr(2, pluginName.length() - 2);
    }
    // Remove non-alphanumeric characters
    pluginName.erase(std::remove_if(pluginName.begin(), pluginName.end(), std::not_fn(static_cast<int(*)(int)>(std::isalnum))), pluginName.end());

    return pluginName;
}

static void show_usage(const std::filesystem::path& appFullPath)
{
    std::cerr << "Usage: " << appFullPath.filename().string() << " pluginname [secondPluginName] [thirdPluginName]" << std::endl
              << std::endl
              << "Description:" << std::endl
              << "\tCreates a plugin folder and project using the default template.  If the" << std::endl
              << "\tplugin name isn't prefixed with MQ, this program will add that prefix." << std::endl
              << std::endl
              << "Example:" << std::endl
              << "\t" << appFullPath.filename().string() << " MQAwesomeThing" << std::endl
              << std::endl;
}

int main(int argc, char* argv[]) // NOLINT
{
    if (argc > 1)
    {
        if (str_equal(argv[1], "-?") || str_equal(argv[1], "/?") || str_equal_ci(argv[1], "-h") || str_equal_ci(argv[1], "/h") || str_equal_ci(argv[1], "-help") || str_equal_ci(argv[1], "/help"))
        {
            show_usage(argv[0]);
        }
        else
        {
            for (int i = 1; i < argc; ++i)
            {
                std::string strPluginName = get_plugin_name(argv[i]);
                std::filesystem::path pluginDir = ".";
                pluginDir /= strPluginName;
                std::cout << "Creating Plugin Template for " << strPluginName << "..." << std::endl;
                std::error_code ec;
                if (std::filesystem::exists(pluginDir, ec) && std::filesystem::is_directory(pluginDir, ec)) {
                    std::cerr << "ERROR: Plugin directory already exists: " << strPluginName << std::endl;
                }
                else {
                    if (save_resource_to_file_with_output(IDR_PLUGIN_TEMPLATE_CPP, "TEXT", pluginDir / std::filesystem::path(strPluginName + ".cpp"), true, "MQPluginTemplate", strPluginName) &&
                        save_resource_to_file_with_output(IDR_PLUGIN_TEMPLATE_README, "TEXT", pluginDir / "README.md", true, "MQPluginTemplate", strPluginName) &&
                        save_resource_to_file_with_output(IDR_PLUGIN_TEMPLATE_VCXPROJ, "XML", pluginDir / std::filesystem::path(strPluginName + ".vcxproj"), true, "MQPluginTemplate", strPluginName) &&
                        save_resource_to_file_with_output(IDR_PLUGIN_TEMPLATE_VCXPROJ_FILTERS, "XML", pluginDir / std::filesystem::path(strPluginName + ".vcxproj.filters"), true, "MQPluginTemplate", strPluginName, "vcxproj.filters file") &&
                        save_resource_to_file_with_output(IDR_PLUGIN_TEMPLATE_RESOURCEH, "TEXT", pluginDir / "resource.h", true, "MQPluginTemplate", strPluginName) &&
                        save_resource_to_file_with_output(IDR_PLUGIN_TEMPLATE_RC, "TEXT", pluginDir / std::filesystem::path(strPluginName + ".rc"), true, "MQPluginTemplate", strPluginName) &&
                        save_resource_to_file_with_output(IDR_PLUGIN_TEMPLATE_GITIGNORE, "TEXT", pluginDir / ".gitignore", true, "MQPluginTemplate", strPluginName))
                    {
                        std::cout << "Plugin Template created for " << strPluginName << std::endl;
                    }

                }
                std::cout << std::endl;
            }
        }
    }
    else
    {
        show_usage(argv[0]);
    }
}