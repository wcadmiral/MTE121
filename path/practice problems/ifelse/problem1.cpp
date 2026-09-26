#include <iostream>
using namespace std;

int main(){
    int age =0;
    int visits = 0;
    int days = 0;
    int points = 0;


    cout << "Insert your age: \n";
    cin >> age;
    cout << "How many days are you staying? \n";
    cin >> days;
    cout << "How many parks are you visiting? \n";
    cin >> visits;

    if (age < 0 || days <0 || visits<0){
        cout << "Invalid data";
    }
    else{
        if (age <= 2){
            points = 40* days;
        }
        else if (age <= 9) {
            points = 100* days;            
        }
        else{
            if (visits>days){
                points = ((visits-days)%days)*140+ ((days-(visits-days)%days))*100;
            }
            else{
                points = 100*days;
            }

        }
        if (age>2 && days>4){
            points=points*0.75;
        }
        cout << "You need " << points << " points.";
    }
}