#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <string>
const int rowSize = 4;
const int colSize = 16;
//typedef string WordArray[rowSize][colSize];
//typedef string Words[colSize];
using namespace std;
//-Function to check for spaces:
bool NoSpace(string Word);
//-Function to return Random Word:
void UnsolvedWord(int, string& Word);
void CorrectWord(int, string& Actual);
//--Game Rules:
void GameRules();
int main()
{
    string Word = "c", Actual = "c";
    char letter;
    int position;
    srand(static_cast<unsigned>(time(0)));
    int random = rand() % 4;// 0 - 3

    GameRules();//Displaying Rules of the game
    cout << endl;
    //call the word functions:
    UnsolvedWord(random, Word);
    cout << "Complete this word:";
    while (!NoSpace(Word))
    {
       cout << Word << endl;
       cout << endl;

       cout << "Enter the position "
            << "you'd like to insert the letter in:";
       cin >> position;
       position = position - 1;
       cout << "Enter the letter you'd like to insert:";
       cin >> letter;
       cout << endl;
       Word[position] = letter;

    }
    CorrectWord(random, Actual);
    cout << endl;
    cout << "Your Results:" << endl;
    if (Word == Actual)
        cout << "Correctly Done!" << endl;
    else
        cout << "Incorrectly Done!" << endl;

    cout << "Your Word: " << Word << endl;
    cout << "The Actual Word: " << Actual << endl;
    return 0;
}

void GameRules()
{
    cout << setw(27) << "Welcome to Word Game:" << endl;
    cout << endl;
    cout << "These are RULES:" << endl;
    cout << "-You can correct your letter position\n"
         << " by inserting a underscore character\n"
         << " in that position of the letter."
         << endl;
    cout << "-You can only enter one letter at a time."
         << endl;
    cout << "-Game ends if there's no space" << endl;
    cout << endl;

    cout << "ENJOY THE GAME!!!" << endl;

}

bool NoSpace(string Word)
{
    int countSpace = 0;
    for (int col = 0; col < colSize; col++)
    {
        if (Word[col] == '_')
            countSpace++;

    }
    if (countSpace != 0)
        return false;
    else
        return true;
}

void UnsolvedWord(int random, string& Word)
{
    char inComplete[rowSize][colSize];
    strcpy(inComplete[0], "L__e");
    strcpy(inComplete[1], "P__c_");
    strcpy(inComplete[2], "_os__i_it_");
    strcpy(inComplete[3], "S__ce_s");

    Word = inComplete[random];
}

void CorrectWord(int random, string& Word)
{
    char Actual[rowSize][colSize];
    strcpy(Actual[0], "Love");
    strcpy(Actual[1], "Peace");
    strcpy(Actual[2], "Positivity");
    strcpy(Actual[3], "Success");

    Word = Actual[random];
}
