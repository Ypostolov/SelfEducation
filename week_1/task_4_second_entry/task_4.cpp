#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string string_;
    std::cin >> string_;
    int count_ = count(string_.begin(), string_.end(), 'f');
    if (count_ == 1) {
        std::cout << -1;
    }
    else if (count_ == 0) {
        std::cout << -2;
    }
    else {
        std::cout << (string_.find('f', string_.find('f') + 1));
    };

    return 0;
}