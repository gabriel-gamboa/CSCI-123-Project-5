//
//  CRentalVehicle.hpp
//
//  Created by Gabriel Gamboa on 11/1/18.
//  Copyright © 2018 Gabriel Gamboa. All rights reserved.

#ifndef CRentalVehicle_hpp
#define CRentalVehicle_hpp

#include <stdio.h>
#include <iostream>
#include "CAutomobile.hpp"
using namespace std;

class CRentalVehicle
{
public:
    enum VehicleStatus {AVAILABLE, RENTED};
    int ID;
    CAutomobile Vehicle;
    VehicleStatus status;
    CRentalVehicle();
    CRentalVehicle(int x, int vy, string vb, string vm, int vs, double pr);
    void getVehicleInfo();
    friend istream& operator >>(istream& ins, CRentalVehicle& vehInfo);
    void display();
    friend ostream& operator <<(ostream& outs, const CRentalVehicle& displayVehInfo);
    double getPrice() const;
    void setPrice(double x);
private:
    double price;
};

#endif /* CRentalVehicle_hpp */
