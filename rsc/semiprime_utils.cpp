
#include "semiprime_utils.h"
#include "prime_utils.h"

bool isSemiPrime(int x) {
    if (x < 4) return false;

    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int j = x / i;
            if (isPrime(i) && isPrime(j)) {
                return true;
            }
        }
    }
    return false;
}
