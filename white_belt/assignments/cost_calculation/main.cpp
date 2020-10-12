#include <iostream>

using namespace std;

int main() {
    double price_a = 0;
    double price_b = 0;
    double original_price = 0;
    double discount_x = 0;
    double discount_y = 0;

    cin >> original_price >> price_a >> price_b >> discount_x >> discount_y;

    if (price_a >= price_b) {
        return -1;
    }
    
    if (original_price > price_a && original_price <= price_b) {
        cout << "" << original_price - (original_price * (discount_x * 0.01));
    } else if (original_price > price_b) {
        cout << "" << original_price - (original_price * (discount_y * 1/100));
    } else {
        cout << original_price;
    }

    return 0;
}