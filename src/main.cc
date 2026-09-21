
#include "includes/lib.hh"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        SearchQuery actual;
        actual.rootDir = argv[1];
        actual.query = argv[2];

        for (int see = 3; see < argc; see++)
        {
            if (strcmp(argv[see], "--NCS") == 0)
                actual.caseSensitive = false;
            else if (argv[see][0] >= '0' && argv[see][0] <= '9')
                actual.maxDepth = atoi(argv[see]);
            else
                std::cout << "Usage of the program:\n" << "SearCher <directory> <query> [--NCS (not case sensitive)] [max-depth (from directory)]" << std::endl;
        }
        dirSearch(actual);
    }
    else
        std::cout << "Usage of the program:\n" << "SearCher <directory> <query> [--NCS (not case sensitive)] [max-depth (from directory)]" << std::endl;
    return 0;
}