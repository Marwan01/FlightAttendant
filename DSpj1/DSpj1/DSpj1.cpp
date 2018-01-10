//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  DSpj1.cpp           ASSIGNMENT #:  1             Grade: _________           *
//*                                                                                                   *
//*   PROGRAM AUTHOR:     __________________________________________                                  *
//*                                     Marouen Helali                                                *
//*                                                                                                   *
//*   COURSE #:  CSC 36000 11                              DUE DATE:  January 23, 2018                *
//*                                                                                                   *
//*****************************************************************************************************

//***************************************Program Description*******************************************
//*                                                                                                   *
//*    Process: This program takes input data regarding passangers boarding number, flight number     *
//*             class, and seat positioning. It then prints out the seating chart for the respective  *
//*             flights and their respective waiting list.                                            *
//*                                                                                                   *
//*    User defined Modules:                                                                          *
//*	    ReadIn -- reads in the passanger information                             		              *
//*         fill -- fills in the seats with -999                                       	              *
//*         convertSeat -- converts the column into an index                                          *
//*         convertAirplane -- converts flight number into an index                                   *
//*         getTrip -- figures out the cities of destination and arrival                              *
//*	        SortTheDudes -- sort the array by last name						                          *
//*         Header -- print the head of the output                                                    *
//*         Footer -- print the footer of the output                                                  *
//*****************************************************************************************************

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//function prototypes
void Header(ofstream&);
void Footer(ofstream&);
int main()
{
	ifstream infile("data1.txt", ios::in);
	ofstream Outfile("output1.txt", ios::out);
	Header(Outfile);
    return 0;
}

//************************** FUNCTION HEADER *************************
void Header(ofstream &Outfile)
{
	// Receives - the output file
	// Task - Prints the output preamble
	// Returns - Nothing
	Outfile << setw(30) << "Marouen Helali";
	Outfile << setw(17) << "CSC 36000";
	Outfile << setw(15) << "Section 11" << endl;
	Outfile << setw(30) << "Spring 2018";
	Outfile << setw(20) << "Assignment #1" << endl;
	Outfile << setw(35) << "-----------------------------------";
	Outfile << setw(35) << "-----------------------------------\n\n";

	return;
}
//*********************** END OF FUNCTION HEADER *********************

//************************** FUNCTION FOOTER *************************
void Footer(ofstream &Outfile)
{
	// Receives - the output file
	// Task - Prints the output salutation
	// Returns - Nothing
	Outfile << endl;
	Outfile << setw(35) << " --------------------------------- "
		<< endl;
	Outfile << setw(35) << "|      END OF PROGRAM OUTPUT      |"
		<< endl;
	Outfile << setw(35) << " --------------------------------- "
		<< endl;

	return;
}
//*********************** END OF FUNCTION FOOTER *********************
