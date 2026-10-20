#include <iostream>
#include <fstream>
using namespace std;

int main(){
    const  int MAX = 5;
    int numbers[MAX] = {1,4,5,9,7};
    bool isFound = false;
    int num = 0, i=0;

    cout <<"Enter the number to be found: \n";
    cin >> num;
    while(!isFound && i<MAX){
        if (numbers[i] == num){
            isFound = true;
        }
        else{
            i++;
        }
    }
    if (isFound){
        cout<< "The number is in position " <<i+1<<endl;
    }
    else {
        cout << "Could not find number" <<endl;
    }
}

