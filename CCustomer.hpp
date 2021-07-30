//Filename: CCustomer.hpp                           CSCI 123, Fall 2018
//Programmer: Gabriel Gamboa                        Instructor:  Timothy Mai
//Due Date: 11/29/18                                Date Submitted: 12/04/18
//

#ifndef CCustomer_hpp
#define CCustomer_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class CCustomer
{
public:
    string ID;
    string firstName;
    string lastName;
    int vehicleID;
    CCustomer();
    CCustomer(string id, string fn, string ln);
    void getCustomerInfo();
    void displayCustomerInfo();
    friend istream& operator >>(istream& ins, CCustomer& customerInfo);
    friend ostream& operator <<(ostream& outs, const CCustomer& displayCustomerInfo);
private:
   
};
#endif /* CCustomer_hpp */
