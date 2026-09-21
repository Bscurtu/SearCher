# SearCher

SearCher is a lightweight C++ command-line tool for recursively searching a directory tree for files that contain a given text query.

It scans files from a root directory, searches for matches in the file contents, and prints the paths of matching files. The tool supports case-sensitive and case-insensitive searches, and allows limiting the search depth.

## Features

- Recursive directory search from a chosen root
- Content-based search inside files
- Case-sensitive and case-insensitive matching
- Optional max-depth restriction
- Fast scanning using buffered reads
- Built with modern C++20 and compiled with a simple Makefile

## Project structure

The repository is organized as follows:

- `src/main.cc`  
  Entry point of the program. Handles command-line arguments and orchestrates the search.

- `src/includes/lib.hh`  
  Shared declarations used across the project. Includes headers and function prototypes.

- `src/includes/searchQuery.hh`  
  Defines the `SearchQuery` structure used to store search parameters such as:
  - root directory
  - query string
  - max depth
  - case sensitivity

- `src/dir_search/dirSearcher.cc`  
  Recursively iterates through the directory tree and calls the file-matching logic for each file encountered.

- `src/file_search/fileCoincidence.cc`  
  Reads files in chunks and checks whether the provided query appears in the content.

- `Makefile`  
  Builds the project and creates the `SearCher` binary.

## How it works

The program accepts a root directory and a query string, then:

1. Walks the directory tree with `std::filesystem::recursive_directory_iterator`
2. Skips inaccessible directories when possible
3. Checks each file's content for the requested query
4. Prints the matching file path(s)
5. Stops scanning once a match is found in a file

The search logic is implemented in two main stages:

- Directory traversal:
  - handled by `dirSearch()`
- File content matching:
  - handled by `checkCoincidence()`

### Search parameters

`SearchQuery` stores:

- `rootDir`: directory to scan
- `query`: text to search for
- `maxDepth`: maximum recursion depth (`-1` means unlimited)
- `caseSensitive`: whether matching should consider uppercase/lowercase differences

## Build

You can build the program using the included Makefile:

```bash
make
