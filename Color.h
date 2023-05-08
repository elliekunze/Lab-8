//
// Created by Ellie Kunze on 11/18/22.
//
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
using namespace std;

class Color {
private:

    string nameCol;
    string hexV;
    unsigned char green_;
    unsigned char blue_;
    unsigned char red_;

public:
    virtual void SetValue(int value);
    void SetName (const char* nameCol);

    string decToHex(unsigned char decChar) const;
    unsigned char GetR() const;
    unsigned char GetB() const;
    unsigned char GetG() const;
    string GetHexValue() const;
    string GetName() const;

};



