//
// Created by salih on 8.12.2021.
//

#ifndef ASS3_TRANSITION_H
#define ASS3_TRANSITION_H
#include "iostream"
#include "vector"
#include "Helper.h"
using namespace std;



class Transition {


private:

    string initState;
    string nexState;
    string read;
    string pop;
    string add;
public:

    Transition(string allStr);
    Transition();

    bool isEmpty();
    const string &getInitState() const;

    const string &getNextState() const;

    const string &getRead() const;

    const string &getPop() const;

    const string &getAdd() const;

    string toStr();

};


#endif //ASS3_TRANSITION_H
