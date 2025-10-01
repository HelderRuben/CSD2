#Importing Modules
import pygame;
import time;
import random;

pygame.init();

#initiating samples from assets
sampleLow = pygame.mixer.Sound("../assets/kick.wav");
sampleMid = pygame.mixer.Sound("../assets/snare.wav");
sampleHigh = pygame.mixer.Sound("../assets/hihat.wav");

# Amount of notes in bar
totalTime = 14;
bpm = 120;


def makeDurList(Options):
    """Returns list w note durations according to options"""
    durList = [];
    for i in range(totalTime):
        #Fill array with note-lengths
        optionLength = len(Options);
        randomOption = random.randrange(optionLength);
        durList.append(Options[randomOption]);
        #Stop filling array if totalTime has been reached
        if sum(durList) >= totalTime:
            #Capping last note so durList doesn't overflow
            durList[-1] -= (sum(durList) - totalTime);
            break;
    return durList;

def makeTimeList(durList, bpm):
    """Returns list w time intervals from note durations"""
    timeList = [];
    #bpm times 2 if time signature is in 16ths
    bpmMultiplyer = 60.0 / (bpm * 2);

    for duration in durList:
        timeList.append(duration * bpmMultiplyer);
    return timeList;

def makeTimestamps(timeList):
    """Returns list w timestamps from time intervals"""
    tsList = [];
    #starts at 0
    timestamp = 0;

    for timeDur in timeList:
        tsList.append(timestamp);
        timestamp += timeDur;
    return tsList;

def makeNoteDict(ts, whatTrack):
    """Returns dictionary w one note with timestamp and sample"""
    return {
        "timestamp": ts,
        "sample": whatTrack
        #Room for more specs like length and velocity
    }

#Next step: combining the dictionaryies
def combineDict(dict1, dict2, dict3):
    pass

def chopOneNote(note, amt):
    """Chops 1 note duration into series of small durations"""
    pass

def chopTracks(chopFactor):
    """Includes chopped notes in the 3 tracks according to chopFactor"""
    #To pick track to chop from
    trackArray = [noteListLow, noteListMid, noteListHigh];

    #gives a number from 1-10 for amount of notes chopped
    randomness = chopFactor / 10;
    #gives a range for how long the chopped notes will become
    chopAmt = (chopFactor / 100) * - 1 + 1;
        #math: / decides range, + decides minimum

    #stappen alvast uitgeschreven in PSEUDO-CODE
    # for i in range(randomness):
        #Initialize array to chop note from
        # whichTrack = random.randrange(3);
        # trackToChop = trackArray[whichTrack];
        # randomNote = random.randrange(len(whichTrack));
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

#To get rid of duplicate code
def OptionsToTimestamps(Options, whatTrack):
    """Returns list of timestamps according to options and prints track kind"""
    noteList = makeDurList(Options);
    timeList = makeTimeList(noteList, bpm);
    timestampsList = makeTimestamps(timeList);
    print(whatTrack, timestampsList);
    return timestampsList;


def playTimestamps(listToPlay, sampleToPlay):
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

tsListLow = OptionsToTimestamps(OptionsLow, "Low: ")
tsListMid = OptionsToTimestamps(OptionsMid, "Mid: ")
tsListHigh = OptionsToTimestamps(OptionsHigh, "High: ")

#testing new makeNoteDict func
dictTestLow = makeNoteDict(tsListLow[1], "low");
dictTestMid = makeNoteDict(tsListMid[1], "mid");
dictTestHigh = makeNoteDict(tsListLow[1], "high");
print("low: ", dictTestLow);
print("mid: ", dictTestMid);
print("high: ", dictTestHigh);

#Choptracks(50);

#Play
playTimestamps(tsListLow, sampleLow);
playTimestamps(tsListMid, sampleMid);
playTimestamps(tsListHigh, sampleHigh);
