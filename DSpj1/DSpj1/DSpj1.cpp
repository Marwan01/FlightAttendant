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

//necessary includes
#include "stdafx.h" //include for using last version of visual studio 
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


//global variables
struct passengerType { //structure to keep all the information for every single passenger
	int boardingNum;
	int flightNum;
	char section;
	int row;
	int column;
} database[1000]; //create an array of structs to hold passengers' information
int numPassengers; //variable to keep count of the number of passengers


struct FlightType {
	int flight;
	int seats[10][3];
	int waitListCount = 0;
	passengerType waitList[50];
} flights[8];

//input file and output file defined as global variables
ifstream infile("data1.txt", ios::in);
ofstream outfile("output1.txt", ios::out);

//function prototypes
void Header(ofstream&);
void Footer(ofstream&);
void Read(ifstream&);
void Rules(passengerType);
void FillSeats();
void Output(ofstream&);
void getTrip(int, string&, string&);


int main()
{	
	Header(outfile); //call for header function	
	Read(infile); //call for read function to read in data from file
	FillSeats(); //call for function to fill the seating chart according to the specified rules
	Output(outfile); //call for output function
	Footer(outfile); //call for footer function
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
	for(int k = 0 ; k < 8 ; k++)
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 3; j++)
				flights[k].seats[i][j] = -999;
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
void Read(ifstream &infile)
{
	
	// Receives - the input file
	// Task - process the reading from file and store everything properly in an array of structures
	// Returns - Nothing
	int sentinelTrack; //temporary value to track the sentinel value
	char c;
	// Read the numbers from the file into the array.
	//infile.open("data1.txt"); //open file to be used
	if (!(infile.good())) {
		cout << "data1.txt could not be accessed!" << endl;
	}
	infile >> sentinelTrack;
	//cin >> c;
	while (sentinelTrack > 0) {
		database[numPassengers].boardingNum = sentinelTrack;
		infile >> database[numPassengers].flightNum;
		infile >> ws;
		infile.get(database[numPassengers].section);
		infile >> database[numPassengers].row;
		infile >> ws;
		infile.get(c);
		if (c == 'L')
		{
			database[numPassengers].column = 0;
		}
		else if (c == 'M')
		{
			database[numPassengers].column = 1;
		}
		else
		{
			database[numPassengers].column = 2;
		}
		numPassengers++;
		infile >> sentinelTrack;
	}
}
//*********************** END OF FUNCTION READ ***********************

//************************** FUNCTION RULES **************************
void Rules(passengerType passenger)
{
	// Receives - a single passenger of type the structure passengerType
	// Task - varifies the rules and seats one passenger given as a parameter
	// Returns - Nothing
	int fn;
	switch (passenger.flightNum) {
	case 1010: fn = 0;  break;
	case 1015: fn = 1;  break;
	case 1020: fn = 2;  break;
	case 1025: fn = 3;  break;
	case 1030: fn = 4;  break;
	case 1035: fn = 5;  break;
	case 1040: fn = 6;  break;
	case 1045: fn = 7;  break;
	}
	flights[fn].flight = database[numPassengers].flightNum;
	cout << database[numPassengers].flightNum;
	cin >> fn;
	if (flights[fn].seats[passenger.row][passenger.column] == -999)
	{
		flights[fn].seats[passenger.row][passenger.column] = passenger.boardingNum;
	}
	else if (flights[fn].seats[passenger.row][passenger.column] != -999)
	{
		if (flights[fn].seats[passenger.row][0] == -999)
		{
			flights[fn].seats[passenger.row][passenger.column] = passenger.boardingNum;
		}
		else if (flights[fn].seats[passenger.row][1] == -999)
		{
			flights[fn].seats[passenger.row][passenger.column] = passenger.boardingNum;
		}
		else if (flights[fn].seats[passenger.row][2] == -999)
		{
			flights[fn].seats[passenger.row][passenger.column] = passenger.boardingNum;
		}
		else
		{
			if (passenger.section == 'F')
			{
				for (int i = 0; i < 3; i++)
				{
					if (flights[fn].seats[i][passenger.column] == -999)
					{
						flights[fn].seats[i][passenger.column] = passenger.boardingNum;
						break;
					}
					else
					{
						for (int i = 0; i < 3; i++)
							for (int j = 0; j < 3; j++)
								if (flights[fn].seats[i][j] == -999)
								{
									flights[fn].seats[i][j] = passenger.boardingNum;
									i = j = 1000; break;
								}
					}
				}
			}
			else
			{
				for (int i = 3; i < 10; i++)
				{
					if (flights[fn].seats[i][passenger.column] == -999)
					{
						flights[fn].seats[i][passenger.column] = passenger.boardingNum;
						break;
					}
					else
					{
						for (int i = 3; i < 10; i++)
							for (int j = 0; j < 3; j++)
								if (flights[fn].seats[i][j] == -999)
								{
									flights[fn].seats[i][j] = passenger.boardingNum;
									i = j = 1000; break;
								}
					}
				}
			}
		}
	}
	else
	{
		//add to waitlist and increment counter that keeps track of number of people in waitlist
		flights[fn].waitList[flights[fn].waitListCount++] = passenger;

	}
}
//********************** END OF FUNCTION RULES ***********************

//************************** FUNCTION FILL ***************************
void FillSeats()
{
	// Receives - Nothing
	// Task - verify the rules for every single passenger in the database that came from the file
	// Returns - Nothing
	int i;
	for (int i = 0; i < numPassengers; i++)
	{
		Rules(database[i]);
	}
	
}
//********************** END OF FUNCTION FILL ************************

//************************** FUNCTION OUTPUT *************************
void Output(ofstream & Outfile) {
	//recives: the outfile 
	//task: prints the seating chart for all planes
	//returns: nothing
	for (int i = 0; i < 8; i++)
	{
		string from;
		string to;
		int flightNumber = flights[i].flight;
		//print the flight information
		getTrip(flightNumber, from, to);
		//print the details for each of the flights based on in and out airports
		Outfile << right << setw(52) << "Southern Comfort Airlines" << endl << endl;
		Outfile << "Flight " << i;
		Outfile << setw(45) << "From: " << from << endl;
		Outfile << setw(54) << "To: " << to << endl;
		// print the boarding numbers as a seating  chart
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				Outfile << " " << flights[i].seats[k][j];
			}
			Outfile << endl;
		}
		//print waiting list header
		Outfile << "\n WAITING LIST" << endl << endl;
		//print boarding number in the list
		if (flights[i].waitListCount > 0)
		{
			for (int k = 0; k < flights[i].waitListCount; k++)
			{
				if (k % 10 == 0 && k != 0) Outfile << endl;
				Outfile << " " << flights[i].waitList[k].boardingNum;
			}
			Outfile << endl << endl;
		}
		else
			Outfile << " there is no waiting list for this flight." << endl << endl;
		Outfile << " end of the seating chart" << endl;
		Outfile << " _________________________";
		Outfile << "___________________________" << endl;
	}

}
//******************** END OF FUNCTION OUTPUT ************************

void getTrip(int flightNumber, string &from, string &to) {
	//recives:the flight number and two strings
	//task: converts the flight number into strings for the flight information
	//returns: a string with the city of departure and arrival
	if ((flightNumber % 2) == 0) {
		//assign default departure from JACKSON, MISSISSIPPI
		from = "Jackson, Mississippi";
		switch (flightNumber) {
		case 1010: to = "Memphis, Tannessee";
			break;
		case 1020: to = "Little Rock, Arkansas";
			break;
		case 1030: to = "Shreveport, Louisiana";
			break;
		case 1040: to = "Orlando, Florida";
			break;
		}
	}
	else {
		//assign default arrival from JACKSON, MISSISSIPPI
		to = "Jackson, Mississippi";
		switch (flightNumber) {
		case 1015: from = "Memphis, Tannessee";
			break;
		case 1025: from = "Little Rock, Arkansas";
			break;
		case 1035: from = "Shreveport, Louisiana";
			break;
		case 1045: from = "Orlando, Florida";
			break;
		}
	}
}