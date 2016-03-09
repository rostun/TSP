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

int openFile(ifstream& readFile, string fileName);
void extractLines(ifstream& readFile, string fileName, vector<string> &myArrays);
void extractInts(vector<string> &myArrays, int row, vector<int> &paArray);
void outputFile(vector <Point>&points, int tourDistance, ofstream& writeFile);

#endif // FILEFILTER_H_INCLUDED