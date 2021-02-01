#include <iostream>
int main() {
    int N, i, k;
    std:: cin >> N;
    for (i = 0; i<N; i++) {
        for (k=0; k<N; k++){
            std::cout << '*';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
return 0;
}