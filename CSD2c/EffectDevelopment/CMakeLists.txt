cmake_minimum_required(VERSION 3.20)
project(EffectDevelopment VERSION 0.0.1)


if(MSVC)
    find_package(liblo CONFIG REQUIRED)
else()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBLO REQUIRED IMPORTED_TARGET liblo)
endif()


#add_subdirectory(JUCE)
juce_add_console_app(EffectDevelopment PRODUCT_NAME "EffectDevelopment")
target_sources(EffectDevelopment
  PRIVATE
  main.cpp
  callback.cpp
  circularBuffer.cpp
)
target_compile_definitions(EffectDevelopment PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(EffectDevelopment PRIVATE ${LIBLO_INCLUDE_DIR})

if(MSVC)
    target_link_libraries(EffectDevelopment PRIVATE
        csd_lib
        liblo::liblo
        #liblo::liblo-static

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #juce::juce_recommended_warning_flags
)
else()
    target_link_libraries(EffectDevelopment PRIVATE
        csd_lib

        PkgConfig::LIBLO

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #juce::juce_recommended_warning_flags
)
endif()
target_compile_features(EffectDevelopment PRIVATE cxx_std_20)
