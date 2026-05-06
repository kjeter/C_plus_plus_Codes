//This program calculates the inflation rate given two Consumer Price Index values and prints it to the monitor.

#include <iostream>
using namespace std;

/*
 * InflationRate - calculates the inflation rate given the old and new consumer price index
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently 
 * @returns the computed inflation rate or 0 if inputs are invalid.
 */
double InflationRate(float old_cpi, float new_cpi);

int main()   //C++ programs start by executing the function main
{
   // TODO #1: declare two float variables for the old consumer price index (cpi) and the new cpi
        float oldCp, newCp; 
        double inflatRate;
    
   // TODO #2: Read in two float values for the cpi and store them in the variables
        cout<<"Enter the old and new consumer price indices: ";
        cin>> oldCp;
        cin >> newCp;
        cout<<endl;
   // TODO #3: call the function InflationRate with the two cpis
    inflatRate = InflationRate(oldCp, newCp);

   // TODO #4: print the results
    cout<< "Inflation rate is " <<inflatRate << endl;

   return 0;
}


// double InflationRate(float old_cpi, float new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or 0 for invalid inputs
double InflationRate(float old_cpi, float new_cpi)
{
   // TODO: Implement InflationRate to calculate the percentage increase or decrease
   // Use (new_cpi - old_cpi) / old_cpi * 100
    double rate;
    if(old_cpi <= 0 || new_cpi <= 0 ){
        return 0;
    }
    rate = (new_cpi - old_cpi) / old_cpi * 100;
    return rate;
}
