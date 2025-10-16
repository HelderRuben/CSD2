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
noteAmount = 14;
quarterOrEight = 0;
bpm = 120;

def optionsInTimeSignature(Options, quarterOrEight):
    """Returns list of options multiplied according to time signature"""
    #If time signature is in eight notes, options are halved
    optionMultiplier = 1 / (quarterOrEight / 2);
    newOptions = [];
    #Filling list
    for option in range(len(Options)):
        newOptions.append(Options[option] * optionMultiplier);
    return newOptions;

def makeDurList(Options):
    """Returns list w note durations according to options"""
    durList = [];
    #Filling list
    for i in range(int(noteAmount * (quarterOrEight / 2))):
        optionLength = len(Options);
        randomOption = random.randrange(optionLength);
        durList.append(Options[randomOption]);
        #Stop filling list
        if sum(durList) >= noteAmount:
            #Capping last note
            durList[-1] -= (sum(durList) - noteAmount);
            break;
    return durList;

def makeTimeList(durList, bpm):
    """Returns list w time intervals from note durations"""
    timeList = [];
    bpmMultiplyer = 60.0 / bpm;
    #Filling list
    for duration in durList:
        timeList.append(duration * bpmMultiplyer);
    return timeList;

def makeTimestamps(timeList):
    """Returns list w timestamps from time intervals"""
    tsList = [];
    #Starts at 0
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
    }

def makeDictList(tsList, whatTrack, noteList):
    """Returns list with note dictionaries"""
    listDict = [];
    #Filling list
    for ts in range(len(tsList)):
        listDict.append(makeNoteDict(tsList[ts], whatTrack, noteList[ts]));
    return listDict;

def tsValueInDict(ts):
    """Returns value of "timestamp" in dictionary"""
    return ts["timestamp"];

def durValueInDict(ts):
    """Returns value of "duration" in dictionary"""
    return ts["duration"];

def combineDictLists(dictList1, dictList2, dictList3):
    """Returns combined list of note dictionaries in order of timestamp"""
    listDict = [];
    listDict.extend(dictList1);
    listDict.extend(dictList2);
    listDict.extend(dictList3);
    listDict.sort(key=tsValueInDict);
    return listDict;

def chopOneNote(listToChop, index, choptensity):
    """Replaces 1 note duration w series of small durations and inserts in dictionary list"""
    dictToChop = listToChop[index];
    chopsAmount = int(dictToChop["duration"] / choptensity);

    #Remove current index dictionary
    removedDict = listToChop.pop(index);
    replaceTimestamp = removedDict["timestamp"];
    replaceSample = removedDict["sample"];

    #Insert chops as dictionaries
    for chop in range(chopsAmount):
        listToChop.insert(index + chop, {                                 #Add timestamp and sample back
            "timestamp": removedDict["timestamp"] + (chop * choptensity), #Increasing timestamps
            "sample": removedDict["sample"],
            "duration": choptensity
        });
    #Sort list (samples played during chopped note is possible)
    listToChop.sort(key=tsValueInDict);
    return listToChop;

def chopTracks(chopFactor):
    """Includes chopped notes in the 3 tracks according to chopFactor"""

def OptionsToDictList(Options, whatTrack):
    """Returns list of note dictionaries according to options and track kind"""
    optionsWithinTimeSignature = optionsInTimeSignature(Options, quarterOrEight)
    noteList = makeDurList(optionsWithinTimeSignature);

    #Testing chopOneNote in second duration of HiHat
    print(noteList);
    # if whatTrack == sampleHigh:
    #     noteList = chopOneNote(noteList, 1, 0.1);

    timeList = makeTimeList(noteList, bpm);
    timestampsList = makeTimestamps(timeList);
    dictList = makeDictList(timestampsList, whatTrack, timeList);
    return dictList;

def playRhythm(listToPlay):
    """Runs time and plays sample on timestamps"""
    print("LISTTOPLAY LENGTH : ", len(listToPlay))
    playList = [];
    #Filling list
    for i in range(len(listToPlay)):
        playList.append(listToPlay[i]);
    #Index of sample to be played
    thisSample = 0
    nextSample = playList[0];
    timeStart = time.time();
    #While-loop plays samples on timestamps
    while True:
        now = time.time();
        if now >= nextSample["timestamp"] + timeStart:
            #Make note duration from dictionary max sample playtime
            noteDur = int(1000 * durValueInDict(nextSample));
            # print("Index before playing: ", thisSample);
            nextSample["sample"].play(maxtime=noteDur);
            #loop list by resetting index and starting time
            if thisSample + 1 >= len(listToPlay):
                thisSample = -1;
                timeStart = time.time() + durValueInDict(nextSample);
            thisSample += 1;
            nextSample = playList[thisSample];

#####  USER INPUT

# Asking BPM
correctInput = False;
while correctInput == False:
    userBpm = input("Please enter a bpm. Say nothing for 120. : ");
    if not userBpm:
        # bpm = 120
        correctInput = True;
    else:
        try:
            bpm = float(userBpm);
            correctInput = True;
        except:
            print("Incorrect, enter a number I can work with please!");
print("Good job, bpm is ", bpm, ".");

#Asking noteAmount
correctInput = False;
while correctInput == False:
    userNoteAmount = input("What amount of notes would you like? : ");
    try:
        noteAmount = float(userNoteAmount);
        correctInput = True;
    except:
            print("Not correct, enter a number I can work with please!");
print("Well done, there are now ", userNoteAmount, " notes in one bar.");

#Asking Quarters or 8ths
correctInput = False;
while correctInput == False:
    userQuarterOrEight = input("Is the time signature in Quarters or Eights? (Type 4 or 8) : ");
    try:
        quarterOrEight = float(userQuarterOrEight);
        if quarterOrEight == 4 or quarterOrEight == 8:
            correctInput = True;
        else: print("No, please enter 4 or 8!");
    except:
            print("No, please enter the number 4 or 8!");
print("Perfect, your time signature is ", int(noteAmount), "/", userQuarterOrEight, " .");

#Defining Options (testing with bpm and quarter/8ths)
OptionsLow = [2, 3, 4];
OptionsMid = [2, 3, 4];
OptionsHigh = [1, 2, 3];

#From Options to List containing all note dictionaries
dictListLow = OptionsToDictList(OptionsLow, sampleLow);
dictListMid = OptionsToDictList(OptionsMid, sampleMid);
dictListHigh = OptionsToDictList(OptionsHigh, sampleHigh);
dictListTotal = combineDictLists(dictListLow, dictListMid, dictListHigh);
choppedDictListTotal = chopOneNote(dictListTotal, 5, 0.05);

#Print
print("+--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---+");
print("|                         TOTAL DICTIONARY LIST                         |");
print("+--- --- --- --- --- --- --- --- --*:*-- --- --- --- --- --- --- --- ---+");
for dict in range(len(choppedDictListTotal)):
    print(choppedDictListTotal[dict]);

#Play
playRhythm(choppedDictListTotal);
