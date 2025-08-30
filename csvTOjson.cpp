#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("input.csv");
    std::ofstream outputFile("output.json");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cout << "can't open file" << std::endl;
        return 1;
    }
    std::string line;
    std::vector<std::string> headers;

    if (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string header;
        while(std::getline(ss, header, ',')) {
            headers.push_back(header);
        }
    }

    outputFile << "[\n";
    bool flag = true;
    while(std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> fields;
        while(std::getline(ss, field, ',')) {
            fields.push_back(field);
        }
        if(!flag) {
            outputFile << ",";
        }
        flag = false;
        outputFile << "{\n";
        for(int i = 0; i < headers.size(); ++i) {
            outputFile << "  \"" << headers[i] << " \": ";

            bool isNumber = true;
            for (char c : fields[i]) {
                if(!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
            if (isNumber) {
                outputFile << fields[i];
            }else {
                outputFile << " \"" << fields[i] << " \"";
            }

            if (i != headers.size() - 1) {
                outputFile << ",";
            }
            outputFile << "\n";
        }
        outputFile << "}";
        outputFile << "\n";
    }
        outputFile << "\n]\n";

    inputFile.close();
    outputFile.close();
    return 0;
}