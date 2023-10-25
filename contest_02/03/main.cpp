

bool compare(const std::string& left, const std::string& right) {
    int countLeft = 0, countRight = 0;
    int leftNum = std::stoi(left);
    int rightNum = std::stoi(right);

    for (char digit : left) {
        countLeft += std::abs(digit - '0');
    }
    for (char digit : right) {
        countRight += std::abs(digit - '0');
    }

    if (countLeft == countRight) {
        return leftNum < rightNum;
    }
    return countLeft > countRight;
}