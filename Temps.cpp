#include<vector>
#include<string>
#include "Temps.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
// to use current time, disable warning 4996
#pragma warning(disable : 4996)

using namespace std;

// setters
void Temps::SetTemps(std::vector<string> tempsInput){   

    tempsInput = tempsInput;
}

void Temps::SetCity(std::vector<string> cityInput) {
    
    cityInput = cityInput;
}

// getters
std::vector<string> Temps::GetTemps(){    return tempsInput;}

std::vector<string> Temps::GetCity(){  return cityInput;}

// convert temperature function
float Temps::ConvertCelsius(float tempc)
{  
    return (tempc - 32) * .55555555555555555555555555;
}

// function to print file contents to the console
void Temps::PrintFileContents(std::vector<string> cityInput, std::vector<string> tempsInput)
{

    cout << "=============================\n";
    cout << "    Input File Contents:    \n";
    cout << "=============================\n";

    for (int index = 0; index < cityInput.size(); index++)
    {
        cout << cityInput.at(index) << ": " << tempsInput.at(index) << endl;
    }

    cout << "=============================\n";
}

// function to write a file with converted temperatures as a text file. 
void Temps::WriteFile(std::vector<string> cityInput, std::vector<string> tempsInput)
{

    //convert string vector to int vector
    std::vector<int> floatTemp;

    std::transform(tempsInput.begin(), tempsInput.end(), std::back_inserter(floatTemp), 
        [&](std::string s) {return stoi(s); });

    // convert int vector to float vector for celsius conversion in floating point
    std::vector<float> floatTemp2(floatTemp.begin(), floatTemp.end());

    ofstream outStream;

    outStream.open("CelsiusTemperature.txt");

    //print out the converted temperature values
    cout << endl;
    cout << "=============================\n";
    cout << "   Temperatures Converted:   \n";
    cout << "=============================\n";


    // loop writes file, looping through length of cityInput vector, each name is printed then a
    // converted temperature is printed after passing through celsius conversion function.
    for (int index = 0; index < cityInput.size(); index++)
    {
        float celsius = floatTemp2.at(index);
        // print to console
        cout << cityInput.at(index) << ": " << tempsInput.at(index) << "F = " << setprecision(4) 
            << ConvertCelsius(celsius) << "C" << endl;
       
        // write to file
        outStream << cityInput.at(index) << ": " << fixed << setprecision(2) << 
            ConvertCelsius(celsius) << endl;
    }
    cout << "=============================\n";

    time_t now = time(0);
    char* date_time = ctime(&now);

    // print timestamp to file print file and print confirmation message to console if file was written successfully.
    if (!outStream.fail())
    {
        cout << "\n** Writing to text file complete. \nText file can be found in project folder.";

        outStream << "\n*File completed:  " << date_time << endl;
    }

    outStream.close();
}
