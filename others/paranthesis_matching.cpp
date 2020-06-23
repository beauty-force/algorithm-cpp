/**
 * @file
 * @brief Perform paranthesis matching. \note Do not know the application of
 * this, however.
 * @note Implementation is C-type and does not utilize the C++ constructs
 * @todo implement as a C++ class
 */
#include <iostream>
#ifdef _MSC_VER
#include <string>  // Visual Studio C requires this include
#else
#include <cstring>
#endif

/** check number */
#define MAX 100

//! @{-------------- stack --------------
//! global stack
char stack[MAX];

//! pointer to track stack index
int top_var = -1;

//! push byte to stack variable
void push(char ch) { stack[++top_var] = ch; }

//! pop a byte out of stack variable
char pop() { return stack[top_var--]; }

//! @}-------------- end stack -----------

/** return opening paranthesis corresponding to the close paranthesis
 * @param[in] ch closed paranthesis character
 */
char opening(char ch) {
    switch (ch) {
    case '}':
        return '{';
    case ']':
        return '[';
    case ')':
        return '(';
    case '>':
        return '<';
    }
    return '\0';
}

int main() {
    std::string exp;
    int valid = 1, i = 0;
    std::cout << "Enter The Expression : ";
    std::cin >> exp;

    while (valid == 1 && i < exp.length()) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' || exp[i] == '<') {
            push(exp[i]);
        } else if (top_var >= 0 && stack[top_var] == opening(exp[i])) {
            pop();
        } else {
            valid = 0;
        }
        i++;
    }

    // makes sure the stack is empty after processsing (above)
    if (valid == 1 && top_var == -1) {
        std::cout << "\nCorrect Expression";
    } else {
        std::cout << "\nWrong Expression";
    }

    return 0;
}
