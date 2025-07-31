#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>
using namespace std;

int main() {
    unordered_set<string> keywords = {
        "int", "float", "if", "else", "while", "return", "char", "double", "for"
    };

    string input;
    cout << "Enter a line of code: ";
    getline(cin, input);

    cout << "\n--- Token Output ---\n";

    int i = 0;
    while (i < input.length()) {
        char ch = input[i];

        if (isspace(ch)) {
            i++;
            continue;
        }

        if (isalpha(ch) || ch == '_') {
            string word;
            while (i < input.length() && (isalnum(input[i]) || input[i] == '_')) {
                word += input[i];
                i++;
            }

            if (keywords.count(word))
                cout << "KEYWORD: " << word << endl;
            else
                cout << "IDENTIFIER: " << word << endl;
        }
        else if (isdigit(ch)) {
            string number;
            while (i < input.length() && isdigit(input[i])) {
                number += input[i];
                i++;
            }
            cout << "NUMBER: " << number << endl;
        }
        else if (string("+-*/%=!<>&|^").find(ch) != string::npos) {
            cout << "OPERATOR: " << ch << endl;
            i++;
        }
        else if (string("();{},[]").find(ch) != string::npos) {
            cout << "DELIMITER: " << ch << endl;
            i++;
        }
        else {
            cout << "ERROR: Unknown character '" << ch << "'\n";
            i++;
        }
    }

    return 0;
}