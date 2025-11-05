//------------- Test case for Database-------------// 

#include <iostream>
#include "database.h"

using std :: cout;
using std :: endl; 

int main(){
    
    cout << endl;
    cout << "Testing the Database class." << endl << endl; 

    Database db;

    cout << "Adding elements to the database..." << endl;
    db.addInformation("Bobby", "Wu", 56, "bobbyW56@gmail.com");
    db.addInformation("Wiley", "Moore", 35, "wileyM35@gmail.com");
    db.addInformation("John", "Bauer", 65, "JohnB65@gmail.com");
    cout << endl;
    
    db.displayAll();
    
    cout << "Fetching 'Wiley':" << endl;
    information& mozart = db.getinformation("Wiley");
    mozart.display();
    cout << endl;
    
    cout << "Trying to fetch non-existent element:" << endl;
    db.getinformation("Smith");
    cout << endl;
    
    cout << "Writing database to file..." << endl;
    db.write();
    cout << "Database written to data.frm successfully!" << endl;
    
    return 0;
}

