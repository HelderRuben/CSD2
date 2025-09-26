// PSEUDO TEXT RHYTHM ALGORHYTHM DESIGN
// CSD 8 SEP 2025
// RUBEN HELDER

Time Signature: 7/8

let TotalTime = 14;
// A value of 1 gives a sixteenth note
let LengthOptionsLow = ["opties van lengtes van laag gedeelte"];
let LengthOptionsMid = ["opties van lengtes van mid gedeelte"];
let LengthOptionsHigh = ["opties van lengtes van hoog gedeelte"];
// 16th, 8th, dotted 8th, quarter, dotted quarter, half
let NoteListLow = [];
let NoteListMid = [];
let NoteListHigh = [];
// Eventual output of algorhythm: List full of note-lengths
let NoteListTotalLow;
let NoteListTotalMid;
let NoteListTotalHigh;
// All note values added up.

//Basic function to complete entire algorhythm
function generateRhythm(chopFactor) {
	//Resetting values
	NoteListLow = [];
	NoteListMid = [];
	NoteListHigh = [];

	NoteListLow = generateNotes(LengthOptionsLow);
	NoteListMid = generateNotes(LengthOptionsMid);
	NoteListHigh = generateNotes(LengthOptionsHigh);

	chopNotes("getal tussen 1 en 100")
}

//Function to fill array with note-length-values
function generateNotes(Options) {
	let noteArrayTotal;
	for (let i = 0; i < TotalTime; i++) {
		let noteArray = [];
		noteArray.append = random optie uit Options;

		//Check if TotalTime has been reached
		if (noteArray.sum >= TotalTime) {
			//Finish algorhythm
			i = TotalTime;
			//Capping last note
			noteArray[last] -= ("Waarde die over is");
		}
	}
	return noteArray;
}

//Function to chop random notes in pieces
function chopNotes(chopFactor) {
	Selectie van random notes uit de 3 tracks 
	-> hoeveelheid van deze selecie op basis van chopFactor

	Die notes choppen
	-> chop-interval op basis van chopFactor
}
//  OUTPUT ALGORHYTHM
//  	List of Note-Length-Values dividing the Total time of 1 time signature bar
//  	into random notes based on the note-choices available




















































