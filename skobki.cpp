#include <stack>
#include <iostream>

using namespace std;

int main(){
    stack <string> skobki_left;
    stack <string> skobki_right;
    string a, b, first, last;
    cin >> a;
    for (int i = 0; i < a.size(); i++){
        b = a[i];
        if (b == ")") skobki_right.push(b);
        if (b =="(") skobki_left.push(b);
    }
    first = a[0];
    last = a[a.size()-1];
    if (first == "(" and last == ")" and skobki_left.size()==skobki_right.size())
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

