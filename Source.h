//
// Created by salih on 8.12.2021.
//

#ifndef ASS3_SOURCE_H
#define ASS3_SOURCE_H
#include "iostream"
#include "vector"
#include "algorithm"
#include "Transition.h"
#include "Helper.h"
#include "stack"

using namespace std;

class Source {

private:

    vector<string> allStates;
    string initState;
    vector<string> finalStates;
    vector<string> allInputs;//possible input chars
    vector<string> alphabet;
    vector<Transition> allTransition;
    vector<string> inputLines;
    vector<string> inputChars;//given input chars


public:
    Source(vector<string> allStr, vector<string> allInput);

    Source();
    const vector<string> &getAllStates() const;

    const string &getInitState() const;

    const vector<string> &getFinalStates() const;

    const vector<string> &getAllInputs() const;

    const vector<string> &getAlphabet() const;

    const vector<Transition> &getAllTransition() const;

    const vector<string> &getInputLines() const;

    const vector<string> &getInputChars() const;

};


#endif //ASS3_SOURCE_H
