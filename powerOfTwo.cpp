// Purpose: To determine whether a number is a power of
// 2 or not using bitwise operation
// Copyright by Harry Vu, Feb 21, 2023

// Coding Trails: This has been approved by Professor Aise Zulal Sevkli
// 1st change: Taken 0 into account
// 2nd change: going to next lines after printing
// 3rd change: fixing based on cpplint.py
// 4th change: adding comments

#include <iostream>

int main() {
  /* Type your code here. */
  unsigned int number;
  // Get the input from the user
  std::cout << "Enter an unsigned integer number:" << std::endl;
  std::cin >> number;
  // the power of 2 numbers, their binary version would only
  // contain one "1" and the rest is "0". So when minus it by 1,
  // we are left with some 0(s) and some 1(s) in a sequence.
  // Example: "001000" - "000001" = "000111". After that, by using "&"
  // operation between the number and (number - 1), if the number is the
  // power of 2, the result should be 0.
  // Noting that for if(integer), it is true when the number is different
  // from 0 and false when the number is 0. Thus, add "!" to make
  // !(number & (number - 1)) true when it is a power of 2.
  // Also, need tto take 0 into consideration so use the logical operator
  // && to make sure that 0 won't be recognized as a power of 2 by the function
  // Result: (number && !(number & (number - 1))).
  if (number && !(number & (number - 1))) {
    // When the number is power of two
    std::cout << number << " is a power of two." << std::endl;
  } else {
    // When the number is not a power of two
    std::cout << number << " is NOT a power of two." << std::endl;
  }

  return 0;
}
