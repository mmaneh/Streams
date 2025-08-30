#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_set>
int main() {
    std::ifstream input1File("input1.csv");
    std::ifstream input2File("input2.csv");
    std::ofstream outputFile("output.json");

    if (!input1File.is_open() || !input2File.is_open() || !outputFile.is_open() ) {
        std::cerr << "can't open file" << std::endl;
        return 1;
    }
    std::string line;
    std::vector<std::string> headers1;
    std::vector<std::string> headers2;
    if (std::getline(input1File, line)) {
        std::stringstream ss(line);
        std::string header;
        while(std::getline(ss, header, ',')) {
            headers1.push_back(header);
        }
    }
    if (std::getline(input2File, line)) {
        std::stringstream ss(line);
        std::string header;
        while(std::getline(ss, header, ',')) {
            headers2.push_back(header);
        }
    }
    bool flag = true;
    if (headers1.size() != headers2.size()) flag = false; 
    else {
        for (int i = 0; i < headers1.size(); ++i) {
            if (headers1[i] != headers2[i]) flag = false;
        }
    }

    if (!flag) {
        std::cerr << "files' headers don't match";
    }
    std::unordered_set<std::string> set;
    
    while (std::getline(input1File,line)) {
        set.insert(line);
    }
    
    while(std::getline(input2File, line)) {
        set.insert(line);
    }

    outputFile << "[\n";
    bool comma = false;
    for (auto s : set) {
        std::stringstream ss(s);
        std::string field;
        if (comma) outputFile << ",";
        comma = true;
        outputFile << "{";

        for (int i = 0; i < headers1.size(); ++i) {

            outputFile << "\"" << headers1[i] << "\": ";
            std::getline(ss,field, ',');
            if (std::all_of(field.begin(), field.end(), ::isdigit)) {
                outputFile << field;
            }else {
                outputFile << "\"" << field << "\"";
            }
            if (i != headers1.size() - 1) outputFile << ",";
        }
        outputFile << "}";
        outputFile << "\n";
    }
    outputFile << "]";
    
    input1File.close();
    input2File.close();
    outputFile.close();
    return 0;
}
