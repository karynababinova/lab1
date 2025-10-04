#include <iostream>
#include <stdexcept>
#include <utility>
#include "Board.h"
#include "calculations.h"
#include "RandomCell.h"
#include "experiment.h"

using namespace std;

int readInt() {
    int value;
    cin >> value;
    if (cin.fail()) {
        throw invalid_argument("Error: expected an integer");
    }
    return value;
}

void input(int& n, int& m) {
    cout << "Enter board size (n): ";
    n = readInt();
    if (n <= 0) {
        throw out_of_range("Board size n must be greater than 0");
    }

    cout << "Enter the amount of cells to choose (m): ";
    m = readInt();
    if (m <= 0) {
        throw out_of_range("The number of chosen cells must be greater than 0");
    }
    if (m > n * n) {
        throw out_of_range("The number of chosen cells must not be greater than the total amount of cells");
    }
}

void output(double average, double median) {
    cout << "Average: " << average << endl;
    cout << "Median: " << median << endl;
}

void chooseCells(int m, RandomCell& rc, Board& board) {
    for (int i = 0; i < m; i++) {
        pair<int, int> xy = rc();
        board.incrementCell(xy);
    }
}

void startExperiment(int n, int m) {
    cout << "Enter the amount of repetitions for the experiment: ";
    int reps = readInt();
    if (reps <= 0) {
        throw out_of_range("The number of repetitions must be greater than 0");
    }
    experiment(n, m, reps);
}

int main() {
    try {
        int n, m;
        input(n, m);

        Board board(n);
        RandomCell rc(n);

        chooseCells(m, rc, board);

        double avg = average(board);
        double mdn = median(board);

        output(avg, mdn);
        startExperiment(n, m);

        return 0;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 0;
    }
}