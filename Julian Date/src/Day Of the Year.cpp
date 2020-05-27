//============================================================================
// Name        : Day.cpp
// Author      : Nick House
// Description : input Month, Day and Year, return julian date
//============================================================================

#include <iostream>
#include <cctype>           //Required for tolower
#include <algorithm>        //Required for transform
#include <stdlib.h>

using namespace std;


    string monthName[12] = {"january", "february", "march", "april" , "may", "june", "july", "august", "september", "october", "november", "december"};
    int monthLength[12] = {31, 28 , 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int julianDate[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    int date(string, int, int);              //Function to give day number of year
    int validation(string, int, int);   //Validation Function
    void leapyear(int);     //Calculate Leap Year

int main()
{

    string month;
    int day, year;

    cout << "*** Get Julian Date for input Date ***\n";
    cout << "Enter a Month, day and year - (Ex: July 4 1776): ";


    cin >> month >> day >> year;

    transform(month.begin(), month.end(), month.begin(), ::tolower);        //Make user input Lowercase

    int val = validation(month, day, year);


    while(val != 1)
    {
        cin.clear ();
        cin.ignore ( 100 , '\n' );

        cout << "You have entered an inccorect date, please try again. (Format Ex \"July 4 1776\")\n";
        cin >> month >> day >> year;
        transform(month.begin(), month.end(), month.begin(), ::tolower);
        val = validation(month, day, year);
    }


    cout << "\nThe Julian Date is: " << date(month, day, year);


    return 0;
}


//Take User input and return Julian
int date(string month, int day, int year)
{
    int julian;
    int format = year * 1000;


    for(int i = 0; i < 12; i++)
    {
        if(monthName[i] == month)
        {
            julian = (julianDate[i]+day);
        }
    }

   julian = format + julian;

    return julian;
}


//Validate User Input for proper month day and year
int validation(string month, int day, int year)
{
    int val = 0;

    if(year > 0 )
    {
        leapyear(year);

        for(int i = 0; i < 12; i++)
        {
            if(monthName[i] == month)
            {

                if(day > 0 && day <= monthLength[i])
                {
                    val = 1;
                }
            }
        }
    }

    return val;
}


//Check and Adjust for Leap Year
void leapyear(int year)
{

    if( year % 4 == 0 )
    {
        if( year % 100 == 0 && year % 400 != 0 )
        {
            exit(0); //Not a Leap Year
        }

        //Conditions Met for leap year, adjust arrays
        monthLength[1] = 29;

        for(int i = 2 ; i < 13 ; i++)
        {
            julianDate[i] += 1;
        }
    }
}

