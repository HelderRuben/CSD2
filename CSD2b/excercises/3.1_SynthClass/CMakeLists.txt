cmake_minimum_required(VERSION 3.22)
project(examp VERSION 0.0.1)

juce_add_console_app(examp PRODUCT_NAME "examp")
target_sources(examp
        PRIVATE
        main.cpp
        callback.cpp
        oscillator.cpp
        sine.cpp
        square.cpp
        saw.cpp
)

target_compile_definitions(examp PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(examp
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(examp PRIVATE cxx_std_20)
