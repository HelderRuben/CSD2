# Hey diaryyy!

Just gonna try some trial and error reverb configurations and paste them in here if they sound somewhat nice ig.

# Sounds nice in high but very delayed
apf1.processFrame(inputChannel[sample] + feedbackSample, apf1output);
apf2.processFrame(apf1output, apf2output);
apf3.processFrame(apf2output, apf3output);
apf4.processFrame(apf3output, apf4output);

apf5.processFrame(inputChannel[sample] + feedbackSample, apf5output);
apf6.processFrame(apf5output, apf6output);
lineOne = apf6output * 0.2;
apf7.processFrame(apf6output, apf7output);
lineTwo = apf7output * 0.3;
apf8.processFrame(apf7output, apf8output);
lineThree = apf8output * 0.5;
feedbackSample = apf8output * 0.25;
outputSample = lineOne + lineTwo + lineThree;


AllPassFilter apf1{0.3, 23, 25};
AllPassFilter apf2{0.3, 14, 16};
NestedAPFOne apf3{
  0.5, 50, 53,
  0.25, 73, 76};
NestedAPFTwo apf4{
  0.5, 41, 44,
  0.25, 107, 110,
  0.25, 89, 93
};

AllPassFilter apf5{0.3, 384, 512};
AllPassFilter apf6{0.3, 576, 600};
NestedAPFOne apf7{
  0.5, 1200, 1250,
  0.25, 2976, 3000};
NestedAPFTwo apf8{
  0.5, 672, 5800,
  0.25, 3648, 3700,
  0.25, 1440, 1500
};

# With delays (sounds very metallic)

apf1.processFrame(inputChannel[sample] + feedbackSample, apf1output);
apf2.processFrame(apf1output, apf2output);
apf3.processFrame(apf2output, apf3output);
apf4.processFrame(apf3output, apf4output);

apf5.processFrame(inputChannel[sample] + feedbackSample, apf5output);
apf6.processFrame(apf5output, apf6output);
lineOne = apf6output * 0.3;
apf7.processFrame(apf6output, apf7output);
lineTwo = apf7output * 0.4;
apf8.processFrame(apf7output, apf8output);
lineThree = apf8output * 0.9;
feedbackSample = apf8output * 0.35;
float tempoutputSample = lineOne + lineTwo + lineThree;
delay1.processFrame(tempoutputSample, delay1Output);
delay2.processFrame(tempoutputSample, delay2Output);
delay3.processFrame(tempoutputSample, delay3Output);
delay4.processFrame(tempoutputSample, delay4Output);
outputSample = (delay1Output + delay2Output + delay3Output + delay4Output + tempoutputSample) * 0.20;


AllPassFilter apf1{0.3, 23, 25};
AllPassFilter apf2{0.3, 14, 16};
NestedAPFOne apf3{
  0.5, 50, 53,
  0.25, 73, 76};
NestedAPFTwo apf4{
  0.5, 41, 44,
  0.25, 107, 110,
  0.25, 89, 93
};

AllPassFilter apf5{0.3, 187, 195};
AllPassFilter apf6{0.3, 289, 300};
NestedAPFOne apf7{
  0.5, 599, 605,
  0.25, 1476, 1500};
NestedAPFTwo apf8{
  0.5, 336, 350,
  0.25, 1823, 1850,
  0.25, 721, 730
};
Delay delay1{0.8, 2048, 2050, 1};
Delay delay2{0.8, 1703, 1850, 1};
Delay delay3{0.8, 1309, 1330, 1};
Delay delay4{0.8, 2246, 2250, 1};

# Multiple large room reverbs summed

THIS SOUNDS GOOD
not too metallic and really diffuse in high-end
Seems like the summed total of multiple reverbs with just different values works really well

Code:
apf1.processFrame(inputChannel[sample] + feedbackSample, apf1output);
apf2.processFrame(apf1output, apf2output);
lineOne = apf2output * 0.5;
apf3.processFrame(apf2output, apf3output);
lineTwo = apf3output * 0.3;
apf4.processFrame(apf3output, apf4output);
lineThree = apf4output * 0.5;
feedbackSample = apf4output * 0.45;
outputSample1 = lineOne + lineTwo + lineThree;

xtra1apf1.processFrame(inputChannel[sample] + feedbackSample, xtra1apf1output);
xtra1apf2.processFrame(xtra1apf1output, xtra1apf2output);
xtra1lineOne = xtra1apf2output * 0.6;
xtra1apf3.processFrame(xtra1apf2output, xtra1apf3output);
xtra1lineTwo = xtra1apf3output * 0.4;
xtra1apf4.processFrame(xtra1apf3output, xtra1apf4output);
xtra1lineThree = xtra1apf4output * 0.55;
xtra1feedbackSample = xtra1apf4output * 0.45;
xtra1outputSample = xtra1lineOne + xtra1lineTwo + xtra1lineThree;

xtra2apf1.processFrame(inputChannel[sample] + feedbackSample, xtra2apf1output);
xtra2apf2.processFrame(xtra2apf1output, xtra2apf2output);
xtra2lineOne = xtra2apf2output * 0.9;
xtra2apf3.processFrame(xtra2apf2output, xtra2apf3output);
xtra2lineTwo = xtra2apf3output * 0.5;
xtra2apf4.processFrame(xtra2apf3output, xtra2apf4output);
xtra2lineThree = xtra2apf4output * 0.4;
xtra2feedbackSample = xtra2apf4output * 0.45;
xtra2outputSample = xtra2lineOne + xtra2lineTwo + xtra2lineThree;

outputSample = (outputSample1 + xtra1outputSample + xtra2outputSample) * 0.33;


AllPassFilter apf1{0.35, 384, 512};
AllPassFilter apf2{0.3, 576, 600};
NestedAPFOne apf3{
  0.5, 1200, 1250,
  0.25, 2976, 3000};
NestedAPFTwo apf4{
  0.5, 672, 680,
  0.25, 3648, 3700,
  0.25, 1440, 1500
};

AllPassFilter xtra1apf1{0.4, 413, 512};
AllPassFilter xtra1apf2{0.35, 534, 600};
NestedAPFOne xtra1apf3{
  0.3, 1134, 1250,
  0.45, 3197, 3200};
NestedAPFTwo xtra1apf4{
  0.6, 649, 660,
  0.45, 3856, 3900,
  0.15, 1340, 1500
};

AllPassFilter xtra2apf1{0.3, 367, 512};
AllPassFilter xtra2apf2{0.4, 614, 630};
NestedAPFOne xtra2apf3{
  0.6, 1236, 1250,
  0.2, 2743, 3000};
NestedAPFTwo xtra2apf4{
  0.45, 699, 710,
  0.15, 3578, 3700,
  0.45, 1540, 1550
};
