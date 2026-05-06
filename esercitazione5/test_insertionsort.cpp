#include <iostream>
#include <vector>

#include "rand_time/randfiller.h"
#include "rand_time/timecounter.cpp" // per tic(), toc()
#include "sorts.hpp"

int main () {
    randfiller rf;

    int runs = 100;

    std::vector<int> dim;
    dim.resize(runs);

    rf.fill(dim, 0, 512);

    for (int i = 0; i < runs; i++) {
        std::vector<double> v;
        v.resize(dim[i]);
        rf.fill(v, -8192.00, 8192.00);
        InsertionSort(v);
        if (!is_sorted(v)) {
            std::cerr << "vettore " << i << " non ordinato" << std::endl;
            return EXIT_FAILURE;
        }
    }

    // vettore di stringhe
    std::vector<std::string> s = {
        "banana",
        "Apple",
        "apple",
        "Zeta",
        "zeta",
        "123",
        "42",
        "",
        " ",
        "Árbol",      // caratteri accentati
        "árbol",
        "banana",     // duplicato
        "Banana",
        "alpha",
        "alPha",      // con maiuscola in mezzo
        "long-string-with-hyphens",
        "short",
        "a",
        "A",
        "same same",  // con spazio
    };

    InsertionSort(s);
    if (!is_sorted(s)) {
        std::cerr << "stringhe non ordinate" << std::endl;
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
    return 0;
}