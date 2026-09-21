
class SearchQuery
{
    public:
    std::filesystem::path rootDir;
    std::string query;
    size_t maxDepth;
    bool    caseSensitive {true};

    SearchQuery(){};
    ~SearchQuery(){};
};