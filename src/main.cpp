#include "obj.h"

#include <iostream>

void used_func()
{
    std::cout << "used_func()";
}

void unused_func()
{
    std::cout << "unused_func()";
}

int main()
{
    std::cout << "main()";
    used_func();

    obj o;
    o.used();
    o.inlineUsed();

    return 0;
}
