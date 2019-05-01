#include <iostream>

using namespace std;

double CtoF(double c);

int main() {
    cout << "C ? ";
    double c;
    cin >> c;
    cout << c << "C = " << CtoF(c) << "F" << endl;
    return 0;
}

double CtoF(double c) {
    return  9.0 / 5.0 * c + 32;
}