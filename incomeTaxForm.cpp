// Purpose: This program is used to calculate U.S.
//  income tax owed given wages, taxable interest,
// unemployment compensation, status (single or married) and taxes withheld
// Copyright by Harry Vu, Feb 21, 2023

// Coding Trails: This has been approved by Professor Aise Zulal Sevkli
// 1st change: doing the first step calculating AGI
// 2nd change: doing the second step calculating deduction and taxable income
// 3rd change: making the taxable income equal 0
// when the deduction is higher than AGI
// 4th change: Doing the third step caculating the federal tax
// 5th change: Doing the last step of seeing whether tax owned or tax refund
// 6th change: Fixing based on cpplint.py
// 7th change: Adding comments + changing the name of some variables

#include <iostream>
#include <cmath>

int main() {
  /* Type your code here. */
  // declare variables
  unsigned int wage, taxInterest, unemployCom, status, withheld;
  // Get input from users
  std::cin >> wage >> taxInterest >> unemployCom >> status >> withheld;
  // Caculate AGI
  int AGI = wage + taxInterest + unemployCom;

  // Print out AGI
  std::cout << "AGI: $" << AGI << std::endl;
  // The form is not valid if AGI is bigger than 120000
  if (AGI > 120000) {
    std::cout << "Error: Income too high to use this form" << std::endl;
    return 0;
  }

  // Calculate deduction based on status
  int deduction = status == 2 ? 24000 : 12000;

  // Caculate taxable income
  int taxableInc = AGI - deduction;
  // If deuduction is larger than AGI,
  // taxable income would be zero
  if (deduction > AGI) {
    taxableInc = 0;
  }

  // Print out deduction amount and taxable income
  std::cout << "Deduction: $" << deduction << std::endl;
  std::cout << "Taxable income: $" << taxableInc << std::endl;

  double tax;

  // Caculate the tax of single
  if (status != 2) {
     if (taxableInc <= 10000) {
      tax = taxableInc*0.1;
     } else if (taxableInc <= 40000) {
      tax = 1000+0.12*(taxableInc-10000);
     } else if (taxableInc <= 85000) {
      tax = 4600 + 0.22*(taxableInc - 40000);
     } else {
      tax = 14500 + 0.24*(taxableInc - 85000);
     }
  } else {
    // calculate the tax of married
    if (taxableInc <= 20000) {
      tax = taxableInc*0.1;
    } else if (taxableInc <= 80000) {
      tax = 2000 + 0.12 * (taxableInc - 20000);
    } else {
      tax = 9200 + 0.22 * (taxableInc - 80000);
    }
  }
  // round the tax
  tax = round(tax);
  // print out the federal tax
  std::cout << "Federal tax: $" << tax << std::endl;

  // Tax need to be paid or refunded based on tax withheld
  if (tax >= withheld) {
    std::cout << "Taxes Owed: $" << tax - withheld << std::endl;
  } else {
    std::cout << "Tax refund: $" << withheld - tax << std::endl;
  }

return 0;
}
