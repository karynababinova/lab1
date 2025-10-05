#pragma once
#include <vector>
#include "Board.h"
#include "RandomCell.h"

using namespace std;

void experiment(int n, int m, int repeat);
vector <int> singleExperiment(int n, int m, Board& board, RandomCell& rc);
double averageInVector(const vector<double>& v);
pair <double, double> multipleExperiments(int n, int m, int repeat);
void checkRandomness(int n, int m);