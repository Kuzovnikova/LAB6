cmake_minimum_required(VERSION 3.10)
project(Lab6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Шаблонные классы UniqueList и MyDictionary полностью в .h, 
# поэтому в add_executable добавляем их для контроля изменений в IDE
add_executable(Lab6
    main.cpp 
    Points.cpp 
    Points.h 
    UniqueList.h 
    MyDictionary.h
)

if(MSVC)
    add_compile_options(/utf-8)
endif()
