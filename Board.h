#include <vector>
#include <utility>

class Board {
private:
    int size;
    std::vector<int> multiplicities;

    int coordToIndex(int x, int y) const {
        return x * size + y;
    }

public:
    explicit Board(int n);

    void incrementCell(const std::pair<int, int>& cell);

    int getMultiplicity(int x, int y) const;
    const std::vector<int>& getAllMultiplicities() const;

    int getSize() const { return size; }
};