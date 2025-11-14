#include "density_analyzer.h"
#include "prime_utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

// تحسب كثافة الأعداد الأولية
double computeDensity(int primeCount, int candidateCount) {
    if (candidateCount == 0) return 0.0;
    return static_cast<double>(primeCount) / static_cast<double>(candidateCount);
}

// تستخرج الأعداد الأولية من قائمة المرشحين
vector<int> extractPrimes(const vector<int>& candidates) {
    vector<int> primes;
    for (int x : candidates) {
        if (isPrime(x)) {
            primes.push_back(x);
        }
    }
    return primes;
}

// تستخرج الأعداد غير الأولية من قائمة المرشحين
vector<int> extractNonPrimes(const vector<int>& candidates) {
    vector<int> nonPrimes;
    for (int x : candidates) {
        if (!isPrime(x)) {
            nonPrimes.push_back(x);
        }
    }
    return nonPrimes;
}

// تعرض تقريرًا تفصيليًا عن الكثافة
void reportDensityDetails(const vector<int>& candidates) {
    vector<int> primes = extractPrimes(candidates);
    vector<int> nonPrimes = extractNonPrimes(candidates);
    int total = static_cast<int>(candidates.size());
    int primeCount = static_cast<int>(primes.size());
    double density = computeDensity(primeCount, total);

    cout << "\n[Density Report]\n";
    cout << "- Total candidates: " << total << "\n";
    cout << "- Prime count: " << primeCount << "\n";
    cout << "- Non-prime count: " << nonPrimes.size() << "\n";
    cout << "- Prime density: " << fixed << setprecision(2) << (density * 100) << "%\n";

    cout << "\n- Prime numbers:\n";
    for (int x : primes) cout << setw(6) << x;
    cout << "\n\n- Non-prime numbers:\n";
    for (int x : nonPrimes) cout << setw(6) << x;
    cout << "\n";
}