#include <iostream>
#include <vector>
#include "experiment.h"
#include "Board.h"
#include "RandomCell.h"
#include "calculations.h"

using namespace std;

vector <int> singleExperiment(int n, int m){
	Board board(n);
	RandomCell rc(n);
	for (int t = 0; t < m; t++) {
		auto [x, y] = rc();
		board.incrementCell(x, y);
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
		vector<int> cells = singleExperiment(n, m);
		avgs.push_back(average(cells));
		meds.push_back(median(cells));
	}
	double avg_avg = 0, med_avg = 0;
	avg_avg = averageInVector(avgs);
	med_avg = averageInVector(meds);
	return { avg_avg, med_avg };
}

void experiment(int n, int m, int repeat) {
	vector<int> ms = { m / 5, m / 4, m / 3, m / 2, m, m * 2, m * 3, m * 4, m * 5 };
	cout << "m\tExpected\tAverage\tMedian" << endl;
	for (int current_m : ms) {
		auto [avg, med] = multipleExperiments(n, current_m, repeat);
		double exp_avg = (double)current_m / (n * n);
		cout << current_m << "\t" << exp_avg << "\t" << avg << "\t" << med << endl;
	}
}