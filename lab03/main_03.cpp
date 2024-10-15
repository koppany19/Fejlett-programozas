#include <iostream>

#include "List.h"
#include "Stack.h"

using namespace std;

int main() {
    List list1;
    for (int i = 0; i < 10; i++) {
        list1.insertFirst(i);
        list1.print();
        cout << endl;
    }
    Stack stack;
    for (int i = 0; i < 10; i++) {
        stack.push(i);
    }
    stack.print();
    cout << endl;
    for (int i = 5; i < 8; i++) {
        stack.pop();
    }
    stack.print();
    cout << endl;

    try {
        cout << stack.pop() << endl;
    }
    catch (const exception &e) {
        cout << "Exception was caught!" << endl;
    }
    return 0;
}

