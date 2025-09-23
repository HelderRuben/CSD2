##### VARIABLES #####
# Amount of 16th notes in bar
totalTime = 14;
# arrays with possible note-lengths
lenOptionsLow = [];
lenOptionsMid = [];
lenOptionsHigh = [];
# Lists with stored note-lengths
noteListLow = [];
noteListMid = [];
noteListHigh = [];

def generateRhythm(chopFactor):
    #Reset values
    global noteListLow = [];
    global noteListMid = [];
    global noteListHigh = [];
    #Fill with notes
    global noteListLow = generateNotes(lenOptionsLow);
    global noteListMid = generateNotes(lenOptionsMid);
    global noteListHigh = generateNotes(lenOptionsHigh);

    chopNotes(chopFactor);

#Function for filling noteArrays with the possible options

# DIT IN PYTHON SYNTAX SCHRIJVEN
def generateNotes(Options):
    noteArray = [];
    for i in range(totalTime):
        #Fill array with note-lengths
        noteArray.append = Options[random(Options.len)];
        #Stop filling array if totalTime has been reached
        if noteArray.sum >= totalTime:
            i = totalTime;
            #Capping last note so noteArray doesn't overflow
            noteArray[-1] -= (noteArray.sum - totalTime);
    return noteArray;

#Function for chopping notes-randomisation based on Chopfactor
def chopNotes(chopFactor):
