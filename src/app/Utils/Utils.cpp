#include "Utils.h"

namespace lm {
namespace utils {
std::vector<std::string> Split(const std::string_view& str, const char seperator)
{
    std::vector<std::string> output;
    std::string::size_type   prev_pos = 0, pos = 0;
    while ((pos = str.find(seperator, pos)) != std::string::npos) {
        if (const auto s = str.substr(prev_pos, pos - prev_pos); !s.empty()) {
            output.emplace_back(s);
        }
        prev_pos = ++pos;
    }
    if (const auto s = str.substr(prev_pos, pos - prev_pos); !s.empty()) {
        output.emplace_back(s);
    }
    return output;
}

std::vector<std::filesystem::path> GetFilesByExtension(const std::filesystem::path& directory,
                                                       const std::string_view&      extension)
{
    std::vector<std::filesystem::path> files;
    try {
        if (std::filesystem::exists(directory) && std::filesystem::is_directory(directory)) {
            for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
                if (entry.is_regular_file() &&
                    (extension.empty() ? true : (entry.path().extension() == extension))) {
                    files.push_back(entry.path());
                }
            }
        }
    }
    catch (...) {
    }
    return files;
}
}   // namespace utils
}   // namespace lm
