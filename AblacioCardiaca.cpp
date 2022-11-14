#include <iostream>
#include <cstdio>
#include <cmath>
#define N 200

using namespace std;

double T[N][N];
double Tc = 36.5 + 273.15;
double t_ = 0.1, z0 = 0.5, h = 2, t0 = 0.1;
double z = h/z0;

double dz = 0.1, dt = 0.51* pow(dz, 2), ta = 0.025;

int main(){
    for (int i = 0; i < N; i++){
        T[i][0] = Tc;
        T[0][i] = Tc;
        T[N-1][0] = Tc;
    }


    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            T[i][j-1] = dt / (pow(dz, 2)) * (T[i-1][j] - 2 * T[i-1][j-1] + T[i-1][j-2]) + dt + T[i-1][j-1];
        }
    }


    for (int i = 0; i < N; i++){
        T[i][0] = Tc;
        T[0][i] = Tc;
        T[N-1][0] = Tc;
    }


    FILE* txt;

    txt = fopen("Ablacio.txt", "w");

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N ; i++) {
            fprintf(txt, "%lf,", T[i][j]);
            }
        fprintf(txt, "\n");
    }

    fclose(txt);
}
