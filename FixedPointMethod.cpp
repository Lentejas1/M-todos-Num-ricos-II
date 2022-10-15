#include <iostream>
#include <cmath>

using namespace std;

double initial_point = 0.615;
double epsilon = 0.001;

double f(double x) {
    return exp(x) - 2 * x;
}

double fixed_point_method(){
    double x_fpm = initial_point;
    while(abs(x_fpm - f(x_fpm)) >  epsilon){
        x_fpm = f(x_fpm);
    }
    return x_fpm;
}
int main() {
    cout << "x=" << fixed_point_method();
    return 0;
}
