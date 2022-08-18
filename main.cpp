#include <iostream>
#include "Helper.h"
#include "Source.h"
#include "Automata.h"
using namespace std;



int main(int argc, char *argv[]) {

    string dpaFile = argv[1];
    string inputFile = argv[2];
    string outputFile = argv[3];

    vector<string> allDpa =    Helper::readFile(dpaFile);
    vector<string> allInput =    Helper::readFile(inputFile);

    Source source(allDpa,allInput);//create all the given data and design properly

    Automata automata(source,outputFile);

    automata.automata();

    Transition t;



    /*
for(auto i : source.getInputLines()){


    vector<string> a = Helper::split(i,",");
    if(a.size()==1){
        cout<<"sa"<<a[0]<<"sa";
    }


}
*/





/*
    stack<int> a ;
    a.push(9);
    a.push(9);
    a.push(9);
    a.push(4);
  */

    /*
    for(auto i: source.getInputChars())
        cout<<i<<endl;

     */
    /*
    for(auto i : allDpa){
        cout<<i<<endl;
    }*/
    /*
    for(auto i :allInput){
        cout<<i<<endl;
    }
    */
    /*
    vector<string> s;

    s.push_back("1");
    s.push_back("2");
    s.push_back("3");
    s.push_back("4");
    s.push_back("5");
    s.push_back("6");
    s.push_back("7");

    s.erase(s.begin(),s.begin()+3);

    for(auto i : s){
        cout<<i<<endl;
    }*/



}
