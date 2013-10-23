PROBLEMY
========

<h1><b>Dodawanie elementów Matrixa</b></h1>

<p><i><h3>OpenMP:</h3></i></p>

N (Threads*100) - jest to zmienna odpowiadająca długości Matrixa. Podczas uruchomiena programu następuje przemnożenie ilości wątków * 100.
W rezultacie otrzymujemy dużego Matrixa.

Threads = 2;
Czas wykonania: 0.333169

Threads = 4;
Czas wykonania: 1.594747

<p><i><h3>sekwencyjny:</h3></i></p>

Matrix[3][3];
Czas wykonania: 0.002781

Matrix[100][100];
Czas wykonania: 0.116085

Matrix[200][200];
Czas wykonania: 0.292558

Matrix[400][400];
Czas wykonania: 1.453480

<u>Wniosek:</u> Program sekwencyjny wykonuje się szybciej niż program w OpenMP.


<h1><b>Mnożenie wektorów</b></h1>
<p><i><h3>MPI:</h3></i></p>

Processors = 2;
Czas wykonania: 0.001204

Processors = 4;
Czas wykonania: 0.002872

Processors = 6;
Czas wykonania: 0.014415

Processors = 8;
Czas wykonania: 0.006724

Processors = 10;
Czas wykonania: 0.005732

<p><i><h3>sekwencyjny</h3></i></p>

Czas wykonania: 0.000060; 0.000036; 0.000089

<u>Wniosek:</u> Program MPI który działa na wielu procesorach, jest wolniejszy od programu sekwencyjnego.


<h1><b>Macierz</b></h1>
<p><i><h3>MPI:</h3></i></p>

Podczas uruchomienia programu podajemy wartość, która określi wielkość naszej macierzy.

Processors = 2; Macierz[4][4];
Czas wykonania: 0.000453

Processors = 2; Macierz[6][6];
Czas wykonania: 0.000499

Processors = 2; Macierz[8][8];
Czas wykonania: 0.000537

Processors = 4; Macierz[4][4];
Czas wykonania: 0.001411

Processors = 4; Macierz[8][8];
Czas wykonania: 0.005341

Processors = 4; Macierz[12][12];
Czas wykonania: 0.001529

Processors = 6; Macierz[6][6];
Czas wykonania: 0.006848

Processors = 6; Macierz[12][12];
Czas wykonania: 0.044477

<p><i><h3>sekwencyjny:</h3></i></p>

Macierz[4][4];
Czas wykonania: 0.000007

Macierz[6][6];
Czas wykonania: 0.000019

Macierz[8][8];
Czas wykonania: 0.000035

Macierz[12][12];
Czas wykonania: 0.000073

<u>Wniosek:</u> Program sekwencyjny jest szybszy od MPI.
