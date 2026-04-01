#include "rational.hpp"

int main() {
    rational<int> nan_val(0,0);         // 0 args -> NaN
    rational<int> whole(5);        // 1 arg  -> 5/1
    rational<int> frac1(1, 2);     // 2 args -> 1/2
    rational<int> frac2(-3, -4);   // properly semplificas to 3/4
    rational<int> inf_pos(1, 0);   // +inf
    rational<int> inf_neg(-5, 0);  // semplificas to -1/0 (-inf)

    std::cout << "--- VALORI ---\n";
    std::cout << "nan_val: " << nan_val << "\n";
    std::cout << "whole:   " << whole << "\n";
    std::cout << "frac1:   " << frac1 << "\n";
    std::cout << "frac2:   " << frac2 << "\n";
    std::cout << "inf_pos: " << inf_pos << "\n";
    std::cout << "inf_neg: " << inf_neg << "\n\n";

    std::cout << "--- OPERAZIONI ---\n";
    std::cout << "1/2 + 3/4 = " << (frac1 + frac2) << "\n";
    std::cout << "1/2 - 3/4 = " << (frac1 - frac2) << "\n";
    std::cout << "1/2 * 3/4 = " << (frac1 * frac2) << "\n";
    std::cout << "1/2 / 3/4 = " << (frac1 / frac2) << "\n\n";
    
    std::cout << "--- CON INTERI ---\n";
    std::cout << "1/2 + 2 = " << (frac1 + 2) << "\n";
    std::cout << "3 - 1/2 = " << (3 - frac1) << "\n";
    std::cout << "1/2 * -4 = " << (frac1 * -4) << "\n";
    std::cout << "5 / 1/2 = " << (5 / frac1) << "\n\n";

    std::cout << "--- PROPAGAZIONE ---\n";
    std::cout << "+inf + 1/2 = " << (inf_pos + frac1) << "\n";
    std::cout << "+inf + -inf = " << (inf_pos + inf_neg) << "\n";
    std::cout << "+inf * -2 = " << (inf_pos * -2) << "\n";
    std::cout << "0 * +inf = " << (rational<int>(0) * inf_pos) << "\n";
    std::cout << "+inf / +inf = " << (inf_pos / inf_pos) << "\n";
    std::cout << "NaN + 5 = " << (nan_val + 5) << "\n";

    return 0;
}