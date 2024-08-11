#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include "top/global.h"

namespace lm {
namespace utils {
TOP_API std::vector<std::string> Split(const std::string_view& str, const char seperator);

TOP_API std::vector<std::filesystem::path> GetFilesByExtension(
    const std::filesystem::path& directory, const std::string_view& extension);

inline std::vector<std::filesystem::path> GetFiles(const std::filesystem::path& directory)
{
    return GetFilesByExtension(directory, "");
}
}   // namespace utils
}   // namespace lm
