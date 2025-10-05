#include "calculations.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <numeric>

double average(const Board& board) {
    const auto& allMultiplicities = board.getAllMultiplicities();
    if (allMultiplicities.empty()) {
        throw std::runtime_error("Cannot compute average: board is empty");
    }

    double sum = std::accumulate(allMultiplicities.begin(), allMultiplicities.end(), 0.0);

    return sum / allMultiplicities.size();
}

double median(const Board& board) {
    auto allMultiplicities = board.getAllMultiplicities();
    if (allMultiplicities.empty()) {
        throw std::runtime_error("Cannot compute median: board is empty");
    }

    std::sort(allMultiplicities.begin(), allMultiplicities.end());

    size_t n = allMultiplicities.size();
    size_t middle = n / 2;

    if (n % 2 != 0) {
        return allMultiplicities[middle];
    }
    else {
        size_t leftMiddle = middle - 1;
        size_t rightMiddle = middle;
        return (allMultiplicities[leftMiddle] + allMultiplicities[rightMiddle]) / 2.0;
    }
}