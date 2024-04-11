#include <iostream>
#include <string>
#include <sstream>
#include "list.h"
#include "gameentry.h"

using namespace std;

void handleInteger()
{
    int maxEntry;
    cin >> maxEntry;
    LinkedList<int> list(maxEntry);
    int score;
    while (true) {
        cin >> score;
        if (score < 0)
            break;
        list.add(score);
    }
    list.printReverse();
    cout << list.length() << endl;
}

void handleGameEntry()
{
    int maxEntry;
    cin >> maxEntry;
    LinkedList<GameEntry> list(maxEntry);
    string name;
    int score;
    while (true) {
        cin >> name;
        if (name == "quit")
        {
            break;
        }
        cin >> score;
        list.add(GameEntry(name, score));
    }
    list.print();
    cout << list.length() << endl;
}

int main(void)
{
    handleInteger();
    handleGameEntry();

    return 0;
}