##### VARIABLES #####
# Amount of 16th notes in bar
totalTime = 14
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


#Function for filling noteArrays with the possible options
def generateNotes(Options):

#Function for chopping notes-randomisation based on Chopfactor
def chopNotes(chopFactor):
