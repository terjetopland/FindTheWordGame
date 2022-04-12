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

//legal characters from a-z
string abc() {
    string abc;
    char a = 'a';

    for (int i = 0; i < 26; ++i) {
        abc += (a+i);
    }
    return abc;
}

void StartGame(const string& correctWord, const string& header) {
    string guessed_word;
    string last_guessed_word;
    string combined_word;
    string used_letters;
    int max_guess = 10;
    static int count_times_guessed = 1;

    PrintHangM(header, true, true);
    cout << endl << "Please enter your guess" << endl;
    getline(cin, guessed_word);
    last_guessed_word = guessed_word;

        while (correctWord != combined_word && count_times_guessed < max_guess) {
            combined_word = LoopThroughWord(last_guessed_word, correctWord);
            used_letters = LoopThroughWord(guessed_word+used_letters, abc());
            count_times_guessed++;
            PrintHangM(header, true, true);
            DrawFigure(count_times_guessed-1);
            PrintHangM("CORRECT LETTERS", true, false);
            PrintHangM(LoopThroughWord(combined_word, correctWord), false, true);
            PrintHangM("USED LETTERS", false, false);
            PrintHangM(used_letters, false, true);
            cout << endl << "Please try again!" << endl;
            getline(cin, guessed_word);
            last_guessed_word = last_guessed_word + guessed_word;
            combined_word = LoopThroughWord(last_guessed_word, correctWord);
        }
    if (count_times_guessed < max_guess) {
        PrintHangM(header, true, true);
        DrawFigure(count_times_guessed - 1);
        PrintHangM(LoopThroughWord(combined_word, correctWord), true, true);
        cout << endl << "Congratulations!! You entered correct word" << endl;
        cin.clear();
    }
    else {

        PrintHangM(header, true, true);
        DrawFigure(count_times_guessed +1);
        PrintHangM("Correct word = " + correctWord, true, true);
        cout << endl << "Sorry, the man is hanging!!" << endl;
    }
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

void AddCorrectWord(const string& file_here) {
    ofstream corr_words(file_here, ios::app);
    if (corr_words.is_open()) {
        cout << "corr_words is open" << endl;
        string n_word;
        cout << "Please enter a new word" << endl;
        cin >> n_word;

        corr_words << "\n";
        corr_words << n_word;
        corr_words.close();
    } else
        cout << "Couldn't open file" << endl;
}

int Mmeny() {
    char yes_or_no = 'y';
    cout << "Are you ready for a hangman?" << " [y/n]" << endl;
    cin >> yes_or_no;
    cin.clear();
    if ( yes_or_no == 'n' || yes_or_no == 'N')
        return 0;


}

int main() {

    StartGame(GetRandomWord("correctWords.txt"), "Guess the word/words");

    return 0;
}