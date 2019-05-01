#include <iostream>

using namespace std;

int sum(int from, int to);

int main() {
    cout << "From: ";
    int from;
    cin >> from;

    cout << "To: ";
    int to;
    cin >> to;

    cout << "Sum = " << sum(from, to) << endl;
    return 0;
}

int sum(int from, int to) {
    int result = 0;
    for (int i = from; i <= to; i++)
        result += i;
    return result;
}
