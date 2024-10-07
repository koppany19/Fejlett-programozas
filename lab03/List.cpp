//
// Created by Koppany on 10/7/2024.
//

#include "List.h"


List::List() : first(nullptr) {

}

List::~List() {
    cout << "Destructor" << endl;
    while (first != nullptr) {
        Node *temp = first;
        first = first -> next;
        delete temp;
    }
}

bool List::exists(int d) const {
    Node *curr = first;
    while (first != nullptr) {
        if(curr->value == d) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return nodeCounter == 0;
}

void List::insertFirst(int d) {
    first = new Node(d, first);
    ++nodeCounter;
}

int List::removeFirst() {
    if(empty()) {
        cout << "The list is empty!";
        return -1;
    }
    Node *temp = first;
    int removed = temp->value;
    first = first->next;
    delete temp;
    nodeCounter--;
    return removed;
}

void List::remove(int d, DeleteFlag df) {
    Node *current = first;
    Node *prev = nullptr;

    while (current != nullptr) {
        bool found = false;
        switch (df) {
            case DeleteFlag::LESS:
                if(current->value < d ) found = true;
                break;
            case DeleteFlag::EQUAL:
                if(current->value == d) found = true;
                break;
            case DeleteFlag::GREATER:
                if(current->value > d) found = true;
                break;
        }
        if(found) {
            if(prev == nullptr) {
                first = current->next;
            }else {
                prev->next = current->next;
            }
            delete current;
            nodeCounter--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void List::print() const {
    Node *current=first;
    while(current!=nullptr){
        cout<<current->value<<" ";
        current=current->next;
    }
    cout<<endl;
}


