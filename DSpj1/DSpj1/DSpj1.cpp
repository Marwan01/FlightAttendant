//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  DSpj1.cpp           ASSIGNMENT #:  1             Grade: _________           *
//*                                                                                                   *
//*   PROGRAM AUTHOR:     __________________________________________                                  *
//*                                     Marouen Helali                                                *
//*                                                                                                   *
//*   COURSE #:  CSC 36000 11                              DUE DATE:  January 26, 2018                *
//*                                                                                                   *
//*****************************************************************************************************

//***************************************Program Description*******************************************
//*                                                                                                   *
//*    Process: This program takes input data regarding passangers boarding number, flight number     *
//*             class, and seat positioning. It then prints out the seating chart for the respective  *
//*             flights and their respective waiting list.                                            *
//*                                                                                                   *
//*    User defined Modules:                                                                          *
//*	        ReadIn -- reads in the passenger information                             		              *
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
void Read(ifstream&, passengerType);
void Rules(passengerType);

//global variables
int seats[10][3];
struct passengerType { //structure to keep all the information for every single passenger
	int boardingNum;
	int flightNum;
	char section;
	int row;
	int column;
} database[1000]; //create an array of structs to hold passengers' information
int numPassengers; //variable to keep count of the number of passengers


int main()
{
	ifstream infile("data1.txt", ios::in);
	ofstream Outfile("output1.txt", ios::out);
	Header(Outfile);
	Footer(Outfile);

	infile.close(); //close file after use
    return 0;
}

//************************** FUNCTION HEADER *************************
void Header(ofstream &Outfile)
{
	// Receives - the output file
	// Task - Prints the output preamble
	// Task - initializes the global array to appropriate values
	// Returns - Nothing
	Outfile << setw(30) << "Marouen Helali";
	Outfile << setw(17) << "CSC 36000";
	Outfile << setw(15) << "Section 11" << endl;
	Outfile << setw(30) << "Spring 2018";
	Outfile << setw(20) << "Assignment #1" << endl;
	Outfile << setw(35) << "-----------------------------------";
	Outfile << setw(35) << "-----------------------------------\n\n";
	//initialize all values of the array to -999 (empty)
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			seats[i][j] = -999;
	//initialize the number of passengers counter variable to 0
	numPassengers = 0;

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

//************************** FUNCTION READ ***************************
void Read(ifstream &infile, passengerType  database[1000])
{
	// Receives - the input file and the array of structures holding database of passengers
	// Task - process the reading from file and store everything properly in an array of structures
	// Returns - Nothing
	infile.open("data1.txt"); //open file to be used
	int sentinelTrack; //temporary value to track the sentinel value
	// Read the numbers from the file into the array.
	while ((infile >> sentinelTrack) && (sentinelTrack > 0)) {
		database[numPassengers].boardingNum = sentinelTrack;
		infile >> database[numPassengers].flightNum;
		infile >> database[numPassengers].section;
		infile >> database[numPassengers].row;
		infile >> database[numPassengers].column;
		numPassengers++;
	}
}
//*********************** END OF FUNCTION READ ***********************

//************************** FUNCTION RULES **************************
void Rules(passengerType passenger)
{
	if (seats[passenger.row][passenger.column] == -999)
	{
		seats[passenger.row][passenger.column] = passenger.boardingNum;
	}
	else if (seats[passenger.row][passenger.column] != -999)
	{
		if (seats[passenger.row][0] == -999)
		{
			seats[passenger.row][passenger.column] = passenger.boardingNum;
		}
		else if (seats[passenger.row][1] == -999)
		{
			seats[passenger.row][passenger.column] = passenger.boardingNum;
		}
		else if (seats[passenger.row][2] == -999)
		{
			seats[passenger.row][passenger.column] = passenger.boardingNum;
		}
		else
		{
			if (passenger.section == 'F')
			{
				for (int i = 0; i < 3; i++)
				{
					if (seats[i][passenger.column] == -999)
					{
						seats[i][passenger.column] = passenger.boardingNum;
						break;
					}
					else
					{
						for (int i = 0; i < 3; i++)
							for (int j = 0; j < 3; j++)
								if (seats[i][j] == -999)
								{
									seats[i][j] = passenger.boardingNum;
									i = j = 1000; break;
								}
					}
				}
			}
			else
			{
				for (int i = 3; i < 10; i++)
				{
					if (seats[i][passenger.column] == -999)
					{
						seats[i][passenger.column] = passenger.boardingNum;
						break;
					}
					else
					{
						for (int i = 3; i < 10; i++)
							for (int j = 0; j < 3; j++)
								if (seats[i][j] == -999)
								{
									seats[i][j] = passenger.boardingNum;
									i = j = 1000; break;
								}
					}
				}
			}
		}
	}
	else
	{
		//add to waitlist
	}
}
//********************** END OF FUNCTION RULES ***********************
