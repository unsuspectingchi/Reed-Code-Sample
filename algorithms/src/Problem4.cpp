#include <stdio.h>
#include "Problem4.hpp"

namespace Problem4
{
  void Run(int *array, int size)
  {
    int lowerBound;
    int upperBound;
    FindUnsortedNumbers(size, array, &lowerBound, &upperBound);
    printf("(%d, %d)\n", lowerBound, upperBound); 
  }

  // Loops through both ranges of the array to establish the min and the max and
  // - checks the bounds against each, updating them as it loops through
  void FindUnsortedNumbers(int size, int *in, int *lowerBound, int *upperBound)
  {
    *lowerBound = size;
    *upperBound = -1;
    int max = *in;
    int min = in[size - 1];

    // Loops through the range to size - 1
    //    If in[i] < max {right = i}

    // Loops through the range to size - 2
    //    If in[i] > min { left = i }

    for (int i = 1; i < size; ++i)
    {
      if (in[i] < max)
      {
        *upperBound = i;
      } else {
        max = in[i];
      }
    }
    for (int i = size - 2; i > -1; --i)
    {
      if (in[i] > min)
      {
        *lowerBound = i;
      } else {
        min = in[i];
      }
    }
  }
}