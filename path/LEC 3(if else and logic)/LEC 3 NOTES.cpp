#include <iostream>
using namespace std; //too lazy now

int main(){
    int num1;
    int num2;
    int num3;

    cout << "Enter first number: \n";
    cin >> num1;
    cout << "Enter second number: \n";
    cin >> num2;
    cout << "Enter third number: \n";
    cin >> num3;

    if (num1=num2){ //I am NOT writing down what if means
        cout << "num1 is bigger than num2 \n";
    }
    else{ //nor what else means
        cout << "num1 is not bigger than num2 \n";
    }

    if (num2>num3){
        cout << "hehe text \n";
    }
    else if (num2 = num3){ //if previous if statement doesn't work check this one(no shit sherlock)
        cout << "I'm running out of things to say \n";
    }

    if (num2>num3){
        if (num2>num1){
            cout << "num2 big"; //nested if statements exist. If you do this 15 times you should be executed (I KNOW THIS CODE IS AUTISTIC STFU)
        }
    }

    if (num2>num1 && num2>num3){ //&& means and, not gonna elaborate on what and means
        cout << "num2 big";
    }

    if (num2>=num1 || num2>=num3){ //|| means or, also not gonna write down what or means
        cout << "num2 kinda big";
    }

    if (!(num2>num1 || num2>num3)){ // ! means not
        cout << "num2 kinda big";
    }

}