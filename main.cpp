#include <iostream>
#include <string>
#include "PrintMessageHang.h"
#include "DrawFigure.h"



using namespace std;

string CorrectWord() {
    char yes_or_no = 'n';
    string correct_word;

    while (yes_or_no != 'y') {

        cout << "Please enter a word for the game" << endl;

        getline(cin, correct_word);

        cout << "You entered: " << correct_word << endl;
        cout << "Are you sure you will use this word? [y/n]: " << endl;
        cin >> yes_or_no;
        getchar();

    } return correct_word;
}

void LoopThroughWord(string to_check, const string& to_compare_with) {
    string letters_correct;
    int count_space{};

    for (int i = 0; i < to_check.length(); ++i) {
        if(to_check[i] == to_compare_with[i]) {
            letters_correct += to_check[i];

            cout    << "The " << i+1 << ". letter is correct: "
                    << to_check[i] << endl
                    << "Letters correct so far" << endl;
        }
        else if(to_check[i] != to_compare_with[i]) {

            for(int j = 0; j <= to_check.length(); j++) {

                if(to_check[i] == to_compare_with[j]){

                    cout    << "The " << i+1 << ". letter is correct" << endl
                            << "And that letter belongs to place: "
                            << j+1
                            << endl
                            << "And the letter is: "
                            << to_compare_with[j]
                            << endl;
                }
            }
        }





    }

    cout << letters_correct;
}





int CheckEqual(string correct_word) {
    string user_word;
    int count_times_guessed = 0;
    char yes_or_no = 'y';

    cout << "Are you ready for a hangman?" << " [y/n]" << endl;
    cin >> yes_or_no;
    cin.clear();

    while (yes_or_no != 'n') {
        PrintHangM("Hang Man", true, true);
        cout << endl << "Please enter your guess" << endl;
        cin >> user_word;

        while (correct_word != user_word) {
            count_times_guessed++;
            PrintHangM("Hang Man", true, true);
            DrawFigure(count_times_guessed);
            cout << endl <<  "Please try again!" << endl;
            cin >> user_word;

        }
        cout << "Congratulations!! You entered correct word" << endl;
        cout << "You want to play again?" " [y/n]" << endl;
        cin >> yes_or_no;
        cin.clear();
    }

    cout << "Hope to see you again soon";
    return 0;
}

int main() {



    //CheckEqual(CorrectWord());

    LoopThroughWord("Trje", "Terje");


    //DrawFigure(11);






    return 0;
}
