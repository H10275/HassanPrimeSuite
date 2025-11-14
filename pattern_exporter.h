#pragma once
#include <vector>
#include <string>

// Structure to hold pattern analysis for each number
struct PatternData {
    int number;
    bool isPrime;
    bool is6kPlus1;
    bool is6kMinus1;
};

// Collects pattern data for numbers from 1 to N
std::vector<PatternData> collectPatternData(int N);

// Opens a Windows save dialog and returns the selected file path (Unicode)
std::wstring getSavePathFromDialog();

// Exports pattern data to a CSV file at the given path (Unicode)
void exportPatternDataToCSV(const std::vector<PatternData>& data, const std::wstring& filename);