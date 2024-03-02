# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Source files
SRCS = main.cpp Classes/Trade.cpp Classes/Dataset.cpp Classes/MovingAverage.cpp Classes/Portfolio.cpp Classes/Simulation.cpp

# Test source files
TEST_SRCS = test.cpp Classes/Trade.cpp Classes/Dataset.cpp Classes/MovingAverage.cpp Classes/Portfolio.cpp Classes/Simulation.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Test object files
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Executable name
EXEC = run

# Test executable namemake test
TEST_EXEC = run_tests

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

test: $(TEST_EXEC)
	./$(TEST_EXEC)