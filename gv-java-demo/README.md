# Java Native Interface (JNI) Demo Project

This project demonstrates the usage of Java Native Interface (JNI) to call a native C/C++ function from Java code. It provides a simple example of how to integrate native code with Java applications, showcasing the power and flexibility of JNI for cross-language development.

The demo consists of a Java class that declares a native method and calls it using JNI. This project serves as a starting point for developers who want to understand how to leverage native code in their Java applications, which can be particularly useful for performance-critical operations or when interfacing with system-level functionalities.

## Repository Structure

The repository has a simple structure:

- `gv-java-demo/`
  - `hellojni.c`: The C source file containing the native implementation of the `hello()` function.
  - `HelloJNI.java`: The Java source file that declares and uses the native method.

## Usage Instructions

### Prerequisites

- Java Development Kit (JDK) 8 or higher
- A C compiler (e.g., GCC)
- Knowledge of compiling and running Java applications

### Compilation

1. Compile the Java file:
   ```sh
   javac gv-java-demo/HelloJNI.java
   ```

2. Generate the C header file:
   ```sh
   javah -jni -classpath gv-java-demo HelloJNI
   ```

3. Compile the C file to create a shared library:
   ```sh
   gcc -shared -fpic -o libhellojni.so -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux gv-java-demo/hellojni.c
   ```

   Note: The exact command may vary depending on your operating system and JDK installation.

### Running the Demo

To run the demo:

```sh
java -Djava.library.path=. -classpath gv-java-demo HelloJNI
```

This command assumes that the shared library (`libhellojni.so` or equivalent) is in the current directory.

### Code Example

Here's the Java code that demonstrates the JNI usage:

```java
public class HelloJNI {

    public native void hello();

    public static void main(String[] args) {
        System.loadLibrary("hellojni");

        HelloJNI hello = new HelloJNI();
        hello.hello();
    }
}
```

This code does the following:
1. Declares a native method `hello()`.
2. Loads the native library `hellojni` in the `main` method.
3. Creates an instance of `HelloJNI`.
4. Calls the native `hello()` method.

### Troubleshooting

- **UnsatisfiedLinkError**: If you encounter this error, ensure that:
  1. The native library is in the correct location.
  2. The library name in `System.loadLibrary()` matches the actual library file name (without the "lib" prefix and file extension).
  3. The `java.library.path` is set correctly.

- **NoClassDefFoundError**: Verify that the classpath is set correctly when running the Java application.

- **Compilation Errors**: Make sure you have the JDK installed and that the paths to the JNI headers are correct in your C compilation command.

## Data Flow

The data flow in this JNI demo is straightforward:

1. Java code initialization
2. Native library loading
3. Java method invocation
4. JNI transition to native code
5. Native function execution
6. Return to Java code

```
[Java Code] --> [JNI] --> [Native C Code]
     ^                         |
     |                         |
     +-------------------------+
```

Note: The actual data exchange between Java and native code is minimal in this demo. In more complex applications, JNI allows for passing various data types and objects between Java and native code.


```bash
g++ -mcpu=native -o output_file source_file.cpp
```