CXX = g++
CXXFLAGS = -std=c++17 -Wall
OBJDIR = obj
BINDIR = bin
SRCDIR = proj1/src
INCDIR = proj1/include
TESTDIR = proj1/testsrc


SOURCES = $(SRCDIR)/StringUtils.cpp $(TESTDIR)/StringUtilsTest.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
EXEC = $(BINDIR)/teststrutils

$(shell mkdir -p $(OBJDIR) $(BINDIR))


all: $(EXEC)


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
   $(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@


$(EXEC): $(OBJECTS)
   $(CXX) $(CXXFLAGS) $^ -o $@


test: $(EXEC)
   ./$(EXEC)


clean:
   rm -rf $(OBJDIR) $(BINDIR)


.PHONY: all test clean
