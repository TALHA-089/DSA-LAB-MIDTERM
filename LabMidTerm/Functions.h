#pragma Once

#include "ScoreList.h"

int getValidScore();
int getValidChoice();
void MainMenu();

int getValidScore() {
    int x;
    string X;
    bool isValidScore = false;
    do {
        string Filter;
        int digitcounter = 0;
        cout << "\nEnter Score: ";
        getline(cin, X);


        for (int i = 0; i < X.length(); i++) {
            char c = X[i];
            if (isdigit(c)) {
                Filter += c;
                digitcounter++;
            }
        }

        if (digitcounter > 0) {
            isValidScore = true;
            stringstream(Filter) >> x;
        } else {
            isValidScore = false;
            cout << "\nInvalid Input!\n";
            cout << "\nTry Again!\n";
        }
    } while (!isValidScore);

    return x;
}

void MainMenu(){

    cout << "\n------------ Linked List (Doubly) ----------------\n";
    cout << "\n1.At Scores at Start";
    cout << "\n2.At Scores at Last";
    cout << "\n3.Delete All Occurunces of a Score";
    cout << "\n4.Display Scores";
    cout << "\n5.Display Scores in Reverse";
    cout << "\n6.Find Highest Score";
    cout << "\n7.Find Lowest Score";
    cout << "\n8.Exit";
    cout << "\n\nEnter your Choice: ";
}

int getValidChoice() {
    int x;
    string X;
    bool isValidChoice = false;

    do {
        MainMenu();
        getline(cin, X);

        string Filter;

        for (int i = 0; i < X.length(); i++) {
            char c = X[i];
            if (isdigit(c)) {
                Filter += c;
            }
        }

        stringstream(Filter) >> x;

        if (x >= 1 && x <= 8) {
            isValidChoice = true;
        } else {
            isValidChoice = false;
            cout << "\nInvalid Input!\n";
            cout << "\nTry Again!\n";
        }
    } while (!isValidChoice);

    return x;
}