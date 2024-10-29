#pragma Once
#include "Score.h"


class ScoreList {
private:

    Score* head;
    Score* tail;


public:

    ScoreList() {
        head = tail = nullptr;
    }

    ~ScoreList() {
        Score* current = head;
        while (current != nullptr) {
            Score* next = current->getNext();
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

    void AddScoreAtStart(int score) {
        Score* newScore = new Score(score);
        if (head == nullptr) {
            head = tail = newScore;
        }
        else {
            head->setPrev(newScore);
            newScore->setNext(head);
            head = newScore;

        }
    }

    void AddScoreAtEnd(int score) {
        Score* newScore = new Score(score);
        if (head == nullptr) {
            head = tail = newScore;
        }
        else {
            
            tail->setNext(newScore);
            newScore->setPrev(tail);
            tail = newScore;

        }
    }

    void DeleteScore(int score) {
        Score* p = head;

        if (head == nullptr) {
            cout << "\nVoid Deletion\n";
            return;
        }

        bool isDeleted = false;

   
        while (p != nullptr) {
            if (p->getScore() == score) {
                isDeleted = true;

                if (p == head) {
                   
                    head = head->getNext();
                    if (head != nullptr) {
                        head->setPrev(nullptr);
                    }
                }
                else {
                    p->getPrev()->setNext(p->getNext());
                }

                if (p == tail) {
                    tail = tail->getPrev();
                    if (tail != nullptr) {
                        tail->setNext(nullptr);
                    }
                }
                else {
                    if (p->getNext() != nullptr) {
                        p->getNext()->setPrev(p->getPrev());
                    }
                }

                cout << "\nScore Deleted: " << score << endl;
                Score* temp = p; 
                p = p->getNext(); 
                delete temp;
            }
            else {
                p = p->getNext();
            }
        }

        if (!isDeleted) {
            cout << "\nVoid Deletion\n";
        }
    }


    int getMax() {
        int max = head->getScore();
        Score* p = head;
        do {
            if (max < p->getScore()) {
                max = p->getScore();
            }
            p = p->getNext();

        } while (p != nullptr);

        return max;
    }

    int getMin() {
        int min = head->getScore();
        Score* p = head;
        do {
            if (min > p->getScore()) {
                min = p->getScore();
            }
            p = p->getNext();

        } while (p != nullptr);
        return min;
    }

    void DisplayScoreList() {

        if (isEmpty()) {
            cout << "\nList is Empty\n";
            return;
        }

        Score* p = head;
        do{
            cout << p->getScore() << " -> ";
            p = p->getNext();
        } while (p != nullptr);
        cout << "NULL";
    }

    void DisplayReverseScoreList() {
        
        if (isEmpty()) {
            cout << "\nList is Empty\n";
            return;
        }
        Score* p = tail;
        do {
            cout << p->getScore() << " -> ";
            p = p->getPrev();
        } while (p != nullptr);
        cout << "NULL";
    }

    bool isEmpty() {
        return (head == nullptr);
    }

};