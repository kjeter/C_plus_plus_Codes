#include <iostream>
#include <string>
#include <stdlib.h>
#include "rational.h"
using namespace std;
/*
Modify the prompt for an operator to include the new relational operators.
cout << "\nEnter operator [+, -, /, *, =, ?(==), <(less), >(greater), c(lear), a(ccessors), q(uit)]: ";
Modify the code to get other oper characters to include '?', '<' and '>'

if (oper in "+-?<>") cout << "\nEnter op2 (in the format of p/q):";

Modify the calls to Add, Subtract, Multiply, and Divide to use your new operators.
Add cases for handing '?' (call operator==), '<' (call operator<), '>' (calls operator>). 
'?':  cout << ((result == op1)? "Correct! Good job!" : "Oh no! Good try!") << endl;
'<':  cout << ((result < op1)? "True, great!" : "False, try again!") << endl
Modify the input and output function calls to use operator>> and operator<< respectively.
Add code to fix the input at the end of the loop. If the operator>> fails, it should set the failbit. To recover, you can add the following code:

   Fixes cin if the last rational was invalid
  if (cin.fail()) {
    cin.clear(); cin.ignore();
  }
  : numerator(numer), denominator(1)
  : numerator(numer), denominator(denom)
*/
// TODO: Default constructor sets numerator to 0 and denominator to 1
rational :: rational(){
    numerator = 0;
    denominator = 1;
}

rational :: rational(int numer) : numerator(0), denominator(1){
   /* if (!isdigit(numer)) {
        cout << "Invalid rational format!" << endl;
        exit(1);
    } */
    numerator = numer;
}
rational :: rational(int numer, int denom) : numerator(0), denominator(1){
    /*if (!isdigit(numer) || !isdigit(denom)) {
        cout << "Invalid rational format!" << endl;
        exit(1);
    } */
    numerator = numer;
    denominator = denom;
} 
void  rational :: set (int a_numerator, int a_denominator){
    numerator = a_numerator;
    denominator = a_denominator;
}
int rational :: getNumerator ()const{
    return numerator;
}
int rational :: getDenominator ()const{
    return denominator;
} 
// TODO: Definitions of all member functions declared above
istream& operator >>(istream & in, rational & op) {
    char dash;
    in >> op.numerator >> dash >> op.denominator;
    return in;
}

ostream& operator << (ostream & out, const rational &op){
    out << "result = " << op.numerator << "/" << op.denominator;
    return out;
}

rational operator + (const rational &op1, const rational &op2){
    rational sum;
        sum.numerator = (op1.numerator * op2.denominator) + (op2.numerator * op1.denominator);
        sum.numerator = abs(sum.numerator);
      
        sum.denominator = op1.denominator * op2.denominator;
        sum.denominator = abs(sum.denominator);
        sum.simplify();
    return sum;
    
}
rational operator -(const rational &op1, const rational &op2){
    rational difference;
            difference.numerator = (op2.numerator * op1.denominator) - (op1.numerator * op2.denominator) ;
            difference.numerator = abs(difference.numerator);
        
            difference.denominator = op2.denominator * op1.denominator;
            difference.denominator = abs(difference.denominator);
        difference.simplify();
    return difference;
            
           
}
rational operator *( const rational &op1, const rational &op2)
{
    rational multiple;
        multiple.numerator = op1.numerator * op2.numerator;
        multiple.numerator = abs(multiple.numerator);
        
        multiple.denominator = op1.denominator * op2.denominator;
        multiple.denominator = abs(multiple.denominator);
    multiple.simplify();
    return multiple;
}
 rational operator /( const rational &op1, const rational &op2){
    rational dividend;

         dividend.numerator = op1.numerator * op2.denominator;
         dividend.numerator = abs(dividend.numerator);
        
         dividend.denominator = op1.denominator * op2.numerator;
         dividend.denominator = abs(dividend.denominator);
    dividend.simplify();
    return dividend;
}
bool operator == (const rational &op1, const rational &op2){
    if(op1.numerator*op2.denominator == op2.numerator*op1.denominator){
        return true;
    }else{
        return false;
    }
}
bool operator < (const rational &op1, const rational &op2){
    if( op1.numerator*op2.denominator < op2.numerator*op1.denominator){
        return true;
    }else{
        return false;
    }
}
bool operator > (const rational &op1, const rational &op2){
    if( op1.numerator*op2.denominator > op2.numerator*op1.denominator){
        return true;
    }else{
        return false;
    }
}
/*rational operator +=(const rational &op1, const rational &op2){
    rational sum;
        sum.numerator = (op1.numerator * op2.denominator) + (op2.numerator * op1.denominator);
        sum.numerator = abs(sum.numerator);
      
        sum.denominator = op1.denominator * op2.denominator;
        sum.denominator = abs(sum.denominator);
        sum.simplify();
    return sum;
}*/
