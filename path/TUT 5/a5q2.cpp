//libraries and namespaces
#include <iostream>
#include <iomanip>
#include <climits>
#include <fstream>
#include <math.h>
using namespace std;


//functions
float triangle_area(float base, float height){
    float triangle_area = base*height*0.5;
    return triangle_area;
}

float polygon_area(float side_length, float inscribed_radius, int side_number){
    float total_area = triangle_area(side_length, inscribed_radius) * side_number;
    return total_area;
}

float polygon_perimeter(float side_length, int side_number){
    float perimeter = side_length*side_number;
    return perimeter;
}

float job_cost(float side_length, float inscribed_radius, int side_number){
    float total_area = polygon_area(side_length, inscribed_radius, side_number);
    float perimeter = polygon_perimeter(side_length, side_number);
    int paving_cost = 12;
    int fence_cost = 3;
    float total_cost = total_area*paving_cost + perimeter*fence_cost;
    return total_cost;
}

//main
int main(){
    //initialize file reading
    ifstream read;
    ofstream write;
    read.open("jobs.txt");
    write.open("output.txt");

    //main logic
    if (read.is_open() && write.is_open()){
        //set up output format
        write << setw(15) << "Job Number" << setw(10) << "Cost" << endl;
        
        //initilize variables
        int job_number = 0;
        int side_number = 0;
        float side_length = 0.0; 
        float inscribed_radius = 0.0;
        float maximum_cost = INT_MIN;
        int counter = 0;
        float total_cost = 0.0;
        float cost = 0.0;
        float average_cost = 0.0;

        //read input file
        while (read>> job_number >> side_number >> side_length >> inscribed_radius){

            //computation
            cost = job_cost(side_length, inscribed_radius, side_number);
            total_cost += cost;
            counter ++;
            if (cost>maximum_cost){
                maximum_cost = cost;
            }

            //output
            write << setw(15) << job_number << fixed << setprecision(2) <<setw(10) << "$"<< cost << endl;
        }

        //final output
        average_cost = total_cost/counter;
        write << "Maximum Cost: $" << maximum_cost << endl;
        write << "Total Cost: $" << total_cost << endl;
        write << "Average Cost: $" << average_cost << endl;
    }

    //error handling
    else {
        cout << "Error opening File";
    }
    return 0;
}

