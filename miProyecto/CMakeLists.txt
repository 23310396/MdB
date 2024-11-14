cmake_minimum_required(VERSION 3.10)
project(MiProyecto)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 17)

# Directorio de los archivos fuente
include_directories(include)
add_executable(MiProyecto src/main.cpp)
