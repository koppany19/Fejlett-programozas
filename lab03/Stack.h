//
// Created by Koppany on 10/7/2024.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"

using namespace std;

class Stack {
public:
    void push(int e);
    int pop();
    bool isEmpty() const;
    void print() const;
private:
    List list;
};



#endif //STACK_H
