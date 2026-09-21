
class SearchQuery
{
    public:
    std::filesystem::path rootDir;
    std::string query;
    int maxDepth {-1};
    bool    caseSensitive {true};

    SearchQuery(){};
    ~SearchQuery(){};
};