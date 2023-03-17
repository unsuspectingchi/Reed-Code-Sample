# Algorithms Info

Each cpp/hpp problem file is a different algorithmic puzzle that I solved with C++. Each problem is kept in a namespace within its file and can be run through calling the relevant run method within its namespace. I have grouped a few algorithmic problems I have done into this single area, while keeping as much of the code the same as possible, so I apologize if the project architecture seems inconsistent. I added some comments to the code to explain the process and any thinking behind it.

## Problems 1 & 2

Problems 1 and 2 are the first and second problems taken from the **MIT primes 2022 Computer Science Problem Set** accessable [_here_](https://math.mit.edu/research/highschool/primes/materials/2022/CSproblems2022.pdf).

The goal of these problems was to finish them quickly in order to complete as many as possible before the PRIMES deadline, and therefore the algorithms did not prioritize optimization.

## Problems 3 & 4

Problems 3 and 4 are separate C++ array manipulation problems where I worked with _Big O Notation_ to more efficiently manipulate C++ arrays. Problem 3 highlights three different algorithms, all done with different time complexities (noted in the code) to demonstrate this. The prompts for both are as follows:

#### Problem 3

_Given an array of integers, return a new array such that each element at index "i" of the new array is the product of all of the numbers in the original array, except, the one at "i."_

Input: [1, 2, 3, 4, 5]
Output: [120, 60, 40, 30, 24]

Input: [3, 2, 1]
Output: [2, 3, 6]

#### Problem 4

_Given an array of integers that are out of order, determine the bounds of the smallest window that must be sorted, in order for the entire array to be sorted._

Input: [ 3, 7, 5, 6, 9 ]
Output: (1, 3)

Input: [ 3, 7, 5, 6, 9, 8 ]
Output: (1, 5)
