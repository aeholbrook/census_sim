#include <string>
#include <fstream>
#include <iostream>
#include "Household.h"
#include "ZipCodeList.h"
#include "BSTree.h"
#include "List.h"
using namespace std;

int printMenu();
void addHousehold(BSTree<ZipCodeList<Household>> tree);
void deleteHousehold(BSTree<ZipCodeList<Household>> tree);
void InitializeTreeFromFile(string filename, BSTree<ZipCodeList<Household>> tree);

int main()
{

    BSTree<ZipCodeList<Household>> a;
    int selection;
    string fileName;

    cout << "Programmed with love by Adam Holbrook\n\n";
    cout << "Enter the file to load the tree: ";
    getline(cin, fileName);

    InitializeTreeFromFile(fileName, a); //The file is sorted by zip codes
    do
    {
        selection = printMenu();
        switch (selection)
        {

        case 1:
            a.printTree();
            break;
        case 2:
            addHousehold(a);
            break;
        case 3:
            deleteHousehold(a);
            break;
        case 4:
            break;
        default:
            cout << "Invalid selection! Please Re-enter!\n";
        }
    } while (selection != 4);
    return 0;

    return 0;

}

// Prints the menu to the screen and returns the users selection
int printMenu()
{
    string schoice;
    cout << endl;
    cout << "1.\tPrint census by zipcode" << endl;
    cout << "2.\tAdd household to zipcode" << endl;
    cout << "3.\tDelete household from  zipcode" << endl;
    cout << "4.\tExit" << endl;
    cout << "Enter your selection: ";
    getline(cin, schoice);
    int choice = stoi(schoice);

    return choice;
}


// Function: addHousehold
// This function asks the user to enter information to make a Household
// object. It them puts the information into the tree. In order to do 
// this, it has to delete the ZipCodeList from 
// the tree, then add the new household into the ZipCodeList's list
// and the puts the ZipCodeList back into the tree
// If the zipcode is not in the tree, it will insert a new node with 
// that zipcode and print a message
// Message: That zipcode is not currently in the tree. so it will be added

void addHousehold(BSTree<ZipCodeList<Household>> tree) {
    string cont = "y";
    string lastName, streetAddress, stateInitials, zipCode;
    int numOccupants;
    Household h;
    do
    {
        cout << "Please enter last name, then press enter:  ";
        getline(cin, lastName);
        cout << "Please enter street address, then press enter:  ";
        getline(cin, streetAddress);
        cout << "Please enter state initials, then press enter:  ";
        getline(cin, stateInitials);
        cout << "Please enter zipcode, then press enter:  ";
        getline(cin, zipCode);
        cout << "Please enter the number of occupants: ";
        cin >> numOccupants;
        h.setLastName(lastName);
        h.setStreetAddress(streetAddress);
        h.setStateInitials(stateInitials);
        h.setZipCode(zipCode);
        h.setnumOccupants(numOccupants);
        cout << "your inputs are as follows: " << endl;
        cout << h << endl;
        cout << "Is this correct? Y/N ";
        cin >> cont;
    }
    while (cont!="y");
    ZipCodeList<Household> zip;
    zip.insertIntoList(h);
    if (!tree.deleteNodePassBackData(zip, zip))
        cout << "That zipcode is not currently in the tree, so it will be added." << endl;
    else zip.insertIntoList(h);
    tree.insert(zip);
}





// Function: deleteHousehold
// This function asks the user to enter the last name and zipcode
// of the person they want to delete from the tree (or list)
// This is done by deleting the correct zipCodeList from the tree
// the deleting the person from the ZipcodeList's list, and then 
// inserting the Zipcodelist back into the tree without the persons 
// name in it
// If thezipcode is not in the tree, or the last name is not in
// the list, it will print a message stating so
// Message: That household is in a zipcode that is not in the tree
// Message: That last name is not in that zipcode

void deleteHousehold(BSTree<ZipCodeList<Household>> tree) {
    string lastName, zipCode;
    Household h;
        cout << "Please enter last name, then press enter:  ";
        getline(cin, lastName);
        cout << "Please enter zipcode, then press enter:  ";
        getline(cin, zipCode);
        h.setLastName(lastName);
        h.setStreetAddress("");
        h.setStateInitials("");
        h.setZipCode(zipCode);
        h.setnumOccupants(0);
    ZipCodeList<Household> zip;
    zip.insertIntoList(h);
    if (!tree.deleteNodePassBackData(zip, zip))
        cout << "That household is in a zipcode that is not in the tree." << endl;
    else
    {
        if (!zip.deleteFromList(h))
            cout << "That last name is not in that zipcode";
        tree.insert(zip);
    }
}






// Function: InitializeTreeFromFile
// This function opens the file that is passed in to the function and then 
// loads all of the information into the tree. The file is in the following 
// format:
// <Last Name>
// <Street Address>
// <State> <Zip code> <occupancy>
// NOTE: - THE FILE IS SORTED BY ZIPCODE
// There is a space between the state, zip code, and occupancy
// Each node of the tree has a ZipCodeList object, and each ZipCodeList
// has a list of Household objects

void InitializeTreeFromFile(string filename, BSTree<ZipCodeList<Household>> tree)
{
    ifstream file;
    file.open(filename);
    string lastName, streetAddress, stateInitials, zipCode, blank;
    int numOccupants;
    while(!file.eof())
    {
        Household h;
        ZipCodeList<Household> l;
            getline(file, lastName);
            getline(file, streetAddress);
            file >> stateInitials
                >> zipCode
                >> numOccupants;
            getline(file, blank);
            h.setLastName(lastName);
            h.setStreetAddress(streetAddress);
            h.setZipCode(zipCode);
            h.setStateInitials(stateInitials);
            h.setnumOccupants(numOccupants);
            l.setZipCode(zipCode);
            tree.deleteNodePassBackData(l, l);
            l.insertIntoList(h);
        tree.insert(l);
    }
}



