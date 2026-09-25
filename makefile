# Compiler settings
CXX = clang++
CXXFLAGS = -std=c++20 

# Libraries required for Vulkan and GLFW window management
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

# Target executable name
TARGET = VulkanApp

# Find all .cpp files in the directory
SRCS = $(wildcard *.cc)

# Convert all .cpp filenames to .o (object) filenames
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile each .cpp file into a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts (removes both .o files and the executable)
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean