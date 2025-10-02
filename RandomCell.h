#pragma once
#include <utility>
#include <random>

class RandomCell {
private:
    int n;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist;

public:
    explicit RandomCell(int size) :
        n(size),
        gen(std::random_device{}()),
        dist(0, size - 1)
    {
        if (n <= 0) throw std::invalid_argument("size must be > 0");
    }

    std::pair<int, int> operator()() {
        return { dist(gen), dist(gen) };
    }
};
