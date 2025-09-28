#Importing Modules
import pygame;
import time;
import random;

pygame.init();

#initiating samples from assets
sampleLow = pygame.mixer.Sound("../assets/kick.wav");
sampleMid = pygame.mixer.Sound("../assets/snare.wav");
sampleHigh = pygame.mixer.Sound("../assets/hihat.wav");

# Amount of 16th notes in bar
totalTime = 14;
bpm = 120;
# arrays with possible note-lengths
lenOptionsLow = [];
lenOptionsMid = [];
lenOptionsHigh = [];

#arrays with timeified durations
timeListLow = [];
timeListMid = [];
timeListHigh = [];

#arrays with timestamps
tsListLow = [];
tsListMid = [];
tsListHigh = [];

##### FUNCTION SCRIPTS

def timeify(durList, bpm):
    timeList = [];
    bpmMultiplyer = 60.0 / bpm;

    for i in durList:
        timeList.append(i * bpmMultiplyer);
    print(timeList);
    return timeList;

def timestampify(timeList):
    timestampList = [];
    #starts at 0
    timestamp = 0;

    for i in timeList:
        timestampList.append(timestamp);
        timestamp += i;

    print(timestampList);
    return timestampList;

# General Script to set algorhythms in motion.
### Output is playable generated rhythm for 3 tracks.
def generateRhythm(OptionsLow, OptionsMid, OptionsHigh, chopFactor):
    # Lists with stored note-lengths
    global noteListLow;
    noteListLow = [];
    global noteListMid;
    noteListMid = [];
    global noteListHigh;
    noteListHigh = [];
    #Fill with notes
    noteListLow = generateNotes(OptionsLow);
    noteListMid = generateNotes(OptionsMid);
    noteListHigh = generateNotes(OptionsHigh);

    #chopNotes(chopFactor);

#Function for filling noteArrays with the possible options
def generateNotes(Options):
    noteArray = [];
    for i in range(totalTime):
        #Fill array with note-lengths
        optionLength = len(Options);
        randomOption = random.randrange(optionLength);
        noteArray.append(Options[randomOption]);
        #Stop filling array if totalTime has been reached
        if sum(noteArray) >= totalTime:
            #Capping last note so noteArray doesn't overflow
            noteArray[-1] -= (sum(noteArray) - totalTime);
            break;
    print(noteArray);
    return noteArray;

#Function to chop only one note, based on chop intensity
def chopOneNote(note, amt):
    pass

#Function for chopping notes-randomisation based on Chopfactor
def chopNotes(chopFactor):
    #To pick track to chop from
    trackArray = [noteListLow, noteListMid, noteListHigh];

    #gives a number from 1-10 for amount of notes chopped
    randomness = chopFactor / 10;
    #gives a range for how long the chopped notes will become
    chopAmt = (chopFactor / 100) * -1 + 1;
        #math: / decides range, + decides minimum

    #stappen uitgeschreven in PSEUDO-CODE
    for i in range(randomness):
        #Initialize array to chop note from
        whichTrack = random.randrange(3);
        trackToChop = trackArray[whichTrack];
        randomNote = random.randrange(len(whichTrack));
        ####PSEUDO FOR SELECTING NOTE TO CHOP:
        #if trackToChop[randomNote] > minimumvalue chopped note:
            #chop one note
            #trackToChop[randomNote] = chopOneNote(trackToChop[randomNote], chopAmt);
            #make sure for loop continues
            #Make variable for amount of notes chopped tied to randomness?
            # -> To make sure for-loop doesnt make less chopped notes bc
            #    of random note being already chopped note
        #elif:
            #Make sure for loop selects other note to chop
        #to chop one note

def playNotes(listToPlay, sampleToPlay):
    timeStep = listToPlay.pop(0);
    timeStart = time.time();
    #Cycling through time and playing samples on timestamps
    while True:
        now = time.time() - timeStart;
        if(now > timeStep):
            sampleToPlay.play();
            if listToPlay:
                timeStep = listToPlay.pop(0);
                now = timeStart;
            else:
                break;
        time.sleep(0.01);


##### TESTING
lenOptionsLow = [2, 3, 4];
lenOptionsMid = [3, 4, 5, 6];
lenOptionsHigh = [1, 2, 3, 4, 6];

generateRhythm(lenOptionsLow, lenOptionsMid, lenOptionsHigh, 50);

timeListLow = timeify(noteListLow, bpm);
timeListMid = timeify(noteListMid, bpm);
timeListHigh = timeify(noteListHigh, bpm);

tsListLow = timestampify(timeListLow);
tsListMid = timestampify(timeListMid);
tsListHigh = timestampify(timeListHigh);

playNotes(tsListLow, sampleLow);
# playNotes(tsListMid, sampleMid);
# playNotes(tsListHigh, sampleHigh);
