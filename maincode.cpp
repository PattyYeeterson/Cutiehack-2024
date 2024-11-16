#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <ctime>
using namespace std;

int main() {
   
   //declaring variable
   int petRate;
   string userName;
   string petName;
   string bossName;
   char captPet;
   
   //making sure that the username does not exceed limit (10)
   cout << "Enter your username (no spaces): ";
   cin >> userName;
   while (userName.size() > 10) {
      cout << "The username is too long, enter a new one: ";
      cin >> userName;
   }
   
   //making sure that the boss name does not exceed limit (15)
   cout << "Enter the boss's name (no spaces): ";
   cin >> bossName;
   while (bossName.size() > 15) {
      cout << "The boss name is too long, enter a new one: ";
      cin >> bossName;
   }
   
   //Block of code for encountering the wild pet, random number to catch pet, if caught ask user to name
   srand(time(0));
   petRate = (rand() % 10) + 1;
   while (petRate != 5) {
      petRate = (rand() % 10) + 1;
      if (petRate == 5) {
         cout << "You've captured the pet! Would you like to name it? (Y/N): ";
         cin >> captPet;
         captPet = toupper(captPet);
         while ((captPet != "Y") || (captPet != "N")) {
            cout << "Enter Y or N: ";
            cin >> captPet;
            captPet = toupper(captPet);
            cout << captPet << endl;
         }
         if (captPet == 'Y') {
            cout << "What do you want to name your pet (no spaces): ";
            cin >> petName;
            cout << endl;
         }
         else {
            cout << "Ok... the wild pet is sad now :(" << endl;
         }
      }
   }
   
   
   return 0;
}
