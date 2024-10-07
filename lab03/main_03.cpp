#include <iostream>

#include "List.h"

using namespace std;

int main() {
    List list1;
    for (int i = 0; i < 10; i++) {
        list1.insertFirst(i);
        list1.print();
        cout << endl;
    }
    return 0;
}

