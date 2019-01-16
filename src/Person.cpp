#include <iostream>
#include <string>
#include "Person.h"

Person::Person(string name)
{
    this->name = name;
}

// Accessors
string Person::getName()    { return name; }
