// Find all prime numbers from 2 to max
// for loops can go inside for loops(dont use same variable)
#include <iostream>
using namespace std;

int main(){
    int max = 0;
    cout << "Enter an upper limit: \n";
    cin >> max;

    for (int num = 2; num<=max; num++){
        bool isPrime = true;
        for(int i=2; i<num&&isPrime; i++){
            if (num%i==0){
                isPrime = false;
            }
        }
        if (isPrime){
            cout << num << " is prime. \n";
        }
    }

}