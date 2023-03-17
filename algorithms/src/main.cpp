#include <iostream>
#include "Problem1.hpp"
#include "Problem2.hpp"
#include "Problem3.hpp"
#include "Problem4.hpp"

using namespace std;

int main(int argc, char** argv)
{
  (void)argc;
  (void)argv;

  // Sample prompts: 26, 33
  Problem1::Run(26);

  // Sample prompts: ace, add
  Problem2::RunEncipher("ace");

  // Sample prompts: 1001101, 1101110011001101
  Problem2::RunDecipher("1001101");

  // Sample prompts: [ 1, 2, 3, 4, 5 ], [ 3, 2, 1 ]
  int array3[] = { 1, 2, 3, 4, 5 };
  int size3 = 5;

  Problem3::Run(array3, size3);

  // Sample prompts: [ 3, 7, 5, 6, 9 ], [ 3, 7, 5, 6, 9, 8 ]
  int array4[] = { 3, 7, 5, 6, 9 };
  int size4 = 5;

  Problem4::Run(array4, size4);
  
  return 0;
}