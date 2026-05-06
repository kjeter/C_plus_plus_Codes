

#include <iostream>
using namespace std;

/*
 * InflationRate - calculates the inflation rate given the old and new consumer price index
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently 
 * @returns the computed inflation rate or 0 if inputs are invalid.
 */
double InflationRate(float old_cpi, float new_cpi);
void getCPIValues(float &old_cpi, float &new_cpi);
void swap_values(double &a, double &b);
void sort_array(double array [], int size);
double findMedianRate(double array [], int size);
const int MAX_RATES = 20;
int main()   //C++ programs start by executing the function main
{
   
        float oldCp, newCp; 
        double inflatRate, avgInfRate, rates[MAX_RATES];
        char ans;
        int num = 0;
        int index = 0, count = 0;
    
  
   do{
        getCPIValues(oldCp, newCp);
        cout<<endl;
  
        inflatRate = InflationRate(oldCp, newCp);
        
        avgInfRate += inflatRate;
    
        
        if(inflatRate != 0){
            num++;
            rates[index] = inflatRate;
            count++;
            if(index < 19){
                index++;
            }
        }
  
    cout<< "Inflation rate is " <<inflatRate<<endl;
    //cout<< " " << rates[index]<<endl;
    if(count < 20){
        cout<<"Try again? (y or Y): ";
        cin>>ans;
    }
    else {
        ans = 'n';
    }
   }while(ans == 'y' || ans == 'Y');
   /*cout << index<<endl;

   for( int val : rates){
       cout<< " " << val;
   }  */
   //cout<<endl;
    cout<<"Average rate is "<< avgInfRate / num <<endl;
    cout<<"Median rate is "<< findMedianRate(rates, count)<< endl;
  /*  
    for( int val : rates){
       cout<< " " << val;
   }
   cout<<endl; */
    
   
   return 0;
}

void getCPIValues(float &old_cpi, float &new_cpi){
    do{
    cout<<"Enter the old and new consumer price indices: ";
        cin>> old_cpi;
        cin >> new_cpi;
       if(old_cpi <= 0 || new_cpi <= 0){
           cout<<"Error: CPI values must be greater than 0 "<<endl;
       }
       
    }while(old_cpi <= 0 || new_cpi <= 0);
}

void swap_values(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}
void sort_array(double array [], int size){
    bool did1swap;
    do{
        did1swap = false;
      for(int i = 0; i < size - 1; i++){
        if(array[i] > array[i + 1]){
            swap_values(array[i], array[i+1]);
            did1swap = true;
        }
    }  
    }while(did1swap == true);
    
}
// double InflationRate(float old_cpi, float new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or 0 for invalid inputs

double InflationRate(float old_cpi, float new_cpi)
{
   
    double rate;
    if(old_cpi <= 0 || new_cpi <= 0 ){
        return 0;
    }
    rate = (new_cpi - old_cpi) / old_cpi * 100;
    return rate;
}

double findMedianRate(double array [], int size){
    int index;
    double median;
    sort_array(array, size);
    if(size % 2 == 1){
        index = size/ 2;
         median = array[index];
    }else if(size % 2 == 0 && size != 2){
        index = size / 2 - 1;
        median = (array[index] - array[index - 1])/ 2;
    }else if(size % 2 == 0 && size == 2){
        median = (array[0] + array[1]) / 2;
    }
    
    return median;
} 


