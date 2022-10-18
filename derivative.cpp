# include <iostream>
# include <cmath>
# include <cstdio>

double *function_def(int steps_f, double t){
    auto *f = new double[steps_f];
    for (int i = 0; i < steps_f; i++) {
        f[i] = pow(float(i) * t, 2) / 2;
    }
    return f;
}

double *derivative(const double *func, int step, double t){
    auto *fp= new double[step];
    fp[0] = (func[1] - func[0]) / t;
    for (int i = 1; i < (step - 1); i++){
        fp[i] = (func[i+1] - func[i-1]) / (2*t);
    }
    fp[step-1] = (func[step-1]- func[step - 2]) / t;
    return fp;
}

double *second_derivative(const double * func, int step, double t){
    auto *fpp = new double[step];
    for (int i = 1; i < (step - 1); i++){
        fpp[i] = (func[i+1] - 2*func[i] + func[i-1]) / (pow(t, 2));
    }
    return fpp;
}

int main(){
    int steps = 1E5;
    std::cout << "Primer check-point\n";
    double x_min = 0, x_max = 100;
    double t = (x_max - x_min) / double(steps);

    double *f = function_def(steps, t);
    double *fp = derivative(f, steps, t);
    std::cout << "Segundo check-point\n";
    double *fpp = second_derivative(f, steps, t);
    std::cout << "Tercer check-point, f''(" << steps << ")=" << fpp[steps-1];



    FILE* file;
    file = fopen("derivatives.dat", "w" );
    for (int i = 0; i < 100; i++){

        fprintf(file, "%f \t %f \t %f \n", f[i] , fp[i] , fpp[i]);

    }

    fclose(file); //Closes the file
    return 0;
}