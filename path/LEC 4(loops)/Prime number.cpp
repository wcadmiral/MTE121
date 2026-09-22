// Find if number n is prime
#include <iostream>
using namespace std;

int main(){
    int num = 0;
    cout << "Enter an number: \n";
    cin >> num;
    bool isPrime = true;

    for (int i=2; i<num-1 && isPrime; i++){ //&&isPrime breaks the loop if number is found to not be prime
        if (num%i == 0){
            isPrime = false;
        } 
    }

    if (isPrime){
        cout << num << " is prime.";
    }
    else{
        cout << num << " isn't prime.";
    }
}