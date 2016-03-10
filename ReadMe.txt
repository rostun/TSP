========================================================================
    CONSOLE APPLICATION : TSP Project Overview
========================================================================

About

TSP is a group project by Rosa Tung, Sam Nelson and Kara Franco. This project implements solutions to the Traveling Salesman Problem with a greedy algorithm that utilizes an altered 2-OPT element. 

A user can input a testfile containing cities and coordinates into the program to find the solution of the tour distance and the city IDs traversed. The results can be found in a new file created in the directory named [yourTestFile].txt.tour

To Run
To run this project, place the following files into a directory along with the .txt file(s) that you wish to test the algorithm against.

TSP.cpp		yourTestFile.txt		makefile	
fileFilter.h		point.h				graph.h
fileFilter.cpp 		point.cpp			graph.cpp

Next, run the makefile to compile by entering “make” (without the quotes “ “) into the flip server. 

Then write “tsp” (without the quotes “ “) into the flip server.

Follow the instructions that the program gives you 
** be sure to enter the filename without the .txt extension **

Results can be found in the [yourTestFile].txt.tour found in the directory. 


Extra Files:

TSP.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

TSP.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named TSP.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
