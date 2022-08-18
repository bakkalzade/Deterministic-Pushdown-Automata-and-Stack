//
// Created by salih on 15.12.2021.
//

#ifndef ASS3_AUTOMATA_H
#define ASS3_AUTOMATA_H
#include "Source.h"

class Automata {

public:



    int index;
    Source source;
    string message;
    Transition prevTrans;
    string outputFile;

    Automata(Source source,string File);

    void automata();
private:


    Transition currentTransition;
    Transition nextTransition;

    bool first(stack<string> &automataStack,vector<string> inputCharVec);



        void errorCheck(Source &source);

     Transition findInitTransition(const Source& source, const string& init);

     Transition findTransition(const Source& source, stack<string> automataStack,const Transition& prev,const string& key);

     void doTransition(const Transition& transition, stack<string> &s);

     void printStackTransition(stack<string> s, Transition t);

     string printStack(stack<string>stack);

     //bool initState(vector<string> inputCharVec, stack<string> automataStack);
};



#endif //ASS3_AUTOMATA_H
