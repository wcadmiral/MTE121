#include <iostream> //u gotta do this if you you wanna use terminal
using namespace std; //less efficient, also semicolon exist

int main(){
    int integer_name = 0; //initializes integer variable(allocates memory)
    float float_name = 0.0; //floats exist btw
    double double_name = 0.0; //better float but more memory
    string string_name = "word"; //word
    char char_name = 'e'; //letter or smth, also gotta use single quotations

    cout << "hello \n"; //print to console, also \n makes new line(no shit)
    cout << string_name << integer_name << endl; // can also do this
    cin >> float_name; // can also input btw

    integer_name = 6+7; //math exists
    integer_name = integer_name+1; //can also do this 
    integer_name += 2; //and this
    integer_name ++; //and this
    return 0; //also remember to do this cuz reasons
    //also floating points exist
}

