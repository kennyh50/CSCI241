#
# PROGRAM: assign6
# PROGRAMMER: Kenneth Harris
# LOGON ID:  z1733721
# DATE DUE:  
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign6: assign6.o
	g++ $(CCFLAGS) -o assign6 assign6.o

assign6.o: assign6.cpp Queue.h
	g++ $(CCFLAGS) -c assign6.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm assign6 *.o

