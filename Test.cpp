#include <iostream>
#include <vector>
using namespace std;

void PrintItems(vector<int> numsList) {
   cout << "items:";
   for (int i = 0; i < numsList.size(); i++) {
      cout << " " << numsList.at(i);
   }
   cout << endl;
}

int main() {
   vector<int> intList(4);
   unsigned int i;

   for (i = 0; i < intList.size(); i++) {
      intList.at(i) = i;
   }
   PrintItems(intList);

   intList.erase(intList.begin() + 2);
   PrintItems(intList);

   intList.insert(intList.begin() + 1, 10);
   PrintItems(intList);

   return 0;
}