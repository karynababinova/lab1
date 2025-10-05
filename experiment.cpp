#include <iostream>
#include <vector>
#include "experiment.h"
#include "calculations.h"

using namespace std;

vector <int> singleExperiment(int n, int m, Board& board, RandomCell& rc) {
    for (int t = 0; t < m; t++) {
        pair<int, int> xy = rc();
        board.incrementCell(xy);
    }
    return board.getAllMultiplicities();
}

double averageInVector(const vector<double>& v) {
    if (v.empty()) {
        return 0;
    }
    double sum = 0;
    for (double a : v) {
        sum += a;
    }
    sum /= v.size();
    return sum;
}

pair <double, double> multipleExperiments(int n, int m, int repeat) {
    vector <double> avgs, meds;
    for (int i = 0; i < repeat; i++) {
        Board board(n);
        RandomCell rc(n);
        vector<int> cells = singleExperiment(n, m, board, rc);
        avgs.push_back(average(board));
        meds.push_back(median(board));
    }
    double avg_avg = 0, med_avg = 0;
    avg_avg = averageInVector(avgs);
    med_avg = averageInVector(meds);
    return { avg_avg, med_avg };
}

void checkRandomness(int n, int m) {
    Board board(n);
    RandomCell rc(n);

    for (int t = 0; t < m; t++) {
        pair<int, int> xy = rc();
        board.incrementCell(xy);
    }

    auto counts = board.getAllMultiplicities();
    cout << "Multiplicities for m = " << m << ": ";
    const int max_display = 10;
    if (counts.size() <= max_display) {
        for (int c : counts)
            cout << c << " ";
    }
    else {
        for (int i = 0; i < 5; i++)
            cout << counts[i] << " ";
        cout << "... ";
        for (int i = counts.size() - 5; i < counts.size(); i++)
            cout << counts[i] << " ";
    }
    cout << endl;
}

void experiment(int n, int m, int repeat) {
    vector<int> ms = { m / 5, m / 4, m / 3, m / 2, m, m * 2, m * 3, m * 4, m * 5 };
    cout << "m/Expected/Average/Median" << endl;
    for (int current_m : ms) {
        auto [avg, med] = multipleExperiments(n, current_m, repeat);
        double exp_avg = (double)current_m / (n * n);
        cout << current_m << "\t" << exp_avg << "\t" << avg << "\t" << med << endl;
    }
    cout << "Randomness check: " << endl;
    for (int current_m : ms) {
        checkRandomness(n, current_m);
    }
}