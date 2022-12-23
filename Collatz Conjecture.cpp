/*
Collatz Conjecture
Created by Kazvin
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    double Number;
    int SequenceNumber = 1;
    string IncludeSequenceNumber;
    cout << "Enter your number: ";
    cin >> Number;
    cout << endl << "Include sequence number? (Y or N) " << endl;
    cin >> IncludeSequenceNumber;
    if ((IncludeSequenceNumber == "Y" || IncludeSequenceNumber == "N") == 0) {
        cout << endl << "Invalid Input";
        return 0;
    }
    cout << endl << "Sequence: " << endl;

    for (;;) {
        string StrNumber = to_string(Number);
        size_t DotIndex = StrNumber.find(".");
        StrNumber = StrNumber.substr(0, DotIndex);
        int NumberLength = StrNumber.length();
        int LastNumberIndex = NumberLength-1;
        string LastDigit = StrNumber.substr(LastNumberIndex, NumberLength);

        if (LastDigit == "1" || LastDigit == "3" ||
        LastDigit == "5" || LastDigit == "7" ||
        LastDigit == "9")
            Number = 3 * Number + 1;
        else if (LastDigit == "2" || LastDigit == "4" ||
        LastDigit == "6" || LastDigit == "8" ||
        LastDigit == "0")
            Number = Number / 2;

        if (IncludeSequenceNumber == "N")
            cout << StrNumber << endl;
        else if (IncludeSequenceNumber == "Y")
            cout << SequenceNumber << ". " << StrNumber << endl;

        if (Number == 1) {
            if (IncludeSequenceNumber == "N")
                cout << Number << endl;
            else if (IncludeSequenceNumber == "Y")
                cout << SequenceNumber+1 << ". " << Number << endl;
            break;
        }

        SequenceNumber++;
    }
    cout << endl << "You are now stuck in a 4, 2, 1 loop";
}
