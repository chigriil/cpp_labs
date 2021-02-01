#include <iostream>
int main() {
    int N, i, k, l;
    std:: cin >> N;
    for (i = 0; i<N; i++) {
        for (k=0; k<i; k++){
            std::cout << ' ';
        }
        for (l=0; l<N-2*i; l++) {
            std::cout << '*';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
    return 0;
}
