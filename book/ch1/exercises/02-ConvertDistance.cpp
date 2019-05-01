#include <iostream>

using namespace std;

int meterToInch(double m);
int meterToFoot(double m);

int main() {
    cout << "Distance in meter ? ";
    double meter;
    cin >> meter;
    cout << meter << "m = " <<  meterToFoot(meter) << "ft " << meterToInch(meter) % 12 << "in." << endl;
    return 0;
}

int meterToInch(double m) {
    return  m / 0.0254;
}

int meterToFoot(double m) {
    return m / 0.0254 / 12;
}
