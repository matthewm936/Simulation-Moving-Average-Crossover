# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRCS = main.cpp Classes/Algorithm.cpp Classes/Dataset.cpp Classes/MovingAverage.cpp Classes/Portfolio.cpp Classes/Simulation.cpp

# Test files
TEST_SRCS = test/test.cpp

# Object files
OBJS = $(SRCS:.cc=.o)

# Test Object files
TEST_OBJS = $(TEST_SRCS:.cc=.o)

# Executable name
EXEC = run

# Test Executable name
TEST_EXEC = test

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJS) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJS) $(OBJS)

clean:
	del /F /Q test.exe run.exe