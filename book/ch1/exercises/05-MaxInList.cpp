#include <iostream>

using namespace std;

const int SENTINEL = 0;
int main() {
    cout << "This program findes the largest integer in a list." << endl;
    cout << "Enter " << SENTINEL << " to signal the end of the list." << endl;

    int max = 0;
    while(true){
        int num;
        cout << " ? ";
        cin >> num;
        if(num == SENTINEL) break;
        max = max < num || max == 0 ? num : max;
    }
    cout << "The largest value was " << max << "." << endl;
    return 0;
}


