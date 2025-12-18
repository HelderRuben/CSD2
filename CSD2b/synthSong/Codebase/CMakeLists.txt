cmake_minimum_required(VERSION 3.22)
project(eindopdracht VERSION 0.0.1)

juce_add_console_app(eindopdracht PRODUCT_NAME "eindopdracht")
target_sources(eindopdracht
        PRIVATE
        main.cpp
        userinput.cpp
        callback.cpp
        melody.cpp
        note.cpp
        synth.cpp
        ringmod.cpp
        freqmod.cpp
        oscillator.cpp
        sine.cpp
        square.cpp
        saw.cpp
)

target_compile_definitions(eindopdracht PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(eindopdracht
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(eindopdracht PRIVATE cxx_std_20)
