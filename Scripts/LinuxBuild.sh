#!/bin/bash

echo -e "\e[32mStarting linux build, 'release' or 'debug'?\e[0m"
read config

clear

echo -e "\e[32mPress any key to start...\e[0m"
read -n 1 -s

clear

echo -e "\e[32mCompiling Umbra...\e[0m"
cd ../
./Vendor/Premake5/Linux/premake5 gmake
make config=$config -j$(nproc)

clear

echo -e "\e[32mCompilation finished, files are located on bin/Debug-linux-x86_64/ ...\e[0m"
