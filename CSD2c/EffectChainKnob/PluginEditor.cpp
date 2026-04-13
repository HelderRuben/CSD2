#include "PluginProcessor.h"
#include "PluginEditor.h"

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_events/juce_events.h>

#include "ParameterID.hpp"

namespace plugin_focus {
  //==============================================================================
  AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
      : AudioProcessorEditor (&p), processorRef (p),
      sliderAttachment {
          *processorRef.getState().getParameter(id::PARAM.getParamID()), slider, nullptr
      }

  {
      addAndMakeVisible(slider);
      slider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
      slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 30);
      setSize (400, 400);
  }

  AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor(){}

  //==============================================================================
  void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g){
      g.fillAll (juce::Colour::fromRGB(195, 70, 55));
      g.setColour(juce::Colours::gainsboro);
      g.setFont(60.0f);
      g.drawFittedText("WAVESHASERVERB", getLocalBounds(), juce::Justification::bottomLeft, 1);
  }

  void AudioPluginAudioProcessorEditor::resized() {
      slider.setBounds(getLocalBounds().reduced(100));
  }
} // namespace plugin_focus
