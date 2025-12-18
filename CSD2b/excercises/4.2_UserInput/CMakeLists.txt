cmake_minimum_required(VERSION 3.22)
project(exiemple VERSION 0.0.1)

juce_add_console_app(exiemple PRODUCT_NAME "exiemple")
target_sources(exiemple
        PRIVATE
        main.cpp
        userinput.cpp
        callback.cpp
        synth.cpp
        oscillator.cpp
        sine.cpp
        square.cpp
        saw.cpp
)

target_compile_definitions(exiemple PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(exiemple
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(exiemple PRIVATE cxx_std_20)
