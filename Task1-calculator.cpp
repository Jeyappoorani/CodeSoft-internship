#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    cout << "Simple Calculator\n";
    cout << "-----------------\n";
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;
    switch(operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << "\n";
            break;
        case '/':
            if(num2 != 0)
                std::cout << "Result: " << num1 / num2 << "\n";
            else
                std::cout << "Error: Division by zero is not allowed.\n";
            break;
        default:
            std::cout << "Invalid operation selected.\n";
    }
    
    return 0;
}
