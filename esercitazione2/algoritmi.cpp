#include <iostream>
#include <cmath>

void bubblesort(double *a, const int lenght) {
    for (int imax = 0; imax < lenght - 1; imax++) {
        bool flag = false;
        for (int i = 0; i < lenght - 1 - imax; i++) {
            if (a[i] > a[i+1]) {
                double temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                flag = true;
            }
        }
        if (!flag) return;
    }
}


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

    double minval = arr[0];
    double maxval = arr[0];
    double somma = 0.0;
    double media = 0.0;
    double E2 = 0.0;
    double var = 0.0;
    double stddev = 0.0;

    // STAMPE A SCHERMO

    // vettore iniziale
    std::cout << "arr[] = { ";
        for (int i = 0; i < N; i++) {

            minval = std::min(minval, arr[i]);
            maxval = std::max(maxval, arr[i]);
            somma += arr[i];
            E2 += arr[i] * arr[i];

            std::cout << arr[i] << " ";
        }
    std::cout << "}" << std::endl;

    media = somma / N;
    var = (E2 - (somma*somma/N)) / (N);
    // varianza in due passaggi
    // non necessaria, risultato praticamente identico per questa scala
/*  
    double var2 = 0.0;
    for (int i = 0; i < N; i++) {
        double diff = arr[i] - media;
        var2 += diff * diff;
    }
    var2 /= N; 
*/
    stddev = std::sqrt(var/N);

    std::cout << "Min = " << minval << std::endl;
    std::cout << "Max = " << maxval << std::endl;
    std::cout << "Somma = " << somma << std::endl;
    std::cout << "Media = " << media << std::endl;
    std::cout << "Varianza = " << var <<std::endl;
    std::cout << "Dev. std = " << stddev <<std::endl;

}