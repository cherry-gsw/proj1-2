CXX = g++
CXXFLAGS = -std=c++17 -Wall
OBJDIR = obj
BINDIR = bin
SOURCES = StringUtils.cpp StringUtilsTest.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
EXEC = $(BINDIR)/teststrutils

# Create directories if they don't exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

all: $(EXEC)

$(OBJDIR)/%.o: %..cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(EXEC)
	./$(EXEC)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all test clean