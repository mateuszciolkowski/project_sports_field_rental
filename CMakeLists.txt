cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_COMPILER g++) 
set(CMAKE_C_COMPILER gcc)   
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED ON) 



set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g3 -gdwarf-4")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4")

project(Orlik)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set (-Wall -Wpedantic -Wextra -Werror)

add_subdirectory(library)
add_subdirectory(program)

enable_testing()