#include "Board.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

Board::Board(int n) : size(n) {
    if (n <= 0) throw std::invalid_argument("n must be > 0");
    multiplicities.resize(n * n, 0);
}

void Board::incrementCell(const std::pair<int, int>& cell) {
    int x = cell.first, y = cell.second;
    if (x < 0 || y < 0 || x >= size || y >= size) {
        throw std::out_of_range("indices out of range");
    }
    multiplicities[coordToIndex(x, y)] += 1;
}

int Board::getMultiplicity(int x, int y) const {
    if (x < 0 || y < 0 || x >= size || y >= size)
        throw std::out_of_range("indices out of range");
    return multiplicities[coordToIndex(x, y)];
}

const std::vector<int>& Board::getAllMultiplicities() const {
    return multiplicities;  
}
