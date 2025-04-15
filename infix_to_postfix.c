#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to determine operator precedence
int precedence(char op) {
    if (op == '^') {
        return 3;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

// Function to apply an operator
double apply_operator(double operand1, double operand2, char operator) {
    if (operator == '+') {
        return operand1 + operand2;
    }
    if (operator == '-') {
        return operand1 - operand2;
    }
    if (operator == '*') {
        return operand1 * operand2;
    }
    if (operator == '/') {
        return operand1 / operand2;
    }
    if (operator == '^') {
        return pow(operand1, operand2);
    }
    return 0.0; // Default return value
}

// Function to convert infix to postfix
char* infix_to_postfix(const char* expression) {
    int length = strlen(expression);
    char* output = (char*)malloc((length + 1) * sizeof(char)); // Allocate space for output string
    char* stack = (char*)malloc(length * sizeof(char)); // Allocate space for stack
    int top = -1; // Stack top index
    int output_index = 0; // Index for output string

    for (int i = 0; i < length; i++) {
        c
