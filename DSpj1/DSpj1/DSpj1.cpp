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

//global variables
int seats[10][3];
struct passengerType {
	int boardingNum;
	int flightNum;
	char section;
	int row;
	int column;
};

int main()
{
	ifstream infile("data1.txt", ios::in);
	ofstream Outfile("output1.txt", ios::out);
	Header(Outfile);
	Footer(Outfile);
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
