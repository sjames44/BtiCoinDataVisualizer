# # Executable Name
# EXENAME = finalproj

# # Object Types
# OBJS = Graph.o main.o

# # Compilation Flags
# CXX = clang++
# CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
# LD = clang++
# LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# # Custom Clang Enforcement
# include make/customClangEnforcement.mk

# # Define Makefile Rules
# .PHONY: all test clean output_msg

# all : $(EXENAME)

# output_msg: ; $(CLANG_VERSION_MSG)

# $(EXENAME): output_msg $(OBJS)
# 	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

# Graph.o: main.cpp Graph.cpp
# 	$(CXX) $(CXXFLAGS) main.cpp Graph.cpp

# test: output_msg catch/catch.cpp tests/tests.cpp readFromFile.cpp
# 	$(LD) catch/catch.cpp tests/tests.cpp readFromFile.cpp $(LDFLAGS) -o test

# clean:
# 	-rm -f *.o $(EXENAME) test



# Executable Name
EXENAME = finalproj

# Object Types
OBJS = Graph.o main.o

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

Graph.o: main.cpp Graph.cpp
	$(CXX) $(CXXFLAGS) main.cpp Graph.cpp

test: output_msg catch/catch.cpp tests/tests.cpp Graph.cpp
	$(LD) catch/catch.cpp tests/tests.cpp Graph.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test