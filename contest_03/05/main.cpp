#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::map<std::string, int> wordCount;
    std::string word;
    

    for (int i = 0; i < n; i++) {
        std::cin >> word;
        wordCount[word]++;
    }

    int maxCount = 0;

    for (const auto& pair : wordCount) {
        maxCount = std::max(maxCount, pair.second);
    }

    std::vector<std::string> mostFrequentWords;
    

    for (const auto& pair : wordCount) {
        if (pair.second == maxCount) {
            mostFrequentWords.push_back(pair.first);
        }
    }
    
    std::sort(mostFrequentWords.begin(), mostFrequentWords.end());

    
    for (const std::string& frequentWord : mostFrequentWords) {
        std::cout << frequentWord << " ";
    }
    
    return 0;
}