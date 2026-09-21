#include "../includes/lib.hh"

void dirSearch(SearchQuery &userInput)
{
    try
    {
        std::filesystem::recursive_directory_iterator searcher(
            userInput.rootDir,
            std::filesystem::directory_options::skip_permission_denied
        );
        std::filesystem::recursive_directory_iterator end;

        for (; searcher != end; ++searcher)
        {
            if (userInput.maxDepth != -1 && searcher.depth() >= userInput.maxDepth)
                searcher.disable_recursion_pending();

            if (!searcher->is_directory())
                checkCoincidence(searcher->path(), userInput);
        }
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Cannot open " << userInput.rootDir << ": " << e.what() << '\n';
    }
}