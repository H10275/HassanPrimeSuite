#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>

#include "prime_utils.h"
#include "semiprime_utils.h"
#include "sieve_generator.h"
#include "GoldbachAnalyzer.h"
#include "density_analyzer.h"
#include "pattern_analysis.h"
#include "pattern_exporter.h"

using namespace std;

void showMenu() {
    cout << "\n=== HASANI PRIME SOLVER ===\n";
    cout << "1 - Check if a number is prime\n";
    cout << "2 - Generate candidates (r + m * k)\n";
    cout << "3 - Analyze Goldbach decomposition\n";
    cout << "4 - Analyze prime density of candidates\n";
    cout << "5 - Pattern analysis of a number\n";
    cout << "6 - Prime forms and representations\n";
    cout << "7 - Export pattern data to CSV\n";
    cout << "0 - Exit\n";
    cout << "Your choice: ";
}

void printSectionHeader(const string& title) {
    cout << "\n----------------------------------------\n";
    cout << "[" << title << "]\n\n";
}

void handlePrimeCheck() {
    printSectionHeader("Prime Check");

    int num, reason = -1;
    cout << "Enter number to check: ";
    cin >> num;
    PrimeStatus status = isPrimeDetailed(num, reason);

    if (status == PRIME)
        cout << "- " << num << " is PRIME.\n";
    else if (status == NOT_PRIME_LESS_THAN_2)
        cout << "- " << num << " is NOT prime (less than 2).\n";
    else
        cout << "- " << num << " is NOT prime (divisible by " << reason << ").\n";
}

void handleCandidateGeneration() {
    printSectionHeader("Candidate Generation");

    int r, m, N;
    cout << "Enter residue r, modulus m, and upper bound N: ";
    cin >> r >> m >> N;

    auto candidates = generateCandidates(r, m, N);
    cout << "\n[Generated Candidates of form r + m * k]\n";
    for (int val : candidates) {
        cout << setw(6) << val;
    }
    cout << "\nTotal: " << candidates.size() << "\n";
}

void handleGoldbachAnalysis() {
    printSectionHeader("Goldbach Decomposition");

    int n;
    cout << "Enter even number n: ";
    cin >> n;
    GoldbachAnalyzer analyzer;
    analyzer.analyze(n);
}

void handleDensityAnalysis() {
    printSectionHeader("Prime Density Analysis");

    int r, m, N;
    cout << "Enter residue r, modulus m, and upper bound N: ";
    cin >> r >> m >> N;

    auto candidates = generateCandidates(r, m, N);
    reportDensityDetails(candidates);
}

void handlePatternAnalysis() {
    printSectionHeader("Pattern Analysis");

    int h;
    cout << "Enter number to analyze: ";
    cin >> h;

    cout << "- Main generative pattern: ";
    if (isInMainPattern(h))
        cout << "YES (h ≡ ±1 mod 6)\n";
    else
        cout << "NO\n";

    cout << "- Can be sum of two primes: ";
    if (canBeSumOfTwoPrimes(h))
        cout << "YES\n";
    else
        cout << "NO\n";

    cout << "- Can be prime + semiprime: ";
    if (canBePrimePlusSemiPrime(h))
        cout << "YES\n";
    else
        cout << "NO\n";
}

void handlePrimeForms() {
    printSectionHeader("Prime Forms and Representations");

    int h;
    cout << "Enter number to analyze: ";
    cin >> h;

    cout << "- Is in form 6k ± 1: ";
    cout << (isInMainPattern(h) ? "YES\n" : "NO\n");

    cout << "- Can be expressed as sum of two primes: ";
    cout << (canBeSumOfTwoPrimes(h) ? "YES\n" : "NO\n");

    cout << "- Can be expressed as prime + semiprime: ";
    cout << (canBePrimePlusSemiPrime(h) ? "YES\n" : "NO\n");

    bool diffOfSquares = false;
    for (int a = 1; a * a < h + a; ++a) {
        int b2 = a * a - h;
        if (b2 > 0 && sqrt(b2) == int(sqrt(b2))) {
            diffOfSquares = true;
            break;
        }
    }
    cout << "- Can be written as difference of squares: ";
    cout << (diffOfSquares ? "YES\n" : "NO\n");

    cout << "- Is in form 4k + 1: ";
    cout << ((h % 4 == 1) ? "YES\n" : "NO\n");

    cout << "- Is in form 4k - 1: ";
    cout << ((h % 4 == 3) ? "YES\n" : "NO\n");
}

void handleExportPatternData() {
    printSectionHeader("Export Pattern Data to CSV");

    int limit;
    cout << "Enter upper bound: ";
    cin >> limit;

    auto data = collectPatternData(limit);
    std::wstring path = getSavePathFromDialog();

    if (path.empty()) {
        cout << "Export cancelled.\n";
        return;
    }

    exportPatternDataToCSV(data, path);
    std::wcout << L"Data exported to: " << path << L"\n";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        case 1:
            handlePrimeCheck();
            break;
        case 2:
            handleCandidateGeneration();
            break;
        case 3:
            handleGoldbachAnalysis();
            break;
        case 4:
            handleDensityAnalysis();
            break;
        case 5:
            handlePatternAnalysis();
            break;
        case 6:
            handlePrimeForms();
            break;
        case 7:
            handleExportPatternData();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}