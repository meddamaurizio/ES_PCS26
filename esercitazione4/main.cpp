#include <iostream>
#include <fstream>
#include <iomanip> // per export dei tempi con precisione
#include <vector>

#include <algorithm> // per sort()

#include "rand_time/randfiller.h"
#include "rand_time/timecounter.cpp" // per tic(), toc()
#include "sorts.hpp"


int main () {

    randfiller rf;  // inizializzo randfiller
    timecounter tc; // inizializzo timecounter
    
    int runs = 15;
    for (int run = 0; run < runs; run++){
        std::string filename;
        filename = "tempi_" + std::to_string(run) + ".txt";
        std::ofstream ofs(filename);
        if (!ofs.is_open()) { return 1; }

        // per poter stampare tutte le cifre utili
        std::cout << std::setprecision(std::numeric_limits<double>::max_digits10);

        for (int i = 2; i < 8193; i *= 2) {

            double times[4] = {};

            std::vector<double> v;
            v.resize(i);
            rf.fill(v, -8192.00, 8192.00);

            std::vector<double> v1, v2, v3, v4;
            v1 = v;
            v2 = v;
            v3 = v;
            v4 = v;

            tc.tic();
            BubbleSort(v1);
            times[0] = tc.toc();

            tc.tic();
            InsertionSort(v2);
            times[1] = tc.toc();

            tc.tic();
            SelectionSort(v3);
            times[2] = tc.toc();

            tc.tic();
            std::sort(v4.begin(), v4.end());
            times[3] = tc.toc();

            // Output su file
            ofs << i << " ";
            for (int j = 0; j < 4; j++) {
                ofs <<std::setprecision(std::numeric_limits<double>::max_digits10) << times[j] << " ";
            }
            ofs << std::endl;

        }

        ofs.close();
    }

}