cmake_minimum_required(VERSION 3.23)
project(M_todos_Num_ricos_II)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(M_todos_Num_ricos_II
        .idea/.gitignore
        .idea/M-todos-Num-ricos-II.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        FixedPointMethod.cpp
        )
add_executable(derivatives derivative.cpp)

add_executable(clase Clase.cpp)

add_executable(Ablacio Ablació/AblacioCardiaca.cpp)