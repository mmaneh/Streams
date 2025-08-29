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

    char ch;


    while(inputFile.get(ch)) {    
        if (isalpha(ch)) {
            if (ch == 'z') ch = 'a';
            else if(ch == 'Z') ch = 'A';

            else ch += 1;        
        }

        outputFile.put(ch);
    }


    
    inputFile.close();
    outputFile.close();
}