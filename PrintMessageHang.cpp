//
// Created by terje on 27.02.2022.
//

#include "PrintMessageHang.h"
#include <iostream>



void PrintHangM(string message, bool printTop = true, bool printBottom = true) {
    string border_top_bottom = "+-------------------------------+";
    int width_of_sketch = (int)border_top_bottom.length();

    if(printTop) {
        cout << endl << border_top_bottom << endl;
        cout << "|";
    }
    else {
        cout << endl << "|";
    }

    bool front = true;
    for (int i = (int)message.length(); i < (width_of_sketch-2); ++i) {
        if (front) {
            message = " " + message;
        } else {
            message = message + " ";
        }
        front = !front;
    }
    cout << message;

    if (printBottom){
        cout << "|" << endl;
        cout << border_top_bottom;
    }
    else {
        cout << "|";
    }

}