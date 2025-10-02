#pragma once
#include <vector>
#include <Board.h>
#include <RandomCell.h>

using namespace std;

void experiment(int n, int m, int trial);
vector <int> singleExperiment(int n, int m, Board& board, RandomCell& rc);
double averageInVector(const vector<double>& v);
pair <double, double> multipleExperiments(int n, int m, int repeat);