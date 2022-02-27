#include <iostream>
#include <string>
#include "PrintMessageHang.h"
#include "DrawFigure.h"
using namespace std;

string correctWord() {
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




void check_equal(string correct_word) {
    string user_word;

    cout << "Please enter your guess" << endl;
    cin >> user_word;

    while (correct_word != user_word){
        cout << "Please try again!" << endl;
        cin >> user_word;

    }
    cout << "Congratulations!! You entered correct word" << endl;

}

int main() {

    PrintHangM("Hang man", true, true);


    DrawFigure(11);





    return 0;
}
