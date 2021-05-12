# Executable Name
EXENAME = finalproj

# Object Types
OBJS = Graph.o main.o

OBJS += cs225/HSLAPixel.o cs225/PNG.o cs225/lodepng/lodepng.o

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

# cs225/HSLAPixel.o: main.cpp cs225/HSLAPixel.cpp
# 	$(CXX) $(CXXFLAGS) main.cpp cs225/HSLAPixel.cpp

# cs225/PNG.o: main.cpp cs225/PNG.cpp
# 	$(CXX) $(CXXFLAGS) main.cpp cs225/PNG.cpp

# cs225/lodepng/lodepng.o: main.cpp cs225/lodepng/lodepng.cpp
# 	$(CXX) $(CXXFLAGS) main.cpp cs225/lodepng/lodepng.cpp

test: output_msg catch/catch.cpp tests/tests.cpp Graph.cpp cs225/PNG.cpp cs225/HSLAPixel.cpp cs225/lodepng/lodepng.cpp
	$(LD) catch/catch.cpp tests/tests.cpp Graph.cpp cs225/PNG.cpp cs225/HSLAPixel.cpp cs225/lodepng/lodepng.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test