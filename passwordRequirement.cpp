// Purpose: this program is used to make sure that the
// password created by the user satisfy the password requirements
// Copyright 2023, Harry Vu

// Coding Trails: This has been approved by Professor Aise Zulal Sevkli
// 1st change: Changing the password at least 9 characters
// to 8 characters, adding
// printing out "OK" if all the requirements are met.
// 2nd change: try to test using long unsigned int for the
// loop but does not work out
// 3rd change: try to cast the sizeof() function from long unsigned
// int to int using (int)
// 4th change: Using static_cast<int> instead
// 5th change: Fixing based on cpplint.py
// 6th change: Adding comments

#include <iostream>
#include <cctype>
#include <string>

int main() {
  /* Type your code here. */
  // Get the input from the user
  std::string password;
  std::cin >> password;

  // Declare variables
  unsigned int count = 0;
  // These boolean are true if the password meets the
  // requirements for letter, number and special
  // character, respectively
  bool letter, number, special;
  char specialC[] = {'!', '#', '%'};
  // loop through every char in the password
  for (char c : password) {
     // Increase the count
     count++;
     if (isalpha(c)) {
      // if contains letter --> true
        letter = true;
     } else if (isdigit(c)) {
      // if contains number --> true
        number = true;
      }

     // if contains special character --> true
     for (int i = 0; i < static_cast<int>(sizeof(specialC)); i++) {
        if (specialC[i] == c) {
           special = true;
        }
     }
  }

  // check if the password is less than 8 characters
  if (count < 8) {
     std::cout << "Too short" << std::endl;
  }

  // check if the password contains at least one letter
  if (!letter) {
     std::cout << "Missing letter" << std::endl;
  }

  // check if the passwords contains at least one number
  if (!number) {
     std::cout << "Missing number" << std::endl;
  }

  // Check if the password contains a special character
  if (!special) {
     std::cout << "Missing special" << std::endl;
  }

  // If all requirements are met, the password is Ok.
  if (count >= 8 && letter && number && special) {
     std::cout << "OK" << std::endl;
  }

  return 0;
}
