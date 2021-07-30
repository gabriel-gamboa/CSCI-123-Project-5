//Filename: CRentalVehicle.cpp                      CSCI 123, Fall 2018
//Programmer: Gabriel Gamboa                        Instructor:  Timothy Mai
//Due Date: 11/29/18                                Date Submitted: 12/04/18
//

#include "CRentalVehicle.hpp"
#include <iostream>
using namespace std;


CRentalVehicle::CRentalVehicle()
{
    ID = 0;
    Vehicle.year = 1900;
    Vehicle.brand = "N/A";
    Vehicle.model = "N/A";
    Vehicle.numberOfSeats = 0;
    price = 0.0;
}

CRentalVehicle::CRentalVehicle(int x, int vy, string vb, string vm, int vs, double pr)
{
    ID = x;
    Vehicle.year = vy;
    Vehicle.brand = vb;
    Vehicle.model = vm;
    Vehicle.numberOfSeats = vs;
    price = pr;
    status=AVAILABLE;
}

void CRentalVehicle::getVehicleInfo()
{
    cout << "Enter a year for the automobile: ";
    cin >> Vehicle.year;
    cout << "Enter the automobile's brand: ";
    cin >> Vehicle.brand;
    cout << "Enter the automobile's model: ";
    cin >> Vehicle.model;
    cout << "Enter the number of seats in the automobile: ";
    cin >> Vehicle.numberOfSeats;
    double x;
    cout << "Enter the price to rent the automobile: ";
    cin >> x;
    setPrice(x);
    status=AVAILABLE;
}

void CRentalVehicle::display()
{
    cout << Vehicle.year << " ";
    cout << Vehicle.brand << " ";
    cout << Vehicle.model << " ";
    cout << Vehicle.numberOfSeats << " ";
    cout << "$" << getPrice() << " ";
    if(status==AVAILABLE)
        cout<<"AVAILABLE"<< endl;
    else
        cout<<"RENTED"<<endl;
}

void CRentalVehicle::setPrice(double x)
{
    price = x;
}

double CRentalVehicle::getPrice() const
{
    return price;
}

