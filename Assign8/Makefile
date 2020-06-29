#
# PROGRAM:    assign8
# PROGRAMMER: Kenneth Harris
# LOGON ID:   z1733721
# DATE DUE:   11/28/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o Maze.o
	g++ $(CCFLAGS) -o assign8 assign8.o Maze.o

# Rules to compile source code files to object code
assign8.o: assign8.cpp Maze.h
	g++ $(CCFLAGS) -c assign8.cpp

Maze.o: Maze.cpp Maze.h
	g++ $(CCFLAGS) -c Maze.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
