//
// Created by PUNPIKORN RATTANAWIROJKUL on 2/19/2016 AD.
//

#include "SyllableReader.h"
#include <iostream>
#include <sstream>

using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc, char* argv[]) {

    char* path = new char;
    clock_t start, end;

    // if (argc > 1) {
        strcpy(path, "~/Desktop/SoftwarePT HW4/SyllableDB-V1.dat");
        cout << "File path: " << path << endl;
    // } else {
        //default
        // cout << "Please enter full path of .dat file" << endl;
        // exit(0);
    // }

    //read file: using SyllableReader library and keep in Trie structure
    SyllableReader::SyllableReader s;
    Trie* trie;
    if (s.readFile(path)) { //return bool to check if things go well
        trie = s.getTrie();
    }

    //read in the text file to vector of search
    ifstream myFile("textInput1000W_v2.txt");
    vector<string> searchList;
    string line;
    string word;
    if (myFile.is_open()) {
        while(getline(myFile, line)) {
            //pick the word part
            word = split(line, ' ').at(3);
            searchList.push_back(word);
        }
    }

    //output file
    ofstream outputFile("searchOutput.txt", std::ofstream::out | std::ofstream::trunc);

    //search
    int found = 0;
    int notFound = 0;
    start = clock();
    for (int i = 0; i < searchList.size(); i++) {
        word = searchList.at(i);
        int result = trie->searchWord(word);
        if (result == -1) {
            outputFile << "NOT FOUND: " << word << endl;
            notFound++;
        } else {
            outputFile << "FOUND    : " << "Text: " << word << ", ID: " << result << endl;
            found++;
        }
    }
    end = clock();

    //write elapsed time
    double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
    outputFile << "Elapsed time = " << elapsed_time << endl;
    outputFile << "Found = " << found << ", Not found = " << notFound;
    outputFile.close();
    cout << "Elapsed time = " << elapsed_time << endl;
    cout << "Found = " << found << ", not found = " << notFound << endl;
    cout << "End of operation, please see searchOutput.txt" << endl;
    cout << "The elapsed time and number of found items will also be shown at the last line of file" << endl;
}
