#include <iostream>
#include <fstream>

int main() {
    std::string line;
    std::string number;
    std::ifstream myfile ("../day1/input");
    uint64_t sum = 0;
    uint32_t l,r;

    if (myfile.is_open())
        {
            while (myfile.good())
            {
                std::getline(myfile,line);
                l = 0;
                r = line.size();
                if (line.empty()) {
                    continue;
                }
                while (l < r) {
                    if (isdigit(line[l])) {
                        number = line[l];
                        ++l;
                        break;
                    }
                    ++l;
                }
                std::string temp = {line[l-1]};
                while (l < r) {
                    if (isdigit(line[l])) {
                        temp = {line[l]};
                    }
                    ++l;
                }
                number += temp;
                sum += std::stoi(number);
            }
            myfile.close();
        }
    else
    {
        std::cout << "Unable to open file";
    }
    std::cout << sum << std::endl;
}
