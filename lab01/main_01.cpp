
#include "functions.h"


int main() {
    int exercise;
    cout << "What exercise want you to solve? ";
    cin >> exercise;
    switch (exercise) {
        case 1: {
            for (int i = 0; i <= 127; i++) {
                cout << i << " -> " << countBit(i) << endl;
            }
        }
        case 2: {
            for (int i = 0; i < 35; i++) {
                int n = 0;
                if(setBit(n, i)) {
                    cout << i << "--->" << n << endl;
                }else {
                    cout << "Impossible operation!" << endl;
                }
            }
        }
        case 3: {
            int nrOfElement = 0;
            double arr[nrOfElement] = {};
            cout << "\b\nThe average of the array: " << mean(arr, nrOfElement) << endl;
        }
        case 4: {
            int nrOfElement = 5;
            double arr[nrOfElement] = {1, 2, 3, 4, 5};
            cout << "The standart deviation of the array is: " << stddev(arr, nrOfElement) << endl;
        }
        case 5: {
            double arr1[] = {1.2, 3.5, 6.7, 8.9, 2.1};
            pair<double, double> result = max2(arr1, 5);
            cout << "Array: " << result.first << ", " << result.second << endl;
        }
        case 6: {
            istringstream inputstream("1 2 3 alma 4");
string word;
while(inputstream >> word){
istringstream wordstream(word);
double number;
if( wordstream >> number ) {
cout << word << ": NUMERICAL" << endl;
} else {
cout << word << ": TEXTUAL" << endl;
}
}

        }
        case 8: {
            string originalText = "Hello, World! zZ aA";
            string encodedText = code(originalText);
            cout << "Eredeti: " << originalText << endl;
            cout << "Kodolt: " << encodedText << endl;
            string decodedText = decode(encodedText);
            cout << "Dekodolt: " << decodedText << endl;
        }
        case 9:{
        string line;
    cout << "Give a text:" << endl;

    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        string capitalized = capitalizeWords(line);
        cout << "Transformed text: " << capitalized << endl;
    }
        }
    }



    return 0;
}
