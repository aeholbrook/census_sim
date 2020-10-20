#include "household.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

Household::Household()
    : lastName(),
      streetAddress(),
      stateInitials(),
      zipCode(),
      numOccupants()
{
}

void Household ::setLastName(string lastName)
{
    this->lastName = lastName;
}
void Household ::setStreetAddress(string streetAddress)
{
    this->streetAddress = streetAddress;
}
void Household ::setStateInitials(string stateInitials)
{
    this->stateInitials = stateInitials;
}
void Household ::setZipCode(string zipCode)
{
    this->zipCode = zipCode;
}
void Household ::setnumOccupants(int numOccupants)
{
    this->numOccupants = numOccupants;
}

string Household ::getLastName()
{
    return lastName;
}
string Household ::getStreetAddress()
{
    return streetAddress;
}
string Household ::getStateInitials()
{
    return stateInitials;
}
string Household ::getZipCode()
{
    return zipCode;
}
int Household::getnumOccupants()
{
    return numOccupants;
}
bool Household::operator<(Household rhsH)
{
    return (lastName < rhsH.lastName);
}
bool Household::operator<=(Household rhsH)
{
    return (lastName <= rhsH.lastName);
}
bool Household::operator!=(Household rhsH)
{
    return (lastName != rhsH.lastName);
}

//I will make the specific formatting later when I know how it will need
//to work. For now, I just threw something in here to show I knew how 
//to make it operate properly.

string Household::toString() const {
    ostringstream str;
    str << setw(15) << setiosflags(ios_base::left) << lastName
        << setw(15) << setiosflags(ios_base::left) << streetAddress
        << setw(10) << setiosflags(ios_base::left) << " "
        << setw(3) << setiosflags(ios_base::left) << stateInitials
        << setw(10) << setiosflags(ios_base::left) << zipCode
        << setw(3) << setiosflags(ios_base::left) << numOccupants;
    return str.str();
}

ostream &operator<<(ostream &out, const Household &p) {
    out << p.toString() << endl;
    return out;
}