#include "sieve_generator.h"

// Generates numbers of the form r + m * k where k ≥ 0 and r + m * k ≤ N
std::vector<int> generateCandidates(int r, int m, int N) {
    std::vector<int> candidates;

    if (m <= 0) return candidates; // avoid infinite loop or division by zero
    if (r < 0 || r > N) return candidates;

    for (int k = 0; ; ++k) {
        int val = r + m * k;
        if (val > N) break;
        candidates.push_back(val);
    }

    return candidates;
}
