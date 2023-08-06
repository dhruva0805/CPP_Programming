//
// Created by dhruva on 05.08.2023.
//
#include <iostream>
#include <vector>
using namespace std;

int G_CONS = 0;
int G_COPY_CONS = 0;
int G_ASSIG = 0;

class ManagedObject{
public:
    string m_id;

    ManagedObject(const string& str): m_id(str){
        G_CONS++;
    }

    ManagedObject(const ManagedObject& rhs){
        G_COPY_CONS++;
        m_id = rhs.m_id;
    }

    ManagedObject& operator=(ManagedObject rhs){
        G_ASSIG++;
        m_id = rhs.m_id;
        return *this;
    }
};

int G_COUNT = 10;

int main()
{
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
    return 0;
}