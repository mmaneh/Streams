#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open() ) {
        std::cerr << "can't open file" << std::endl;
        return 1;
    }
    std::unordered_map<std::string, int> freq;  
    std::string line;
    std::string res;

    while(std::getline(inputFile,line)) {
        std::stringstream ss(line);
        std::string word;
    
        while(ss >> word) {
            for(auto& w : word) {
                if(w >= 'A' && w <= 'Z') {
                    w += 32;
                }
            }
            ++freq[word];
        }
        
    }
    std::vector<std::pair<std::string, int>> vec(freq.begin(), freq.end());
    auto lambda = [&freq] (const std::pair<std::string,int>& a, const std::pair<std::string,int>& b) {
        return freq[a.first] < freq[b.first];
    };
    std::sort(vec.begin(), vec.end(), lambda);
    for (auto v : vec) {
        outputFile << v.first << " ";
    }
    inputFile.close();
    outputFile.close();
}