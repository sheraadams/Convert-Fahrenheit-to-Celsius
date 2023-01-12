/*
 * Shera Adams
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include "Temps.h"


using namespace std;

// Function converts fahrenheit to celsius
float convertCelsius(float tempc)
{
    return (tempc - 32) * .55555555555555555555555555;
}


// apapted file reading process from : https://www.youtube.com/watch?v=x1-3CmFNbso
int main()
{
    Temps TempsObj;

    system("COLOR 0A");

    //initialize variables
    vector<string> names;
    vector<string> temps;

    int index;

    //read in the file
    ifstream inStream;

    inStream.open("FahrenheitTemperature.txt"); // declare file to open

    //Error reading file will print message to console
    if (!inStream.is_open())
    {
        cout << "Could not open file called";
    }

    // Successful reading of file process
    else
    {
        // initialize variables
        string name;
        string temp;

        //tell stream the order of variables to read in from the file
        inStream >> name >> temp;

        // add variables to the vectors, both vectors are read in as string
        while (!inStream.fail())
        {
            names.push_back(name);
            temps.push_back(temp);
            //tell stream the order of variables to read
            inStream >> name >> temp;
        }
    }

    //close the file reading stream when finished
    inStream.close();
    cout << endl;

    TempsObj.SetTemps(temps);
    TempsObj.SetCity(names);
   
    TempsObj.PrintFileContents(names, temps);
    TempsObj.WriteFile(names, temps);


}


