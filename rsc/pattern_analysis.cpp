#include "pattern_analysis.h"
#include "prime_utils.h"
#include "semiprime_utils.h"

bool isInMainPattern(int h) {
    return (h % 6 == 1 || h % 6 == 5);
}

bool canBeSumOfTwoPrimes(int h) {
    if (h < 4 || h % 2 != 0) return false;
    for (int i = 2; i <= h / 2; ++i) {
        int j = h - i;
        if (isPrime(i) && isPrime(j)) return true;
    }
    return false;
}

bool canBePrimePlusSemiPrime(int h) {
    if (h < 5) return false;
    for (int i = 2; i < h; ++i) {
        int j = h - i;
        if (isPrime(i) && isSemiPrime(j)) return true;
    }
    return false;
}
