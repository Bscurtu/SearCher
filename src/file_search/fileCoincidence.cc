#include "../includes/lib.hh"

void checkCoincidence( const std::filesystem::path& actualPath, const SearchQuery& actual)
{
    std::ifstream file(actualPath, std::ios::binary);

    if (!file)
    {
        std::cerr << "Cannot open this file: " << actualPath << '\n';
        return ;
    }

    if (actual.query.empty())
        return ;

    constexpr std::size_t chunkSize = 1000;
    const std::size_t overlapSize =
        std::min(chunkSize, actual.query.size() - 1);
    std::string previous;
    std::array<char, chunkSize> chunk{};

    while (file)
    {
        file.read(chunk.data(), chunk.size());
        const std::streamsize bytesRead = file.gcount();
        if (bytesRead <= 0)
            break;
        std::string current = previous;
        current.append(chunk.data(), static_cast<std::size_t>(bytesRead));

        bool found = false;
        if (actual.caseSensitive)
            found = current.find(actual.query) != std::string::npos;
        else
        {
            auto equalsIgnoringCase =
                [](unsigned char left, unsigned char right)
                {
                    return std::tolower(left) == std::tolower(right);
                };

            auto result = std::search(
                current.begin(),
                current.end(),
                actual.query.begin(),
                actual.query.end(),
                equalsIgnoringCase
            );
            found = result != current.end();
        }

        if (found)
        {
            std::cout << actualPath.string() << '\n';
            return;
        }
        if (current.size() > overlapSize)
            previous = current.substr(current.size() - overlapSize);
        else
            previous = current;
    }
}