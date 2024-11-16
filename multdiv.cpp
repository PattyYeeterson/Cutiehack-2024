#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool division(){
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

bool multiplication(){
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
int main(){
    srand(time(0));
    if (division()){
        cout << "Division done" << endl;
    }
    if (multiplication()){
        cout << "Multiplication done" << endl;
    }
    return 0;
}