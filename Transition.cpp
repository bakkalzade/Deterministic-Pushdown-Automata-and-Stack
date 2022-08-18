//
// Created by salih on 8.12.2021.
//

#include "Transition.h"

#include <utility>

const string &Transition::getInitState() const {
    return initState;
}

const string &Transition::getRead() const {
    return read;
}

const string &Transition::getPop() const {
    return pop;
}

const string &Transition::getAdd() const {
    return add;
}

const string &Transition::getNextState() const {
    return nexState;
}

Transition::Transition(string allStr) {

    vector<string> all = Helper::split(Helper::split(std::move(allStr),":")[1],",");

    initState=all[0]; read=all[1]; pop = all[2]; nexState = all[3]; add = all[4] ;

}
Transition::Transition() {}

string Transition::toStr() {

    string message =  initState+","+read+","+pop+" => "+nexState+","+add+" ";

    return message;

}

bool Transition::isEmpty() {

    return this->pop.empty();

}
