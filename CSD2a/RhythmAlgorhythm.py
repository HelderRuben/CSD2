#Importing Modules
import pygame;
import time;
import random;

pygame.init();

#Initiating samples from assets
sampleLow = pygame.mixer.Sound("../assets/kick.wav");
sampleMid = pygame.mixer.Sound("../assets/snare.wav");
sampleHigh = pygame.mixer.Sound("../assets/hihat.wav");

# Amount of notes in bar
noteAmount = 14;
quarterOrEight = 0;
bpm = 120;
stopLoop = 0;

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

def chopOneNote(listToChop, index, choptensity, changeGrainsize, chopLenMin, chopLenMax, normalOrGranulised):
    """Replaces 1 note duration w series of small durations and appends to dictionary list"""
    dictToChop = listToChop[index];
    chopsAmount = int(dictToChop["duration"] / choptensity);

    #Remove current index dictionary
    removedDict = listToChop.pop(index);

    #Insert chops as dictionaries
    for chop in range(chopsAmount):
        #If it's time to change grainsize, randomise choptensity again
        if chop % changeGrainsize == 0:
            choptensity = random.randint(int(chopLenMin), int(chopLenMax));

            #Implementing right conditions for granulator
            if chopFactor >= 80:
                choptensity = random.randint(150, 300);
            choptensity = choptensity * normalOrGranulised;
            print("changed grainSize, choptensity is now: ", choptensity);
        #Timestamp increases each chop
        newTimestamp = removedDict["timestamp"] + (chop * choptensity);
        listToChop.append(makeNoteDict(newTimestamp, removedDict["sample"], choptensity));
    # print("Chopped note at: ", removedDict["timestamp"], ", with duration", removedDict["duration"]);
    return listToChop;

def chopTracks(listToChop, chopFactor):
    """returns dictionary list including chopped notes according to chopFactor"""

    #Calculate amount of notes in final list
    totalNoteAmount = len(listToChop);

    #Calculate percentage of notes to be chopped
    amountOfChops = int(totalNoteAmount / (100/chopFactor));
    print("AMOUNT OF CHOPS IN LIST:::::: ", amountOfChops);

    #Testing with chop length range
    rangeWithinRangeFactor = 2.5;
    normalOrGranulised = 0.001;

    invertChopFactor = 100 - chopFactor;
    print("INVERT: ", invertChopFactor);
    chopLenMin = 100 + (int(invertChopFactor - 20) * rangeWithinRangeFactor);
    chopLenMax = chopLenMin + 15;
    #If chopFactor is high, granulise instead of chop (very small chops)
    if chopFactor >= 80:
        normalOrGranulised = 0.0001;
    #For bug-fixing
    else: print("RANGE OF CHOPS::: ", chopLenMin, " - ", chopLenMax);

    for chop in range(amountOfChops):
        #Randomise index, one less in randrange every chop
        chopIndex = random.randrange(0, totalNoteAmount - chop);
        print("CHOPINDEX == ", chopIndex);
        #Randomise length
        choptensity = random.randint(int(chopLenMin), int(chopLenMax));

        #Implementing right conditions for granulator
        if chopFactor >= 80:
            choptensity = random.randint(150, 300);

        #Make sure choptensitys are small floats and very small for granuliser
        choptensity = choptensity * normalOrGranulised;

        #Every so often within a note-length, the grainsize changes
        changeChoptensityInterval = int(0.5 / choptensity);
        print("Length of current chop::: ", choptensity, ", NOTE DURATION WAS: ", listToChop[chopIndex]["duration"], "And with TIME STAMP ", listToChop[chopIndex]["timestamp"]);
        #Change list by adding one chop
        listToChop = chopOneNote(listToChop, chopIndex, choptensity, changeChoptensityInterval, chopLenMin, chopLenMax, normalOrGranulised);
    #Sort giant dictionary list including chops
    listToChop.sort(key=tsValueInDict);
    return listToChop;

def OptionsToDictList(Options, whatTrack):
    """Returns list of note dictionaries according to options and track kind"""
    optionsWithinTimeSignature = optionsInTimeSignature(Options, quarterOrEight)
    noteList = makeDurList(optionsWithinTimeSignature);
    timeList = makeTimeList(noteList, bpm);
    timestampsList = makeTimestamps(timeList);
    dictList = makeDictList(timestampsList, whatTrack, timeList);
    return dictList;

def askChopFactor():
    """Sets chopFactor to correct user input"""
    correctInput = False;
    while correctInput == False:
        userChopFactor = input("From 0-99, How trippy do you want your rhythm to be? : ");
        try:
            chopFactor = float(userChopFactor);
            if chopFactor >= 0 and chopFactor <= 99:
                correctInput = True;
            else:
                print(" ");
                print("Don't try to be funny!, number between 0-99");
        except:
            print(" ");
            print("Come on, that's not a number!");
    print(" ");
    print("Great, your trippy-ness-factor is ", chopFactor, " .");
    return chopFactor;


def newBeatOrQuit():
    correctInput = False;
    while correctInput == False:
        userBeatAgain = input("Would you like to make a new beat? ('no' quits script) : ");
        try:
            beatAgain = str(userBeatAgain);
            if beatAgain == "yes":
                correctInput = True;
                beatInputParameters();
            elif beatAgain == "no":
                correctInput = True;
            else:
                print(" ");
                print("Just say yes or no.");
        except:
            print(" ");
            print("You're not even making sense, just say yes or no");

def oldBeatOrNewInput():
    correctInput = False;
    while correctInput == False:
        userChangeBeat = input("Do you want to change the trippy-ness of this beat? : ");
        try:
            changeBeat = str(userChangeBeat);
            if changeBeat == "yes":
                correctInput = True;
                chopFactor = askChopFactor();
                choppedDictListTotal = chopTracks(dictListTotal, chopFactor);
                playRhythm(choppedDictListTotal);
            elif changeBeat == "no":
                correctInput = True;
                newBeatOrQuit();
            else:
                print(" ");
                print("Just say yes or no.");
        except:
            print(" ");
            print("You're not even making sense, just say yes or no");

def playAgainOrNot():
    """Lets beat play again or make new beat based on user input"""
    correctInput = False;
    while correctInput == False:
        userPlayAgain = input("Nice beat! Do you want to play it again? : ");
        try:
            playAgain = str(userPlayAgain);
            if playAgain == "yes":
                correctInput = True;
                playRhythm(choppedDictListTotal);
            elif playAgain == "no":
                correctInput = True;
                oldBeatOrNewInput();
            else:
                print(" ");
                print("Just say yes or no.");
        except:
            print(" ");
            print("You're not even making sense, just say yes or no");

def playRhythm(listToPlay):
    """Runs time and plays sample on timestamps"""
    #Make sure loop can be started
    loopCount = 0;
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
            #Loop list by resetting index and starting time, stop loop if user says so
            if thisSample + 1 >= len(listToPlay) and loopCount < 4:

                thisSample = -1;
                timeStart = time.time() + durValueInDict(nextSample);
                loopCount += 1;
            if loopCount >= 4:
                playAgainOrNot();
                break;
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
            print(" ");
            print("Incorrect, enter a number I can work with please!");
print(" ");
print("Good job, bpm is ", bpm, ".");

#Asking noteAmount
correctInput = False;
while correctInput == False:
    userNoteAmount = input("What amount of notes would you like? : ");
    try:
        noteAmount = float(userNoteAmount);
        correctInput = True;
    except:
            print(" ");
            print("Not correct, enter a number I can work with please!");
print(" ");
print("Well done, there are now ", userNoteAmount, " notes in one bar.");

#Asking Quarters or 8ths
correctInput = False;
while correctInput == False:
    userQuarterOrEight = input("Is the time signature in Quarters or Eights? (Type 4 or 8) : ");
    try:
        quarterOrEight = float(userQuarterOrEight);
        if quarterOrEight == 4 or quarterOrEight == 8:
            correctInput = True;
        else:
            print(" ");
            print("No, please enter 4 or 8!");
    except:
        print(" ");
        print("No, please enter the number 4 or 8!");
print(" ");
print("Perfect, your time signature is ", int(noteAmount), "/", userQuarterOrEight, " .");

chopFactor = askChopFactor();

#Defining Options (testing with bpm and quarter/8ths)
OptionsLow = [2, 3, 4];
OptionsMid = [2, 3, 4];
OptionsHigh = [1, 2, 3];

#From Options to List containing all note dictionaries
####TESTING WITH ONLY HIHAT
dictListLow = OptionsToDictList(OptionsLow, sampleLow);
dictListMid = OptionsToDictList(OptionsMid, sampleMid);
dictListHigh = OptionsToDictList(OptionsHigh, sampleHigh);
# dictListTotal = OptionsToDictList(OptionsHigh, sampleMid);
dictListTotal = combineDictLists(dictListLow, dictListMid, dictListHigh);

#Testing with before and after chopping
print("+--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---+");
print("|                         TOTAL DICTIONARY LIST (not chopped)           |");
print("+--- --- --- --- --- --- --- --- --*:*-- --- --- --- --- --- --- --- ---+");
for dict in range(len(dictListTotal)):
    print(dictListTotal[dict]);

choppedDictListTotal = chopTracks(dictListTotal, chopFactor);

#Print after chopping
print("+--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---+");
print("|                         TOTAL DICTIONARY LIST (CHOPPED)               |");
print("+--- --- --- --- --- --- --- --- --*:*-- --- --- --- --- --- --- --- ---+");
for dict in range(len(choppedDictListTotal)):
    print(choppedDictListTotal[dict]);

#Play
playRhythm(choppedDictListTotal);
