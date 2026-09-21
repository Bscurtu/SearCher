#include "../includes/lib.hh"
#include <cctype>

void checkCoincidence(const std::filesystem::path& actualPath, const SearchQuery& actual)
{
    std::ifstream thisFile(actualPath, std::ios::binary);
    if (!thisFile.is_open()) return;
    thisFile.seekg(0, std::ios::end);
    size_t size = thisFile.tellg();
    if (size == 0) return;

    std::vector<uint8_t> buffer(size);
    thisFile.seekg(0, std::ios::beg);
    thisFile.read(reinterpret_cast<char*>(buffer.data()), size);
    std::ranges::subrange<std::vector<uint8_t>::iterator> result;

    if (actual.caseSensitive == true)
    {
        result = std::ranges::search(buffer, actual.query);
    }
    else
    {
        result = std::ranges::search(buffer, actual.query, [](uint8_t a, char b) {
            return std::tolower(a) == std::tolower(static_cast<unsigned char>(b));
        });
    }

    if (!result.empty()) {
        std::cout << actualPath.string() << std::endl;
    }
};
