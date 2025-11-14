#pragma once
#include <vector>
#include <string>

// Class for analyzing Goldbach-related patterns and representations
class GoldbachAnalyzer {
public:
    // Performs full analysis on the given number
    void analyze(int n);

private:
    // Checks if the number is one of the small primes excluded from analysis
    bool isSmallExcludedPrime(int x);

    // Checks if the number fits the main generative pattern (6k ± 1)
    bool isGenerated(int x);

    // Finds all prime pairs that sum to the given number
    std::vector<std::pair<int, int>> findPrimePairs(int h);

    // Finds all mixed pairs (prime + semiprime) that sum to the given number
    std::vector<std::pair<int, int>> findMixedPairs(int h);

    // Reports details of the found pairs with a label
    void reportPairDetails(const std::vector<std::pair<int, int>>& pairs, const std::string& type);
};
