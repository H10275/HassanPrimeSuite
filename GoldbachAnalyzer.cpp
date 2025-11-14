#include "GoldbachAnalyzer.h"
#include "prime_utils.h"
#include "semiprime_utils.h"
#include "pattern_analysis.h"
#include <iostream>

void GoldbachAnalyzer::analyze(int n) {
    std::cout << "Analyzing number: " << n << "\n";

    if (isSmallExcludedPrime(n)) {
        std::cout << "→ Small prime excluded from analysis\n";
        return;
    }

    if (isGenerated(n)) {
        std::cout << "→ Number fits generative pattern (6k ± 1)\n";
    }
    else {
        std::cout << "→ Number does NOT fit generative pattern\n";
    }

    auto primePairs = findPrimePairs(n);
    reportPairDetails(primePairs, "Prime + Prime");

    auto mixedPairs = findMixedPairs(n);
    reportPairDetails(mixedPairs, "Prime + Semiprime");
}

bool GoldbachAnalyzer::isSmallExcludedPrime(int x) {
    return (x == 2 || x == 3);
}

bool GoldbachAnalyzer::isGenerated(int x) {
    return isInMainPattern(x);
}

std::vector<std::pair<int, int>> GoldbachAnalyzer::findPrimePairs(int h) {
    std::vector<std::pair<int, int>> pairs;
    for (int i = 2; i <= h / 2; ++i) {
        int j = h - i;
        if (isPrime(i) && isPrime(j)) {
            pairs.emplace_back(i, j);
        }
    }
    return pairs;
}

std::vector<std::pair<int, int>> GoldbachAnalyzer::findMixedPairs(int h) {
    std::vector<std::pair<int, int>> pairs;
    for (int i = 2; i < h; ++i) {
        int j = h - i;
        if (isPrime(i) && isSemiPrime(j)) {
            pairs.emplace_back(i, j);
        }
    }
    return pairs;
}

void GoldbachAnalyzer::reportPairDetails(const std::vector<std::pair<int, int>>& pairs, const std::string& type) {
    std::cout << "→ " << type << " pairs found: " << pairs.size() << "\n";
    for (const auto& p : pairs) {
        std::cout << "   " << p.first << " + " << p.second << " = " << (p.first + p.second) << "\n";
    }
}