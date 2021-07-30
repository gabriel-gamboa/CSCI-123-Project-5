//
//  CAutomobile.hpp
//
//  Created by Gabriel Gamboa on 10/30/18.
//  Copyright © 2018 Gabriel Gamboa. All rights reserved.
//

#ifndef CAutomobile_hpp
#define CAutomobile_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class CAutomobile
{
public:
    int year;
    string brand;
    string model;
    int numberOfSeats;
    CAutomobile();
    CAutomobile(int y, string b, string m, int n);
    void getAutoInfo();
    friend istream& operator >>(istream& ins, CAutomobile& vehInfo);
    void display();
    friend ostream& operator <<(ostream& outs, const CAutomobile& displayVehInfo);
};

#endif
