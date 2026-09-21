
#include "includes/lib.hh"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        SearchQuery actual;
        actual.rootDir = argv[1];
        actual.query = argv[2];

        for (size_t see = 3; see < argc; see++)
        {
            if (strcmp(argv[see], "--NCS") == 0)
            {
                actual.caseSensitive = false;
            }
            else if (argv[see][0] >= '0' && argv[see][0] <= '9')
                actual.maxDepth = atoi(argv[see]);
        }
        dirSearch(actual);
    }
    return 0;
}

//holApaca