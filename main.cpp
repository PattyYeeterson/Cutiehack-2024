#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
#include <list>


using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace chrono; // nanoseconds, system_clock, seconds
using std::chrono::system_clock;

int range = 5;
bool result = false;


void printText(string text){
    for (char c : text) {
        std::cout << c << std::flush;  // Print character immediately without a newline
        std::this_thread::sleep_for(std::chrono::milliseconds(20));  // ms delay
    }
    cout<<endl;
}

class Answer {
    //all functions are here
    public:

        Answer(){
            answer = "a";
        }

        string decision(){
            return answer;
        }

        void choice(string startText, string prompt, string yesOutcome, string noOutcome, string decision){
            printText(startText);
            printText(prompt);
            cin>>decision;
            answer = decision;
            while(true){
                if(decision == "y"){
                    printText(yesOutcome);
                    break;
                }
                else if(decision == "n"){
                    printText(noOutcome);
                    break;
                }
                else{
                    cout<<"Please enter y or n."<<endl;
                }
            }
        }

        void choiceForcedYes(string startText, string prompt,string yesOutcome, string noOutcome, string decision){
            printText(startText);
            printText(prompt);
            cin>>decision;
            answer = decision;
            while(true){
                if(decision == "y"){
                    printText(yesOutcome);
                    break;
                }
                else{
                    printText(noOutcome);
                    cout << endl;
                    cin>>decision;
                }
            }
        }

    private:
        string answer;

};

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

void mathGame(int option){
   while(!(option > 0 && option < 5)){
      cout << "Please enter one of the numbers above." << endl;
      cin >> option;
   }
   
   if(option == 1){
      add();
   }
   else if(option == 2){
      sub();
   }
   else if(option == 3){
      mult();
   }
   else{
      divi();
   }
}
    
int main() {
    srand(time(0));
    Answer userDecision;
    //int petRate;
    string userName;
    string petName;
    string bossName;
    //char captPet;
    int option;
    
    string message1 = "Enter your username (no spaces): ";
    printText(message1);
    
    cin >> userName;
    while (userName.size() > 10) {
       string message2 = "The username is too long, enter a new one: ";
       printText(message2);
       cin >> userName;
    }
    
    message1 = "Enter the Boss's name (no spaces): ";
    printText(message1);
    
    cin >> bossName;
    while (bossName.size() > 10) {
       string message2 = "The boss name is too long, enter a new one: ";
       printText(message2);
       cin >> bossName;
    }
    
    string startText = "On a cold brisk saturday morning there was a hackathon brewing and everyone was peacefully waiting to get ready. As the announcers begin to shout the countdown for the hackathon to commence, a wild "+ bossName +" appeared and warned everyone that if this hackathon commences, "+bossName+" will ensure we regret it. Despite "+ bossName+ " regards, we continued “3…2…1 Ha-” before the announcers could finish the words, "+bossName+" one fell swoop stole all the hackers, however one hero named "+userName+" escaped and hid in a knick of time. It is up to our hero "+ userName +" to now save everyone!";
    string choiceOne = "Do you accept? Y or N:";
    string choiceOneYes = "since you accepted the quest. You leave Winston Chung and venture to find where "+ bossName +" took the hackers. As you leave you see a mentor standing named Ryan, and it appears he knows about the "+bossName+".He tells us the lore, "+ bossName+" is a rival of the revered Highlanders and they come once a year to disrupt the hackers. "+bossName+" is evil and one young hacker must venture to defeat him. ";
    string choiceOneNo = "Think of the people suffering!!! Have you no heart? Choose again wisely.";
    string deci = "";
    string prompt;
    userDecision.choiceForcedYes(startText, choiceOne, choiceOneYes, choiceOneNo, deci);

    string contextTwo = ""; // same as choice one
    string choiceTwo = "Do you wish to learn where the cave where everyone was taken is located? If not, I'll continue talking.";
    string choiceTwoYes = "Ryan tells you that the cave is located on the top of the nearest mountain and you must now venture to attack "+bossName+" to save everyone.";
    string choiceTwoNo = "You listen on and Ryan gives you the instructions to the secret lair of "+ bossName+". You must follow take two left turns in the corroder. You follow his instruction and you continue on.";
    userDecision.choice(contextTwo, choiceTwo, choiceTwoYes, choiceTwoNo, deci);

    // wants to know where lair is, no to continue talking
    
    if(userDecision.decision() == "y"){
        string contextThree = ""; // same as choice made
        string choiceThreePrevYes = "After a long and egregious hike up the nearest mountain, " + userName +" comes across the lair and they decide to enter. "+ userName + " comes across the complicated firewall of the security system and in order to defeat it you engage it in battle.";
        printText(choiceThreePrevYes);
        //math battle
        cout << endl << "What math questions would you like?" << endl << "Enter 1 for addition\nEnter 2 for subtraction\nEnter 3 for multiplication\nEnter 4 for division\n" << endl;
        cin >> option;
        mathGame(option);
        if (result == true) {
            cout << endl << "You defeated the firewall!" << endl;
            string contextfirewallwin = "Now " + userName + " comes across a corridor where they have an option to go left or right. ";
            string choiceFourFinal = "Do you go left?";
            string choiceFourYes = userName + " found " + bossName + " and now has to fight them to free everyone!";
            string choiceFourNo= "You died, this corridor led to a dead end...and lead to your deadend.";
            userDecision.choice(contextfirewallwin, choiceFourFinal, choiceFourYes, choiceFourNo, deci);
            if(userDecision.decision() == "y"){
                cout << endl << "What math questions would you like?" << endl << "Enter 1 for addition\nEnter 2 for subtraction\nEnter 3 for multiplication\nEnter 4 for division\n" << endl;
                cin >> option;
                mathGame(option);
                if(result == true){
                    cout <<"After a long battle against " << bossName << ", you've managed to save everyone from the treacherous evil! As a result, you return to the hackathon with everyone safe and you are revered a hero." << endl;
                }
                else{
                    cout << userName << " got captured and as a result everyone couldn't make it back to the hackathon and Ryan was sad.";
                }
                return 0;
            }

        }
        else{
            cout << endl<< "The firewall incinerated you (skill issue)." << endl;
            return 0;
        }
    }
    
    if(userDecision.decision() == "n"){
        string contextThreeNo = userName + " arrives at the corridor."; //same as choice 2 no
        string choiceThreePrevNo = "Do you go left?";
        string choiceThreeYes = "You made it to the next turn";
        string choiceThreeNo = "You failed to listen to the goat Ryan and you died.";
        userDecision.choice(contextThreeNo, choiceThreePrevNo, choiceThreeYes, choiceThreeNo, deci);
        if(userDecision.decision() == "y"){
            string contextFourYes = userName +" makes it to the next turn and is once again faced with a choice between a left or right turn."; //same as choice 2 no
            string choiceFour = "Do you go left?";
            string choiceFourYes = "You arrive to the lair and find all the hackers. You try to negotiate with "+bossName+" and you strike a deal, trading your life for the freedom of the hackers. You will forever be remembered as the hero who saved cutiehack.";
            string choiceFourNo = "You failed to listen to the goat Ryan and you died.";
            userDecision.choice(contextThreeNo, choiceThreePrevNo, choiceThreeYes, choiceThreeNo, deci);
            return 0;
        }
        return 0;
    }

/* needs to track which choice is made, maybe input value for decision outside of the functicon and assign it to a different variable*/
    string contextFour = "You're in! Now you come across a corridor.";
    string choiceFour = "Does "+userName+" go left?";
    string choiceFourYes = userName+" decided to go left and suddenly… "+bossName+" appears and now it is time to fight the boss!";
    string choiceFourNo = userName+" decided to go right and it led to them to a hall where all the hackers were captured. As "+userName+" frees them one by one they notice that "+bossName+" is not there.";
    userDecision.choice(contextFour, choiceFour, choiceFourYes, choiceFourNo, deci);
    if (userDecision.decision() == "y"){
        mathGame(option);
        if (result == true) {
            cout << endl << "You beat " << bossName << endl;
        }
        else{
            cout << endl<< "You Lose" << endl;
            return 0;
        }
    }

    string contextFive = ""; // same as choice four no
    string choiceFive = "Do you want to explore the cave more or continue saving people? ";

    
    
    return 0;
}
