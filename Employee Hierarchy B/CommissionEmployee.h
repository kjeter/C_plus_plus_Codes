//#pragma once
#include <iostream>
#include "Employee.h"

#ifndef _COMMISSION_H
#define _COMMISSION_H

class CommissionEmployee : public Employee
{
public:
	// ToDo: declare default constructor for CommissionEmployee
    CommissionEmployee();

	// ToDo: declare constructor for CommissionEmployee that takes a name, SSN, sales, commission percent
    CommissionEmployee(string name, string SSN, double sales, double commission);

	// ToDo: declare Accessor/Mutator functions
    double get_sales() const;
    double get_commission() const;
	// ToDo: declare vitual functions to override
    double get_net_pay() const override;
    void print_check() const override;
    istream& promptInput(istream& in, ostream& out) override;
    
private:
	// ToDo: declare a sales, commission percent member
    double sales, commission;
};
#endif // _COMMISSION_H

