//
// Created by dhshriva on 07.08.2023.
//

#ifndef CPP_PROGRAMMING_MANAGEDOBJECT_H
#define CPP_PROGRAMMING_MANAGEDOBJECT_H
#include <iostream>
using namespace std;
int G_CONS = 0;
int G_COPY_CONS = 0;
int G_ASSIG = 0;

class ManagedObject {
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


#endif //CPP_PROGRAMMING_MANAGEDOBJECT_H
