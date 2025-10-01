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
        #Room for more specs like length, velocity and tone.
    }

def makeListDict(tsList, whatTrack):
    """Returns list with note dictionaries"""
    listDict = [];
    for ts in range(len(tsList)):
        listDict.append(makeNoteDict(tsList[ts], whatTrack));
    return listDict;

def tsValueInDict(ts):
    """Returns value of "timestamp" in dictionary"""
    return ts["timestamp"];

#Next step: combining the dictionaries
def combineDict(dictLow, dict2, dict3):
    """Returns combined list of note dictionaries in order of timestamp"""
    listDict = [];
    for ts in range(len(dictLow)): listDict.append(dictLow[ts]);
    for ts in range(len(dictMid)): listDict.append(dictMid[ts]);
    for ts in range(len(dictHigh)): listDict.append(dictHigh[ts]);
    listDict.sort(key=tsValueInDict);
    return listDict;

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
def OptionsToDictionaries(Options, whatTrack):
    """Returns list of timestamps according to options and prints track kind"""
    noteList = makeDurList(Options);
    timeList = makeTimeList(noteList, bpm);
    timestampsList = makeTimestamps(timeList);
    dictList = makeListDict(timestampsList, whatTrack);
    print(whatTrack, ": ", dictList);
    return dictList;


def playSample(listToPlay):
    """Runs time and plays sample on timestamps"""
    nextSample = listToPlay.pop(0);
    timeStart = time.time();

    while True:
        now = time.time() - timeStart;
        if(now > nextSample["timestamp"]):
            nextSample["sample"].play();
            if listToPlay:
                nextSample = listToPlay.pop(0);
                now = timeStart;
            else:
                time.sleep(1);
                break;
        time.sleep(0.01);


##### TESTING

#options
OptionsLow = [2, 3, 4];
OptionsMid = [3, 4, 5, 6];
OptionsHigh = [1, 2, 3, 4, 6];

dictLow = OptionsToDictionaries(OptionsLow, sampleLow)
dictMid = OptionsToDictionaries(OptionsMid, sampleMid)
dictHigh = OptionsToDictionaries(OptionsHigh, sampleHigh)

dictTotal = combineDict(dictLow, dictMid, dictHigh);
print("TOTAL DICTIONARY:")
for dict in range(len(dictTotal)):
    print(dictTotal[dict]);
#Choptracks(50);

#Play
playSample(dictTotal);
