# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRCS = main.cpp Classes/Algorithm.cpp Classes/Dataset.cpp Classes/MovingAverage.cpp Classes/Portfolio.cpp Classes/Simulation.cpp

# Object files
OBJS = $(SRCS:.cc=.o)

# Executable name
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

.cc.o:
    $(CXX) $(CXXFLAGS) -c $<  -o $@

clean:
    rm -f *.o Classes/*.o $(EXEC)