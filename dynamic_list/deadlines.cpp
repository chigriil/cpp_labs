#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct task{
    int price, day;
};

bool comp(const task& lhs, const task& rhs){
    if (lhs.price == rhs.price){
        return lhs.day < rhs.day;
    }
    return lhs.price > rhs.price;
}

int main() {
    int N, sum, max_day;
    cin >> N;
    sum = 0;
    max_day = 0;
    vector<task> tasks(N);
    for (int i = 0; i < N; i++){
        cin >> tasks[i].day >> tasks[i].price;
        if (tasks[i].day >= max_day)
            max_day = tasks[i].day;
    }
    sort(tasks.begin(), tasks.end(), comp);
    vector<int> days(max_day, 0);
    for (int i = 0; i < max_day; i++){
        if (i == 0){
            days[tasks[i].day -1] = tasks[i].day;
            sum += tasks[i].price;
        }
        if (i != 0) {
            if (days[tasks[i].day - 1] != 0){
                for (int l = tasks[i].day - 1; l >= 0; l--){
                    if (days[l] == 0){
                        days[l] = tasks[i].day;
                        sum += tasks[i].price;
                        break;
                    }
                }
            }
            if (days[tasks[i].day - 1] == 0){
                days[tasks[i].day - 1] = tasks[i].day;
                sum += tasks[i].price;
            }
        }
    }
    cout << sum << '\n';
}
