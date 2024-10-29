#include "Functions.h"

int main() {

    ScoreList Pakistan;
    bool isRunning = true;



    while(isRunning){
        int choice;
        choice = getValidChoice();

        if(choice == 8){
            isRunning = false;
            cout << "\nGoodBye!\n";
        }else if(choice == 1 || choice == 2 || choice == 3){
            int score;
            score = getValidScore();

            if(choice == 1){
                Pakistan.AddScoreAtStart(score);
                cout << "\nInserted " << score << " at Start.\n";
            }else if(choice == 2){
                Pakistan.AddScoreAtEnd(score);
                cout << "\nInserted " << score << " at Last.\n";
            }else if(choice == 3){
                Pakistan.DeleteScore(score);
            }
        }else if(choice == 4){
            cout << endl << endl;
            cout << "\n------------ Linked List (Doubly) ----------------\n";            
            Pakistan.DisplayScoreList();
            cout << endl << endl;

        }else if(choice == 5){
            cout << endl << endl;
            cout << "\n------------ Linked List (Doubly) ----------------\n";
            Pakistan.DisplayReverseScoreList();
            cout << endl << endl;

        }else if(choice == 6){
            cout << "\n\nMax Score: " << Pakistan.getMax() << endl;
        }else if(choice == 7){
            cout << "\n\nMin Score: " << Pakistan.getMin();
        }else {
            cout << "\nTry Again\n";
            cout << "\nInvalid Input!\n";
        }

    }

    cout << endl << endl;
	return 0;
}

