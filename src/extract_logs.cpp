#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void extractLogs(const string& dateStr) {
    string logFilePath = "C:\\Users\\Lenovo\\Desktop\\farmart\\logs.log"; // Log file is in the same directory

   string outputFilePath = "C:\\Users\\Lenovo\\Desktop\\farmart\\output_" + dateStr + ".txt";
    
    ifstream logFileStream(logFilePath);
    if (!logFileStream.is_open()) {
        cerr << "Error: Could not open the log file." << endl;
        return;
    }
    
    ofstream outFile(outputFilePath);
    if (!outFile.is_open()) {
        cerr << "Error: Could not create the output file." << endl;
        return;
    }
    
    string line;
    bool foundLogs = false;
    while (getline(logFileStream, line)) {
        if (line.substr(0, 10) == dateStr) {
            outFile << line << endl;
            foundLogs = true;
        }
    }

    logFileStream.close();
    outFile.close();

    if (foundLogs) {
        cout << "Logs for " << dateStr << " have been saved to " << outputFilePath << endl;
    } else {
        cout << "No logs found for the date " << dateStr << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: ./extract_logs <YYYY-MM-DD>" << endl;
        return 1;
    }

    string dateInput = argv[1];  
    
    extractLogs(dateInput);
    
    return 0;
}

