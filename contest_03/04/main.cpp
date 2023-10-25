
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n;
    std::cin.ignore(); // Пропускаем символ новой строки
    std::string line;
    std::getline(std::cin, line);
    std::set<std::string> words1;
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        words1.insert(word);
    }
    std::cin >> m;
    std::cin.ignore(); // Пропускаем символ новой строки
    std::getline(std::cin, line);
    std::set<std::string> words2;
    iss.clear();
    iss.str(line);
    while (iss >> word) {
        words2.insert(word);
    }
    std::set<std::string> common_words;
    std::set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(), std::inserter(common_words, common_words.begin()));
    if (common_words.empty()) {
        std::cout << -1 << std::endl;
    } else {
        for (const std::string& word : common_words) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}