//find max of a list of numbers, with 0 ending the game
#include <iostream>
#include <climits> //needed for INT_MIN / number limits
using namespace std;
int main(){
    cout << "Enter the number: ";
    int num = 0;
    int maximum = INT_MIN; //INT_MIN= lowest 32-bit signed number
    bool end_of_game = false;
    while (!end_of_game && cin >>num){//runs program while conditions are true
        if (num==0){
            end_of_game = true;
        }
        else{
            if (num>maximum){
                maximum = num;
            }
            cout << "Enter the next number or 0 to end the program \n";
        }
    }
    cout << "The largest number is " << maximum;
}