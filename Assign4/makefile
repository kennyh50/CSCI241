#
# PROGRAM:    assign4
# PROGRAMMER: Kenneth Harris
# LOGON ID:   z1733721
# DATE DUE:   10/23/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign4: assign4.o Complex.o
	g++ $(CCFLAGS) -o assign4 assign4.o Complex.o

# Rules to compile source code files to object code
assign4.o: assign4.cpp Complex.h
	g++ $(CCFLAGS) -c assign4.cpp

Complex.o: Complex.cpp Complex.h
	g++ $(CCFLAGS) -c Complex.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4
