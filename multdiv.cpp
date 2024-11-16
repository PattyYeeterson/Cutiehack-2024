#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool div(){
    unsigned i;
    int answer;
    int num1 = (rand() % 41) - 20;
    int num2 = (rand() % 41) - 20;
    while (num1 % num2 != 0){
        num1 = (rand() % 41) - 20;
        num2 = (rand() % 41) - 20;
    }
    cout << num1 << " / " << num2 << " = ?" << endl;
    cin >> answer;
    if (answer == num1 / num2){
        cout << "Correct" << endl;
        return true;
    }
    cout << "False" << endl;
    return false;
}

bool mult(){
    int answer;
    int num1 = (rand() % 41) - 20;
    int num2 = (rand() % 41) - 20;
    cout << num1 << " * " << num2 << " = ?" << endl;
    cin >> answer;
    if (answer == num1 * num2){
        cout << "Correct" << endl;
        return true;
    }
    cout << "False" << endl;
    return false;
}

bool add(){
   int num1 = rand() % 41 - 20;
   int num2 = rand() % 41 - 20;
   int answ;
   bool result = false;
   cout << num1 << " + " << num2 << " = ?" << endl;
   cin >> answ;
   if(answ == num1 + num2){
      result = true;
   }
   return result;
}

bool sub(){
   int num1 = rand() % 41 - 20;
   int num2 = rand() % 41 - 20;
   int answ;
   bool result = false;
   cout << num1 << " - " << num2 << " = ?" << endl;
   cin >> answ;
   if(answ == num1 - num2){
      result = true;
   }
   return result;
}
