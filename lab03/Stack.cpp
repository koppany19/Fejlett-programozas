//
// Created by Koppany on 10/7/2024.
//

#include "Stack.h"
#include <stdexcept>


void Stack::push(int e) {
    list.insertFirst(e);
}

int Stack::pop() {
    if(list.empty()) {
        throw exception();
    }
    return list.removeFirst();
}

bool Stack::isEmpty() const {
    return list.empty();
}

void Stack::print() const {
    list.print();
}
