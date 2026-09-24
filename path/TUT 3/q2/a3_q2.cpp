#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <math.h>
using namespace std;

int main(){
    //initialize objects and open files
    ifstream read;
    ofstream write;
    read.open("taxi.txt");
    write.open("report.txt");

    //initialize variables
    int trip_number = 0;
    double cumulative_distance = 0.0;


    if (read.is_open() && write.is_open()){
        write << setw(10) << "Trip" << setw(20) << "VIP" << setw(20) << "number of stops" << setw(20) << "total distance" << setw(20) << "total cost" << setw(20) << "odometer";
        int isVIP = 0;
        int number_of_stops = 0;
        float total_distance;
        while (read >> isVIP >> number_of_stops){
            trip_number++;
            float total_trip_distance = 0.0;
            float cost = 0.0;
            float x1_value = 0.0;
            float y1_value = 0.0;
            float x2_value = 0.0;
            float y2_value = 0.0;
            for (int i=0; i < number_of_stops; i++){

                read >> x2_value >> y2_value;
                total_trip_distance += sqrt(pow(x2_value-x1_value, 2.0) + pow(y2_value-y1_value, 2.0)); 
                x1_value = x2_value;
                y1_value = y2_value;
            }

            total_trip_distance += sqrt(pow(x1_value, 2.0) + pow(y1_value, 2.0)); 
            total_distance += total_trip_distance;

            if (isVIP == 1){
                cost = 0.75*(15*number_of_stops + 2.6*total_trip_distance);
            }
            else{
                cost = 15*number_of_stops + 2.6*total_trip_distance;
            }
            

        }
    }
    else{
        cout <<"error opening file";
    }
}