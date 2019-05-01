#include <iostream>

using namespace std;

const int SENTINEL = 0;
int main() {
    cout << "This program findes the largest integer in a list." << endl;
    cout << "Enter " << SENTINEL << " to signal the end of the list." << endl;

    int max = 0, second = 0;
    while(true){
        int num;
        int secondMax;
        cout << " ? ";
        cin >> num;
        if(num == SENTINEL) break;
        secondMax = max;
        max = max < num || max == 0 ? num : max;
        second = max != secondMax ? secondMax : second < num || second == 0 ? num : second;
    }

    cout << "The largest value was " << max << "." << endl;
    if(second != 0) cout << "The second largest value was " << second << "." << endl;

    return 0;
}


