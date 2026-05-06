//Implementation of the class CheckingAccount.
#include <iostream>
#include <cmath>
using namespace std;

// To Do: include necessary header files
#include "CheckingAccount.h"


// To Do: Please write comments and code to implement CheckingAccount here

//Initializes the account balance to $dollars.cents and the check fee to fee.
CheckingAccount :: CheckingAccount(int dollar, int cents, double check_fee) : BankAccount(dollar, cents), fee(check_fee){
    
}

//Initializes the account balance to $dollars.00 and check fee to the fee.
CheckingAccount :: CheckingAccount(int dollar, double check_fee) : BankAccount(dollar), fee(check_fee){
   
}

//Initializes the account balance to $0.00 and the check fee to $0.00.
CheckingAccount :: CheckingAccount(): BankAccount(), fee(0.00){

}

//Returns the check fee.
double CheckingAccount :: getFee() const{
    return fee;
}

//Precondition: If outs is a file output stream, then outs has already been
//connected to a file.
//Postcondition: balance and check fee have been written to the stream outs.
void CheckingAccount :: output(ostream& outs) const{
    BankAccount::output(outs);
    outs << "Check fee: $" << getFee() << endl;
}

//Precondition: If ins is a file input stream, then ins has already been
//connected to a file.
//Postcondition: balance and check fee have been read from the stream ins.
void CheckingAccount :: input(istream& ins){
    BankAccount::input(ins);
    ins >> fee;
}

// Precondition: dollars and cents must be greater or equal to 0.
// Dollars and cents be less than or equal to balance.
// Postcondition: increase the balance by the dollars and cents
// plus the fee.
void CheckingAccount :: check(int dollars, int cents){
    int Dollar = floor(fee);
    int Cents = (fee * 100) - (Dollar * 100);
    //BankAccount :: withdraw(dollars + Dollar, cents + Cents); 
    BankAccount :: withdraw(dollars, cents);
    BankAccount :: withdraw(Dollar, Cents);
    
    
   
}