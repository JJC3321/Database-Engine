//------------- Infomation Implementation -------------// 
#include "infomation.h"
#include <iostream>

using std::cout;
using std::endl;

// Constructor
Composer::Composer() {
    firstName_ = "";
    Lastname_ = "";
    age_ = 0;
    email_ = "";
    id_ = 0;
}

// Destructor
Composer::~Composer() {
    // Cleanup if needed
}

// Mutators
void Composer::setFirstName(string firstName) {
    firstName_ = firstName;
}

void Composer::setLastName(string lastName) {
    Lastname_ = lastName;
}

void Composer::setAge(int age) {
    age_ = age;
}

void Composer::setEmail(string email) {
    email_ = email;
}

void Composer::setId(int id) {
    id_ = id;
}

// Accessors
string Composer::firstName() {
    return firstName_;
}

string Composer::LastName() {
    return Lastname_;
}

int Composer::age() {
    return age_;
}

string Composer::email() {
    return email_;
}

int Composer::id() {
    return id_;
}

// Methods

void Composer::display() {
    cout << "Composer Information:" << endl;
    cout << "ID: " << id_ << endl;
    cout << "Name: " << firstName_ << " " << Lastname_ << endl;
    cout << "Age: " << age_ << endl;
    cout << "Email: " << email_ << endl;
}
