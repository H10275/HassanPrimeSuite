#pragma once
#include <vector>

// Struct to hold statistical data for a given residue class
struct ResidueStats {
    int r;               // Residue value
    int N;               // Upper bound for candidate generation
    int primeCount;      // Number of primes found in the residue class
    int candidateCount;  // Total number of candidates generated
    double density;      // Prime density = primeCount / candidateCount
};

// Compares multiple residue classes by generating candidates and analyzing prime density
void compareResidues(const std::vector<int>& residues, int m, int N);