//
// Created by terje on 01.03.2022.
//

#include "LoopThroughWord.h"
string LoopThroughWord(const string& to_check, const string& to_compare_with) {
    string correct_answer_so_far;
    for (int i = 0; i < to_compare_with.length(); ++i) {
        if (to_check.find(to_compare_with[i]) == string::npos){
            correct_answer_so_far += "_";
        }
        else
            correct_answer_so_far += to_compare_with[i];

    }

    return correct_answer_so_far;
}