#include <iostream>
#include <string>
#include <stdlib.h>
#include "rational.h"
using namespace std;


int main()
{
	char oper;
	int num = 0, i = 0;
	// TODO: declare rational objects for result and operand.
    rational op1, op2, result;
	cout << "Enter op1 (in the format of p/q): ";
	// TODO: Use your input function to read the first operand into result.
    cin >> op1;
	//Test rational class member function 
	do {
		cout << "\nEnter operator [+, -, /, *, =, ?(==), <(less), >(greater), c(lear), a(ccessors), q(uit)]: ";
		// TODO: Read the operator into oper
        cin >> oper;
		// TODO: Change the pseodocode below to test oper for binary operators
		if (oper == '+' || oper == '-' || oper == '*' || oper == '/'|| oper == '?' || oper == '<' || oper == '>') {
			cout << "\nEnter op2 (in the format of p/q): ";
			// TODO: Use your input function to read the operand into operand

            cin >> op2;
		}


        switch (oper){
            case '+':
                if(num > 0 && i != 1){
                result = result + op2;
                }else{
                    result = op1 + op2;
                }
                //result.output();
            break;
            case '-':
                if(num > 0 && i != 1){
                result = result - op2;
                }else{
                    result = op1 - op2;
                }
                //result.output();
            break;
            case '*':
                if(num > 0 && i != 1){
                result = result * op2;
                }else{
                    result = op1 * op2;
                }
                //result.output();
            break;
            case'/':
                if(num > 0 && i != 1){
                result = result / op2;
                }else{
                    result = op1 / op2;
                }
                //result.output();
            break;
            case '=':
                cout << result;
            break;
            case '?':
                if(num == 0){
                    cout << ((op2 == op1)? "Correct! Good job!" : "False, try again!") << endl;
                    i = 1;
                }else{
                    cout << ((result == op2)? "True, great!" : "False, try again!") << endl;
                }
            break;
            case '<':  
            if(num == 0){
                    cout << ((op1 < op2)? "True, great!" : "False, try again!") << endl;
                    i = 1;
                }else{
                    cout << ((result < op2)? "True, great!" : "False, try again!") << endl;
                }
                //cout << ((result < op1)? "True, great!" : "False, try again!") << endl;
            break;
             case '>':  
             if(num == 0){
                    cout << ((op1 > op2)? "True, great!" : "False, try again!") << endl;
                    i = 1;
                }else{
                    cout << ((result > op2)? "True, great!" : "False, try again!") << endl;
                }
                //cout << ((result > op1)? "True, great!" : "False, try again!") << endl;
            break;
            case 'c':
                result.set(0,1);
                cout << "\nEnter op1 (in the format of p/q): ";
                cin >> op1;
                num = 0;
            break;
            case 'a':
                    cout << "result's numerator is: " << result.getNumerator()<<endl;
                    cout << "result's denominator is: " << result.getDenominator();
                    //cout << result;
            
            break;
        }
    if(oper != 'c'){
        num++;
    }
    if (cin.fail()) {
    cin.clear(); cin.ignore();
  }
	} while (oper != 'q');
	
	return 0;
}



