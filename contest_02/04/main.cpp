
std::tuple<long long, long long> reduce(long long a, long long b) {
    long long x = a;
    long long y = b;
    a = std::abs(a);
    b = std::abs(b);
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    a = a + b;
    return std::make_tuple(x / a, y / a);
}

std::tuple<long long, long long, long long> find_lcm(long long a, long long b) {
    long long m;
    long long n;
    std::tie(m, n) = reduce(a, b);
    long long res = (a * b) / (a / m);

    return std::make_tuple(res, res / a, res / b);
}