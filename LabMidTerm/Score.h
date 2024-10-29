#pragma Once
#include<iostream>
#include<sstream>

using namespace std;

class Score {
private:
    int score;
    Score* next;
    Score* prev;

public:
    Score(int score) {
        this->score = score;
        next = prev = nullptr;
    }


    int getScore() {
        return score;
    }

    void setScore(int score) {
        this->score = score;
    }

    Score* getNext() {
        return next;
    }


    void setNext(Score* next) {
        this->next = next;
    }


    Score* getPrev()  {
        return prev;
    }

    void setPrev(Score* prev) {
        this->prev = prev;
    }
};
