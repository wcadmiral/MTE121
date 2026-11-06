#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int deltaF (int mass, string direction){
    if (direction == "departing"){
        mass = -mass;
    }
    int force = mass * 10;
    return force;
}

void read_write(){
    ifstream read;
    ofstream write;
    read.open("schedule.txt");
    write.open("output.txt");

    int hour, ships, max, sum, avg, total_force, force, total_hours;
    string direction;

    if (read.is_open() && write.is_open()){
        while (read >> hour >> ships){
            total_force = 10000;
            for (int i = 1; i<=ships; i++){
                read >> force >> direction;
                total_force += deltaF(force, direction);
            }
            write << setw(10) << hour <<setw(10)<<  total_force;
            total_hours=total_hours+1;
            if (total_force>max){
                max=total_force;
            }
            sum+=total_force;
        }
        avg=sum/total_hours;
        write << setw(10)<<max << setw(10) << avg;
    }
}

int main(){
    read_write();
    return 0;
}