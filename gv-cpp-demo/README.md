# Hello ARM

A simple C++ project to test compilation on ARM architecture (Graviton).

## Building the Project

1. Create a build directory:

```bash
mkdir -p build && cd build
```

2. Configure the build:

```bash
cmake ..
```

3. Build the project:

```bash
make
```

4. Run the executable:

```bash
./hello_arm
```

## Notes
- This project is configured to be built on ARM architecture
- The program will display which ARM architecture it's running on (ARM64 or ARM32)

