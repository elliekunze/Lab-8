//
// Created by Ellie Kunze on 11/18/22.
//
using namespace std;
#include "Color.h"

unsigned char Color::GetB() const {
    return blue_;
}
unsigned char Color::GetR() const {
    return red_;
}
unsigned char Color::GetG() const {
    return green_;
}
void Color::SetName(const char *nameCol) {
    this -> nameCol = nameCol;
}

void Color::SetValue(int value) {
    blue_ = value; //blue is already at 0
    green_ = value >> 8; //right shift by 3
    red_ = value >> 16; //right shift by 16
}

string Color::GetHexValue() const {
    string valHex = "0x";
    valHex += decToHex((red_ / 16));
    valHex += decToHex((red_ % 16));
    valHex += decToHex((green_ / 16));
    valHex += decToHex((green_ % 16));
    valHex += decToHex((blue_ / 16));
    valHex += decToHex((blue_ % 16));
    return valHex;
}

string Color::GetName() const {
    return nameCol;
}

string Color::decToHex(unsigned char decChar) const {
    int decValue = int(decChar);
//    string hex;
//    int temp = 0;
//    while (decValue != 0) {
//        temp = decValue % 16;
//        if (temp < 10)
//            hex += to_string(temp);
//         else {
//            switch (temp) {
//                case 10:
//                    hex += "A";
//                    break;
//                case 11:
//                    hex += "B";
//                    break;
//                case 12:
//                    hex += "C";
//                    break;
//                case 13:
//                    hex += "D";
//                    break;
//                case 14:
//                    hex += "E";
//                    break;
//                case 15:
//                    hex += "F";
//                    break;
//            }
//        }
//        decValue /= 16;
//    }
//    for (int i = hex.length(); i >= 0; i--) {
//        cout << hex[i];
//    }
//    //cout << endl;
//    return nullptr;
//}
//

    if ((decValue < 10) && (decValue >= 0)) {
        return to_string(decValue);
    } else {
        if (decValue == 10) {
            return "A";
        }
        if (decValue == 11) {
            return "B";
        }
        if (decValue == 12) {
            return "C";
        }
        if (decValue == 13) {
            return "D";
        }
        if (decValue == 14) {
            return "E";
        }
        if (decValue == 15) {
            return "F";
        }
    }
    return 0;


}