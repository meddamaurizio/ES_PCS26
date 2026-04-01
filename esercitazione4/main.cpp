#include <iostream>
#include <vector>

#include "rand_time/randfiller.h"
#include "rand_time/timecounter.h"
#include "sorts.hpp"

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main () {
    randfiller rf; /* instantiate a randfiller */

    std::vector<int> vi;
    vi.resize(10);
    rf.fill(vi, 30, 50); /* use it on vectors */
    print_vector(vi);

    std::cout << is_sorted(vi) << "\n";

}