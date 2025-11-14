#include "residue_comparator.h"
#include "sieve_generator.h"
#include "density_analyzer.h"

#include <iostream>

// Compares multiple residue classes by generating candidates and analyzing prime density
void compareResidues(const std::vector<int>& residues, int m, int N) {
    std::vector<ResidueStats> stats;

    for (int r : residues) {
        // Generate candidates of the form r + m * k ≤ N
        std::vector<int> candidates = generateCandidates(r, m, N);

        // Extract primes from the candidate list
        std::vector<int> primes = extractPrimes(candidates);

        // Compute statistics
        int primeCount = static_cast<int>(primes.size());
        int candidateCount = static_cast<int>(candidates.size());
        double density = computeDensity(primeCount, candidateCount);

        // Store results
        stats.push_back({ r, N, primeCount, candidateCount, density });
    }

    // Display comparison table
    std::cout << "\nResidue Comparison Table:\n";
    std::cout << "r\tN\tPrimes\tCandidates\tDensity\n";
    for (const auto& row : stats) {
        std::cout << row.r << "\t" << row.N << "\t" << row.primeCount << "\t"
            << row.candidateCount << "\t\t" << row.density << "\n";
    }
}