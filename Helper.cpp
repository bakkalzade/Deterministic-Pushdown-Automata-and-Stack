//
// Created by salih on 8.12.2021.
//

#include "Helper.h"

vector<string> Helper::split(string s, string delimiter) {

    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

vector<string> Helper::readFile(const string &file) {
    vector<string> allLines;

    string myText;

    // "../" to absolute path
    ifstream MyReadFile(file);


    while (getline (MyReadFile, myText)) {

        allLines.push_back(myText);

    }

    MyReadFile.close();

    return allLines;
}

bool Helper::contains(vector<string> a, string i) {

   a.push_back("e");
   a.push_back("");
   a.push_back("\r");

    if (std::find(a.begin(), a.end(), i) != a.end()) {
        return true;
    }
    else {// no match
    //    std::cout<<i;
        return false;
    }
}

void Helper::write(string fileName, string message) {

    // Create and open a text file
    ofstream MyFile(fileName);

    // Write to the file
    MyFile << message;

    // Close the file
    MyFile.close();
}


