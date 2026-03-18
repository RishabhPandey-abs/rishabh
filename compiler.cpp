#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

vector<string> tokenize(const string& code) {
    vector<string> tokens;
    string token;

    for (char ch : code) {
        if (isspace(ch) || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            if (ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}') {
                tokens.push_back(string(1, ch));
            }
        } else {
            token += ch;
        }
    }

    if (!token.empty()) tokens.push_back(token);

    return tokens;
}

void lexicalAnalysis(const string& code) {
    cout << "\nLexical Analysis Output:\n";
    vector<string> tokens = tokenize(code);

    for (const auto& t : tokens) {
        cout << "Token: " << t << endl;
    }
}

void syntaxAnalysis(const string& code) {
    cout << "\nSyntax Analysis Output:\n";
    if (code.find(';') != string::npos) {
        cout << "Syntax looks valid (basic check)" << endl;
    } else {
        cout << "Syntax Error: Missing semicolon" << endl;
    }
}

void semanticAnalysis(const string& code) {
    cout << "\nSemantic Analysis Output:\n";
    if (code.find("int") != string::npos && code.find('=') != string::npos) {
        cout << "Basic semantic looks correct" << endl;
    } else {
        cout << "Possible semantic issue" << endl;
    }
}

int main() {
    string code;

    cout << "Enter C/C++ code (single line):\n";
    getline(cin, code);

    lexicalAnalysis(code);
    syntaxAnalysis(code);
    semanticAnalysis(code);

    return 0;
}
