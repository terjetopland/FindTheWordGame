#include <iostream>
#include <string>

#include "PrintMessageHang.h"
#include "DrawFigure.h"

#define lenghtCorrectWord 20




using namespace std;
int count_times_guessed = 0;
string correct_word;


string CorrectWord() {
    char yes_or_no = 'n';

    while (yes_or_no != 'y') {

        cout << "Please enter a word for the game" << endl;

        getline(cin, correct_word);

        cout << "You entered: " << correct_word << endl;
        cout << "Are you sure you will use this word? [y/n]: " << endl;
        cin >> yes_or_no;
        getchar();

    } return correct_word;
}

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


int StartGame(const string& correctWord) {
    string guessed_word;

    char yes_or_no = 'y';

    cout << "Are you ready for a hangman?" << " [y/n]" << endl;
    cin >> yes_or_no;
    cin.clear();

    PrintHangM("Hang Man", true, true);
    cout << endl << "Please enter your guess" << endl;
    cin >> guessed_word;

        while (correctWord != guessed_word) {
            count_times_guessed++;
            PrintHangM("Hang Man", true, true);
            DrawFigure(count_times_guessed);
            PrintHangM(LoopThroughWord(guessed_word, correctWord), true, true);
            cout << endl <<  "Please try again!" << endl;
            cin >> guessed_word;

        }
        PrintHangM("Hang Man", true, true);
        DrawFigure(count_times_guessed-1);
        PrintHangM(LoopThroughWord(guessed_word, correctWord), true, true);
        cout << endl << "Congratulations!! You entered correct word" << endl;
        cin.clear();


    cout << "Hope to see you again soon";
    return 0;
}

int main() {

    cout << LoopThroughWord("eterj", "terje");


  // CorrectWord();

   //StartGame(correct_word);













    return 0;
}