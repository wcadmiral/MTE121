//Person A: Sidant Medhra
//Person B: Allen Zhu
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


//array maximum constants
const int MAX=50;
const int DeltaMAX=30;

//function 1(read current file)
void readCurrent(ifstream& fileIn, int (&PersonTypeList)[MAX], string (&PersonList)[MAX]){
    int counter = 0;
    string name = "";
    int personType = 0;
    int spot = 0;
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
}


//function 2(read add and remove files)
void readDelta(ifstream& fileIn, int (&PersonTypeList)[DeltaMAX], string (&PersonList)[DeltaMAX]){
    int counter=0;
    string name="";
    int personType = 0;
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
}


//function 3(remove one person)
void removePerson(int(&currentPeopleType)[MAX], string(&currentPeople)[MAX], string removedPerson){
    bool isRemoved=false;
    for (int i=0; i<MAX && !isRemoved; i++){
        if (removedPerson == currentPeople[i]){
        currentPeople[i] = "";
        currentPeopleType[i] = 0;
        isRemoved=true;
        }
    }    
}

//function 4(find space)
int findSpace(string(&CurrentPeople)[MAX], int PersonType){
    int lowestValidSpace = 0;
    bool isDone =  false;
    if (PersonType == 1){
        for (int i=0; i<MAX && !isDone; i++){
            if (CurrentPeople[i]==""){
                lowestValidSpace = i+101;
                isDone = true;
            }
        }
    }
    else{
        for (int i=24; i<MAX && !isDone; i++){
            if (CurrentPeople[i]==""){
                lowestValidSpace = i+101;
                isDone = true;
            }
        }
    }
    if (!isDone){
        lowestValidSpace=0;
    }   
    return lowestValidSpace;
}


//function 5(add one person)
bool addPerson (int (&CurrentPeopleType)[MAX], string(&CurrentPeople)[MAX], string Person, int PersonType){
    bool isSpace= false;
    int spaceNumber=findSpace(CurrentPeople, PersonType);
    if (spaceNumber == 0){
        isSpace =  false;
    }
    else{
        CurrentPeople[spaceNumber-101] = Person;
        CurrentPeopleType[spaceNumber-101] = PersonType;
        isSpace = true;
    }
    return isSpace;
}

//function 6(reorganize parking)
void reorganizeParking (int (&CurrentPeopleType)[MAX], string(&CurrentPeople)[MAX]){
    int CurrentPersonType = 0;
    string CurrentPerson ="";
    for (int i=24; i<MAX; i++){
        if (CurrentPeopleType[i] == 1){
            CurrentPerson=CurrentPeople[i];
            CurrentPersonType=CurrentPeopleType[i];
            removePerson(CurrentPeopleType, CurrentPeople, CurrentPerson);
            addPerson(CurrentPeopleType, CurrentPeople, CurrentPerson, CurrentPersonType);

        }
    }
}

//function 7(output to file)
void output(ofstream& fout, string title, int(&CurrentPeopleType)[MAX], string(&CurrentPeople)[MAX]){
    bool isDone =  false;
    fout << title << endl;
    fout << setw(10) << "Spot" << setw(20) << "Name" << setw(10) << "Type" << endl;
    for (int i=0; i<MAX && !isDone; i++){
        fout << setw(10) << i+101 << setw(20) << CurrentPeople[i] << setw(10) << CurrentPeopleType[i] << endl;
    }

}

int main(){

    //declare objects and arrays
    ifstream fin;
    ofstream fout;
    string currentPeople[MAX] ={};
    int currentPeopleType[MAX] ={}; 
    string addedPeople[DeltaMAX] ={};
    int addedPeopleType[DeltaMAX] ={};
    string removedPeople[DeltaMAX] ={};
    int removedPeopleType[DeltaMAX] ={};
    string extraPeople[DeltaMAX]={};

    //read all text files and write into arrays
    fin.open("parking_current.txt");
    readCurrent(fin, currentPeopleType, currentPeople);
    fin.open("parking_add.txt");
    readDelta(fin,  addedPeopleType, addedPeople);
    fin.open("parking_remove.txt");
    readDelta(fin, removedPeopleType, removedPeople);
    
    //output initial state
    fout.open("initial_parking.txt");
    output(fout, "initial", currentPeopleType, currentPeople);
    fout.close();

    //remove people 
    for (int i=0; i<DeltaMAX; i++){
        removePerson(currentPeopleType, currentPeople, removedPeople[i]);
    }

    //reorganize existing people
    reorganizeParking(currentPeopleType, currentPeople);

    //output reorganized state
    fout.open("reorganized_parking.txt");
    output(fout, "reorganized", currentPeopleType, currentPeople);
    fout.close();


    //add people
    bool isSpace=false;
    int counter=0;
    for (int i=0; i<DeltaMAX; i++){
        isSpace=addPerson(currentPeopleType, currentPeople, addedPeople[i], addedPeopleType[i]);
        if (isSpace==false){
            cout << addedPeople[i] << " was not given a spot." << endl;
        }
    }


    //output to file
    fout.open("parking_update.txt");
    output(fout, "final", currentPeopleType, currentPeople);
    fout.close();

}