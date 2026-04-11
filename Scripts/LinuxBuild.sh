#!/bin/bash

echo -e "\e[32mStarting linux build, Debug configuration will be used by default.\e[0m"

echo -e "\e[32mPress any key to start...\e[0m"
read -n 1 -s

echo -e "\e[32mCompiling bgfx for linux, this may take a while...\e[0m"
cd ../Vendor/Bgfx/bgfx
make linux-gcc-release64 -j$(nproc)

echo -e "\e[32mCompiling Umbra...\e[0m"
cd ../../../
./Vendor/Premake5/Linux/premake5 gmake
make -j$(nproc)

echo -e "\e[32mCompilation finished, files are located on bin/Debug-linux-x86_64/ ...\e[0m"
