#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//array maximum constants
const int MAX=50;
const int DeltaMAX=30;

//function 1(read current file)
int readCurrent(ifstream& fileIn, int (&PersonTypeList)[MAX], string (&PersonList)[MAX]){
    int counter = 0;
    string name = "";
    int personType = 0;
    int spot = 0;
    fileIn.open("parking_add.txt"); 
    if(fileIn.is_open()){
        while (fileIn >> personType >> name >> spot && counter<50){
            PersonTypeList[spot-101]=personType;
            PersonList[spot-101]=name;
            counter++;
        }
    }   
    else{
        cout<<"File Not Found";
    } 
    fileIn.close();
    return 0;
}


//function 2(read add and remove files)
int readDelta(ifstream& fileIn, string file, int (&PersonTypeList)[MAX], string (&PersonList)[MAX]){
    int counter=0;
    string name="";
    int personType = 0;
    fileIn.open(file);
    if (fileIn. is_open()){
        while (fileIn>>personType>>name && counter<50){
            PersonTypeList[counter]=personType;
            PersonList[counter]=name;
            counter++;
        }
    }
    else{
        cout<<"File Not Found";
    }
    fileIn.close();
    return 0;
}



int main(){
    ifstream fin;
    string currentSpaces[MAX];
    int currentSpaceType[MAX]; 
    string addedPeople[MAX];
    int addedPeopleType[MAX];
    string removedPeople[MAX];
    int removedPeopleType[MAX];
    readCurrent(fin, currentSpaceType, currentSpaces);
    readDelta(fin, "parking_add.txt", addedPeopleType, addedPeople);
    readDelta(fin, "parking_remove.txt", removedPeopleType, removedPeople);
}