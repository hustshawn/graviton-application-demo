# Build directory
BUILD_DIR = build

# Default target
all: $(BUILD_DIR) build_project

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run cmake and make
build_project: $(BUILD_DIR)
	@echo "Building project..."
	@echo "cd $(BUILD_DIR) && cmake .. && make"
	@echo "\nBuild complete! To run the application, use either:\n"
	@echo "  ./build/hello_arm \n"
	@echo "or with \n"
	@echo "  make run\n"

# Clean build directory
clean:
	@echo "Cleaning up build directory..."
	@rm -rf $(BUILD_DIR)

# Run the executable
run:
	@echo "Running command: ./$(BUILD_DIR)/hello_arm \n"
	@./$(BUILD_DIR)/hello_arm

.PHONY: all build_project clean run 