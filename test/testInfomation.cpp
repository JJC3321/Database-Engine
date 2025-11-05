//------------- Test case for infomation.h-------------// 

#include <iostream>
#include "infomation.h"

using std :: cout;
using std :: endl; 

int main(){
    
    cout << endl;
    cout << "Testing the Composer class." << endl << endl; 

    Composer composer;

    composer.setFirstName("Jian Jin");
    composer.setLastName("Chen");
    composer.setAge(22);
    composer.setEmail("jianjinchen59@gmail.com");
    composer.display();
    
}
