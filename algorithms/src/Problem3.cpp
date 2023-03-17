#include <stdio.h>
#include "Problem3.hpp"

namespace Problem3 
{
  // O(n^2)
  // - Loops through each array position, and for each, loops again through the
  //   array, multiplying all other elements, excluding the one at that position.
  void GetProductArrayV1(int size, int *in, int *out)
  {
    for (int i = 0; i < size; ++i)
    {
      int number = 1;
      for (int j = 0; j < size; ++j)
      {
        if (j != i)
        {
          number *= in[j];
        }
      }
      out[i] = number;
    }
  }

  // O(n) (with division)
  // - Loops through each array position, continously mutliplying a total product
  //   of all the numbers. It then loops again, dividing each array position by 
  //   the number in the same array position, in order to exclude it.
  void GetProductArrayV2(int size, int *in, int *out)
  {
    int product = 1;
    for (int i = 0; i < size; ++i)
    {
      product *= in[i];
    }
    for (int i = 0; i < size; ++i)
    {
      out[i] = product / in[i];
    }
  }

  // O(n)
  // - Loops through both ends of the array, counting up total product of the 
  //   "prefixes" up until that point as well as the "suffixes" and multiplies
  //   both together to find the total product of the array, excluding the number
  //   at each index.
  void GetProductArrayV3(int size, int *in, int *out)
  {
    int prefixes[size];
    int suffixes[size];
    int preProduct = 1;
    int sufProduct = 1;
    prefixes[0] = 1;
    suffixes[size - 1] = 1;
    for (int i = 0; i < size; ++i)
    {    
      prefixes[i] = preProduct;
      preProduct *= in[i];
    }
    for (int i = 0; i < size; ++i)
    {
      suffixes[size - i - 1] = sufProduct; 
      sufProduct *= in[size - i - 1];
    }
    for (int i = 0; i < size; ++i)
    {
      out[i] = prefixes[i] * suffixes[i];
    }
  }

  void Run(int *array, int size)
  {
    int array2[size];

    GetProductArrayV3(size, array, array2);
    PrintArray(size, array2);
  }

  void PrintArray(int size, int *array)
  {
    for (int i = 0; i < size; ++i)
    {
      printf("%d  ", array[i]);
    }
    printf("\n");
  }
}