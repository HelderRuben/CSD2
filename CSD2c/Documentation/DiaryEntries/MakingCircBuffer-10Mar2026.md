# Hey Diary!

Now i kind of understand the basics of what i'm working with and i can test things in the terminal, i'm making an all-pass filter
To be honest, i don't really know where to start so i'm just making a bit of an overview here:

An AllPassFilter has:
- A delay
  - Should be a handful of milliseconds
- A feedbackloop with a gain
- A feedforward with a gain  

- I also know the cutoff-freq has probably something to do with the ratio between the 2 different gains
Don't know how though, so we'll see and i'll do some extra research + look at some existing code.

Welll before starting the actual all-passfilter i ofcourse need a delay, and for a delay i need a circular buffer. Sooo this is not yet the APF, but certainly a step towards it.

# Start Coding a Circular Buffer

To get used to the syntax (again...), I'm going to be looking at the Ciska code first and then writing without looking, and then processing the things i missed.
At this step, i looked at the *00_circBufferSession* in codeclinic 1 and already tried to make sure the buffersize would be dynamic.

Things i did wrong:
- forgot void incr(int& head), especially with &
- forgot to add the buffer-array (for now doing it without dynamic size)
- wrote head-position-variables as floats i.o. ints (i'm not even sleep-deprived like what?)  

Before looking at *01_circularBuffer*, i'll try making the .cpp as well:  
Things i did wrong:  
- forgot that tick increments things
- in increment-ifstatement, did head = 0 i.o. head -= size of buffer
- forgot one ; (ofcourse)  

also added circularBuffer.cpp to CMakeLists.

# Dynamic Size Circular Buffer
Anyway, onto the dynamic size of the buffer.  
List of things that are added and my understanding of them:
- resetSize = reset the size of the buffer
- setter and getter for delayLength = same thing as distance from R to W, delaytime.
- inline things = compiled faster but more memory, handy for some things
- uints = unsigned integers
- wrap = is now a separate function to increment
- bufferSize = buffer size is now a member
- incrementHead = split up in IncrR and incrW (bc of inline? Or to get rid of int&? not sure)
- releaseBuffer = alter buffer size by freeing allocated data
- allocateBuffer = alter buffer size by making space for it
- constructer can instantly allocate and set the delaylength
- destructor releases allocated memory
- the buffer is a pointer now (no idea why actually)
- malloc? let me try to put it into words:  
```buffer = (float*)malloc(bufferSize * sizeof(float));```  
this creates empty memory space for the buffer array (which is float*), with the size of 1 float times the bufferSize, which is the amount of floats in the array.  
```memset(buffer, 0, bufferSize * sizeof(float));```
the memory of all the samples in the buffer are then set to 0 (still in the size of a float times the bufferSize).  
- With releaseBuffer, that memory space is freed up  

after some syntax-fixing, the dynamic memory circularBuffer is pretty much done.  
Since it is a new day today, i'll make a new Diary entry.
