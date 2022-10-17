# include <iostream>
# include <cmath>
# include <cstdio>

using namespace std;

const int steps = 1E4;
double fpp[steps];
double fp[steps];
double f[steps];
double x_min = 0;
double x_max = 100;
double t =  (x_max - x_min)/ double(steps);

void function_def(int steps_f){
    for (int i = 0; i < steps_f; i++){
        f[i] = pow(float(i)*t, 2) / 2;
    }
}

void derivative(double func[], double t){
    double fp[sizeof(f)];

    fp[0] = (func[1]- func[0]) / t;
    for (int i = 1; i < (steps - 1); i++){
        fp[i] = (f[i+1] - f[i-1]) / (2*t);
    }
    fp[int(steps)-1] = (f[int(steps)-1]- f[int(steps) - 2]) / t;
}

double * second_derivative(double func[], double t){
    // double t = (x_max - x_min) / double(steps);
    for (int i = 1; i < (steps - 1); i++){
        fpp[i] = (func[i+1] - 2*func[i] + func[i-1]) / (pow(t, 2));
    }
    return fpp;
}
int main(){

    function_def(steps);
    derivative(f, t);
    second_derivative(f, t);


    FILE* file;
    file = fopen("derivatives.dat", "w" );
    for (int i = 0; i < 100; i = i+1){

        fprintf(file, "%f \t %f \t %f \t %f \n", i*t, f[i] , fp[i] , fpp[i]);

    }

    fclose(file); //Cerramos el fichero
}