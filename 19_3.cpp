#include <iostream>
#include <sstream>

double totalResult (double num1, char action, double num2)
{
    if (action == '+') return num1 + num2;
    else if (action == '-') return num1 - num2;
    else if (action == '*') return num1 * num2;
    else return num1 / num2;
}

int main() {
    std::cout << "Enter an example (first number,\naction sign (+, -, *, /),\nsecond number without space)\n";
    std::stringstream temp;
    std::string example;
    std::cin >> example;
    double num1;
    double num2;
    char action;

    temp << example;
    temp >> num1 >> action >> num2;

    if (num2 == 0 && action == '/') std::cerr << "Can't divide by zero";
    else if (action != '+' && action != '-' && action != '*' && action != '/') std::cerr << "Unknown action";
    else {
        double result = totalResult (num1, action, num2);
        std::cout << num1 << " " << action << " " << num2 << " = " << result << std::endl;
    }
}