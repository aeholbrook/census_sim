 #ifndef ZIPCODELIST_H
 #define ZIPCODELIST_H
 #include <string>
 #include <iostream>
 #include "list.h"
 using namespace std;

 template <class DataType>
 class ZipCodeList
 {
     private:
         string zipCode;
        
     public:
         List<DataType> list;

 	  // inserts the formal parameter into the list
         void insertIntoList(DataType a)
         {
             list.insert(a);
         }

 	  // deletes the formal parameter from the list and 
        // returns true or false if it happened
         bool deleteFromList(DataType a)
         {
             return list.deleteListItem(a);
         }

 	  // deletes and passes back the object being deleted. It
 	  // returns true if the delete deletes correctly
         bool deleteFromListPassBackItem(DataType a, DataType &tmp)
         {
             return list.deleteAndPassBackListItem(a,tmp);
         }
        
         void setZipCode(string zip)
         {
             zipCode=zip;
         }
         string getZipCode()
         {
             return zipCode;
         }

         void printList()
         {
             list.printList();
         }

 	  // Compares the zip codes of the object
         bool operator <(ZipCodeList rhsH)
         {
             return zipCode < rhsH.zipCode;
         }
 	  // Compares the zip codes of the object
         bool operator <=(ZipCodeList rhsH)
         {
             return zipCode <= rhsH.zipCode;
         }
 	  // Compares the zip codes of the object
         bool operator >(ZipCodeList rhsH)
         {
             return zipCode > rhsH.zipCode;
         }
 	  // Compares the zip codes of the object
         bool operator ==(ZipCodeList rhsH)
         {
             return zipCode == rhsH.zipCode;
         }
 // The following operators were not used in my code, but if you code
 // needs them you can implement them
         // bool operator >=( ZipCodeList  rhsH);
         // bool operator !=( ZipCodeList  rhsH);

 };
 template <class DataType>
 ostream & operator <<(ostream &out, ZipCodeList<DataType>& c)
 {
     out << c.getZipCode() << endl;
     out << "\n";
     c.printList();
     return out;
 }
 #endif
