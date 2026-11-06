#include <iostream>
using namespace std;

//initialize variables
double first_number = 0.0;
double second_number = 0.0;
string operation = "";
double answer = 0.0;

int main(){
    cout << "enter your first value" <<endl;
    cin >> first_number;
    cout << "enter the operation" << endl;
    cin >> operation;
    cout << "enter your second value" << endl;
    cin >> second_number;

    if (operation == "+"){
        answer = first_number + second_number;
        cout << answer << endl;

    }
    else if (operation == "-"){
        answer = first_number - second_number;
        cout << answer << endl;

    }
    else if (operation == "x"){
        answer = first_number * second_number;
        cout << answer << endl;

    }
    else if (operation == "/"){
        answer = first_number / second_number;
        cout << answer << endl;
    }
    else {
        cout << "answer is invalid";
    }
    return 0;
}
