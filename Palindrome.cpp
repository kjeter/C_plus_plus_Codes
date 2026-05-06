/* 
 * pallindrome: checks a string to see if it is a pallindrome.
 *  
 *  Examples:
 * 
 *  Able was I 'ere I saw Elba.
 *  Madam, I'm Adam.
 *  A man, a plan, a canal, Panama.
 *  Racecar
 * 
 *  First, create a clean version of the string. 
 *  	- convert all characters to lower case.
 *  	- remove all punctuation.
 * 
 *  Second, create a reverse version of the string.
 *   - use reverse and swap from our lab assignment
 *   so first make a copy of the string and pass in
 *   the copy to reverse.
 *   
 *  Third
 *  	- compare the two strings 
 *  		if they are the same, palindrome.
 *  		else, not palindrome.
 */ 
#include <iostream>
#include <string>
#include <vector>
// ToDo: Add include files.
using namespace std;


string remove_punct(const string& str);
// Function: remove_punct
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton
// removed.

string convert_lower(string& str);
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string

string swap(char& c1, char& c2);
// Precondition: two characters that have to swapped.
// Postcondition: c1 is in c2 and c2 is in c1 when swapped.

string reverse(string& str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print. 
// Postcondition: Use a tab character for space. strings are printed one per line.

bool is_palindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.

int main() {

   // ToDo: Declare two vectors of strings to save the input strings: palindromes,
   // not_palindromes.
   vector<string> palindromes;
   vector<string> notPalindromes;
   string ans, newAns;
 

   // ToDo: Implement a loop to read in the palindrome strings using getline until
   // the user quits.

   // ToDo: In the loop, call the isPalindrome function on the input string and
   // store it in the palindromes vector if true and the notPalindromes vector if
   // false.
    do{
        
        cout<< "Enter your palindrome or type quit: ";
        getline(cin, ans);
        newAns = ans;
        if(ans != "quit"){
            if(is_palindrome(ans)){
                palindromes.push_back(newAns);
                
            }else{
                notPalindromes.push_back(newAns);
                
            }
            
        }
    }while(ans != "quit");

   // ToDo: After exiting the loop, print the list of palindromes under a Palindrome
   // heading and the list that are not palindromes under a Not Palindrome heading.
   cout<<"Palindromes: "<<endl;
   display(palindromes);
   cout<<endl;
   cout<<"NOT Palindromes: "<<endl;
   display(notPalindromes);
   cout<<endl;
   

	return 0;
}
string remove_punct(const string& str){
    string cleanStr;
    for(int i =0; i<str.length(); i++){
        if(isalpha(str[i]) || isdigit(str[i])){
            cleanStr += str[i];
        }
    }
    //cout<< "cleanStr" << cleanStr << endl;
    return cleanStr;
}


string convert_lower(string& str){
    string cleanStr;
    for(int i =0; i < str.length(); i++){
        str[i] = char(tolower(str[i]));
    }
    cleanStr = str;
    return cleanStr;
}

/*
void swap(char& c1, char& c2){
    char temp = c1;
    c1 = c2;
    c2= temp;
}
*/

string reverse(string& str){
    string reverseStr;
    for(int i = str.length() - 1, j =0; i >= 0; i--, j++){
        str[j] = str[i];
    }
    //cout<<"Str: "<< str << endl;
    reverseStr = str;
   // cout<< "reverseStr: " <<reverseStr<<endl;
    return reverseStr;
}


void display(vector<string> vstrings){
    for(int i =0; i < vstrings.size(); i++){
        cout<< vstrings[i]<< endl;
    }
}


bool is_palindrome(string str){
    //bool is_pal = false;
   string cleanstr = remove_punct(str);
   cleanstr = convert_lower(cleanstr);
   //cout<< cleanstr << endl;
   //cout<< "cleanstr: " << cleanstr << endl;
   string reverseStr = cleanstr;
   //cout<< "reverseStr: " <<reverseStr<< endl;
   reverseStr = reverse(reverseStr);
   //cout << reverseStr << endl;
   return (reverseStr == cleanstr);
   
    
}

