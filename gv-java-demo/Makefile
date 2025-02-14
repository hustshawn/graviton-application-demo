# Makefile for Java JNI project

# Variables
JAVA_SOURCE = HelloJNI.java
JAVA_CLASS = HelloJNI
C_SOURCE = hellojni.c
LIBRARY = libhellojni.dylib
JAVA_HOME ?= $(shell /usr/libexec/java_home)

# Default target is now run
.DEFAULT_GOAL := run

# Build stages
compile-java: $(JAVA_SOURCE)
	javac $(JAVA_SOURCE)

generate-header: compile-java
	javac -h . $(JAVA_SOURCE)

compile-library: $(C_SOURCE) generate-header
	gcc -shared -fpic -o $(LIBRARY) \
		-I$(JAVA_HOME)/include \
		-I$(JAVA_HOME)/include/darwin \
		$(C_SOURCE)

build: compile-java generate-header compile-library

# Run the Java program
run: build
	java $(JAVA_CLASS)

# Clean built files
clean:
	rm -f *.class *.h $(LIBRARY)

.PHONY: compile-java generate-header compile-library build run clean 