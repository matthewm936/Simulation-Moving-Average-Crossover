# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Source files
SRCS = main.cpp Classes/Trade.cpp Classes/Dataset.cpp Classes/MovingAverage.cpp Classes/Portfolio.cpp Classes/Simulation.cpp

# Object files
OBJS = $(SRCS:.cc=.o)

# Executable name
EXEC = run

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@
