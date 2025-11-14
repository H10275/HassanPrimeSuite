#pragma once
#ifndef PRIME_UTILS_H
#define PRIME_UTILS_H

#include <vector>

// Represents the result of a primality check
enum PrimeStatus {
    PRIME,                    // The number is prime
    NOT_PRIME_LESS_THAN_2,   // The number is less than 2
    NOT_PRIME_DIVISIBLE      // The number is divisible by another integer
};

// Checks whether a number is prime using basic trial division
bool isPrime(int x);

// Provides a detailed primality status and sets the reason if not prime
PrimeStatus isPrimeDetailed(int x, int& reason);

// Generates all prime numbers up to a given limit
std::vector<int> generatePrimesUpTo(int limit);

#endif // PRIME_UTILS_H
