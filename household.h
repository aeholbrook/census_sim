// Household.h File – You are to create the .cpp file
// Name: Adam Holbrook
// Assignment: 1

#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include <string>
#include <iostream>
using namespace std;

class Household
{
    private:
        string lastName;
        string streetAddress;
        string stateInitials;
        string zipCode;
        int numOccupants;
    public:
        Household();
        void setLastName(string lastName);
        void setStreetAddress(string streetAddress);
        void setStateInitials(string stateInitials);
        void setZipCode(string zipCode);
        void setnumOccupants(int numOccupants);

        string getLastName();
        string getStreetAddress();
        string getStateInitials();
        string getZipCode();
        int getnumOccupants();

        // Operators compare the last names and will be 
        // used in the list to put them in aphabetical order
        bool operator <(Household rhsH);
        bool operator <=(Household rhsH);
        bool operator !=(Household rhsH);
        // The way I implemented the list, I did not need the following
        // However, you may need them.
        // bool operator >(Household rhsH);
        // bool operator >=(Household rhsH);
        //bool operator ==(Household rhsH); //I don't need this; will rework code
       

        string toString() const;    
};

// This is implemented in the .cpp file
ostream & operator <<(ostream &out, const Household &p);
#endif
