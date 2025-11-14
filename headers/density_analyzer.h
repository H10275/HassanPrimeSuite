#pragma once
#include <vector>

// تحسب كثافة الأعداد الأولية من بين المرشحين
double computeDensity(int primeCount, int candidateCount);

// تستخرج الأعداد الأولية من قائمة المرشحين
std::vector<int> extractPrimes(const std::vector<int>& candidates);

// تستخرج الأعداد غير الأولية من قائمة المرشحين
std::vector<int> extractNonPrimes(const std::vector<int>& candidates);

// تعرض تقريرًا تفصيليًا عن الكثافة والأعداد الأولية وغير الأولية
void reportDensityDetails(const std::vector<int>& candidates);
