/*  This rational class practice basics of defining and using class. Start with the rational class from part1
 *  Make the required changes and leave the rest.
 */
#include <iostream>

#ifndef RATIONAL_H
#define RATIONAL_H
using namespace std;
class rational {
    public:
    // TODO: Modify constructor declaration to set default values for parameters. See instructions below.
    rational();
    rational(int numer);
    rational(int numer, int demnom);
    void set(int a_numerator, int a_denominator); 
    int getNumerator() const;
    int getDenominator() const;
    
    // TODO: Overload the >> operator so it can be used to input values of type rational
    // Precondition: If in is a file input stream, then in has already been connected to a file
    friend istream& operator >>(istream & in,  rational &op);
    
    // TODO: Overloads the << operator so it can be used to output values of type rational
    // Precondition: If out is a file output stream, then out has already been connected to a file
    friend ostream& operator << (ostream & out, const rational &op);

    // TODO: Modify the add member function to overload operator+
    // op1 + op2 is stored in a local rational object which is returned
    // @return a rational with the sum
    friend rational operator + (const rational &op1, const rational &op2);  
  
    // TODO: Modify the subtract member function to overload operator-
    // op1 - op2 is stored in a local rational object which is returned
    // @return a rational with the difference
    friend rational operator - (const rational &op1, const rational &op2);

    // TODO: Modify the multiply member function to overload operator*
    // op1 * op2 is stored in a local rational object which is returned
    // @return a rational with the product
    friend rational operator * (const rational &op1, const rational &op2);

    // TODO: Modify the divide member function to overload operator/
    // op1 / op2 is stored in a local rational object which is returned
    // @return a rational with the quotient

    friend rational operator / (const rational &op1, const rational &op2);
    // TODO: Declare operator== where op1 and op2 are compared to see if they are equal
    // @return true if equal (compare cross product of n1*d2 == n2*d1) or false if not.
    friend bool operator == (const rational &op1, const rational &op2);

    // TODO: Declare operator< where op1 and op2 are compared to see if op1 < op2.
    // @return true if op1 < op2 (compare cross product of n1*d2 < n2*d1) or false if not. 
    friend bool operator < (const rational &op1, const rational &op2);

    // TODO: Declare operator> where op1 and op2 are compared to see if op1 > op2.
    // @return true if op1 > op2 (compare cross product of n1*d2 > n2*d1) or false if not. 
    friend bool operator > (const rational &op1, const rational &op2);
    //friend rational operator +=(const rational &op1, const rational &op2);
 private:
    int numerator;
    int denominator;

    // TODO: Declare simplify() member that sets the invoking object to be a simplified rational
    void simplify(){
        int GCD = gcd(numerator, denominator);
        numerator = numerator/GCD;
        denominator = denominator/GCD;
    }

    // TODO: Implement the gcd function to return the greatest common denominator, use it in simplify above.
    int gcd(int a, int b){
         while (a!=0 && b!=0)
        {
            a = a % b;
            if (a!=0)
                b = b % a;
        }
        if (a==0){
            return b;
        }
        if (b==0){
            return a;
        }
        return 1;
    }
};
#endif // RATIONAL_H