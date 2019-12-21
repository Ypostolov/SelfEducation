#include <iostream>

int main() {
  uint16_t number_of_blocks = 0;
  uint16_t density_of_block = 0;
  uint16_t W = 0;
  uint16_t H = 0;
  uint16_t D = 0;
  uint64_t total_weight = 0;

  std::cin >> number_of_blocks;
  std::cin >> density_of_block;
  for (size_t i = 0; i < number_of_blocks; ++i) {
    std::cin >> W >> H >> D;
    total_weight += W * H * D;
  }

  total_weight *= density_of_block;
  std::cout << total_weight << std::endl;

  return 0;
}
