# Makefile for Java JNI project

# Variables
JAVA_SOURCE = HelloJNI.java
JAVA_CLASS = HelloJNI
C_SOURCE = hellojni.c
LIBRARY = libhellojni.dylib
JAVA_HOME ?= $(shell /usr/libexec/java_home)

# Default target is now build instead of run
.DEFAULT_GOAL := build

# Help command
help:
	@echo "Available commands:"
	@echo "  make       - Build the project (compile Java, generate header, compile library)"
	@echo "  make run   - Build and run the Java program"
	@echo "  make clean - Clean built files"
	@echo ""
	@echo "After building, you can also run directly with:"
	@echo "  java $(JAVA_CLASS)"

# Build stages
compile-java: $(JAVA_SOURCE)
	javac $(JAVA_SOURCE)

generate-header: compile-java
	javac -h . $(JAVA_SOURCE)

compile-library: $(C_SOURCE) generate-header
	gcc -shared -fpic -o $(LIBRARY) \
		-I$(JAVA_HOME)/include \
		-I$(JAVA_HOME)/include/darwin \
		-mcpu=native \
		$(C_SOURCE)

# Default target to build and show run instructions
build:
	@make compile-java generate-header compile-library
	@echo ""
	@echo "Build complete! To run the program, use either:"
	@echo "  make run"
	@echo "  java $(JAVA_CLASS)"

# Run the Java program
run:
	@echo "Running command: java $(JAVA_CLASS) \n"
	@java $(JAVA_CLASS)

# Clean built files
clean:
	@echo "Cleaning up built files..."
	@rm -f *.class *.h $(LIBRARY)

.PHONY: help compile-java generate-header compile-library build run clean 