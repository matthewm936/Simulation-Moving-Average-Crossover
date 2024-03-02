# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Source files
SRCS = main.cpp Classes/Trade.cpp Classes/Dataset.cpp Classes/MovingAverage.cpp Classes/Portfolio.cpp Classes/Simulation.cpp

# Test source file
TEST_SRCS = test/test.cpp Classes/Trade.cpp Classes/Dataset.cpp Classes/MovingAverage.cpp Classes/Portfolio.cpp Classes/Simulation.cpp

# Object files
OBJS = $(SRCS:.cc=.o)

# Test object files
TEST_OBJS = $(TEST_SRCS:.cc=.o)

# Executable name
EXEC = run

# Test executable name
TEST_EXEC = test

all: $(EXEC) $(TEST_EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@