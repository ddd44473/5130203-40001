#define _CRT_SECURE_NO_WARNINGS
#ifndef LIBR_H
#define LIBR_H

#include <iostream>
#include <cstring>

class MyString {
public:
    char* p_str;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();
    void set_string(const char* str);
    const char* get_string() const;

    // Оператор присваивания
    MyString& operator=(const MyString& other);
};

#endif // LIBR_H
