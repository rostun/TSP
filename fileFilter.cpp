#include "stdafx.h"

#include "fileFilter.h"
#include <iostream>

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
			cout << line << endl;
		}
	}

	readFile.close();
}

void extractInts(vector<string> &myArrays, int row, vector<int> &paArray, vector<int> &pXArray, vector<int> &pYArray) {//also can check if character is numeric
	string line = myArrays[row];
	
	string number;
	int num;
	int counter = 0; 

	for (int place = 0; place<=line.size(); place++)
	{
		if(line[place] == ' ' || place == line.size()) {
			num = atoi(number.c_str());
			if(counter == 0){ //its a city
				paArray.push_back(num); //push back city vector
			} 
			else if(counter == 1){ //its a X coordinate
				pXArray.push_back(num); //push back X vector
			}
			else if(counter == 2){
				num = atoi(number.c_str());
				pYArray.push_back(num); //push back Y vector
			}
			counter++;
			number.clear();
		}
		else{
			number.push_back(line[place]); //keep pushing back characters
		}
	}
}

void outputFile(vector<string> const &myArrays, int const row, vector<int> const &paArray, int const &leftIdx, int const &rightIdx, ofstream& writeFile) {
	writeFile << myArrays[row] << endl;
	writeFile << "[";													//cout << "outputting" << endl;
	for (int place = leftIdx; place<rightIdx + 1; place++) {
		if (place == rightIdx) {
			writeFile << paArray[place];
		}
		else {
			writeFile << paArray[place] << ", ";
		}
	}
	writeFile << "]" << endl;
}