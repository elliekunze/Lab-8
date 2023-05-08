#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <sstream>
#include "Color.h"

using namespace std;

void ReadFile(const char *filename, map<string, Color> &colors);

void PrintColors(const map<string, Color> &colors);

void PrintColor(const Color &color);

void SearchForColor(map<string, Color> &colors);

int main() {
    cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
    cout << "7. Load all 6 files" << endl;
    int choice;
    cin >> choice;

    map<string, Color> colors;
    if (choice >= 1 && choice <= 6) {
        string file = "colors" + to_string(choice) + ".txt";
        ReadFile(file.c_str(), colors);
    } else if (choice == 7) {
        for (int i = 1; i <= 6; i++) {
            string file = "colors" + to_string(i) + ".txt";
            ReadFile(file.c_str(), colors);
        }

    }
    // Secondary menu
    cout << "1. Show all colors" << endl;
    cout << "2. Search for a color" << endl;
    cin >> choice;

    if (choice == 1)
        PrintColors(colors);
    else if (choice == 2)
        SearchForColor(colors);
    return 0;
}

void ReadFile(const char *filename, map<string, Color> &colors) {
    ifstream file;
    file.open(filename);
    string fileLine;
    Color color_;
    string nameColor;
    int colorInfo;
    if (file.is_open()) {
        while (!file.eof()) {
            stringstream parse(fileLine);
            file >> nameColor;
            color_.SetName(nameColor.c_str());
            file >> colorInfo;
            color_.SetValue(colorInfo);
            colors.emplace(nameColor, color_);
        }
    }
}

void PrintColors(const map<string, Color> &colors) {
    int colorCount = 0;
    map<string, Color>::const_iterator iter;
    for (iter = colors.begin(); iter != colors.end(); iter++) {
        PrintColor(iter -> second);
        colorCount++;
    }
    cout << "Number of colors: " << colorCount << endl;
}

void SearchForColor(map<string, Color> &colors) {
    string findColor;
    cin >> findColor;
    if(colors.find(findColor) != colors.end()){
        PrintColor(colors.find(findColor)->second);
    }
    else {
        cout << findColor << " not found!" << endl;
    }
}

void PrintColor(const Color &color) {
    cout << left << setw(20) << color.GetName();
    cout << right << setw(10) << color.GetHexValue();
    cout << "\t\t" << (int) color.GetR() << "," << (int) color.GetG() << "," << (int) color.GetB() << endl;
}
