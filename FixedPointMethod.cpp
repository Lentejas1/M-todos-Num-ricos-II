#include <iostream>
#include <cmath>

using namespace std;


// Declaramos que la función nos va a devolver un double y precisa un input double (la x)

}

// Creaamos la función en sí y nos devuelve la x solución
double fixed_point_method(double initial_point, double epsilon){
    double x_fpm = initial_point; // Declaramos que la x que usa inicialmente la función es initial_point
    while(abs(x_fpm - f(x_fpm)) >  epsilon){ // Comprueba que se cumpla o no el requisito
        x_fpm = f(x_fpm);
    }
    return x_fpm; // Solución
}

// Todo se corre en el main
int main() {
    double epsilon;
    double initial_point; // Poned 0.615
    double f(double x){
        return exp(x) - 2 * x;}
    cout << "Input initial point:"; // print de toda la vida
    cin >> initial_point; // input de toda la vida
    cout << "Input epsilon:";
    cin >> epsilon;
    cout << "x=" << fixed_point_method(initial_point, epsilon);
    return 0;
}
