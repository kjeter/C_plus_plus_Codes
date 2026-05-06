/* Implement Administrator class */
#include <iostream>
#include "Administrator.h"

using namespace std;

// ToDo: implement the default constructor, remember to call base class constructor
Administrator :: Administrator() : SalariedEmployee(), bonus(0), job_title(" "){
    
}

// ToDo: implement the constructor, remember to call base class constructor
Administrator::Administrator(string the_name, string the_SSN, double the_salary, string the_title, double the_bonus) : SalariedEmployee(the_name, the_SSN, the_salary), bonus(the_bonus), job_title(the_title)

{
	// deliberately empty
	//cout << "Adminstrator(" << the_name << "," << the_SSN << "," << the_salary << "," << the_title << "," << the_bonus << ")\n"; 
}


// ToDo: implement accessor/mutators
string Administrator :: get_title() const{
    return job_title;
}
double Administrator :: get_bonus() const{
    return bonus;
}
// ToDo: implement virtual functions
double Administrator :: get_net_pay() const{
    return SalariedEmployee::get_net_pay() + bonus;
}


// ToDo: implement virtual get_net_pay function
// Hint: compensation is salary + bonus


// ToDo: implement the print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void Administrator::print_check() const
{   
    
    SalariedEmployee::print_check();
	cout << "Administrator Title:" << job_title << endl;
	cout<< "Bonus: " << bonus << " Pay: " << SalariedEmployee::get_net_pay() + bonus << endl;
	cout << "_________________________________________________\n";
}

// ToDo: implement the promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream & Administrator::promptInput(istream & in, ostream & out) 
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee
	SalariedEmployee :: promptInput(in, out);
	out << "Enter bonus and title: ";
	


	// ToDo: read the bonus. Use ignorespace() to skip newline.

	ignorespace(in);
    in >> bonus;

	// ToDo: read the rest of the line for the title
    getline(in, job_title);
    return in;
}

