//------------- Database Implementation-------------// 

#include "database.h"

Database :: Database(){
    nextSlot = 0;
}


Database :: ~Database(){

}


void Database :: write(){
   
    std :: ofstream outPutFile; 
    outPutFile.open("data.frm");
    
    
    if(!outPutFile.is_open()) { 
        std :: cout << "error file not open" << std :: endl;
        return;
    }

    outPutFile << nextSlot << std :: endl;

    // Write infomation to database 
    for(int i = 0; i < nextSlot; i++){
        outPutFile << composer_[i].id() << std :: endl;
        outPutFile << composer_[i].firstName() << std :: endl;
        outPutFile << composer_[i].LastName() << std :: endl;
        outPutFile << composer_[i].age() << std :: endl;
        outPutFile << composer_[i].email() << std :: endl;
    }

    outPutFile.close(); 
}



Composer& Database :: AddComposer(string firstName, string lastName, int age, string email){

    if(nextSlot >= kMaxComposers){
        std :: cout << "Database is full!" << std :: endl;
        return composer_[kMaxComposers - 1]; // Return last slot if full
    }
    
    composer_[nextSlot].setId(nextSlot + 1);  // Auto-assign ID starting from 1
    composer_[nextSlot].setFirstName(firstName);
    composer_[nextSlot].setLastName(lastName);
    composer_[nextSlot].setAge(age);
    composer_[nextSlot].setEmail(email);
    
    nextSlot++;
    return composer_[nextSlot - 1];
}


Composer& Database :: getComposer(string lastName){
    for(int i = 0; i < nextSlot; i++){
        if(composer_[i].LastName() == lastName){
            return composer_[i];
        }
    }
    
    // Composer not found - return a static empty composer
    std :: cout << "Composer with last name '" << lastName << "' not found!" << std :: endl;
    static Composer emptyComposer;
    return emptyComposer;
}

void Database :: displayAll(){
    if(nextSlot == 0){
        std :: cout << "Database is empty!" << std :: endl;
        return;
    }
    
    std :: cout << "=== Database Contents ===" << std :: endl;
    std :: cout << "Total Composers: " << nextSlot << std :: endl << std :: endl;
    
    for(int i = 0; i < nextSlot; i++){
        std :: cout << "Composer #" << (i + 1) << ":" << std :: endl;
        composer_[i].display();
        std :: cout << std :: endl;
    }
}