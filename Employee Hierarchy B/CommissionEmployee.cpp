#include "CommissionEmployee.h"
#include <iostream>
using namespace std;
// ToDo: implement the default constructor, remember to call base class constructor
    CommissionEmployee :: CommissionEmployee() : Employee(), sales(0), commission(0){
        
    }

// ToDo: implement the constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee(string name, string SSN, double sales, double commission) : Employee(name, SSN), sales(sales), commission(commission)

{
	// deliberately empty
	// cout << "CommissionEmployee(" << name << "," << SSN << "," << sales << "," << commission << ")\n"; 
}

// ToDo: implement accessor/mutators
double CommissionEmployee :: get_sales() const{
    return sales;
}
double CommissionEmployee :: get_commission() const{
    return commission;
}
// ToDo: implement virtual get_net_pay function
// Hint: compensation is commission/100 * sales

double CommissionEmployee :: get_net_pay() const{
     return commission/100 * sales;
}

// ToDo: implement the virtual print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void CommissionEmployee::print_check() const
{
    /*
    Employee Number: 321-65-789
    Commission Employee.
    Gross sales: 200000 Commission: 6.5 Pay: 13000
    */
    Employee :: print_check();
	cout << "Commission Employee. " << endl;
	cout << "Gross sales: " << sales << " Commission: " << commission << " Pay: " << commission/100 * sales << endl;
	cout << "_________________________________________________\n";
}

// ToDo: implement the virtual promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream& CommissionEmployee::promptInput(istream& in, ostream& out)
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee
    Employee :: promptInput(in, out);
    out << "Enter sales and commission: ";
    in >> sales >> commission;
    return in;

	// ToDo: read the sales and commission.


}



