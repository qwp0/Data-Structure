#include <iostream>
#include <string>
#include <sstream>
#include "list.h"

using namespace std;

int main(void) {
    LinkedList list;
    
    string numbers;
    int number;
    getline(cin, numbers);
    
    istringstream is(numbers);
    while (is >> number) {
        if (number % 2)
            list.append(number);
        else
            list.prepend(number);
    }
    
    list.printReverse();
    cout << list.length() << endl;
    
    return 0;
}