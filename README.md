# Networking Tools


## Overview 
Jojo's Networking Tools is a collection of command-line tools designed to simplify network management and troubleshooting tasks. The tools are written in C++ and are designed to be fast, efficient, and easy to use.

## Installation

To install this library on Windows, follow these steps:

1. **Clone the repository**:
   ```sh
   git clone https://github.com/jojo6550/Networking-Tools.git
   cd Networking-Tools
   ```

2. **Build the library manually using `g++` (MinGW required)**:
   ```sh
   mkdir obj
   g++ -c src/*.cpp -o obj/
   ar rcs libNetworking.a obj/*.o
   ```

3. **Install the library** (move headers and compiled library to a standard location):
   ```sh
   mkdir C:\NetworkingTools\include
   mkdir C:\NetworkingTools\lib
   copy include\*.h C:\NetworkingTools\include\
   copy libNetworking.a C:\NetworkingTools\lib\
   ```

## Usage

To use this library, include the `ip_converter.h` header file and link against the `NetworkingTools` library.

### **Compiling and Linking Manually**

```sh
g++ -o your_program your_program.cpp -L"C:\\NetworkingTools\\lib" -lNetworking -I"C:\\NetworkingTools\\include"
```

### **Example Code**

```cpp
#include "ip_converter.h"
using namespace IpConverter;

int main() {
    IPv4Converter ipv4;
    // Use the library functions here...
    return 0;
}
```

### **Running the Program**

After compilation, run the executable:

```sh
your_program.exe
```

For dynamic libraries (`.dll` on Windows), ensure the library path is set:

- **Windows**: Add the `C:\NetworkingTools\lib` path to the `PATH` environment variable:
  ```sh
  set PATH=C:\NetworkingTools\lib;%PATH%
  ```

---

