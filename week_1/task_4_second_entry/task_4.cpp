#include <iostream>
#include <string>

int main() {
  std::string string_;
  std::cin >> string_;

  if (string_.find('f') == std::string::npos) {
      
    std::cout << -2;
    
  } else if ((string_.find('f', string_.find('f') + 1)) > 0 &&
             (string_.find('f', string_.find('f') + 1)) != std::string::npos) {

    std::cout << (string_.find('f', string_.find('f') + 1));
    
  } else {
    std::cout << -1;
  };

  return 0;
}