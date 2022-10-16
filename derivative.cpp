# include <iostream>
# include <cmath>
# include <cstdio>

using namespace std;

const int steps = 1E4;
double f[steps];
double fp[steps];
double fpp[steps];

double x_min = 0;
double x_max = 100;
const double t =  (x_max - x_min)/ double(steps);

void function_def(int steps_f){
    for (int i = 0; i < steps_f; i++){
        f[i] = pow(float(i)*t, 2) / 2;
    }
}

void derivative(){
    fp[0] = (f[1]- f[0]) / t;
    for (int i = 1; i < (steps - 1); i++){
        fp[i] = (f[i+1] - f[i-1]) / (2*t);
    }
    fp[int(steps)-1] = (f[int(steps)-1]- f[int(steps) - 2]) / t;
}

void second_derivative(){
    for (int i = 1; i < (steps - 1); i++){
        fpp[i] = (f[i+1] - 2*f[i] + f[i-1]) / (pow(t, 2));
    }
}
int main(){

    function_def(steps);
    derivative();
    second_derivative();


    FILE* file;
    file = fopen("derivatives.dat", "w" );
    for (int i = 0; i < 100; i = i+1){

        fprintf(file, "%f \t %f \t %f \t %f \n", i*t, f[i] , fp[i] , fpp[i]);

    }

    fclose(file); //Cerramos el fichero
}