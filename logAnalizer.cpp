#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_set>
int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::ofstream errorFile("error.txt");


    if (!inputFile.is_open() || !outputFile.is_open() || !errorFile.is_open()) {
        std::cerr << "can't open file" << std::endl;
        return 1;
    }
    int InfoCount = 0;
    int ErrorCount = 0;
    int WarningCount = 0;

    std::string line;
    while(std::getline(inputFile,line)) {
       if(line.find("[INFO]") == 0) ++InfoCount;
       else if (line.find("[WARNING]") == 0) ++WarningCount;
       else if (line.find("[ERROR]") == 0) {
        ++ErrorCount;
        errorFile << line << std::endl;
       }
    }
    outputFile << "[INFO] - " << InfoCount << std::endl;
    outputFile << "[WARNING] - " << WarningCount << std::endl;
    outputFile << "[ERROR] - " << ErrorCount << std::endl;
    inputFile.close();
    outputFile.close();
}