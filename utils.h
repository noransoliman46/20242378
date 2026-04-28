#pragma once
#include <iostream>
#include <string>
#include <limits>
using namespace std;
//  HELPERS

void flushInputStream() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string promptReadLine(const string& caption) {
    string userText;
    cout << caption;
    getline(cin, userText);
    return userText;
}

int promptReadInt(const string& caption) {
    int val;
    cout << caption;
    while (!(cin >> val)) {
        cin.clear();
        flushInputStream();
        cout << "  Invalid. Enter a number: ";
    }
    flushInputStream();
    return val;
}
