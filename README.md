1. Projekt_AI
Projekt to „Klasyfikator parzystości oparty na sieci neuronowej”. Wyjaśnij krótko cel: program uczy się rozpoznawać regułę logiczną (co najmniej dwie liczby parzyste z trzech podanych).

2. Architektura sieci (Struktura)

Warstwa wejściowa: 3 neurony (dla każdej liczby jeden sygnał 0 lub 1).

Warstwa ukryta: 4 neurony (przetwarzające relacje między danymi).

Warstwa wyjściowa: 1 neuron (wynik końcowy: Prawda/Fałsz).

Funkcja aktywacji: Sigmoid.

3. Instrukcja instalacji (Kompilacja)

Wymagany kompilator C++ (np. MinGW lub wbudowany w Visual Studio).

Polecenie kompilacji (jeśli używa terminala): g++ main.cpp -o Projekt.exe.

4. Instrukcja obsługi (Krok po kroku)
Wyjaśnij, jak korzystać z programu:

Uruchom plik .exe.

Zaczekaj, aż sieć skończy się uczyć (komunikat "Nauka zakończona").

Wpisz trzy liczby (np. 4 7 10) i naciśnij Enter.

Odczytaj wynik i procentową pewność sieci.

Aby wyjść, wpisz 0 0 0.

5. Przykładowe wyniki (Scenariusze testowe)

Wejście 2 4 1 -> Wynik: PRAWDA (2 parzyste).

Wejście 1 3 5 -> Wynik: FAŁSZ (0 parzystych).

Wejście 8 3 11 -> Wynik: FAŁSZ (tylko 1 parzysta).

6. Technologie

Język: C++.

Biblioteki standardowe: iostream, cmath, ctime.

Algorytm: Propagacja wsteczna błędu (Backpropagation).

7. Informacje o autorze
Marcin Kopta 
