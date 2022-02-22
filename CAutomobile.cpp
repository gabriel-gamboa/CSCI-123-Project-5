//
//  CAutomobile.cpp
//  Homework 10
//
//  Created by Gabriel Gamboa on 10/30/18.
//  Copyright © 2018 Gabriel Gamboa. All rights reserved.
//
//

#include "CAutomobile.hpp"
#include <iostream>
using namespace std;


CAutomobile::CAutomobile()
{
    year = 1900;
    brand = "N/A";
    model = "N/A";
    numberOfSeats = 0;
}

CAutomobile::CAutomobile(int y, string b, string m, int n)
{
    year = y;
    brand = b;
    model = m;
    numberOfSeats = n;
}

void CAutomobile::getAutoInfo()
{
    cout << "Enter a year for the automobile: ";
    cin >> year;
    cout << "Enter the automobile's brand: ";
    cin >> brand;
    cout << "Enter the automobile's model: ";
    cin >> model;
    cout << "Enter the number of seats in the automobile: ";
    cin >> numberOfSeats;
}

void CAutomobile::display()
{
    cout << year << " ";
    cout << brand << " ";
    cout << model << " ";
    cout << numberOfSeats << " " << endl;
}
