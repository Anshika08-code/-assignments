#include <iostream>
#include <cstring>   
using namespace std;

const int MAX=100   
char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
    } else {
        stack[++top] = c;
    }
}
char pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        push(str[i]);
    }

    cout << "Reversed string: ";
  
    for (int i = 0; i < n; i++) {
        cout << pop();
    }

    cout << endl;
    return 0;
}
