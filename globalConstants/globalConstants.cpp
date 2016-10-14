// This program calculates gross pay

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

//---Global constants--------------------------------------------
const double Pay_Rate = 22.55,		// Hourly pay rate
			 Base_Hours = 40.0,		// Max non-overtime hours
			 OT_Multiplier = 1.5;	// Overtime multiplier

//---Function prototypes---------------------------------------
double getBasePay(double);
double getOvertimePay(double);


int main()
{
	double	hours,					// Hours worked
			basePay,				// Base pay
			overtime = 0.0,			// Overtime pay
			totalPay;				// Total pay

	// Get the number of hours worked
	cout << "How many hours did you work? ";
	cin >> hours;

	// Get the amount of base pay.
	basePay = getBasePay(hours);

	// Get overtime pay, if any
	if (hours > Base_Hours)
		overtime = getOvertimePay(hours);

	// Calculate the total pay
	totalPay = basePay + overtime;

	// Set up numeric output formatting
	cout << setprecision(2) << fixed << showpoint;

	// Display the pay
	cout << "Base pay: $" << basePay << endl
		 << "Overtime pay $" << overtime << endl
		 << "Total pay $" << totalPay << endl;
    return 0;
}

//******************************************************************************
//	This function accepts the number of hours worked as an argument
//	and returns the employee's pay for non-overtime hours
//*****************************************************************************

double getBasePay(double hoursWorked)
{
	double basePay;			// To hold base pay
	
	// Determine base pay
	if (hoursWorked > Base_Hours)
		basePay = Base_Hours * Pay_Rate;
	else
		basePay = hoursWorked * Pay_Rate;
	return basePay;
}

//*********************************************************************************
//	This function accepts the number of hours worked as an argument
//	and returns the employee's overtime pay
//*********************************************************************************

double getOvertimePay(double hoursWorked)
{
	double overtimePay;			// To hold overtime pay

	// Determine overtime pay
	if (hoursWorked > Base_Hours)
	{
		overtimePay = (hoursWorked - Base_Hours) * Pay_Rate * OT_Multiplier;

	}
	else
		overtimePay = 0.0;
	return overtimePay;
}