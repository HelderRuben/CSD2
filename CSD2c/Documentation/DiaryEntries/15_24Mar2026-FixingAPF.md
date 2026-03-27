# Hey Diary!

Even though it's currently March 23, I'm writing this introduction to have a grasp on what i'm going to be doing tomorrow on this project.  
Presenting the reverb that i have (plus takeaways) was really helpful for me. The main thing i learned is that my Interpolation inside the APF is just wrong. Especially for the reverb.  
So that's the plan!

To make a list of actions:
1. Some short self study on (cubic) Interpolation
2. Implementing it in the AllPassFilter
3. Testing the reverb and hoping its fixed

# Interpolation Self Study

**Interpolation**  
Estimating new data points based on a known set of (discrete) data points.  
https://en.wikipedia.org/wiki/Interpolation  

**Linear Interpolation**  
Interpolation based on calculating a line from one discrete point to the other.  

**Cubic (Spline) Interpolation**  
Interpolation based on calculating a (low-degree) polynomial between each 2 discrete points.  
https://en.wikipedia.org/wiki/Spline_interpolation  

**Fourier Series**  
A nice way to see a periodic function as a sum of trigonometric functions that converge to it.  
https://en.wikipedia.org/wiki/Fourier_series  

**Fourier Transform**  
Yea something with frequencies idk.  
https://en.wikipedia.org/wiki/Fourier_transform  

**Gaussian Process**  
Something with randomness idk.  
https://en.wikipedia.org/wiki/Gaussian_process  

# Interpolation in AllPassFilter

When i looked at code online, i saw someone already using cubic interpolation but i didn't get it. I'm researching that further now.  

About the code that i'm looking at:
- Has Linear Interpolation method
- Has Cubic Interpolation method.

Fortunately for me, this line is added:  
```
//Cubic interp (this algorithm) taken from: http://paulbourke.net/miscellaneous/interpolation/
```

**Cubic**  
Requires 4 points. 2 points in between which the interpolation is done, and the 2 neighbouring points of these.  
mu: the place between the 2 discrete points, value between 0 and 1.  
I understand! I'm implementing this formula into my own circular buffer/AllPassFilter.  

I presume the code uses doubles for more accurate calculation.  

*Question: Do i still need the m_makeUpGain if this fixes it?*
*Question: Do i still need the setBreakFrequency?*

# Implementing and Testing
Testing, i feel like this should work.  

No hold on, why does the code that i'm looking at have floats as a value for the readheadposition?
Don't get interpolation anymore. But i guesss i do want to have it for the reverb? but i'm not really sure anymore

**Okay I know what i don't get now (partially):**  
The readCubic() expects a float for the RHPosition, but then the 4 variables are just turned into integers by using floor.
By doing getReadValue(), the SAMPLES are floats by using integers as RHPosition.  
The thing i don't get about the formula is "mu", because i do think that should be a float? And also, why are y1 and y2 the same value? We'll see how this goes.

First testing with only AllPassFilters, not the nested ones.  
(also deleted the debug methods for the plugin focus bc i'm not using them anyway)

Tested it, not sure if i hear the difference but i'll implement it into the nested ones and then we'll really see.

Now all the APF's have cubic interpolation, but the sound in exactly the same.

Testing on phaser: Sounds exactly the same
So the interpolation doesn't work?

Feels like i'm waisting my time here
