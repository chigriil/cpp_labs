#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> coords;
    int n, c, l, dist;
    cin >> n;
    l = 0;
    dist = n;
    while (cin >> c){
        coords.push_back(c);
        l++;
    }
    sort(coords.begin(), coords.end());
    for (int i = 0; i <= l; i++){
        if (i == 0 and n >= coords[0]){
            dist = coords[0] + n;
        }
        if (i == 0 and n < coords[0]){
            dist = n;
            break;
        }
        if (i != 0 and coords[i-1]+n >= coords[i]){
            dist = coords[i] + n;
        }
        if (i != 0 and coords[i-1] + n < coords[i]){
            break;
        }
    }
    cout << dist<<'\n';
}
