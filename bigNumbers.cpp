#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
std::string addString(std::string str1, std::string str2) {
    int i = str1.size() - 1;
    int j = str2.size() - 1;
    int carry = 0;
    std::string res;

    while(i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? str1[i--] - '0' : 0;
        int y = (j >= 0) ? str2[j--] - '0' : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        res.push_back((sum % 10) + '0');
    }
    std::reverse(res.begin(), res.end());
    return res;

}

int main() {
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "can't open file";
        return 1;
    }

    std::string sum = "0";

    std::string line;
    std::cout << line;
    while(std::getline(input,line)){

        sum = addString(sum,line);
    }
    std::cout << sum << std::endl;

    return 0;
}
