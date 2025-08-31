#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <algorithm>

std::string toUpper(std::string& str) {

    std::transform(str.begin(), str.end(), str.begin(), [] (char c) {return toupper(c);});
    return str;
}
std::string toLower(std::string& str) {

    std::transform(str.begin(), str.end(), str.begin(), [] (char c) {return tolower(c);});
    return str;
}
std::string title_upper(std::string& str) {

    bool newWord = true;
    for (char& c : str) {
        if (c == ' ') {
            newWord = true;
        }
        else if (newWord) {
            c = toupper(c);
            newWord = false;
        }
    }
    return str;
}

void write(std::string& line, int& wrap, std::string& prefix, std::ofstream& output) {
    std::stringstream ss(line);
    std::string word;
    std::string currentLine;
    while(ss >> word) {
        if (currentLine.size() > wrap) {
            output << prefix << currentLine << "\n";
            currentLine = word;
        }else {
            if(!currentLine.empty()) output << " ";
            currentLine += word;
        }

    }

}

int main() {
    std::ifstream formatfile("format.cfg");
    std::ifstream inputfile("input.txt");
    std::ofstream outputfile("output.txt");

    if(!formatfile.is_open() || !inputfile.is_open() || !outputfile.is_open()) {
        std::cerr << "can't open file";
        return 1;
    }
    std::string line;

    
    std::getline(formatfile, line);
    auto it = line.find("=");
    std::string uppercase = line.substr((it + 1));
    std::getline(formatfile, line);
    it = line.find("=");
    int wrap = std::stoul(line.substr((it + 1)));
    std::getline(formatfile, line);
    it = line.find("=");
    std::string prefix = line.substr((it + 1));

 
    while(std::getline(inputfile, line)) {
        if (uppercase == "title") {
            line = title_upper(line);
        }else if (uppercase == "all") {
            line = toUpper(line);
        }else if (uppercase == "none") {
            line = toLower(line);
        }

        std::stringstream ss(line);
        write(line, wrap, prefix, outputfile);
    }

    
}