#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

// Funkcja aktywacji
double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }
double sigmoid_pochodna(double x) { return x * (1.0 - x); }

int main() {
    srand(time(0));

    // --- PARAMETRY SIECI ---
    double wagi_wejscie[3][4]; 
    double wagi_wyjscie[4];    
    double lr = 0.15; // Współczynnik uczenia

    // Inicjalizacja wag (losowe wartości bliskie zeru)
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            wagi_wejscie[i][j] = ((rand() % 2000) / 1000.0) - 1.0;

    for (int j = 0; j < 4; j++)
        wagi_wyjscie[j] = ((rand() % 2000) / 1000.0) - 1.0;

    // --- UCZENIE (50 000 powtórzeń dla pewności) ---
    cout << "Siec sie uczy zasady 'minimum dwie parzyste'..." << endl;

    for (int epoka = 0; epoka < 50000; epoka++) {
        // Generujemy losowe 3 liczby do nauki w każdej iteracji
        int l1 = rand() % 100;
        int l2 = rand() % 100;
        int l3 = rand() % 100;

        // Zamiana na wejście binarne (1 = parzysta, 0 = nieparzysta)
        double x[3];
        x[0] = (l1 % 2 == 0) ? 1.0 : 0.0;
        x[1] = (l2 % 2 == 0) ? 1.0 : 0.0;
        x[2] = (l3 % 2 == 0) ? 1.0 : 0.0;

        // Obliczamy poprawny wynik (target) dla tych liczb
        int licznik_parzystych = (int)x[0] + (int)x[1] + (int)x[2];
        double target = (licznik_parzystych >= 2) ? 1.0 : 0.0;

        // --- FORWARD PASS ---
        double hidden[4];
        for (int j = 0; j < 4; j++) {
            double suma = 0;
            for (int i = 0; i < 3; i++) suma += x[i] * wagi_wejscie[i][j];
            hidden[j] = sigmoid(suma);
        }

        double output = 0;
        for (int j = 0; j < 4; j++) output += hidden[j] * wagi_wyjscie[j];
        output = sigmoid(output);

        // --- BACKPROPAGATION ---
        double error = target - output;
        double delta_output = error * sigmoid_pochodna(output);

        double delta_hidden[4];
        for (int j = 0; j < 4; j++)
            delta_hidden[j] = delta_output * wagi_wyjscie[j] * sigmoid_pochodna(hidden[j]);

        // Aktualizacja wag
        for (int j = 0; j < 4; j++) {
            wagi_wyjscie[j] += lr * delta_output * hidden[j];
            for (int i = 0; i < 3; i++)
                wagi_wejscie[i][j] += lr * delta_hidden[j] * x[i];
        }
    }

    cout << "Nauka zakonczona!" << endl;

    // --- TESTOWANIE ---
    while (true) {
        int t1, t2, t3;
        cout << "\nPodaj trzy liczby (np. 2 1 6) lub 0 0 0 by wyjsc: ";
        cin >> t1 >> t2 >> t3;
        if (t1 == 0 && t2 == 0 && t3 == 0) break;

        // Przygotowanie wejścia (tak samo jak przy nauce!)
        double tx[3];
        tx[0] = (t1 % 2 == 0) ? 1.0 : 0.0;
        tx[1] = (t2 % 2 == 0) ? 1.0 : 0.0;
        tx[2] = (t3 % 2 == 0) ? 1.0 : 0.0;

        // Przejście przez sieć
        double h[4], out = 0;
        for (int j = 0; j < 4; j++) {
            double s = 0;
            for (int i = 0; i < 3; i++) s += tx[i] * wagi_wejscie[i][j];
            h[j] = sigmoid(s);
            out += h[j] * wagi_wyjscie[j];
        }
        out = sigmoid(out);

        // Wynik i procenty
        cout << "------------------------------------" << endl;
        cout << "Liczby: " << t1 << ", " << t2 << ", " << t3 << endl;
        cout << "Interpretacja (P=1, N=0): " << tx[0] << ", " << tx[1] << ", " << tx[2] << endl;
        cout << "Wynik sieci: " << (out > 0.5 ? "PRAWDA (min. 2 parzyste)" : "FALSZ") << endl;
        cout << "Pewnosc: " << fixed << setprecision(2) << (out > 0.5 ? out * 100 : (1.0 - out) * 100) << "%" << endl;
        cout << "Raw output: " << out << endl;
        cout << "------------------------------------" << endl;
    }

    return 0;
}