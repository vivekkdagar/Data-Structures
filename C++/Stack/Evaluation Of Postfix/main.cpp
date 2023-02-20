#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

unsigned OutPre(char t) {           // Precedence outside of stack
    switch (t) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '^':
            return 6;
        case '(':
            return 7;
        case ')':
            return 0;
        default:
            return -1;
    }
}

unsigned InPre(char t) {           // Precedence inside of stack
    switch (t) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5;
        case '(':
            return 0;
        default:
            return -1;
    }
}

bool isOperand(char t) {
    switch (t) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case ')':
        case '(':
            return false;
        default:
            return true;
    }
}

unsigned countBkt(const string& t) {
    unsigned count = 0;
    for (char i: t)
        if (i == '(' || i == ')')
            count++;
    return count;
}

string InfixToPostfix(string infix) {
    stack<char> stk;
    string postfix;
    postfix.resize(infix.length() - countBkt(infix));
    int j = 0;
    for (int i{0}; infix[i] != '\0';) {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (!isOperand(infix[i])) {
            if (stk.empty() || OutPre(infix[i]) > InPre(stk.top())) {
                stk.push(infix[i++]);
            } else if (OutPre(infix[i]) == InPre(stk.top())) {
                stk.pop();
                i++;
            } else {
                if (stk.top() != '(') {
                    postfix[j++] = stk.top();
                    stk.pop();
                }
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

int eval(string postfix) {
    stack<int> stk;
    int result = 0;
    for(int i{0}; postfix[i] != '\0';) {
        if(isOperand(postfix[i])){
            stk.push(postfix[i] - '0');
            i++;
        }
        else {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            char op = postfix[i];
            switch(op) {
                case '+':
                    result = b+a;
                    break;
                case '-':
                    result = b-a;
                    break;
                case '/':
                    result = b/a;
                    break;
                case '*':
                    result = b*a;
                    break;
                case '^':
                    result = pow(b, a);
                    break;
            }
            stk.push(result);
            i++;
        }
    }
    return stk.top();
}

int main() {
   cout << eval(InfixToPostfix("(5*(6/2)^4)"));
}
