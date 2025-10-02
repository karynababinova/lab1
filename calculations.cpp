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

    int n = allMultiplicities.size();
    int middle = n / 2;

    if (n % 2 != 0) {
        return allMultiplicities[middle];
    }
    else {
        int leftMiddle = middle - 1;
        int rightMiddle = middle;
        return (allMultiplicities[leftMiddle] + allMultiplicities[rightMiddle]) / 2.0;
    }
}