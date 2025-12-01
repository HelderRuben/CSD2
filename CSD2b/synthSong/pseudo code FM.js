// PSEUDO CODE FM

//Variables
float ratio = "ratio between carrier and modulator oscillating frequency"
float depth = "how much FM is applied to the carrier"
float melFreq = "frequency played by melody"
float carFreq = "frequency played by carrier"
float modFreq = "frequency played by modulator"
float carAmp = "amplitude of carrier"
float modAmp = "amplitude of modulator"
float soundoutput = "sound being played"

//Class
class Oscillator() {
  float freq
  float amp
  //Incorporates chosen waveform as well
  //outputs sample signal playable by playSound function
}

//Initialisation
melFreq = 440.0
ratio = 2.5
modFreq = melFreq * ratio
depth = 1.0
carAmp = 1.0
modAmp = depth * ratio * melFreq

//Frequency modulated by modulator
modulator = new Oscillator(modFreq, modAmp)
carFreq = melFreq + modulator.output
carrier = new Oscillator(carFreq, carAmp)

//Functions
function getSample() {//gets the sample of an oscillator}
function playSound() {
  //play signal of thisPhase
  soundoutput = getSample(carrier)
}
