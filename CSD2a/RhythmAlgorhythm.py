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

def timeify(durList, bpm):
    """Converts list w note durations to time intervals"""
    timeList = [];
    #bpm times 2 if time signature is in 16ths
    bpmMultiplyer = 60.0 / (bpm * 2);

    for i in durList:
        timeList.append(i * bpmMultiplyer);
    print(timeList);
    return timeList;

def timestampify(timeList):
    """Converts list w time intervals to timestamps"""
    timestampList = [];
    #starts at 0
    timestamp = 0;

    for i in timeList:
        timestampList.append(timestamp);
        timestamp += i;

    print(timestampList);
    return timestampList;

def generateNotes(Options):
    """Outputs list w note durations according to options"""
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

def chopOneNote(note, amt):
    """Chops note duration into series of small intervals"""
    pass

def chopNotes(chopFactor):
    """Outputs 3 chopped notelists according to chopFactor"""
    #To pick track to chop from
    trackArray = [noteListLow, noteListMid, noteListHigh];

    #gives a number from 1-10 for amount of notes chopped
    randomness = chopFactor / 10;
    #gives a range for how long the chopped notes will become
    chopAmt = (chopFactor / 100) * -1 + 1;
        #math: / decides range, + decides minimum

    #stappen alvast uitgeschreven in PSEUDO-CODE
    for i in range(randomness):
        #Initialize array to chop note from
        whichTrack = random.randrange(3);
        trackToChop = trackArray[whichTrack];
        randomNote = random.randrange(len(whichTrack));
        ####PSEUDO FOR SELECTING N0TE TO CHOP:
        #if trackToChop[randomNote] > minimumvalue chopped note:
            #chop one note
            #trackToChop[randomNote] = chopOneNote(trackToChop[randomNote], chopAmt);
            #make sure for loop continues
            #Make variable for amount of notes chopped tied to randomness?
            # -> To make sure for-loop doesnt make less chopped notes bc
            #    of random note being already chopped note
        #elif:
            #Make sure for loop selects other note to chop
            #one note

def playNotes(listToPlay, sampleToPlay):
    """Runs time and plays sample on timestamps"""
    timeStep = listToPlay.pop(0);
    timeStart = time.time();

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

#options
OptionsLow = [2, 3, 4];
OptionsMid = [3, 4, 5, 6];
OptionsHigh = [1, 2, 3, 4, 6];

#Fill with notes
noteListLow = generateNotes(OptionsLow);
noteListMid = generateNotes(OptionsMid);
noteListHigh = generateNotes(OptionsHigh);

#chopNotes(chopFactor);

#Convert to time intervals
timeListLow = timeify(noteListLow, bpm);
timeListMid = timeify(noteListMid, bpm);
timeListHigh = timeify(noteListHigh, bpm);

#convert to timestamsp
tsListLow = timestampify(timeListLow);
tsListMid = timestampify(timeListMid);
tsListHigh = timestampify(timeListHigh);

#Play
playNotes(tsListLow, sampleLow);
playNotes(tsListMid, sampleMid);
playNotes(tsListHigh, sampleHigh);
