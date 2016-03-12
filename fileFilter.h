/*
filter.h
Created by Rosa Tung on 1.19.16
Last Modified by Group: 1.31.16
*/

#ifndef FILEFILTER_H
#define FILEFILTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

#include "point.h"

int openFile(ifstream& readFile, string fileName); //opens file 
void extractLines(ifstream& readFile, string fileName, vector<string> &myArrays); //extracts lines as strings
void extractInts(vector<string> &myArrays, int row, vector<int> &paArray); //converts string to integers
void outputFile(vector <Point>&points, int tourDistance, ofstream& writeFile); //writes final tour to file

#endif // FILEFILTER_H_INCLUDED