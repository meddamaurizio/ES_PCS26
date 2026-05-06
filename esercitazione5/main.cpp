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
    
    int runs = 25;
    for (int run = 0; run < runs; run++){
        std::string filename;
        filename = "tempi_" + std::to_string(run) + ".txt";
        std::ofstream ofs(filename);
        if (!ofs.is_open()) { return 1; }

        // per poter stampare tutte le cifre utili
        std::cout << std::setprecision(std::numeric_limits<double>::max_digits10);

        for (int i = 60; i < 200; i += 3) {

            double times[7] = {};

            std::vector<double> v;
            v.resize(i);
            rf.fill(v, -8192.00, 8192.00);

            std::vector<double> vsort = v;

            tc.tic();
            BubbleSort(vsort);
            times[0] = tc.toc();

            vsort = v;
            tc.tic();
            InsertionSort(vsort);
            times[1] = tc.toc();

            vsort = v;
            tc.tic();
            SelectionSort(vsort);
            times[2] = tc.toc();

            vsort = v;
            tc.tic();
            MergeSort(vsort);
            times[3] = tc.toc();
           
            vsort = v;
            tc.tic();
            QuickSort(vsort, 0, vsort.size()-1);
            times[4] = tc.toc();

            vsort = v;
            tc.tic();
            std::sort(vsort.begin(), vsort.end());
            times[5] = tc.toc();

            vsort = v;
            tc.tic();
            mySort(vsort);
            times[6] = tc.toc();



            // Output su file
            ofs << i << " ";
            for (int j = 0; j < 7; j++) {
                ofs <<std::setprecision(std::numeric_limits<double>::max_digits10) << times[j] << " ";
            }
            ofs << std::endl;

        }

        ofs.close();
    }

}