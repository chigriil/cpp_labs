#include <iostream>
#include <string>

using namespace std;

int main() {
    int s, n, sum;
    cin >> s;
    sum = 0;
    while (cin >> n) {
        if (sum >= s) {
            sum -= n;
        } else {
            sum += n;
        }
    }

    if (sum == s)
        cout << "YES";
    if (sum != s)
        cout << "NO";

}