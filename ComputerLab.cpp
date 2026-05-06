/*********************************************************************
 Lab3.cpp

   This program uses dynamic arrays to store login information for
four labs.  Each of the four labs is referenced by the labs[] array
which is indexed from 0-3.  A pointer in the labs[] array then
references a dynamic array that is of size for however many computers
are in that lab.

Written by: 
Last modified on:
Known bugs:
*********************************************************************/

#include <iostream>

using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes

/*
 Creates the dynamic arrays for the labs.
 @param labs: the array of labs,
 @param labsizes: contains the size (or number of computers) of each lab
  This dictates the size of the dynamic array.
 @precondition: labsize[0] is the # of computers in lab1,
                labsize[1] is the # of computers in lab2, ...
 @postcondition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/
void createArrays(IntPtr labs[], int labsizes[]);

/* 
freeArrays:
Releases memory we allocated with "new".
*/
void freeArrays(IntPtr labs[]);


/*
showLabs:
Displays the status of all labs (who is logged into which computer).
*/
void showLabs(IntPtr labs[], int labsizes[]);


// ======================
// login:
// Simulates a user login by asking for the login info from
// the console.
// ======================
void login(IntPtr labs[], int labsizes[]);


// ======================
// logout:
// Searches through the arrays for the input user ID and if found
// logs that user out.
// ======================
void logout(IntPtr labs[], int labsizes[]);


// ======================
// search:
// Searches through the arrays for the input user ID and if found
// outputs the station number.
// ======================
void search(IntPtr labs[], int labsizes[]);


// ======================
//     main function
// ======================
int main()
{
	IntPtr labs[NUMLABS]; 	// store the pointers to the dynamic array for each lab
	int labsizes[NUMLABS];	// Number of computers in each lab
	int choice = -1;
	
	cout <<"Welcome to the LabMonitorProgram!\n";

	// Prompt the user to enter labsizes 
	cout <<"Please enter the number of computer stations in each lab:\n"; 
	for (int i=0; i< NUMLABS; i++)
	{
		do
		{
			cout <<"How many computers in Lab "<< i+1<<"?";
			cin >> labsizes[i]; 
		} while (labsizes[i]<0); 
	}

	// Create ragged array structure
	createArrays(labs, labsizes);

	// Main Menu
	while (choice != 0)
	{
		cout << endl;
		cout << "MAIN MENU" << endl;
		cout << "0) Quit" << endl;
		cout << "1) Simulate login" << endl;
		cout << "2) Simulate logout" << endl;
		cout << "3) Search" << endl;
		cin >> choice;
		if (choice == 1)
		{
			login(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 2)
		{
			logout(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 3)
		{
			search(labs, labsizes);
		}
	}

	freeArrays(labs);		// Free memory before exiting
	cout << "Bye!\n";
	return 0;
}


/* 
    uses a nested for-loop to created an array that conains dynamic arrays and sets their values to -1
 */
void createArrays(IntPtr labs[], int labsizes[])
{
    for(int i =0; i < NUMLABS; i++){
        labs[i] = new int [labsizes[i]];
        for(int q =0; q < labsizes[i]; q++){
            labs[i][q] = -1;
        }
    }



}

/* uses a for-loop to delete the dynamic arrays within an array of pointers
 */
void freeArrays(IntPtr labs[])
{
  //TO BE DONE BY STUDENTS
  for(int i =0; i < NUMLABS; i++){
      delete labs[i];
  }
}


/*  showLabs:
    Displays the status of all labs (who is logged into which computer).
	Precondition: labs[] is a multidimension array of labs with computers
				  labsizes[i] contains the size of the array in labs[i]
 */
void showLabs(IntPtr labs[], int labsizes[])
{

	int i;
	int j;

	cout << "LAB STATUS" << endl;
	cout << "Lab #     Computer Stations" << endl;
	for (i=0; i < NUMLABS; i++)
	{
		cout << i+1 << "         ";
		for (j=0; j < labsizes[i]; j++)
		{
			cout << (j+1) << ": ";
			if (labs[i][j] == -1)
			{
				cout << "empty ";
			}
			else
			{
				cout << labs[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

/* login:
   Simulates a user login by asking for the login info from the console. 
   Reads the user-id, the lab and the computer then assigns the id to labs[lab-1][computer-1]
   Precondition: labs is a multidimension array of labs with computers
                 labsizes[i] is the size of the array in labs[i]
   Postcondition: labs[lab-1][computer-1] = user-id
 */
void login(IntPtr labs[], int labsizes[])
{
	int id, lab, num = -1;

	// read user id 
	do
	{
  		cout << "Enter the 5 digit ID number of the user logging in:" << endl;
		cin >> id;
	} while ((id < 10000) || (id > 99999));

	// read the lab number 
	do 
	{
		cout << "Enter the lab number the user is logging in from (1-" <<
			NUMLABS << "):" << endl;
		cin >> lab;
	} while ((lab <= 0) || (lab > NUMLABS));

	//read computer number 
	do
	{
		cout << "Enter computer station number the user is logging in to " <<
			"(1-" << labsizes[lab-1] << "):" << endl;
		cin >> num;
	} while ((num <= 0) || (num > labsizes[lab-1]));

	// Check to see if this station is free
	if (labs[lab-1][num-1]!=-1)
	{
		cout << "ERROR, user " << labs[lab-1][num-1] <<
			" is already logged into that station." << endl;
		return;
	}
	// Assign this station to the user
	labs[lab-1][num-1] = id;
	return;
}


/* Takes in id number from user. Than searches through a 2-d array using a nested for-loop if value is found changes the value at the index to -1 than prints out the logout statement if its not found prints 'The user is not logged in'
 */
void logout(IntPtr labs[], int labsizes[])
{
    int id, lab, comp;
    bool found = false;
	// Get an ID from the keyboard, validating data ranges (0 - 99999)
    	do
	{
  		cout << "Enter the 5 digit ID number of the user logging in:" << endl;
		cin >> id;
	} while ((id < 10000) || (id > 99999));
	
	    for(int r = 0; r < NUMLABS; r++){
	        for(int c = 0; c < NUMLABS; c++ ){
	            if( labs[r][c] == id){
	                labs[r][c] = -1;
	                lab = r + 1;
	                comp = c + 1;
	                found = true;
	            }
	        }
	    }
	    
	    if(found){
	        cout<<"Logout user " << id << " in Lab " << lab<<" at computer " << comp << endl;
	    }else{
	        cout<< "User not logged in."<< endl;
	    }
	
}

/* Takes in id number from user. Than searches through a 2-d array using a nested for-loop
    if value is found prints lab number and computer spot
 */
void search(IntPtr labs[], int labsizes[])
{
  int id, lab, comp;
    bool found = false;
    	do
	{
  		cout << "Enter the 5 digit ID number of the user logging in:" << endl;
		cin >> id;
	} while ((id < 10000) || (id > 99999));
	
	    for(int r = 0; r < NUMLABS; r++){
	        for(int c = 0; c < NUMLABS; c++ ){
	            if( labs[r][c] == id){
	                lab = r + 1;
	                comp = c + 1;
	                found = true;
	            }
	        }
	    }
	    
	    if(found){
	        cout<< "User " << id << " logged in Lab " << lab << " at computer " << comp << endl;
	    }else{
	        cout<< "User not logged in."<< endl;
	    }

}

