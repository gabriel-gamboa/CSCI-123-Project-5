//Filename: CCustomer.cpp                           CSCI 123, Fall 2018
//Programmer: Gabriel Gamboa                        Instructor:  Timothy Mai
//Due Date: 11/29/18                                Date Submitted: 12/04/18
//
//

#include "CCustomer.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

CCustomer::CCustomer()//why aren't my strings being displayed here?
{
    ID = "0000";
    firstName = "None";
    lastName = "None";
    int vehicleID = 0;
}// why weren't the first three variable displayed when I called the display customer function?

CCustomer::CCustomer(string id, string fn, string ln)
{
    ID = id;
    firstName = fn;
    lastName = ln;
}

void CCustomer::getCustomerInfo()
{
    cout << "Enter customer first name: ";
    cin  >> firstName;
    cout << "Enter customer last name: ";
    cin  >> lastName;
}

void CCustomer::displayCustomerInfo()
{
    cout << setw(5) << ID << setw(15) << firstName << setw(15) << lastName << setw(9) << vehicleID;
}

