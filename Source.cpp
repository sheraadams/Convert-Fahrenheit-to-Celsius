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


// to use current time, disable warning 4996
#pragma warning(disable : 4996).

using namespace std;

// Function converts fahrenheit to celsius
float convertCelsius(float tempc)
{
    return (tempc - 32) * .55555555555555555555555555;
}


// apapted file reading process from : https://www.youtube.com/watch?v=x1-3CmFNbso
int main() 
{

    system("COLOR 01");

    //initialize variables
    vector<string>  names;
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

    //convert string vector to int vector
    std::vector<int> floatTemp;

    std::transform(temps.begin(), temps.end(), std::back_inserter(floatTemp), [&](std::string s) {return stoi(s); });

    // convert int vector to float vector for celsius conversion in floating point
    std::vector<float> floatTemp2(floatTemp.begin(), floatTemp.end());

    //Print out file contents:
    cout << "=============================\n";
    cout << "    Input File Contents:    \n";
    cout << "=============================\n";

    for (index = 0; index < names.size(); index++) 
    {
        cout << names.at(index) << ": " << temps.at(index) << endl;
    }

    cout << "=============================\n";

    system("Color 03");

    //Write the file and specify the outfile name.
    ofstream outStream;
    outStream.open("CelsiusTemperature.txt");

    //print out the converted temperature values
    cout << endl;
    cout << "=============================\n";
    cout << "   Temperatures Converted:   \n";
    cout << "=============================\n";

  
    // loop writes file, looping through length of names vector, each name is printed then a
    // converted temperature is printed after passing through celsius conversion function.
    for (index = 0; index < names.size(); index++) 
    {
        float celsius = floatTemp2.at(index);

        cout << names.at(index) << ": " << temps.at(index) << "F = " << setprecision(4) << convertCelsius(celsius) << "C" << endl;
        outStream << names.at(index) << ": " << fixed << setprecision(2) << convertCelsius(celsius) << endl;
    }
    cout << "=============================\n";

    system("Color 5");

    time_t now = time(0);
    char* date_time = ctime(&now);
  
    
    // print timestamp to file if file was written successfully.
    //print file location to console if file was written successfully.
    if (!outStream.fail()) 
    {
        cout << "\n** Writing to text file complete. \nText file can be found in project folder 'cmake-build-debug'.";

        outStream << "\n*File completed:  " << date_time << endl;
    }

    outStream.close();


    //print to console the location where the text file can be found.
}

// if you choose to print to console to show the contents of the vectors:
/*
    for (string i: temps)
        std::cout << i << " (temps) "<<' ';
    for (string i: names)
        std::cout << i << " (name) "<< ' ';
    for (int i: floatTemp)
        std::cout << i << " (float) "<<' ';
    for (double i: floatTemp2)
        std::cout << i << " (float2) "<<' ';


    // conversion without function
     for (index=0; index < names.size(); index++) {
        float m = ((floatTemp2.at(index)) -32) * (.5555555555555555555);
        outStream << names.at(index) << ": "<< m << endl;
    }

     // print out name vector
    cout << "Names read: \n";
    for (auto &i: names){
        std::cout << i << '\n';
    }

    //print out temp vector
    cout << "Temperatures read: \n";
    for (auto &i: floatTemp){
        std::cout << i << ' ' << endl;
        }

 */

