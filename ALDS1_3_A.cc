#include <iostream>
#include <stack>
#include <string>

int main() {
  std::stack<int> stack;
  std::string symbol;

  while (std::cin >> symbol, !std::cin.eof()) {
    if (symbol == "+") {
      int operand1 = stack.top();
      stack.pop();
      int operand2 = stack.top();
      stack.pop();

      stack.push(operand2 + operand1);
    } else if (symbol == "-") {
      int operand1 = stack.top();
      stack.pop();
      int operand2 = stack.top();
      stack.pop();

      stack.push(operand2 - operand1);
    } else if (symbol == "*") {
      int operand1 = stack.top();
      stack.pop();
      int operand2 = stack.top();
      stack.pop();

      stack.push(operand2 * operand1);
    } else {
      stack.push(std::stoi(symbol));
    }
  }

  std::cout << stack.top() << std::endl;
  return 0;
}