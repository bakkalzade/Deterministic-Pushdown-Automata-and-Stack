//
// Created by salih on 15.12.2021.
//

#include "Automata.h"

void Automata::errorCheck(Source &source) {

        //dpa file check
        for (const auto& i: source.getAllTransition()) {

            //cout<<i.getInitState()<<" "<<i.getNextState()<<endl;

            if (Helper::contains(source.getAllStates(), i.getInitState())
                && Helper::contains(source.getAllStates(), i.getNextState())
                && Helper::contains(source.getAllInputs(), i.getRead())
                && Helper::contains(source.getAlphabet(), i.getPop())
                && Helper::contains(source.getAlphabet(), i.getAdd())
                    ) {

                //dpa file has no error
            } else {// no match
                Helper::write(outputFile,"Error [1]:DPDA description is invalid!");
                exit(0);
            }
        }

        //input file chars check
        for (const auto& i: source.getInputChars()) {

            if (Helper::contains(source.getAllInputs(), i)) {

                //input chars are valid
            } else {// no match
                Helper::write(outputFile,"Error [2]:INPUT description is invalid!");
                exit(0);
            }
        }

    }

Transition Automata::findInitTransition(const Source& source, const string& init) {

    Transition transition;

    for(const auto& i : source.getAllTransition()){

        if(i.getInitState()==init){
            transition=i;

        }

    }
    return transition;
}

Transition Automata::findTransition(const Source& source, stack<string> automataStack, const Transition& prev,const string& key) {

    Transition transition;
    for(const auto& i : source.getAllTransition()){

        if (i.getInitState()==prev.getNextState()//is it next state
            )//is pop e or stack's top
        {

            if (!automataStack.empty()){

                if (i.getPop()  == automataStack.top()||i.getPop()=="e"){

                    if ((i.getRead() == key)){
                        transition=i;
                        index++;
                        break;
                    }
                    else if (i.getRead()=="e"){
                        transition=i;
                        break;
                    }
                }

            }else{
                if ((i.getRead() == key)){
                    transition=i;
                    index++;
                    break;
                }
                else if (i.getRead()=="e"){
                    transition=i;
                    break;
                }


            }

        }
    }
    return transition;//it can return null check it
}

void Automata::doTransition(const Transition& transition, stack<string> & s) {


    if (transition.getPop()!="e"){//remove from stack

        s.pop();

    }
    if (transition.getAdd()!="e"){//add to stack

        s.push(transition.getAdd());

    }

    printStackTransition(s,transition);



}

void Automata::printStackTransition(stack<string> s, Transition t) {

    message+= t.toStr()+ printStack(s);

}

string Automata::printStack(stack<string> s) {

    vector<string> vector;

    while (!s.empty()) {

        vector.push_back(s.top());
        s.pop();

    }

    reverse(vector.begin(),vector.end());

    string m;

    for(auto i : vector){

        m+=i;
        m+=",";

    }
    m = m.substr(0,m.size()-1);

    return "[STACK]:"+m+"\n";

}

Automata::Automata(Source source,string file) {


    this->source=std::move(source);
    index=0;
    message="";
    outputFile=file;
}



void Automata::automata() {
    errorCheck(source);



    for (const auto& inputLine : source.getInputLines()){

        stack<string> automataStack;
        index=0;

        vector<string> inputCharVec = Helper::split(inputLine,",");


        Transition inTrans = findInitTransition(source, source.getInitState());

        if(inputCharVec[0].empty())//if input line is empty
        {

            int counter = 0;

            for( const auto& i : source.getFinalStates()){//if initial state is final state
                if (inTrans.getInitState()==i){
                    counter++;
                    break;
                }
            }

            if(counter==0){

                message += "REJECT\n\n";
                continue;

            }else{

                message += "ACCEPT\n\n";
                continue;

            }

        }


        //start state

        if (inTrans.isEmpty()){//if no matched init state
            //cout<<"c\n";

            message += "REJECT\n\n";

            continue;

        }
        if(inTrans.getRead()=="e"){//if init state has "e" as read


            if(inTrans.getAdd()!="e"){

                doTransition(inTrans,automataStack);

            }

        }else if (inTrans.getRead() == inputCharVec[index]){//if it has right char as read

            index++;

            doTransition(inTrans,automataStack);


        }else{//if init state not true

            message += "REJECT\n\n";

            continue;
        }


        prevTrans= inTrans;
        Transition transition;
        bool go= true;

        while(go){

                if (index<inputCharVec.size()){//if input is not ended

                    transition =
                            findTransition(source,automataStack,prevTrans,inputCharVec.at(index));

                }else{

                    transition=
                            findTransition(source,automataStack,prevTrans,"e");


                }

                if(!transition.isEmpty())//while there is a matching transition
                {

                    prevTrans=transition;
                    doTransition(transition,automataStack);


                }else{

                    if (inputCharVec.size()<=index //if input is ended
                    && (automataStack.empty() || (automataStack.size()==1 && automataStack.top()=="$")) //if stack is empty
                    && Helper::contains(source.getFinalStates(),prevTrans.getNextState()))//if it is final state
                    {

                        message+= "ACCEPT\n\n";
                        go= false;

                    }else{

                        message+= "REJECT\n\n";
                        go= false;

                    }

                }

        }



    }
    Helper::write(outputFile,message);

}


