#include <iostream>
#include<fstream> //includes 2 classes: ifstream and ofstream, allows read and write from files, i.e. file operations
#include<climits> //provides INT_MIN, the smallest possible int value in c++
using namespace std;

int main(){
    ifstream fileReader; //creates an input file object for reading
    fileReader.open("numbers.txt"); //opens the file containing the numbers
    if(fileReader.is_open()){ //checks if file is open
        int num=0; //stores each number read from the file
        int max=INT_MIN; //starts the maximum at the smallest possible int value
        while(fileReader>>num){ //reads one number at a time until the file ends
            if (num>max){ //checks whether the new number is larger than the current maximum
                max=num; //updates the maximum when a larger number is found
            }
        }
        cout<< "Maximum is "<<max<<endl; //displays the largest number found
    }
    else{ //error handling
        cout <<"Error opening file" << endl;
    }
    fileReader.close(); //closes the file after reading is finished
    return 0;
}