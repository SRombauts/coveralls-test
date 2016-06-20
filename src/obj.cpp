#include "obj.h"

#include <iostream>

obj::obj () :
   mValue(0)
{
}

obj::~obj ()
{
}

void obj::used() const
{
    std::cout << "obj::used()";
}

void obj::unused() const
{
    std::cout << "obj::unused()";
}

