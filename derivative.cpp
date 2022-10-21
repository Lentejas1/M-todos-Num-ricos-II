# include <iostream>
# include <cmath>
# include <cstdio>
# include <vector>

using namespace std;

vector<double> function_def(double t){
    vector<double> fv(1E6);
    for (int i = 0; i < fv.size(); i++) {fv[i] = pow(float(i) * t, 2) / 2;}
    return fv;
}

vector<double> derivative(vector<double> fv, double t){
    int steps = int(fv.size());
    vector<double> fp(steps);
    fp[0] = (fv[1] - fv[0]) / t;
    for (int i = 1; i < (steps - 1); i++){
        fp[i] = (fv[i+1] - fv[i-1]) / (2*t);
    }
    fp[steps-1] = (fv[steps-1]- fv[steps - 2]) / t;
    return fp;
}

vector<double> second_derivative(vector<double> fv, double t){
    int steps = int(fv.size());
    vector<double> fpp(steps, 0);
    for (int i = 1; i < (steps - 1); i++){
        fpp[i] = (fv[i+1] - 2*fv[i] + fv[i-1]) / (pow(t, 2));
    }
    fpp[0] = fpp[1];
    fpp[steps - 1] = fpp[steps - 2];
    return fpp;
}

int main(){
    double x_min = 0, x_max = 100;
    double t = (x_max - x_min) / double(10E5);
    vector<double> fv;
    vector<double> f = function_def(t);
    vector<double> fp = derivative(f, t);
    vector<double> fpp = second_derivative(f, t);

    int steps = int(f.size());
    FILE* csv;
    csv = fopen("derivatives.csv", "w" );
    fprintf(csv, "f(x), f'(x), f\"(x)\n");
    for (int i = 0; i < steps; i++){

        fprintf(csv, "%f,%f,%f \n", f[i] , fp[i] , fpp[i]);

    }

    fclose(csv); //Closes the file
    return 0;
}