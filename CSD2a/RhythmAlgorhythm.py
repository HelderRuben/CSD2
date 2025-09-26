#Importing Modules
import random

# Amount of 16th notes in bar
totalTime = 14;
# arrays with possible note-lengths
lenOptionsLow = [];
lenOptionsMid = [];
lenOptionsHigh = [];

##### FUNCTION SCRIPTS

# General Script to set algorhythms in motion.
### Output is playable generated rhythm for 3 tracks.
def generateRhythm(OptionsLow, OptionsMid, OptionsHigh, chopFactor):
    # Lists with stored note-lengths
    global noteListLow
    noteListLow = [];
    global noteListMid
    noteListMid = [];
    global noteListHigh
    noteListHigh = [];
    #Fill with notes
    noteListLow = generateNotes(OptionsLow);
    noteListMid = generateNotes(OptionsMid);
    noteListHigh = generateNotes(OptionsHigh);

    chopNotes(chopFactor);

#Function for filling noteArrays with the possible options
def generateNotes(Options):
    noteArray = [];
    for i in range(totalTime):
        #Fill array with note-lengths
        optionLength = len(Options)
        randomOption = random.randrange(optionLength);
        noteArray.append(Options[randomOption]);
        #print(optionLength);
        #Stop filling array if totalTime has been reached
        #if noteArray.sum >= totalTime:
        #    i = totalTime;
            #Capping last note so noteArray doesn't overflow
        #    noteArray[-1] -= (noteArray.sum - totalTime);
    print(noteArray);
    return noteArray;

#Function for chopping notes-randomisation based on Chopfactor
##### DIT IN PYTHON SYNTAX SCHRIJVEN
def chopNotes(chopFactor):
    #To pick track to chop from
    trackArray = [noteListLow, noteListMid, noteListHigh];

    #gives a number from 1-10 for amount of notes chopped
    randomness = chopFactor / 10;
    #gives a range for how long the chopped notes will be
    chopIntensity = chopFactor / 3;

    #stappen uitgeschreven in PSEUDO-CODE
    for i in range(randomness):
        #Initialize array to chop note from
        whichTrack = random.randrange(3);
        trackToChop = trackArray[whichTrack];


#test
testList = [1, 2, 3];
generateNotes(testList);
