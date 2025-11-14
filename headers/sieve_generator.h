#pragma once
#include <vector>

// Generates numbers of the form r + m * k where k ≥ 0 and r + m * k ≤ N
std::vector<int> generateCandidates(int r, int m, int N);
