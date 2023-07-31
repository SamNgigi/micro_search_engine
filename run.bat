@echo off

for %%i in ("%~dp0.") do set "DIR_NAME=%%~ni"

if not exist build (
    mkdir build
)

cd build
cmake -DCMAKE_TOOLCHAIN_FILE=C:\Users\samtn\vcpkg\scripts\buildsystems\vcpkg.cmake ..
cmake --build .

cd ..
build\Debug\%DIR_NAME%.exe
build\Debug\%DIR_NAME%_test.exe