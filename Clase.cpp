#include <iostream>
#include <cstdio>

using namespace std;

#define N 3000000

double predators[N], preys[N];

int main(){
    double dt = 0.000001, k2 = 1.0;

    preys[0] = 0.5, predators[0] = 0.9;



    for (int i = 1; i < N; i++){
        for (i = 1; i < N; i ++) {
            preys[i] = preys[i-1] + dt * preys[i-1]*(1-predators[i-1]) ;
            predators[i] = predators[i-1] + dt * predators[i-1]*(preys[i -1] - k2 );
            }

        //cout << "Preys[" << i << "] = " << preys[i] <<  "\nPredators["<< i <<"] = " << predators[i] << "\n";
    }

    FILE* csv;

    csv = fopen("population.csv", "w");

    fprintf(csv, "Time,Preys,Predators");

    for (int i = 0; i < N; i++){
        fprintf(csv, "\n%lf,%lf,%lf", dt*i, preys[i], predators[i]);
    }

    fclose(csv);
    return 0;
}