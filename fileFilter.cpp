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
	string line = myArrays[row];
	
	string number;
	int num;
	int counter = 0; 

	for (int place = 0; place<=line.size(); place++)
	{
		if(line[place] == ' ' || place == line.size()) {
			if(number.size() > 0)
			{
				num = atoi(number.c_str());
				paArray.push_back(num);
				if(counter == 3){
					counter = 0;
				}
				else{
					counter++;
				}
				number.clear();
			}
		}
		else{
			number.push_back(line[place]); //keep pushing back characters
		}
	}
}

void outputFile(vector <Point>&points, int tourDistance, ofstream& writeFile) {
	cout << "outputting" << endl;
	writeFile << tourDistance << endl;
	for (unsigned int place = 0; place < points.size(); place++) 
	{
		writeFile << points[place].getCityID() << endl;
	}
}
