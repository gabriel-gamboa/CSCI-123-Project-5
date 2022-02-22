//Filename: Project #5.cpp                          CSCI 123, Fall 2018
//Programmer: Gabriel Gamboa                        Instructor:  Timothy Mai
//Due Date: 11/29/18                                Date Submitted: 12/04/18
//This project gives users the option to view vehicles in a fleet, view which vehicles in the fleet are available, view which vehicles in the fleet have been rented, and it gives users the option to rent and return a vehicle fromt the fleet.  This program takes in information from a "VehicleFleet.txt" file and updates this file depending on whether the user rents a vehicle or not.  This project also gives the user the option to add or remove a vehicle.
//

#include <iostream>
#include "CAutomobile.hpp"
#include "CRentalVehicle.hpp"
#include "CCustomer.hpp"
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;


int menu(); //Displays a menu for users that gives them different options for what they may do in this program.  Allows users to pick an option, and the function returns the choice the user made.
void listAllVehicles();//Function prototype for a function that lists all vehicles currently in the program, whether rented or not, and also shows their status.
void listAvailableVehicles();//Function prototype for a function that lists all available vehicles currently in the program.
void listRentedVehicles();//Function prototype for a function that lists all rented vehicles currently in the program.
void RentingVehicle();//Function prototype for a function that gives the user the option to rent a vehicle.
void ReturningVehicle();//Function prototype for a function that allows user to return a rented vehicle.
void Quit();//Function prototype for a function that calls the function writeVehicleInfo() write the newly updated information of the vehicle fleet back to the file, and outputs a goodbye message to the user.
CRentalVehicle rentalVehicles[20];//array object of type CRentalVehicle.
void readVehicleInfo();//Function prototype for a function that opens the file VehicleFleet.txt, and reads all of the data from VehicleFleet.txt and inputs that dat into each appropriate data member for the object rentalVehicles[] for each member of the array.  The file is closed at the end of the function.
void writeVehicleInfo();//Function prototype for a function that opens the file VehicleFleet.txt, and outputs all of the data in the data type rentalVehicles[] for each member of the array (not including array members that are initialized to default values) into VehicleFleet.txt.  The data is inputted with appropriate formatting.  The file is closed at the end of the function.
void displayVehicles(int x);//Function prototype for a function that displays all of the data members in the rentalVehicles[] array data type, with formatted spacing. Function is intended to be a part of a for loop which contains a variable that iterates by 1, which starts at 0, so that every desired array member may be shown.
void header();//Function prototype for a function that displays a header for the vehicle fleet, naming every type data member of the rentalVehicles[] data type, with formatted spacing.
int findVehicleIndex(CRentalVehicle arr[], int length, int seek);//Function prototype for a function that goes through an array of a data type of the class CRentalVehicle and finds the array index number for a vehicle ID.
void addVehicle();//Function prototype for a function that adds a vehicle to the fleet.
void removeVehicle();//Function prototype for a function that lists all available vehicle's to show readers options for removing vehicles.
int assignID();//Function prototype for a function that finds an available ID to assign to a newly added vehicle.
int theGreatestIndex();//Function prototype for a function that finds the last index number of activated vehicles in the rentalVehicles[] array.
CCustomer customers[20];//Array object of type CCustomer. this is where I've left off.  I finished creating the "CCustomers" class and created an object for that data type that is an array of 20 elements.
void readCustomerInfo();//Function prototype for a function that initializes the array of CCustomer elements.  Reads data from file and applies it to CCustomer elements. Do this before starting program fully.
void writeCustomerInfo();
void listSeatsVehicles();//Function prototype for a function that lists all available vehicles with a certain number of seats.
void listBrandVehicles();//Function prototype for a function that lists all available vehicles with a certain brand.
void listCustomerInfoLN();//Lists customer information based on the last name.
void listCustomersRenting();//List customer information of a specific rented vehicle (based on Vehicle ID).
void displayCustomers(int x);
int nextAvailableCustomerIndex();
void availableCustomers();
string assignCustomerID();//assigns customers an ID.
int findCustomerIndex(CCustomer arr[], int length, int seek);//finds customer index based on vehicleID

int main()//writes data from Vehicle.txt onto rentalVehicles[] object array. Calls the menu function, and lets user pick an option given from the menu.  The corresponding function for each option is then called.
{
    readVehicleInfo();
    readCustomerInfo();//may have bugs, recently added.  Verify whether function works or not once you create a display for the customer info.
    int choice;
    do
    {
        system("CLS");
        choice = menu();
        
        switch (choice) {
            case 1:
                listAllVehicles();
                break;
            case 2:
                listAvailableVehicles();
                break;
            case 3:
                listSeatsVehicles();;
                break;
            case 4:
                listBrandVehicles();
                break;
            case 5:
                listRentedVehicles();
                break;
            case 6:
                listCustomerInfoLN();
                break;
            case 7:
                listCustomersRenting();
                break;
            case 8:
                RentingVehicle();
                break;
            case 9:
                ReturningVehicle();
                break;
            case 10:
                addVehicle();
                break;
            case 11:
                removeVehicle();
                break;
            case 12:
                Quit();
                break;
            default:
                cout << "That was an invalid choice, please try again! \n";
        }
        system("PAUSE");
    } while (choice > 0 && choice < 12);
    system("PAUSE");
    return 0;
}

int menu() //displays a menu for users that gives them different options for what they may do in this program.  Allows users to pick an option, and the function returns the choice the user made.
{
    int option;
    cout << "     RENT-A-VEHICLE MENU\n\n";
    cout << " 1.  List All Vehicles. \n";
    cout << " 2.  List Available Vehicles. \n";
    cout << " 3.  List Available Vehicles with a certain number of seats. \n";
    cout << " 4.  List Available Vehicles from a specific brand. \n";
    cout << " 5.  List Rented Vehicles. \n";
    cout << " 6.  List customer information based on last name. \n";
    cout << " 7.  List customer information of a specific rented vehicle (based on vehicle ID). \n";
    cout << " 8.  Renting A Vehicle. \n";
    cout << " 9.  Returning A Vehicle. \n";
    cout << " 10. Add A Vehicle. \n";
    cout << " 11. Remove A Vehicle. \n";
    cout << " 12. Quit. \n\n";
    cout << "Please select your option: ";
    cin >> option;
    
    while (option < 1 || option > 12)
    {
        cout << "Invalid option!!! Please select valid option: ";
        cin >> option;
    }
    return option;
}

void listAllVehicles()//lists all vehicles currently in the program, whether rented or not, and also shows their status.
{
    header();
    int totalVehicles= 0; //New variable for P5.  Variable keeps track of total number of vehicles in the fleet.  May need to move it somewhere else later.
    for(int i = 0; rentalVehicles[i].ID!=0; i++)
    {
        string tempStatus;
        displayVehicles(i);
        if(rentalVehicles[i].status==CRentalVehicle::AVAILABLE)
            cout << "AVAILABLE";
        else
            cout << "RENTED";
        cout << endl;
        totalVehicles++;
    }
    
}

void listAvailableVehicles()//lists all available vehicles currently in the program.
{
    header();
    int x = 0;
    for (int i = 0; rentalVehicles[i].ID!=0; i++)
    {
        if(rentalVehicles[i].status==CRentalVehicle::AVAILABLE)
        {
            displayVehicles(i);
            cout <<"AVAILABLE" << endl;
            x++;
        }
    }
    if(x==0)
        cout << "There are no available vehicles!";
    
    return;
}

void listRentedVehicles()//lists all rented vehicles currently in the program.
{
    header();
    int x = 0;
    for (int i = 0; rentalVehicles[i].ID!=0; i++)
    {
        if(rentalVehicles[i].status==CRentalVehicle::RENTED)
        {
            displayVehicles(i);
            cout <<"RENTED" << endl;
            x++;
        }
    }
    if(x==0)
        cout << "There are no rented vehicles!";
    return;
}

void listSeatsVehicles()//Make sure you include this function as an option in the menu. ADD IT! Also, debug this later.  Next I need to create the function that lists vehicles of a certain brand.
{
    int specificSeats;
    cout << "Choose how many seats you want in your vehicle: ";
    cin >> specificSeats;
    for (int i = 0; rentalVehicles[i].ID!=0; i++)
    {
        if(rentalVehicles[i].Vehicle.numberOfSeats==specificSeats)
        {
            displayVehicles(i);
            cout << endl;
        }
    }
    return;
}

void listBrandVehicles()//Make sure you include this function as an option in the menu. ADD IT! Also, debug this later.
{
    string brand;
    cout << "Choose which brand of vehicles you want displayed (Capitalize first letter, rest are lower!): ";
    cin >> brand;
    for (int i = 0; rentalVehicles[i].ID!=0; i++)
    {
        if(rentalVehicles[i].Vehicle.brand==brand)
        {
            displayVehicles(i);
            cout << endl;
        }
    }
    return;
}



void RentingVehicle()//gives the user the option to rent a vehicle. Displays all available vehicles (I should probably go back and change this code to call the listAvailableVehicles() function). If there are are no available vehicles, the function displays a message notifying the user of this. (I should probably go back and change this code to call the listAvailableVehicles() function). However if there are vehicles available to rent, the user is allowed to choose to rent a vehicle from the ones available.  If a user picks an invalid ID, or one of a vehicle that is already rented, she is notified of this.
{
    int customerID;
    int customerIndex;
    cout << "Which customer will be renting the vehicle? " << endl;
    availableCustomers();
    cout << "Enter customer ID.  If it is a new customer, enter 0: ";
    cin >> customerID;
    int a = nextAvailableCustomerIndex();
    if(customerID==0)
    {
        customers[a].ID = assignCustomerID();
        customers[a].getCustomerInfo();
        customerIndex = a;
    }
    else
    {
        if(customers[customerID-1].vehicleID!=0)
        {
            cout << "A customer cannot rent more than 1 vehicle." << endl;
        }
        customerIndex = customerID-1;
    }
    header();
    int x = 0;
    for (int i = 0; rentalVehicles[i].ID!=0; i++)
    {
        if(rentalVehicles[i].status==CRentalVehicle::AVAILABLE)
        {
            displayVehicles(i);
            cout <<"AVAILABLE" << endl;
            x++;
        }
    }
    if(x==0)
        cout << "There are no available vehicles!";
    else if(x>0)
    {
        int rentID;
        cout << "Pick an ID of a vehicle to rent (ID must be > 0 & < 21): ";
        cin >> rentID;
        while(rentID<1||rentID>20)
        {
            cout << "Error- ID must be > 0 & < 21. " << endl;
            cout << "Pick an ID of a vehicle to rent: " << endl;
            cin  >> rentID;
        }
        int index = findVehicleIndex(rentalVehicles, 20, rentID);
        if(rentalVehicles[index].status==CRentalVehicle::RENTED)
            cout << "Error, vehicle is already rented. " << endl;
        else
        {
            cout << "You rented " << rentalVehicles[index].Vehicle.brand << " " << rentalVehicles[index].Vehicle.model;
            rentalVehicles[index].status=CRentalVehicle::RENTED;
        }
        customers[customerIndex].vehicleID=rentID;
    }
}

void ReturningVehicle()//Allows user to return a rented vehicle.  The function checks if there are any rented vehicles. If no vehicles are rented, an error message is raised and the funtion ends.  Otherwise, the user is allowed to pick an ID of a rented vehicle to return.  If she enters an ID that is negative or greater than highest ID possible, an error message is raised and she is re-prompted to enter a correct ID.  If she picks an ID of a vehicle that has not been rented, an error message is raised alerting her of this.  If she chooses an appropriate ID number, a message displaying which vehicle is shown is outputted to the computer screen.
{
    int x = 0;
    for (int i = 0; rentalVehicles[i].ID!=0; i++)
    {
        if(rentalVehicles[i].status==CRentalVehicle::RENTED)
        {
            x++;
        }
    }
    if(x==0)
        cout << "There are no rented vehicles" << endl;
    else if(x>0)
    {
        int rentID;
        cout << "Enter the ID number of the vehicle you rented: ";
        cin >> rentID;
        while(rentID<1||rentID>20)
        {
            cout << "Error- ID must be > 0 & < 21. " << endl;
            cout << "Pick an ID of a vehicle to rent: " << endl;
            cin  >> rentID;
        }
        int index = findVehicleIndex(rentalVehicles, 20, rentID);
        if(rentalVehicles[index].status==CRentalVehicle::AVAILABLE)
            cout << "Error, vehicle chosen has not been rented. " << endl;
        else
        {
            cout << "You returned " << rentalVehicles[index].Vehicle.brand << " " << rentalVehicles[index].Vehicle.model;
            rentalVehicles[index].status=CRentalVehicle::AVAILABLE;
            for(int i =0;i<20;i++)
            {
                if(customers[i].vehicleID==rentalVehicles[index].ID)
                    customers[i].vehicleID=0;
            }
        }
    }
}

void Quit()//calls the function writeVehicleInfo() write the newly updated information of the vehicle fleet back to the file, and outputs a goodbye message to the user.
{
    writeVehicleInfo();
    writeCustomerInfo();
    cout << "Have a nice day! \n\n";
}

void readVehicleInfo()//opens the file VehicleFleet.txt, and reads all of the data from VehicleFleet.txt and inputs that dat into each appropriate data member for the object rentalVehicles[] for each member of the array (not including array members that are initialized to default values- initialized automatically by default constructor, data from VehicleFleet.txt overrides default values initialized by constructor).  The file is closed at the end of the function.
{
    ifstream inStream;
    inStream.open("VehicleFleet.txt");
    if (inStream.fail( ))
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    int i =0;
    double z;
    string tempStatus;
    while(inStream >> rentalVehicles[i].ID
          >> rentalVehicles[i].Vehicle.year
          >> rentalVehicles[i].Vehicle.brand
          >> rentalVehicles[i].Vehicle.model
          >> rentalVehicles[i].Vehicle.numberOfSeats
          >> z//rentalVehicles[i].setPrice(double z)- why is this necessary??
          >> tempStatus)
    {
        rentalVehicles[i].setPrice(z);
        if(tempStatus == "AVAILABLE")
            rentalVehicles[i].status=CRentalVehicle::AVAILABLE;
        else
            rentalVehicles[i].status=CRentalVehicle::RENTED;
        i++;
    };
    inStream.close();
}

void writeVehicleInfo()//opens the file VehicleFleet.txt, and outputs all of the data in the data type rentalVehicles[] for each member of the array (not including array members that are initialized to default values) into VehicleFleet.txt.  The data is inputted with appropriate formatting.  The file is closed at the end of the function.
{
    ofstream outStream;
    outStream.open("VehicleFleet.txt");
    if (outStream.fail( ))
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    int i = 0;
    string tempStatus;
    do
    {
        if(rentalVehicles[i].status==CRentalVehicle::AVAILABLE)
            tempStatus = "AVAILABLE";
        else if(rentalVehicles[i].status==CRentalVehicle::RENTED)
            tempStatus="RENTED";
        outStream << setw(2)  << rentalVehicles[i].ID
        << setw(6)  << rentalVehicles[i].Vehicle.year
        << setw(10) << rentalVehicles[i].Vehicle.brand
        << setw(10) << rentalVehicles[i].Vehicle.model
        << setw(5)  << rentalVehicles[i].Vehicle.numberOfSeats
        << setw(10) << fixed << showpoint << setprecision(2) << rentalVehicles[i].getPrice()
        << setw(10) << tempStatus;
        
        outStream << endl;
        i++;
    }while(i<20);
    
    outStream.close();
}

void displayVehicles(int x)//displays all of the data members in the rentalVehicles[] array data type, with formatted spacing. Function is intended to be a part of a for loop which contains a variable that iterates by 1, which starts at 0, so that every desired array member may be shown.
{
    cout << setw(2) << rentalVehicles[x].ID << setw(6) << rentalVehicles[x].Vehicle.year << setw(10) << rentalVehicles[x].Vehicle.brand << setw(10) << rentalVehicles[x].Vehicle.model << setw(6) << rentalVehicles[x].Vehicle.numberOfSeats << setw(10) << fixed << showpoint << setprecision(2) << rentalVehicles[x].getPrice() << setw(10);
    return;
}

void displayCustomers(int x)//displays all of the data members in the customers[] array data type, with proper formatted spacing. Function is intended to be a part of a for loop which contains a variable that iterates by 1, which starts at 0, so that every desired array member may be shown.   -why weren't the first three variable displayed when I called the display customer function? (besides ones that were read from file.)
{
    cout << setw(8) << customers[x].ID << setw(15) << customers[x].firstName << setw(15) << customers[x].lastName << setw(11) << customers[x].vehicleID << endl;
    return;
}

void header()//Displays a header for the vehicle fleet, naming every type data member of the rentalVehicles[] data type, with formatted spacing.
{
    cout << setw(2) << "ID" << setw(6) << "YEAR" << setw(10) << "BRAND" << setw(10) << "MODEL" << setw(6) << "SEATS" << setw(10) << "PRICE" << setw(10) << "STATUS" << endl;
    return;
}


void customerHeader()//Displays a header for the vehicle fleet, naming every type data member of the rentalVehicles[] data type, with formatted spacing.
{
    cout << setw(8) << "Cust. ID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(11) << "Vehicle ID";
    return;
}

int findVehicleIndex(CRentalVehicle arr[], int length, int seek)//this function goes through an array of a data type of the class CRentalVehicle and finds the array index number for a vehicle ID. The ID being searched for is entered as an argument for the parameter 'seek'. (Currently, lenth is not necessary but I don't have the time to take it out and check if it still functions w/o it.  Most likely it will.)  If the array index number of the ID is found, this function returns that array index number. If vehicle ID is not found, this function returns a value of -1. Make sure something is done in other functions to prevent -1 from being returned?
{
    for (int i = 0; i < 20; i++)
    {
        if (arr[i].ID == seek) return i;
    }
    return -1;
}

int findCustomerIndex(CCustomer arr[], int length, int seek)//this function goes through an array of a data type of the class CRentalVehicle and finds the array index number for a vehicle ID. The ID being searched for is entered as an argument for the parameter 'seek'. (Currently, lenth is not necessary but I don't have the time to take it out and check if it still functions w/o it.  Most likely it will.)  If the array index number of the ID is found, this function returns that array index number. If vehicle ID is not found, this function returns a value of -1. Make sure something is done in other functions to prevent -1 from being returned?
{
    for (int i = 0; i < 20; i++)
    {
        if (arr[i].vehicleID == seek) return i;
    }
    return -1;
}
void addVehicle()//Adds a vehicle to the fleet. Allows users to initialize the data members of a vehicle to an array member of rentalVehicles[], if there is an array that is uninitialized.  I should add some sort of code that lets users know that they cannot add a vehicle if the fleet is full.  All data members of the type rentalVehicles[] are initialized by the user, except the ID, which is generated by the function assignID().
{
    for(int i =0; i<20;i++)
    {
        if(rentalVehicles[i].ID==0)
        {
            rentalVehicles[i].getVehicleInfo();
            rentalVehicles[i].ID=assignID();
            return;
        }
    }
    cout << "Vehicle list is full! Cannot add vehicle! " << endl;
    return;
}

void removeVehicle()//Lists all available vehicle's to show readers options for removing vehicles. Lets user choose the ID of a vehicle they want to remove.  Function then finds the index of the rentalVehicles array which contains this ID (each vehicle should have a different ID).  If the vehicle is rented, the user is not allowed to remove the vehicle, and the user is given an error message alerting them of this. (Note: I should write some code that let's the user know they won't be allowed to remove a rented vehicle.) Otherwise, the function displays to the user which vehicle they have chosen to remove, then assigns the data of the last vehicle displayed from the array to the vehicle that has been decided to be removed, and sets the data of the index of the last vehicle displayed to the default values for the vehicles.  If the vehicle is not found, the function displays an error message.
{
    listAvailableVehicles(); //lists all available vehicle's to show readers options for removing vehicles.
    int rentID;
    cout << "Choose ID of vehicle you want to remove: " << endl;
    cin >> rentID;  //accepts ID of vehicle user wants to remove.
    int index;
    if(findVehicleIndex(rentalVehicles, 20, rentID)!=-1)  //checks whether or not ID of vehicle that the user inputted was actually found or not.
    {
        index = findVehicleIndex(rentalVehicles, 20, rentID); //int index is the array index of the vehicle ID the user is searching for.
        if(rentalVehicles[index].status==CRentalVehicle::RENTED)
        {
            cout << "Error, vehicle is not available. " << endl;
            return;
        }
        else
        {
            cout << "You have chosen to remove " << rentalVehicles[index].Vehicle.brand << " " << rentalVehicles[index].Vehicle.model << endl;
            CRentalVehicle defaultValue; //new data type of class CRentalVehicle created to replace last automobile with default value, after the last vehicle is assigned to the vehicle that was removed.
            rentalVehicles[index] = rentalVehicles[theGreatestIndex()]; //the data for the automobile the user decides to removed is replaced by the data of the last vehicle in the array list.
            rentalVehicles[theGreatestIndex()] = defaultValue;//the data of the last vehicle in the array list is set to default, effectively removing the vehicle the user has decided to remove.
        }
    }
    else
    {
        cout << "Vehicle ID not found";
    }
    return;
}

int assignID()//finds an available ID to assign to a newly added vehicle.  This function returns the next greatest ID after the largest ID currently available in the fleet.  If an ID of 20 is present (there are a maximum of 20 vehicles, so there should not be an ID greater than 20), the function searches and finds missing ID's under 20 and returns that ID instead. This function currently has some bugs and may assign an ID that may have already been assigned.  Needs to be fixed.
{
    int y = 1;
    int theGreatest = rentalVehicles[0].ID;
    for(int i = 0; i<20; i++)
    {
        if(rentalVehicles[i].ID > theGreatest)
        {
            theGreatest=rentalVehicles[i].ID;
            if(theGreatest>=20)
            {
                for(int x=0; x<20; x++)
                {
                    if(rentalVehicles[x].ID==y)
                    {
                        y++;
                    }
                    else if(rentalVehicles[x].ID!=y)
                        return y;
                }
                break;
            }
        }
    }
    return theGreatest+1;
}

string assignCustomerID()//
{
    int y = 1;
    int theGreatest = atoi(customers[0].ID.c_str());
    for(int i = 0; i<20; i++)
    {
        if(atoi(customers[i].ID.c_str()) > theGreatest)
        {
            theGreatest=atoi(customers[i].ID.c_str());
            if(theGreatest>=20)
            {
                for(int x=0; x<20; x++)
                {
                    if(atoi(customers[x].ID.c_str())==y)
                    {
                        y++;
                    }
                    else if(atoi(customers[x].ID.c_str())!=y)
                        return to_string(y);
                }
                break;
            }
        }
    }
    return to_string(theGreatest+1);
}

int theGreatestIndex()//Finds the last index number of activated vehicles in the rentalVehicles[] array.
{
    int theGreatestInd;
    for(int i=0; i<20; i++)
    {
        if(rentalVehicles[i].ID ==0)
        {
            theGreatestInd = i-1;
            return theGreatestInd;
        }
    }
    return 19;
}

void readCustomerInfo()////opens the file Customers.txt, and reads all of the data from Customers.txt.txt and inputs that dat into each appropriate data member for the object rentalVehicles[] for each member of the array (not including array members that are initialized to default values- initialized automatically by default constructor, data from VehicleFleet.txt overrides default values initialized by constructor).  The file is closed at the end of the function.
{
    ifstream inStream;
    inStream.open("Customers.txt");
    if (inStream.fail( ))
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    int i =0;
    while(inStream >> customers[i].ID
          >> customers[i].firstName
          >> customers[i].lastName
          >> customers[i].vehicleID)
    {
        i++;
    };
    inStream.close();
}

void writeCustomerInfo()
{
    ofstream outStream;
    outStream.open("Customers.txt");
    if (outStream.fail( ))
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    int i = 0;
    do
    {
        outStream << setw(5)  << customers[i].ID
        << setw(15)  << customers[i].firstName
        << setw(15) << customers[i].lastName
        << setw(9) << customers[i].vehicleID;
        
        outStream << endl;
        i++;
    }while(i<20);
    
    outStream.close();
}

void listCustomerInfoLN()
{
    string ln;
    cout << "Enter the last name of the customer: ";
    cin >> ln;
    customerHeader();
    cout << endl;
    for (int i = 0; atoi(customers[i].ID.c_str())!=0; i++)
    {
        if(customers[i].lastName==ln)
        {
            displayCustomers(i);
            return;
        }
    }
    cout << endl << "There are no customers with the last name of " << ln << endl;
    return;
}

void listCustomersRenting()
{
    int q = 0;
    for (int i = 0; rentalVehicles[i].ID!=0; i++)
    {
        if(rentalVehicles[i].status==CRentalVehicle::AVAILABLE)
        {
            displayVehicles(i);
            cout <<"AVAILABLE" << endl;
            q++;
        }
    }
    if(q==0)
        cout << "There are no rented vehicles!";
    else if(q>0)
    {
        listRentedVehicles();
        int x;
        cout << "Enter the ID number of a rented vehicle to see cutomer info of the customer renting the vehicle:  " << endl;
        cin >> x;
        int a = findVehicleIndex(rentalVehicles, 20, x);
        int z = findCustomerIndex(customers, 20, x);
        cout << "Customer renting this vehicle is: " << endl;
        if(rentalVehicles[a].status==CRentalVehicle::RENTED)
        {
            customerHeader();
            displayCustomers(z);
        }
        else
        {
            cout << "Vehicle is not being rented. " << endl;//add check to make sure user can only input id for a vehicle that is being rented???
        }
    }

    return;
}

void availableCustomers()
{
    int x[20];
    for (int i = 0; i<20; i++)
    {
         x[i] = atoi(customers[i].ID.c_str());
    }
    customerHeader();
    for (int i = 0; x[i]!=0; i++)
     {
         displayCustomers(i);
     }
    return;
}

int nextAvailableCustomerIndex()
{
    int x[20], y=0;
    for (int i = 0; i<20; i++)
    {
        x[i] = atoi(customers[i].ID.c_str());
    }
    for (int i = 0; x[i]!=0; i++)
    {
        y++;
    }
    //put a check in for when all customers are filled up later on.
    return y;
}

istream& operator >>(istream& ins, CRentalVehicle& vehInfo)//overloaded extraction operator for CRentalVehicle data type. (Return to all overloaded operators here on and specify in comments what their function is).
{
    cout << "Enter a year for the automobile: ";
    cin >> vehInfo.Vehicle.year;
    cout << "Enter the automobile's brand: ";
    cin >> vehInfo.Vehicle.brand;
    cout << "Enter the automobile's model: ";
    cin >> vehInfo.Vehicle.model;
    cout << "Enter the number of seats in the automobile: ";
    cin >> vehInfo.Vehicle.numberOfSeats;
    vehInfo.setPrice(50.00);
    return ins;
}

ostream& operator <<(ostream& outs, const CRentalVehicle& displayVehInfo)//overloaded insertion operator for CRentalVehicle data type.
{
    cout << displayVehInfo.Vehicle.year << " ";
    cout << displayVehInfo.Vehicle.brand << " ";
    cout << displayVehInfo.Vehicle.model << " ";
    cout << displayVehInfo.Vehicle.numberOfSeats << " ";
    cout << "$" << displayVehInfo.getPrice() << " ";
    if(displayVehInfo.status==displayVehInfo.AVAILABLE)
        cout<<"AVAILABLE"<< endl;
    else
        cout<<"RENTED"<<endl;
    return outs;
}

istream& operator >>(istream& ins, CAutomobile& vehInfo)//overloaded extraction operator for CAutomobile data type.
{
    cout << "Enter a year for the automobile: ";
    cin >> vehInfo.year;
    cout << "Enter the automobile's brand: ";
    cin >> vehInfo.brand;
    cout << "Enter the automobile's model: ";
    cin >> vehInfo.model;
    cout << "Enter the number of seats in the automobile: ";
    cin >> vehInfo.numberOfSeats;
    return ins;
}

ostream& operator <<(ostream& outs, const CAutomobile& displayVehInfo)//overloaded insertion operator for CAutomobile data type.
{
    cout << displayVehInfo.year << " ";
    cout << displayVehInfo.brand << " ";
    cout << displayVehInfo.model << " ";
    cout << displayVehInfo.numberOfSeats << " " << endl;
    return outs;
}

istream& operator >>(istream& ins, CCustomer& customerInfo)//overloaded extraction operator for CCustomer data type.
{
    cout << "Enter customer ID: ";
    cin  >> customerInfo.ID;
    cout << "Enter customer first name: ";
    cin  >> customerInfo.firstName;
    cout << "Enter customer last name: ";
    cin  >> customerInfo.lastName;
    return ins;
}

ostream& operator <<(ostream& outs, const CCustomer& displayCustomerInfo)//overloaded insertion operator for CCustomer data type.

{
    cout << setw(5) << displayCustomerInfo.ID << setw(15) << displayCustomerInfo.firstName << setw(15) << displayCustomerInfo.lastName << setw(9) << displayCustomerInfo.vehicleID;
    return outs;
}
