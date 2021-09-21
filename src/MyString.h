#include <iostream>
#pragma once
class MyString
{
    public:
        char symbol;
        MyString* next;
        MyString* previous;
        MyString()
        {
            next = nullptr;
            previous = nullptr;
        }
};