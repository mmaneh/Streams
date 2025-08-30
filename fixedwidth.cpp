#include <iostream>
#include <fstream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.csv");

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "can't open file" <<  std::endl;
        return 1;
    }

    output << "Id,Name,DOB" << std::endl;
    
    std::string line;
    while(std::getline(input, line)) {
        std::string id = line.substr(0, 4);
        std::string name = line.substr(4, 12);
        std::string dob = line.substr(16,8);

       id.erase(id.find_last_not_of(" ") + 1);
       name.erase(name.find_last_not_of(" ") + 1);
       dob.erase(dob.find_last_not_of(" ") + 1);

       	int Id = std::stoi(id); 
        output << Id << "," << name << "," ;
        std::string year = dob.substr(0,4);
        std::string month = dob.substr(4,2);
        std::string day = dob.substr(6,2);

        output << year << "-" << month << "-" << day << std::endl;
    }

    return 0;
}
