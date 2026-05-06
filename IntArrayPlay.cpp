#include <iostream>
using namespace std;

const int CAPACITY=20;
// [Already implemented]
// displayArray - display the array on a single line separated by blanks.
 // @param: int array[] is an unordered array of integers
 // @param: int numberOfElements
 // [Already implemented]
 void displayArray(int array[], int numElements);
 
 //ToDo: Declare a function fillArray that fills an int array with values entered
 // by the user. Stop reading when the user inputs -1 or you reach CAPACITY.
 // fillArray - reads a list of positive integers ending with -1 or until CAPACITY.
 // @param: int array[] is an unordered array of integers when leaving this function
 // @param: int& numberElements is the number of Elements in the array after function
 // @returns void.
 void fillArray(int array[], int& numEle);
 //ToDo: Delcare a function that removes (i.e., deletes) the element
 // removeElement - removes the element of the given index from the given array.
 // @param: int array[] is an unordered array of integers
 // @param: int& numberElements
 // @param: int position of element to delete
 // @returns: true if delete was successful, false otherwise
 bool removeElement(int array[], int& numEle, int pos);
 
 //ToDo: Delcare a function that inserts the element in the given position
 // insertElement - removes the element of the given index from the given array.
 // @param: int array[] is an unordered array of integers
 // @param: int& numberElements
 // @param: int position to insert into
 // @param: int target to insert.
 // @returns: true if insert was successful, false otherwise
 bool insertElement(int array[], int& numEle, int pos, int target);
 
  //ToDo: Declare a funcxtion that searches for an element in the given array
 // searchElement - searches for the element in the given array.
 // @param int array[] is an unordered array of integers
 // @param int numberOfElements
 // @param int element
 // @returns index of element or -1 if not found.
 int searchElement(int array[], int numEle, int element);
 int main()
 {
   // The NumArray can be partially filled, we use variable NumArrayElems to keep track of how many numbers
   // have been stored in the array.
   int NumArray[CAPACITY];   // an int array with a given CAPACITY
   int NumArrayElems=0, val1, pos1, val2, index, val3;      // the array is initially empty, i.e., contains 0 elements
 
 
   // 1. ToDo: Call your fillArray function to read in a sequence of integer values,
   // separated by space, and ending with -1. Store the values in the NumArray array
   // and the number of elements in NumArrayElems.
   // Display the contents of the array afterwards
         fillArray(NumArray, NumArrayElems);
         //cout<<endl;
         displayArray(NumArray, NumArrayElems);
 
   // 2. ToDo: Read in a value and position from the user. Call your insertElement function
   // to insert the given value into the given position of the array
   // Display the contents of the array afterwards
  // Display the contents of the array afterwards
         cout<<"Enter a value and a position to insert: ";
         cin>> val1;
         cin>> pos1;
         insertElement(NumArray, NumArrayElems, pos1, val1);
                 displayArray(NumArray, NumArrayElems);
         
 
   // 3. ToDo: Read in a value and call your searchElement function.
   // 4. if the value is  found, delete it from the array using your deleteElement function
 //    if the value not found, print "Value not found!"
   // Display the contents of the array afterwards
         cout<<"Enter a value to delete from the array: ";
         cin>> val2;
         index = searchElement(NumArray, NumArrayElems, val2);
         if(index != -1){
                 if(removeElement(NumArray, NumArrayElems, index)){
                         displayArray(NumArray, NumArrayElems);
                 }
         }else if( index == -1){
                 cout<<"Value not found!"<<endl;
                 //displayArray(NumArray, NumArrayElems);
         }
 
   // 5. TODO: Read in a value and call your insertElement function to append
   // a value to the end of the array
   // Display the contents of the array afterwards
         cout<<"Enter a value to append: ";
         cin>> val3;
         if(NumArrayElems != CAPACITY){
             NumArrayElems++;
             NumArray[NumArrayElems - 1] = val3;
         }
                 displayArray(NumArray, NumArrayElems);
         
   return 0;
 }
 
 
 //searchElement- searches through an array for a specific element and returns that element's
//index
//precondition: array is an unsorted array, numEle is an interger with the number of elements 
//in the array, element is an interger that the user is searching for
//postcondition: the index of element has been returned if the element isn't in the array -1 is
 //returned
 int searchElement(int array[], int numEle, int element){
        /* int first = 0, last = numEle - 1, middle, pos = -1;
         bool found = false;
        while( !found && first <= last){
                 middle = (first + last)/2;
                 if(array[middle] == element){
                         found = true;
                         pos = middle;
                 }else if( array[middle] > element){
                         last = middle - 1;
                 }else{
                         first = middle + 1;
                 }
         }
         if( first <= last && !found){
                 pos = -1;
         } */
         int pos = -1;
         for(int i = 0; i < numEle; i++){
             if(array[i] == element){
                 pos = i;
             }
         }
         return pos;
 }
 
 //removeElement - removes a element from an unsorted array
//precondition: array is an unsorted array, numEle is an interger holding the number of elements
 // in the array, and pos holds the postiont of the element that is being removed
 // postcondition: the element at pos has been removed from array and numEle has decreased
 bool removeElement(int array[], int& numEle, int pos){
         //int size = numEle;
         int val = array[pos];
         for (int i = pos + 1; i < numEle; i++){
                 array[i - 1] = array[i];
         }
         numEle--;
         int searchEle = searchElement(array, numEle, val);
         if(searchEle == -1){
                 return true;
         }else{
                 return false;
         }
 }
 
 // fillArray - fills an array with user inputed vaules
 // precondition: int array[] is an empty array with max-capacity of 20 elements 
 // precondtion: numElems is an interger set to zero
 // postcondition: array is filled with user inputed values and numEle holds the number of elements in the array
 void fillArray(int array[], int& numEle){
         int val;
         cout<<"Enter a list of up to 20 integers or -1 to end the list ";
         do{
                 cin>> val;
                /* if(val == -1){
                     break;
                 } */
                 array[numEle] = val;
                 numEle++;
         }while( val != -1 && numEle < CAPACITY);
         
         if(array[numEle - 1] == -1){
             numEle--;
         }
 }
 
 //insertElement- inserts an element in an array at a certain index
 //precondition - array is an unsorted array, numEle hold the number of elements in the array
//target is the element which is being placed in the array, pos holds the index of the target
//postcondition: target has been placed in the array at pos and numEle has increased
 bool insertElement(int array[], int& numEle, int pos, int target){
        if(pos >= numEle || pos < 0){
            return false;
        }else{
            if (numEle < CAPACITY){
                    numEle++;
                    for (int i = numEle - 1; i > pos; i--){
                            array[i] = array[i - 1];
                     }
                     array[pos] = target;
            }
            if(array[pos] == target){
                    return true ;
            }else{
                    return false;
            }
        }
 }
 
 
 // displayArray - displays the array
 // precondition: int array[] is an unordered array of numElems integers.
 // postcondition: array is displayed on the console on a single line separated by blanks.
 void displayArray(int array[], int numElems)
 {
     for (int i = 0; i < numElems; i++){
                
                 cout << array[i] << " ";
            
      }
        cout << endl;
}