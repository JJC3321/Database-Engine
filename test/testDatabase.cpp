//------------- Test case for Database-------------// 

#include <iostream>
#include "database.h"

using std :: cout;
using std :: endl; 

int main(){
    
    cout << endl;
    cout << "Testing the Database class." << endl << endl; 

    Database db;

    cout << "Adding composers to the database..." << endl;
    db.AddComposer("Ludwig van", "Beethoven", 56, "beethoven@classical.com");
    db.AddComposer("Wolfgang Amadeus", "Mozart", 35, "mozart@classical.com");
    db.AddComposer("Johann Sebastian", "Bach", 65, "bach@classical.com");
    cout << endl;
    
    db.displayAll();
    
    cout << "Fetching composer 'Mozart':" << endl;
    Composer& mozart = db.getComposer("Mozart");
    mozart.display();
    cout << endl;
    
    cout << "Trying to fetch non-existent composer:" << endl;
    db.getComposer("Chopin");
    cout << endl;
    
    cout << "Writing database to file..." << endl;
    db.write();
    cout << "Database written to data.frm successfully!" << endl;
    
    return 0;
}

