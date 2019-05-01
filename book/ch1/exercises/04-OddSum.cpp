#include <iostream>

using namespace std;

int sumOfOdds(int n);

int main() {
    cout << "N: ";
    int n;
    cin >> n;

    cout << "Sum of odds = " << sumOfOdds(n) << endl;
    return 0;
}

int sumOfOdds(int n) {
    int result = 0;
    for (int i = 0, j = 1; i < n; i++, j += 2)
        result += j;
    return result;
}

