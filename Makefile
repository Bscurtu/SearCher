CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -Isrc


SRC_DIR  := src
SRCS     := $(SRC_DIR)/main.cc \
            $(SRC_DIR)/dir_search/dirSearcher.cc \
            $(SRC_DIR)/file_search/fileCoincidence.cc

OBJS     := $(SRCS:.cc=.o)
TARGET   := SearCher


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@


run: all
	./$(TARGET)


clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(TARGET)

.PHONY: all clean fclean run