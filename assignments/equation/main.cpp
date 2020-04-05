#include <iostream>
#include <cmath>

using namespace std;

void calculate_square_equation (double a, double b, double c) {
    double d = 0;
    double x0 = 0;
    double x1 = 0;

    d = (b * b) - (4 * a * c);
    if (d < 0) return;

    x0 = ((b * -1) + sqrt(d))/(2 * a);
    x1 = ((b * -1) - sqrt(d))/(2 * a); 
    
    if (x0 == x1) cout << x0;
    else cout << x0 << " " << x1;
}

void calculate_linear_equation (double b, double c) {
    if (!b) return;
    cout << "" << (-1 * c)/b;
}

int main () {
    double a = 0;
    double b = 0;
    double c = 0;

    cin >> a >> b >> c;
    if (a)  calculate_square_equation (a, b ,c);
    else    calculate_linear_equation (b, c);

    return 0;
}