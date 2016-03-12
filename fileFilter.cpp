#include "fileFilter.h"

int openFile(ifstream& readFile, string fileName) {
	//opens file, puts .txt at the end of it
	readFile.open((fileName + ".txt").c_str());

	if (!readFile) {
		cout << fileName << ".txt could not be opened." << endl;
		cout << " " << endl;
		return 1;
	}
	else {
		cout << fileName << ".txt read!" << endl;

		return 0;
	}
}

void extractLines(ifstream& readFile, string fileName, vector<string> &myArrays) {
	//opens file
	openFile(readFile, fileName);

	string line;

	//don't know length of a line or how many lines before i start to parse it, so use a vector
	while (getline(readFile, line)) {
		if (line.size() != 0)
		{
			myArrays.push_back(line);
		}
	}

	readFile.close();
}

void extractInts(vector<string> &myArrays, int row, vector<int> &paArray) {//also can check if character is numeric
	string line = myArrays[row]; //store current string we're looking at into line
	
	string number; //string version of cityID or X or Y value
	int num; //number version of cityID or X or Y value
	int counter = 0; //1 cityID 2 X 3 Y

	for (int place = 0; place<=line.size(); place++) //go throuhg row
	{
		if(line[place] == ' ' || place == line.size()) { //if we hit a space or the end of the line
			if(number.size() > 0) //if there's something to convert
			{
				num = atoi(number.c_str()); //convert our string into a number
				paArray.push_back(num); //push into our integer vector
				if(counter == 3){ //reset counter, might not really need
					counter = 0;
				}
				else{
					counter++; //move counter up
				}
				number.clear(); //make room for next "number"
			}
		}
		else{ 
			number.push_back(line[place]); //keep pushing back characters
		}
	}
}

void outputFile(vector <Point>&points, int tourDistance, ofstream& writeFile) {
	cout << "outputting" << endl;
	writeFile << tourDistance << endl; //tourdistance double checked at this point
	for (unsigned int place = 0; place < points.size(); place++) 
	{	//get cityID from our point objects
		writeFile << points[place].getCityID() << endl;
	}
}
