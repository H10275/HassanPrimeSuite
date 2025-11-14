#include "goldbach_solver.h"
#include "pattern_analysis.h"
#include <iostream>

void analyzeGoldbachPatterns(int h) {
    std::cout << "Analyzing number: " << h << "\n";

    if (isInMainPattern(h)) {
        std::cout << "→ Belongs to main generative pattern (6k ± 1)\n";
    }
    else {
        std::cout << "→ Does NOT belong to main generative pattern\n";
    }

    if (canBeSumOfTwoPrimes(h)) {
        std::cout << "→ Can be expressed as the sum of two primes\n";
    }
    else {
        std::cout << "→ Cannot be expressed as the sum of two primes\n";
    }

    if (canBePrimePlusSemiPrime(h)) {
        std::cout << "→ Can be expressed as prime + semiprime\n";
    }
    else {
        std::cout << "→ Cannot be expressed as prime + semiprime\n";
    }
}
