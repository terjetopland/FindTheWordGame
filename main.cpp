#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>


#include "PrintMessageHang.h"
#include "DrawFigure.h"
#include "LoopThroughWord.h"

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

void StartGame(const string& correctWord) {
    string guessed_word;


        PrintHangM("Hang Man", true, true);
        cout << endl << "Please enter your guess" << endl;
        cin >> guessed_word;

        while (correctWord != guessed_word) {
            count_times_guessed++;
            PrintHangM("Hang Man", true, true);
            DrawFigure(count_times_guessed);
            PrintHangM(LoopThroughWord(guessed_word, correctWord), true, true);
            cout << endl << "Please try again!" << endl;
            cin >> guessed_word;
        }

        PrintHangM("Hang Man", true, true);
        DrawFigure(count_times_guessed - 1);
        PrintHangM(LoopThroughWord(guessed_word, correctWord), true, true);
        cout << endl << "Congratulations!! You entered correct word" << endl;
        cin.clear();
}

string GetRandomWord(const string& from_file) {
    int count_lines {};
    string word;
    vector<string> v_word;
    ifstream read (from_file);
    if(read.is_open()){
        while (getline(read, word)) {
            v_word.push_back(word);

            count_lines++;
        }

    } else
        cout << "couldn't open file" << endl;

    read.close();
    srand(time(nullptr));
    int index = rand() % v_word.size();
    word = v_word[index];


 return word;
}

int Mmeny() {
    char yes_or_no = 'y';
    cout << "Are you ready for a hangman?" << " [y/n]" << endl;
    cin >> yes_or_no;
    cin.clear();
    if(yes_or_no == 'y' || yes_or_no == 'Y') {
        StartGame(GetRandomWord("correctWords.txt"));
    }
    if ( yes_or_no == 'n' || yes_or_no == 'N')
        return 0;


}
int main() {

    Mmeny();

    //CorrectWord();
    //StartGame(GetRandomWord("correctWords.txt"));

    //cout << GetRandomWord("correctWords.txt");

   /*
    std::ifstream corr_words;
    corr_words.open("correctWords.txt");

    if (corr_words.is_open())
        cout << "File is opened" << endl;
    */











    return 0;
}