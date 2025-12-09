cmake_minimum_required(VERSION 3.10)
project(oscillator)

add_executable(oscillator)

target_sources(oscillator PRIVATE
    main.cpp
    oscillator.cpp
)
set_property(TARGET oscillator PROPERTY CXX_STANDARD 20)
