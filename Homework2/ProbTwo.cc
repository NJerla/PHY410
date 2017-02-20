#include <iostream>
int main(void) {

int i1 = 2, i2 = 5, i3 = -3;
double d1 = 2.0, d2 = 5.0, d3 = -0.5;

  std::cout << "a)" << i1 + (i2 * i3) << std::endl;
  std::cout << "b)" << i1 * (i2 + i3) << std::endl;
  std::cout << "c)" << i1 / (i2 + i3) << std::endl;
  std::cout << "d)" << i1 / i2 + i3 << std::endl;
  std::cout << "e)" << 3 + 4 + 5 / 3 << std::endl;
  std::cout << "f)" << (3 + 4 + 5) / 3 << std::endl;
  std::cout << "g)" << d1 + (d2 * d3) << std::endl;
  std::cout << "h)" << d1 + d2 * d3 << std::endl;
  std::cout << "i)" << d1 / d2 - d3 << std::endl;
  std::cout << "j)" << d1 / (d2 - d3) << std::endl;
  std::cout << "k)" << d1 + d2 + d3 / 3 << std::endl;
  std::cout << "l)" << (d1 + d2 + d3) / 3 << std::endl;
  std::cout << "m)" << d1 + d2 + (d3 / 3) << std::endl;
  std::cout << "n)" << 3 * (d1 + d2) * (d1 - d3) << std::endl;
  return 0;
} 
