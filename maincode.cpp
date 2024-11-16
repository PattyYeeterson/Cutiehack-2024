#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

void displayTextLetterByLetter(const std::string& text, int delayMilliseconds) {
    for (char ch : text) {
        cout << ch << std::flush; 
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds)); // Added std:: prefix
    }
    cout << endl;
}

int main() {
   
   //declaring variable
   int petRate;
   string userName;
   string petName;
   string bossName;
   char captPet;
   const int delay = 60; 
   
   
   //making sure that the username does not exceed limit (10)
   string message1 = "Enter your username (no spaces): ";
   displayTextLetterByLetter(message1, delay);
   cin >> userName;
   while (userName.size() > 10) {
      string message2 = "The username is too long, enter a new one: ";
      displayTextLetterByLetter(message2, delay);
      cin >> userName;
   }
   
   //making sure that the boss name does not exceed limit (15)
   string message3 = "Enter the boss's name (no spaces): ";
   displayTextLetterByLetter(message3, delay);
   cin >> bossName;
   while (bossName.size() > 15) {
      string message4 = "The boss name is too long, enter a new one: ";
      displayTextLetterByLetter(message4, delay);
      cin >> bossName;
   }
   
   //Block of code for encountering the wild pet, random number to catch pet, if caught ask user to name
   srand(time(0));
   petRate = (rand() % 10) + 1;
   while (petRate != 5) {
      petRate = (rand() % 10) + 1;
      if (petRate == 5) {
         string message5 = "You've captured the pet! Would you like to name it? (Y/N): ";
         displayTextLetterByLetter(message5, delay);
         cin >> captPet;
         captPet = toupper(captPet);
         while ((captPet != 'Y') && (captPet != 'N')) {
            string message6 = "Enter Y or N: ";
            displayTextLetterByLetter(message6, delay);
            cin >> captPet;
            captPet = toupper(captPet);
   
         }
         if (captPet == 'Y') {
            string message7 = "What do you want to name your pet (no spaces): ";
            displayTextLetterByLetter(message7, delay);
            cin >> petName;
            cout << endl;
         }
         else {
            string message8 = "Ok... the wild pet is sad now :(";
            displayTextLetterByLetter(message8, delay);
         }
      }
   }
   
   return 0;
}
