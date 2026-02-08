CXX = g++
CXXFLAGS = -std=c++17 -Wall
OBJDIR = obj
BINDIR = bin
SRCDIR = src
INCDIR = include
TESTDIR = testsrc

SOURCES = $(SRCDIR)/StringUtils.cpp $(TESTDIR)/StringUtilsTest.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
EXEC = $(BINDIR)/teststrutils

$(shell mkdir -p $(OBJDIR) $(BINDIR))

all: $(EXEC)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lgtest -lgtest_main -pthread

test: $(EXEC)
	./$(EXEC)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all test clean
