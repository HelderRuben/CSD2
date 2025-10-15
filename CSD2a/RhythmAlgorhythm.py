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
    #Filling list
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
    #Filling list
    for duration in durList:
        timeList.append(duration * bpmMultiplyer);
    return timeList;

def makeTimestamps(timeList):
    """Returns list w timestamps from time intervals"""
    tsList = [];
    #starts at 0
    timestamp = 0;
    #Filling list
    for timeDur in timeList:
        tsList.append(timestamp);
        timestamp += timeDur;
    return tsList;

def makeNoteDict(ts, whatTrack, timeDur):
    """Returns dictionary containing timestamp, sample and duration of one note"""
    return {
        "timestamp": ts,
        "sample": whatTrack,
        "duration": timeDur
        #Room for more specs like length, velocity and tone.
    }

def makeDictList(tsList, whatTrack, noteList):
    """Returns list with note dictionaries"""
    listDict = [];
    for ts in range(len(tsList)):
        listDict.append(makeNoteDict(tsList[ts], whatTrack, noteList[ts]));
    return listDict;

def tsValueInDict(ts):
    """Returns value of "timestamp" in dictionary"""
    return ts["timestamp"];

def durValueInDict(ts):
    """Returns value of "duration" in dictionary"""
    return ts["duration"];

#Next step: combining the dictionaries
def combineDictLists(dictList1, dictList2, dictList3):
    """Returns combined list of note dictionaries in order of timestamp"""
    listDict = [];
    listDict.extend(dictList1);
    listDict.extend(dictList2);
    listDict.extend(dictList3);
    listDict.sort(key=tsValueInDict);
    return listDict;

def chopOneNote(listToChop, index, chopTime):
    """Chops 1 note duration into series of small durations and inserts in list"""
    #For testing in this phase: amt isn't linked to chopFactor, so default = 0.2
    chopsAmount = int(listToChop[index] / chopTime);
    #Remove current index...
    listToChop.pop(index);
    print(chopsAmount);
    #... and replace with chops
    for chop in range(chopsAmount):
        listToChop.insert(index, chopTime);
    return listToChop;

def chopTracks(chopFactor):
    """Includes chopped notes in the 3 tracks according to chopFactor"""
    #To pick track to chop from
    trackArray = [noteListLow, noteListMid, noteListHigh];

    #gives a number from 1-10 for amount of notes chopped
    randomness = chopFactor / 10;
    #gives a range for chopped note duration
    chopAmt = (chopFactor / 100) * - 1 + 1;
        #math: / decides range, + decides minimum

    # stappen alvast uitgeschreven in PSEUDO-CODE
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

def OptionsToDictList(Options, whatTrack):
    """Returns list of note dictionaries according to options and track kind"""
    noteList = makeDurList(Options);

    #Testing chopOneNote in second duration for HiHat
    print(noteList);
    if whatTrack == sampleHigh:
        noteList = chopOneNote(noteList, 1, 0.2);

    timeList = makeTimeList(noteList, bpm);
    timestampsList = makeTimestamps(timeList);
    dictList = makeDictList(timestampsList, whatTrack, timeList);
    return dictList;

def playSample(listToPlay):
    """Runs time and plays sample on timestamps"""
    playList = [];
    for i in range(len(listToPlay)):
        playList.append(listToPlay[i]);
    nextSample = playList.pop(0);
    timeStart = time.time();
    #While-loop for playing samples on timestamps
    while True:
        now = time.time() - timeStart;
        if(now > nextSample["timestamp"]):
            nextSample["sample"].play();
            if playList:
                nextSample = playList.pop(0);
                now = timeStart;
            else:
                playSample(dictListTotal);
                break;
        time.sleep(0.01);


##### TESTING

#Options
OptionsLow = [2, 3, 4];
OptionsMid = [3, 4, 5, 6];
OptionsHigh = [1, 2, 3, 4, 6];

#From Options to List containing all note dictionaries
dictListLow = OptionsToDictList(OptionsLow, sampleLow);
dictListMid = OptionsToDictList(OptionsMid, sampleMid);
dictListHigh = OptionsToDictList(OptionsHigh, sampleHigh);
dictListTotal = combineDictLists(dictListLow, dictListMid, dictListHigh);

#Print
print("+--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---+");
print("|                         TOTAL DICTIONARY LIST                         |");
print("+--- --- --- --- --- --- --- --- --*:*-- --- --- --- --- --- --- --- ---+");
for dict in range(len(dictListTotal)):
    print(dictListTotal[dict]);

#Play
playSample(dictListTotal);
