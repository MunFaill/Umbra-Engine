# Umbra-Engine

> [!NOTE]
> This is a study project; confusing code may be common.

# Building

### Dependencies
- SDL System binary temporarily

Currently tested and running only on Linux.

``` shell
git clone https://github.com/MunFaill/Umbra-Engine.git
cd Umbra-Engine
./Vendor/Premake5/Linux/premake5 gmake
make -j$(nproc)
./bin/Debug-linux-x86_64/UmbraSandbox/UmbraSandbox # Bin path
```