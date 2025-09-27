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
# arrays with possible note-lengths
lenOptionsLow = [];
lenOptionsMid = [];
lenOptionsHigh = [];

##### FUNCTION SCRIPTS

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
    #append note plek in array
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
    step = listToPlay.pop(0);
    #for-loop cycles through one sequence
    for i in range(int(totalTime)):
        #test for current step
        print("Current step: ", i);
        if(i +1 == step):
            #sample plays if the time reaches the i value
            sampleToPlay.play();
            # Next step
            step += listToPlay.pop(0);
        #testing the sequence with a step-value of 1
        time.sleep(1);

#test
lenOptionsLow = [2, 3, 4];
lenOptionsMid = [3, 4, 5, 6];
lenOptionsHigh = [1, 2, 3, 4, 6];

generateRhythm(lenOptionsLow, lenOptionsMid, lenOptionsHigh, 50);

playNotes(noteListLow, sampleLow);
