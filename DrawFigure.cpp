//
// Created by terje on 27.02.2022.
//

#include "DrawFigure.h"
#include <iostream>
#include "PrintMessageHang.h"

using namespace std;

void DrawFigure(int count_attempt = 0) {
    if(count_attempt >= 1)
        PrintHangM("|", false, false);
    else
        PrintHangM("", false, false);

    if(count_attempt >= 2)
        PrintHangM("|", false, false);
    else
        PrintHangM("", false, false);

    if(count_attempt >= 3)
        PrintHangM("o", false, false);
    else
        PrintHangM("", false, false);

    if(count_attempt == 4)
        PrintHangM("/", false, false);

    if(count_attempt == 5)
        PrintHangM("/|", false, false);

    if(count_attempt >= 6)
        PrintHangM("/|\\", false, false);
    else
        PrintHangM("", false, false);

    if(count_attempt >= 7)
        PrintHangM("|", false, false);
    else
        PrintHangM("", false, false);

    if(count_attempt == 8)
        PrintHangM("/ ", false, false);

    if(count_attempt >= 9)
        PrintHangM("/ \\", false, false);
    else
        PrintHangM("", false, false);
    if (count_attempt >= 0 && count_attempt <= 10) {
        PrintHangM("+---------+", false, false);
        PrintHangM("|         |", false, false);
    }
}