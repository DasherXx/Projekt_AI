#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_pochodna(double x) {
    return x * (1.0 -x);
}

