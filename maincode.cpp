#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

//global variable (number used to determine the amount of questions)
int range = 5;
bool result = false;

//function to add text delay
void displayTextLetterByLetter(const std::string& text, int delayMilliseconds) {
   for (char ch : text) {
      cout << ch << flush; 
      this_thread::sleep_for(chrono::milliseconds(delayMilliseconds)); 
   }
   cout << endl;
}

bool divi(){
   int answer;
   int rightNum = 0;
   int wrongNum = 0;
   result = false;
   
   for (int a = 0; a < range; ++a) {
      int num1 = (rand() % 25) - 12;
      int num2 = (rand() % 25) - 12;
      while (num1 % num2 != 0){
         num1 = (rand() % 25) - 12;
         num2 = (rand() % 25) - 12;
      }
      cout << num1 << " / " << num2 << " = ?" << endl;
      cin >> answer;
      if (answer == num1 / num2){
         cout << "Correct!" << endl;
         ++rightNum;
      }
      else {
         ++wrongNum;
         cout << "Incorrect!" << endl;
      }
      if (rightNum > wrongNum) {
         result = true;
      }
   }
   return result;
}

bool mult(){
   int answer;
   int rightNum = 0;
   int wrongNum = 0;
   result = false;
    
   for (int b = 0; b < range; ++b) {
      int num1 = (rand() % 25) - 12;
      int num2 = (rand() % 25) - 12;
      cout << num1 << " * " << num2 << " = ?" << endl;
      cin >> answer;
      if (answer == num1 * num2){
         cout << "Correct!" << endl;
         ++rightNum;
      }
      else {
         cout << "Incorrect!" << endl;
         ++wrongNum;
      }
      if (rightNum > wrongNum) {
      result = true;
      }
   }
   return result;
}

bool add(){
   int num1; 
   int num2;
   int answ;
   int rightNum = 0;
   int wrongNum = 0;
   result = false;
   for (int c = 0; c < range; ++c) {
      num1 = rand() %  41 - 20;
      num2 = rand() % 41 - 20;
      cout << num1 << " + " << num2 << " = ?" << endl;
      cin >> answ;
      if(answ == (num1 + num2)){
         cout << "Correct!" << endl;
         ++rightNum;
      }
      else {
         cout << "Incorrect!" << endl;
         ++wrongNum;
      }
      if (rightNum > wrongNum) {
         result = true;
      }
   }
   return result;
}

bool sub(){
   int answ;
   int rightNum = 0;
   int wrongNum = 0;
   result = false;
   
   for (int d = 0; d < range; ++d) {
      int num1 = rand() % 41 - 20;
      int num2 = rand() % 41 - 20;
      cout << num1 << " - " << num2 << " = ?" << endl;
      cin >> answ;
      if(answ == num1 - num2){
         cout << "Correct!" << endl;
         ++rightNum;
      }
      else {
         cout << "Incorrect!" << endl;
         ++wrongNum;
      }
      if (rightNum > wrongNum) {
         result = true;
      }
   }
   return result;
}


int main() {
   
   //declaring variable
   int petRate;
   string userName;
   string petName;
   string bossName;
   char playGame;
   char captPet;
   const int delay = 60; 
   int option;
   char seeAn;
   
   //asking user if they want to play
   string message0 = "Do you want to play (Y/N): ";
   displayTextLetterByLetter(message0, delay);
   cin >> playGame;
   playGame = toupper(playGame);
   while ((playGame != 'Y') && (playGame != 'N')) {
      string message0 = "Enter Y or N: ";
      displayTextLetterByLetter(message0, delay);
      cin >> playGame;
      playGame = toupper(playGame);
   }
   
   //playing the game if user put Y in previous statement
   if (playGame == 'Y') {
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
   string message9 = userName + " has encountered a wild animal, would you like to try to befriend it (Y/N): ";
   displayTextLetterByLetter(message9, delay);
   cin >> seeAn;
   seeAn = toupper(seeAn);
   while ((seeAn != 'Y') && (seeAn != 'N')) {
      string message11 = "Enter Y or N: ";
      displayTextLetterByLetter(message11, delay);
      cin >> seeAn;
      seeAn = toupper(seeAn);
   }
   petRate = (rand() % 10) + 1;
   if (seeAn == 'Y') {
      if (petRate == 5) {
         string message5 = "You've captured the pet! Would you like to name it? (Y/N): ";
         displayTextLetterByLetter(message5, delay);
         cin >> captPet;
         captPet = toupper(captPet);
         range = 3;
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
            string message8 = "Ok... the pet will be nameless :(";
            displayTextLetterByLetter(message8, delay);
         }
      }
      else {
         string message12 = "Sorry the animal ran away... :(";
         displayTextLetterByLetter(message12, delay);
      }
   }
   else {
      string message13 = "Ok... the animal will be all alone... ;(";
      displayTextLetterByLetter(message13, delay);
   }

   
   //the choice of class system, corresponds to which function is called
   cout << endl << "What math questions would you like?" << endl << "Enter 1 for addition\nEnter 2 for subtraction\nEnter 3 for multiplication\nEnter 4 for division\n" << endl;

   cin >> option;

   while(!(option > 0 && option < 5)) {
      cout << "Please enter one of the numbers above." << endl;
      cin >> option;
   }
   
   if(option == 1) {
      add();
   }
   else if(option == 2) {
      sub();
   }
   else if(option == 3) {
      mult();
   }
   else {
      divi();
   }
   
   if (result == true) {
      cout << endl << "You beat " << bossName << endl;
   }
   else{
      cout << endl<< "You Lose" << endl;
   }
   
   }
   
   return 0;
}