#include "MyString.h"
#pragma once
class MainLogic
{
    private:
        MyString* head;
        MyString* tail;
        int fullness;

        void setFromCString(const char* text)
        {
            auto current = head = tail = new MyString();
            fullness = 0;
            if(*text)
            {
                current->symbol = text[0];
                current->next = new MyString();
                current->next->previous = current;
                current = current->next;
                fullness++;
                for (int i = 1; i < strlen(text); ++i) {
                    current->symbol = text[i];
                    tail = current;
                    current->next = new MyString();
                    current->next->previous = current;
                    current = current->next;
                    fullness++;
                }
                current->next = nullptr;
            }
            else
            {
                head = tail = nullptr;
            }
        }
        void deleteList()
        {
            auto current = head;
            MyString* prev;
            while (current != nullptr)
            {
                prev = current;
                current = current->next;
                delete prev;
            }
            fullness = 0;
            head = tail = nullptr;
        }

    public:


        MainLogic(int size)
        {
            head = nullptr;
            tail = nullptr;
            fullness = 0;
        }
        MainLogic(const char* text)
        {
            setFromCString(text);
        }
        MainLogic(const std::string& text)
        {
            setFromCString(text.c_str());
        }
        MainLogic(const MyString& text)
        {
            //TODO
        }
        ~MainLogic()
        {
            deleteList();
        }


        void Concatenate(MyString* text)
        {
            auto current = head;

            while(true)
            {
                if (current != nullptr)
                {
                    current = current->next;
                }
                else
                {
                    break;
                }
            }
            if (text != nullptr)
            {
                while (true)
                {
                    auto currentText = text;
                    if (currentText != nullptr)
                    {
                        current = new MyString();
                        current->symbol = currentText->symbol;
                        current->previous = tail;
                        tail = current;
                        current->previous->next = current;
                        current->next = new MyString();
                        current = current->next;
                        currentText = currentText->next;
                    }

                    if (currentText == nullptr)
                    {
                        break;
                    }
                }
            }

        }






};