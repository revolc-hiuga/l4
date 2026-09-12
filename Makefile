CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

BIN = l4.exe
TEST = l4_test.exe
SRC = src/main.cpp src/str.cpp
TEST_SRC = src/tests/test_main.cpp src/tests/test_trim.cpp src/tests/test_split.cpp src/str.cpp

.PHONY: test clean

default: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

$(TEST): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST)

test: $(TEST)
	./$(TEST)

clean:
	del $(BIN)
	del $(TEST)