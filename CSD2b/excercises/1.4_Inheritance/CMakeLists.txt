cmake_minimum_required(VERSION 3.10)
project(inheritance)

add_executable(inheritance)

target_sources(inheritance PRIVATE
    main.cpp
    pet.cpp
    dog.cpp
    cat.cpp
    corgy.cpp
    husky.cpp
)
set_property(TARGET inheritance PROPERTY CXX_STANDARD 20)
