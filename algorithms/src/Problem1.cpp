#include "Problem1.hpp"
#include <iostream>

namespace Problem1 {

  // Receives the size of the alphabet of which it must determine the encoded size
  // 1. Continues increasing power of 2 until entire alphabet can fit
  // 2. Logs the power of 2 necessary to encompass all encodings for size
  void Run(int alphabetSize)
  {
    int pwr2 = 0;
    int product = 1;

    while (product < alphabetSize) {
      product *= 2; 
      ++pwr2;
    }

    std::cout << "The number of bits: " << pwr2 << std::endl;
  }
} 