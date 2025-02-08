# Networking Tools

A C++ library designed for Networking Admins, Engineers, etc.

## Installation

To install this library, follow these steps:

1. **Clone the repository**:
   ```sh
   git clone https://github.com/jojo6550/Networking-Tools.git
   cd Networking-Tools
   ```

2. **Build the library manually using `g++`**:
   ```sh
   mkdir obj
   g++ -c src/*.cpp -o obj/
   ar rcs libNetworking.a obj/*.o
   ```

3. **Install the library** (move headers and compiled library to standard locations):
   ```sh
   sudo mkdir -p /usr/local/include/NetworkingTools
   sudo cp include/*.h /usr/local/include/NetworkingTools/
   sudo cp libNetworking.a /usr/local/lib/
   ```

## Building with CMake

Alternatively, you can use CMake to build and install the library:

```sh
mkdir build
cd build
cmake ..
cmake --build .
sudo cmake --install .
```

## Usage

To use this library, include the `ip_converter.h` header file and link against the `NetworkingTools` library.

### **Compiling and Linking Manually**

```sh
g++ -o your_program your_program.cpp -L"/usr/local/lib" -lNetworking -I"/usr/local/include/NetworkingTools"
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
./your_program
```

For dynamic libraries (`.so` on Linux, `.dll` on Windows), ensure the library path is set:

- **Linux/macOS**: `export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH`
- **Windows**: Add the `.dll` path to the `PATH` environment variable.

---

Now your `README.md` includes detailed build, install, and run instructions using `g++` and CMake! 🚀

