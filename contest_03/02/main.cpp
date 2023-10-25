#include <iostream>
#include <stack>
#include <string>

std::string checkBracketsBalance(const std::string& text) {
    std::stack<char> brackets;
    for (char c : text) {
        if (c == '(' || c == '{' || c == '[') {
            brackets.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (brackets.empty()) {
                return "NO";
            }
            char lastBracket = brackets.top();
            if ((c == ')' && lastBracket != '(') ||
                (c == '}' && lastBracket != '{') ||
                (c == ']' && lastBracket != '[')) {
                return "NO";
            }
            brackets.pop();
        }
    }
    return brackets.empty() ? "YES" : "NO";
}

int main() {
    std::string text;
    std::getline(std::cin, text, '!');
    std::cout << checkBracketsBalance(text) << std::endl;
    return 0;
}
