# C++ and Java JNI Demo for ARM Architecture

This project demonstrates the implementation of a C++ application and a Java Native Interface (JNI) example, both optimized for ARM architecture. It showcases cross-language integration and platform-specific optimizations.

The repository contains two main components: a C++ demo application built with CMake, and a Java application that utilizes JNI to call native C functions. These demos are designed to illustrate best practices for developing high-performance applications on ARM-based systems, such as those powered by AWS Graviton processors.

The C++ demo leverages CMake for cross-platform build management, ensuring compatibility and optimal performance on ARM architectures. The Java demo demonstrates how to integrate native C code with Java applications using JNI, which is particularly useful for performance-critical sections of code or when interfacing with system-level libraries.

## Repository Structure

```
.
├── gv-cpp-demo
│   ├── CMakeLists.txt
│   ├── README.md
│   └── src
│       └── main.cpp
└── gv-java-demo
    ├── hellojni.c
    ├── HelloJNI.java
    └── README.md
```

### Key Files:
- `gv-cpp-demo/CMakeLists.txt`: CMake configuration for the C++ project
- `gv-cpp-demo/src/main.cpp`: Main C++ source file
- `gv-java-demo/HelloJNI.java`: Java class demonstrating JNI usage
- `gv-java-demo/hellojni.c`: C implementation of the native method

## Usage Instructions

### C++ Demo

#### Prerequisites
- CMake (version 3.31.4 or later)
- C++ compiler with ARM architecture support (e.g., AppleClang for macOS on ARM)

#### Building the C++ Demo
1. Navigate to the `gv-cpp-demo` directory:
   ```
   cd gv-cpp-demo
   ```
2. Create a build directory and navigate into it:
   ```
   mkdir build && cd build
   ```
3. Run CMake to configure the project:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   make
   ```

#### Running the C++ Demo
After building, run the executable:
```
./hello_arm
```

### Java JNI Demo

#### Prerequisites
- Java Development Kit (JDK) with support for the target ARM architecture
- C compiler compatible with JNI and the target ARM architecture

#### Building the Java JNI Demo
1. Navigate to the `gv-java-demo` directory:
   ```
   cd gv-java-demo
   ```
2. Compile the Java class:
   ```
   javac HelloJNI.java
   ```
3. Generate the C header file:
   ```
   javah -jni HelloJNI
   ```
4. Compile the C code into a shared library:
   ```
   gcc -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin hellojni.c -o libhellojni.so
   ```

#### Running the Java JNI Demo
Execute the Java application:
```
java -Djava.library.path=. HelloJNI
```

### Troubleshooting

#### Common Issues and Solutions

1. CMake configuration fails
   - Problem: CMake fails to detect the C or C++ compiler.
   - Solution: Ensure that Xcode Command Line Tools are installed on macOS:
     ```
     xcode-select --install
     ```

2. Java JNI library not found
   - Problem: `java.lang.UnsatisfiedLinkError: no hellojni in java.library.path`
   - Solution: Verify that `libhellojni.so` is in the current directory and that you're using the `-Djava.library.path=.` option when running the Java application.

#### Debugging

- For C++ debugging, compile with debug symbols:
  ```
  cmake -DCMAKE_BUILD_TYPE=Debug ..
  make
  ```
  Then use a debugger like `lldb` or `gdb`.

- For Java JNI debugging, use the `-verbose:jni` option:
  ```
  java -verbose:jni -Djava.library.path=. HelloJNI
  ```

#### Performance Optimization

- Use the `-mcpu=native` flag for C/C++ compilation to optimize for the specific ARM CPU:
  ```
  CXXFLAGS="-mcpu=native" cmake ..
  ```
- Profile the application using tools like `perf` on Linux or Instruments on macOS to identify bottlenecks.

## Data Flow

The data flow in both demos is straightforward:

1. C++ Demo:
   - The main function is called
   - Application logic executes
   - Output is generated

2. Java JNI Demo:
   - Java `main` method is invoked
   - Native library `hellojni` is loaded
   - `HelloJNI` object is created
   - Native `hello()` method is called
   - Control passes to C code
   - C code executes and returns control to Java
   - Java program terminates

```
[Java Main] -> [JNI Load Library] -> [Create HelloJNI Object]
     |                                         |
     v                                         v
[Call Native Method] <- - - - - - - - - [C Native Method]
     |                                         ^
     v                                         |
[Program Termination] <- - - - - - - - - - - - -
```

Note: The dashed lines represent the flow of control between Java and native C code.