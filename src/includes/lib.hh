#pragma once
#include <filesystem>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cstring>
#include "searchQuery.hh"

int main(int argc, char **argv);
void dirSearch(SearchQuery &userInput);
void checkCoincidence(const std::filesystem::path& actualPath, const SearchQuery& actual);