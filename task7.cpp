#include <iostream>
int main() {
    long long int a, b, c, i, x;
    a = 1;
    b = 2;
    i = 4000000;
    x = 2;
    c = 0;
    while (c <= i) {
        c = a + b;
        if (c % 2 == 0)
            x += c;
    a = b;
    b = c;
}
std::cout<<x;
return 0;
}