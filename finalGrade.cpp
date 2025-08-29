#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open() ) {
        std::cerr << "can'topen file" << std::endl;
        return 1;
    }
    std::vector<std::pair<std::string,double>> Students;


    std::string line;

    while(std::getline(inputFile,line)) {
        std::stringstream ss(line);
        std::string name;

        double midterm, final, homework;

        std::getline(ss,name, ',');
        ss >> midterm;
        ss.ignore();
        ss >> final;
        ss.ignore();
        ss >> homework;

        double finalGrade = 0.3 * midterm + 0.3 * final + 0.4 * homework;
        Students.push_back({name,finalGrade});
      
    }
    auto lambda = [] (const std::pair<std::string,double>& a, const std::pair<std::string,double>& b) {
        return a.second < b.second;
    };
    std::sort(Students.begin(), Students.end(), lambda);
    for (auto s : Students) {
    outputFile << s.first << ": " << s.second << std::endl;
    }
    inputFile.close();
    outputFile.close();
}