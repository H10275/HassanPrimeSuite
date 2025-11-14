#include "pattern_exporter.h"
#include "prime_utils.h"
#include <fstream>
#include <windows.h>
#include <commdlg.h>

std::vector<PatternData> collectPatternData(int N) {
    std::vector<PatternData> data;
    for (int i = 1; i <= N; ++i) {
        PatternData entry;
        entry.number = i;
        entry.isPrime = isPrime(i);
        entry.is6kPlus1 = (i % 6 == 1);
        entry.is6kMinus1 = (i % 6 == 5);
        data.push_back(entry);
    }
    return data;
}

std::wstring getSavePathFromDialog() {
    wchar_t filename[MAX_PATH] = L"";

    OPENFILENAMEW ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFilter = L"CSV Files\0*.csv\0All Files\0*.*\0";
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_OVERWRITEPROMPT;
    ofn.lpstrDefExt = L"csv";
    ofn.lpstrTitle = L"Save Pattern Data";

    if (GetSaveFileNameW(&ofn)) {
        return std::wstring(filename);
    }
    else {
        return L"";
    }
}

void exportPatternDataToCSV(const std::vector<PatternData>& data, const std::wstring& filename) {
    std::wofstream file(filename);
    file << L"Number,Prime,6k+1,6k-1\n";
    for (const auto& entry : data) {
        file << entry.number << L","
            << (entry.isPrime ? L"YES" : L"NO") << L","
            << (entry.is6kPlus1 ? L"YES" : L"NO") << L","
            << (entry.is6kMinus1 ? L"YES" : L"NO") << L"\n";
    }
    file.close();
}
