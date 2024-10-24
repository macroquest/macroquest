#include "pch.h"
#include "zep/mcommon/string/stringutils.h"

#include <algorithm>
#include <locale>
#include <string>

namespace Zep {

std::string string_tolower(const std::string& str)
{
    std::string copy = str;
    std::transform(copy.begin(), copy.end(), copy.begin(), [](char ch) {
        return (char)::tolower(int(ch));
    });
    return copy;
}

std::string string_replace(std::string subject, const std::string& search, const std::string& replace)
{
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos)
    {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

void string_replace_in_place(std::string& subject, const std::string& search, const std::string& replace)
{
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos)
    {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}

std::vector<std::string> string_split(const std::string& text, const char* delims)
{
    std::vector<std::string> tok;
    string_split(text, delims, tok);
    return tok;
}

// String split with multiple delims
// https://stackoverflow.com/a/7408245/18942
void string_split(const std::string& text, const char* delims, std::vector<std::string>& tokens)
{
    tokens.clear();
    std::size_t start = text.find_first_not_of(delims), end = 0;

    while ((end = text.find_first_of(delims, start)) != std::string::npos)
    {
        tokens.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(delims, end);
    }
    if (start != std::string::npos)
        tokens.push_back(text.substr(start));
}

void string_split_each(const std::string& text, const char* delims, std::function<bool(size_t, size_t)> fn)
{
    std::size_t start = text.find_first_not_of(delims), end = 0;

    while ((end = text.find_first_of(delims, start)) != std::string::npos)
    {
        if (!fn(start, end - start))
            return;
        start = text.find_first_not_of(delims, end);
    }
    if (start != std::string::npos)
        fn(start, text.length() - start);
}

size_t string_first_not_of(const char* text, size_t start, size_t end, const char* delims)
{
    for (auto index = start; index < end; index++)
    {
        bool found = false;
        auto pDelim = delims;
        while (*pDelim != 0)
        {
            if (text[index] == *pDelim++)
            {
                found = true;
                break;
            }
        }
        if (!found)
            return index;
    }
    return std::string::npos;
}

size_t string_first_of(const char* text, size_t start, size_t end, const char* delims)
{
    for (auto index = start; index < end; index++)
    {
        auto pDelim = delims;
        while (*pDelim != 0)
        {
            if (text[index] == *pDelim++)
            {
                return index;
            }
        }
    }
    return std::string::npos;
}

void string_split_each(char* text, size_t startIndex, size_t endIndex, const char* delims, std::function<bool(size_t, size_t)> fn)
{
    // Skip delims (start now at first thing that is not a delim)
    std::size_t start = string_first_not_of(text, startIndex, endIndex, delims);
    std::size_t end;

    // Find first delim (end now at first delim)
    while ((end = string_first_of(text, start, endIndex, delims)) != std::string::npos)
    {
        // Callback with string between delims
        if (!fn(start, end))
            return;

        if (text[end] == 0 && end < endIndex)
            end++;

        // Find the first non-delim
        start = string_first_not_of(text, end, endIndex, delims);
    }
    // Return the last one
    if (start != std::string::npos)
        fn(start, endIndex);
}

void string_split_lines(const std::string& text, std::vector<std::string>& split)
{
    string_split(text, "\r\n", split);
}

std::string string_slurp_if(std::string::const_iterator& itr, std::string::const_iterator itrEnd, char first, char last)
{
    if (itr == itrEnd)
    {
        return "";
    }

    auto itrCurrent = itr;
    if (*itrCurrent == first)
    {
        while ((itrCurrent != itrEnd) && *itrCurrent != last)
        {
            itrCurrent++;
        }

        if ((itrCurrent != itrEnd) && *itrCurrent == last)
        {
            itrCurrent++;
            auto ret = std::string(itr, itrCurrent);
            itr = itrCurrent;
            return ret;
        }
    }
    return "";
}

std::string string_slurp_if(std::string::const_iterator& itr, std::string::const_iterator itrEnd, std::function<bool(char)> fnIs)
{
    if (itr == itrEnd)
    {
        return "";
    }

    auto itrCurrent = itr;
    while ((itrCurrent != itrEnd) && fnIs(*itrCurrent))
    {
        itrCurrent++;
    }

    if (itrCurrent != itr)
    {
        auto ret = std::string(itr, itrCurrent);
        itr = itrCurrent;

        return ret;
    }
    return "";
};

} // namespace Zep
