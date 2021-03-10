#include <iostream>
#include <string>
#include <cmath>

int main() {
  std::string whole;
  std::cout << "Enter the number to the decimal point: \n";
  std::cin >> whole;
  std::string fractional;
  std::cout << "Enter the number after the decimal point: \n";
  std::cin >> fractional;
  double result = std::stod(whole) +
      std::stod(fractional) / pow(10, fractional.length());
  std::cout << "Result = " << result;
}
