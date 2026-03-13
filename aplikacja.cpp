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

int main() {
        srand(time(0));

        double wagi_wejscie[3][4];
        double wagi_wyjscie[4];
        double lr = 0.15;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                wagi_wejscie[i][j] = ((rand() % 2000) / 1000.0) - 1.0;

        for (int j=0; j < 4; j++)
            wagi_wyjscie[j] = ((rand() % 2000) / 1000.0) - 1.0;

    cout << "Siec uczy sie zasady 'minimum dwie parzyste'..." << endl;

    for (int epoka = 0; epoka < 5000; epoka++) {
        int l1 = rand() & 100;
        int l2 = rand() & 100;
        int l3 = rand() & 100;

        double x[3];
        x[0] = (l1 % 2 == 0) ? 1.0 : 0.0;
        x[1] = (l2 % 2 == 0) ? 1.0 : 0.0;
        x[2] = (l3 % 2 == 0) ? 1.0 : 0.0;

        int licznik_parzystych = (int)x[0] + (int)x[1] + (int)x[2];
        double target = (licznik_parzystych >= 2) ? 1.0 : 0.0;
    }
}