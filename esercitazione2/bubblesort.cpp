#include <iostream>

int main() {
    static const int N = 10;
    double arr[N] = {
        1.0957,
        0.4644,
        9.6600,
        5.7694,
        10.7074,
        7.8964,
        0.3355,
        3.8594,
        4.0388,
        1.9712
    };

    for (int imax = 0; imax < N - 1; imax++) {
        bool flag = false;
        for (int i = 0; i < N - 1 - imax; i++) {
            if (arr[i] > arr[i+1]) {
                double temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = true;
            }
        }
        if (!flag) break;
    }
    
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << std::endl;
    }

}