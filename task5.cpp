#include <iostream>
#include <vector>

class Time {
    int h, m, s;
public:
    Time() : h(0), m(0), s(0) {}
    Time(int h, int m, int s) : h(h), m(m), s(s) {}

    void print() const {
        std::cout << (h < 10 ? "0" : "") << h << ":"
                  << (m < 10 ? "0" : "") << m << ":"
                  << (s < 10 ? "0" : "") << s << "\n";
    }

    bool isNight() const { return h >= 0 && h < 5; }

    bool operator<(const Time& other) const {
        return std::tie(h, m, s) < std::tie(other.h, other.m, other.s);
    }

    bool operator==(const Time& other) const {
        return h == other.h && m == other.m && s == other.s;
    }
};

void printTimes(const std::vector<Time>& times) {
    for (const auto& t : times) t.print();
}

void task5() {
    std::vector<Time> times = {
        {1, 2, 63}, {14, 57, 19}, {7, 32, 20},
        {5, 13, 23}, {10, 19, 45}, {19, 9, 59}
    };

    std::cout << "Все времена:\n";
    printTimes(times);

    std::vector<Time> night;
    for (const auto& t : times) {
        if (t.isNight()) night.push_back(t);
    }

    std::cout << "\nНочные времена:\n";
    printTimes(night);
}
