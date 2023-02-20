#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char t) {
    switch (t) {
        case '+':
        case '/':
        case '*':
        case '-':
            return false;
        default:
            return true;
    }
}

unsigned precedence(char t) {
    switch (t) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

string convert(const string &s) {
    string postfix;
    postfix.resize(s.length());

    stack<char> stk;
    int i {0}, j {0};
    while(s[i] != '\0') {
        if(isOperand(s[i])) {
            postfix[j++] = s[i++];
        } else {
            if(stk.empty() || precedence(s[i]) > precedence(stk.top())) {
                stk.push(s[i++]);
            } else {
                postfix[j] = stk.top();
                stk.pop();
                j++;
            }
        }
    }

    while(!stk.empty()) {
        postfix[j] = stk.top();
        stk.pop();
        j++;
    }

    return postfix;
}

int main() {
    string infix = "a+d*f/g";
    string postfix = convert(infix);
    cout << postfix;
    return 0;
}
