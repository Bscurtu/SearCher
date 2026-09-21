
#include "../includes/lib.hh"

void dirSearch(SearchQuery &userInput)
{
    std::filesystem::recursive_directory_iterator searcher(userInput.rootDir);
    std::filesystem::recursive_directory_iterator end;

    for (; searcher != end; ++searcher)
    {
        if (searcher.depth() >= userInput.maxDepth)
            searcher.disable_recursion_pending();
        if (!searcher->is_directory())
            checkCoincidence(*searcher, userInput);
    }
}