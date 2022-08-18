//
// Created by salih on 8.12.2021.
//

#include "Source.h"

Source::Source(vector<string> allDpa, vector<string> allInput) {


    //all state
    string a = Helper::split(Helper::split(allDpa[0],":")[1],"=>")[0];
    string b = a.substr(0,a.size()-1);//delete the last " "
    allStates = Helper::split(b,","); //all the given states

    //init state
    string temp_initState = Helper::split(Helper::split(Helper::split(allDpa[0],":")[1],"=>")[1],",")[0];// with form (q0)

    initState = temp_initState.substr(2,temp_initState.size()-3); //from " (q0)" to "q0" transition

    //final States
    vector<string> temp_finalStates =Helper::split(Helper::split(Helper::split(allDpa[0],":")[1],"=>")[1],",");

    temp_finalStates.erase(temp_finalStates.begin());//remove the first item which is initial state



    vector<string> all_finalStates;

    for(auto i: temp_finalStates){

        string temp = i.substr(1,i.size()-2);
        all_finalStates.push_back(temp);

    }
    finalStates = all_finalStates;

    //all possible inputs chars
    allInputs = Helper::split(Helper::split(allDpa[1],":")[1],",");

    //alphabet
    alphabet = Helper::split(Helper::split(allDpa[2],":")[1],",");

    //all transitions
    vector<string> trans = allDpa;

    trans.erase(trans.begin(),trans.begin()+3);//remove the first 3 lines


    //create transition instances...
    for(auto i : trans){

        Transition transition(i);
        allTransition.push_back(transition);

    }
    //design input file
    for(auto i : allInput){

        inputLines.push_back(i);

        vector<string> chars = Helper::split(i,",");

        for (auto j : chars){//gather the whole given chars to compare with the possibles

            if(std::find(inputChars.begin(), inputChars.end(), j) != inputChars.end()){

            }
            else{
                inputChars.push_back(j);
            }
        }
    }

}

const vector<string> &Source::getAllStates() const {
    return allStates;
}

const string &Source::getInitState() const {
    return initState;
}

const vector<string> &Source::getFinalStates() const {
    return finalStates;
}

const vector<string> &Source::getAllInputs() const {
    return allInputs;
}

const vector<string> &Source::getAlphabet() const {
    return alphabet;
}

const vector<Transition> &Source::getAllTransition() const {
    return allTransition;
}

const vector<string> &Source::getInputLines() const {
    return inputLines;
}

const vector<string> &Source::getInputChars() const {
    return inputChars;
}

Source::Source() {

}
