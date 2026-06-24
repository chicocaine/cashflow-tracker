## CashFlowTracker

This is a simple cashflow tracking app that has a C/C++ core and different target platforms.

> This is a work in progress.

### Requirements
- C23 Standard
- C++26 Standard
- CMake
- Ninja
- gcc and g++

### Configuring build files with cmake and ninja
debug build configuration with ninja:
```bash
cmake -G Ninja -B build/build-debug -DCMAKE_BUILD_TYPE=Debug
```

release build configuration with ninja:
```bash
cmake -G Ninja -B build/build-release -DCMAKE_BUILD_TYPE=Release
```

### Build and compile

#### debug build:
```bash
cmake --build build/build-debug
```

#### release build:
```bash
cmake --build build/build-release
```

#### target platform build:
```bash
cmake --build build/build-debug --target cli-cashflow-tracker
```