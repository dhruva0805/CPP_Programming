//
// Created by dhruva on 05.08.2023.
//
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <iterator>
#include <fstream>
#include "ManagedObject.h"
using namespace std;

void driverCodeManagedObject();
void learnSet();
void learnMap();
void learnStack();
void countWordsInFile();

int main()
{
    countWordsInFile();
    return 0;
}

void driverCodeManagedObject(){
    int G_COUNT = 10;
    vector<ManagedObject> mos;
    //mos.reserve(G_COUNT);
    char buffer[50];

    for (int i = 0; i < G_COUNT; ++i) {
        sprintf(buffer, "DN=%d", i);
        ManagedObject temp(buffer);
        mos.push_back(temp);
        cout << "Capacity: " << mos.capacity() << ", Size: " << mos.size() << endl;
    }

    try {
        cout << "About t use the subscript operator: " << endl;
        cout << mos.at(G_COUNT + 1).m_id << endl;

    }
    catch (exception& exec){
        cout << exec.what() << endl;
    }

    cout << "The number of objects created with overridden constructor: " << G_CONS << endl;
    cout << "The number of objects created with copy constructor: " << G_COPY_CONS << endl;
}

void learnSet(){
    // set with default sorting order
    set<int> setInts{2,4,6,2,3,9,7};
    copy(setInts.begin(), setInts.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // set with decreasing sorting order
    set<int, greater<>> setIntsGreater{2,4,6,2,3,9,7};
    copy(setIntsGreater.begin(), setIntsGreater.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // unordered set
    unordered_set<int> unSetInts{2,4,6,2,3,9,7};
    copy(unSetInts.begin(), unSetInts.end(), ostream_iterator<int>(cout, " "));
}

void learnMap(){
    //map<int, string> employees;
    unordered_map<int, string> employees;
    employees[61256123] = "Dhruva";
    employees[61256124] = "Kiran";
    employees[61256125] = "Babu";
    employees[61256126] = "Mahesh";

    cout << "Employee name with emp Id 61256123 is " << employees[61256123] << endl;
    cout << "Map size is " << employees.size() << endl;

    for (unordered_map<int, string>::iterator iter = employees.begin(); iter != employees.end(); ++iter)
    {
        pair<int, string> obj = *iter;
        cout << "Key is " << obj.first << " and value is " << obj.second << endl;
    }
}

void learnStack(){
    stack<int> myStack;
}

void countWordsInFile(){
    unordered_map<string, int> wordCount;
    ifstream myFile("/mnt/c/Users/dhshriva/Desktop/Study/C++/CPP_Programming/word.txt");

    string word;
    while(myFile >> word)
    {
        ++wordCount[word];
    }
    for(auto iter = wordCount.begin(); iter != wordCount.end(); ++iter)
    {
        cout << iter->first << " : " << iter->second << endl;
    }

}