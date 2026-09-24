#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    //initialize objects and open files
    ifstream reader;
    ofstream writer;
    reader.open("clients.txt");
    writer.open("report.txt");

    //initialize variables
    string first_name = "";
    string last_name = "";
    float initial_investment = 0.0;
    float interest_rate = 0.0;
    float final_investment = 0.0;

    if (reader.is_open() && writer.is_open()){
        writer << setw(20) <<"First Name" << setw(20) << "Last Name" << setw(20) << "Years needed" <<endl; //generate report format

        //pull variables
        while (reader>>first_name>>last_name>>initial_investment>>interest_rate>>final_investment){
            float investment = initial_investment;
            int number_of_years = 0;
            interest_rate=interest_rate/100;
            while(investment < final_investment){
                investment = investment * (1+interest_rate);
                number_of_years++;
            }
            writer << setw(20) << first_name << setw(20) << last_name << setw(20) << number_of_years << endl;
        }
    }
    else{
        cout << "Error opening file \n";
    }
    return 0;
}