
Complex make_complex(std::string num) {
    bool is_minus = false;
    bool is_plus = false;
    std::string first;
    std::string second;
    for (char c : num) {
        if (c == '-') {
            is_minus = true;
            continue;
        }
        else if (c == '+') {
            is_plus = true;
            continue;
        }
        if (!(is_plus || is_minus) && c != ' ') {
            first += c;
        }
        else if ((is_plus || is_minus) && c != ' ') {
            if (first.empty()) {
                first += '-';
                first += c;
                is_minus = false;
                continue;
            }
            second += c;
        }
    }
    double re = std::stod(first);
    double im = std::stod(second);
    if (is_minus) {
        im *= -1;
    }
    return {re, im};
}

Complex sum(const Complex& left, const Complex& right) {
    double f = left.re + right.re;
    double s = left.im + right.im;
    if (left.im + right.im == 0) {
        s = 0.;
    }
    return {f, s};
}

Complex sub(const Complex& left, const Complex& right) {
    return {left.re - right.re, left.im - right.im};
}

Complex mul(const Complex& left, const Complex& right) {
    double f = left.re * right.re - left.im * right.im;
    double s = left.re * right.im + left.im * right.re;
    return {f, s};
}

Complex div(const Complex& left, const Complex& right) {
    double denominator = right.re * right.re + right.im * right.im;
    double f = (left.re * right.re + left.im * right.im) / denominator;
    double s = (left.im * right.re - left.re * right.im) / denominator;
    return {f, s};
}

void print(const Complex& num) {
    double re = num.re;
    double im = num.im;
    std::cout << re;
    if (im >= 0) {
        std::cout << "+";
    }
    std::cout << im << "j\n";
}

