#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_set>
int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open() ) {
        std::cerr << "can't open file" << std::endl;
        return 1;
    }
    std::unordered_set<std::string> wordSet;  
    std::string line;
    std::string res;

    while(std::getline(inputFile,line)) {
        std::stringstream ss(line);
        std::string word;
    
        while(ss >> word) {
            if (wordSet.count(word)) {
                res += "*";
            }else {
                wordSet.insert(word);
                res += " " + word;
            }
        }
        for (auto r : res) {
            outputFile << res;
        }

    }
    inputFile.close();
    outputFile.close();
}