#include "prime_utils.h"

// Checks whether a number is prime using basic trial division
bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

// Provides a detailed primality status and sets the reason if not prime
PrimeStatus isPrimeDetailed(int x, int& reason) {
    if (x < 2) return NOT_PRIME_LESS_THAN_2;
    if (x == 2 || x == 3) return PRIME;
    if (x % 2 == 0) {
        reason = 2;
        return NOT_PRIME_DIVISIBLE;
    }
    if (x % 3 == 0) {
        reason = 3;
        return NOT_PRIME_DIVISIBLE;
    }

    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0) {
            reason = i;
            return NOT_PRIME_DIVISIBLE;
        }
        if (x % (i + 2) == 0) {
            reason = i + 2;
            return NOT_PRIME_DIVISIBLE;
        }
    }

    return PRIME;
}

// Generates all prime numbers up to a given limit
std::vector<int> generatePrimesUpTo(int limit) {
    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}
