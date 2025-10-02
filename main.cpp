#include <iostream>
#include <vector>
#include "Board.h"
#include "calculations.h"
#include "RandomCell.h"
#include "experiment.h"

using namespace std;

void input(int& n, int& m) {
    cout << "Enter board size (n): ";
    cin >> n;

    cout << "Enter the amount of cells to choose (m): ";
    cin >> m;
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
    int reps;
    cout << "Enter the amount of repetitions for the experiment: ";
    cin >> reps;

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