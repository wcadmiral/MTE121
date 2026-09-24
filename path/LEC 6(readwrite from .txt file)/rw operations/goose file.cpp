#include <iostream>
#include <fstream>
#include <iomanip>//file formatting header
using namespace std;
int main(){
    ifstream read;
    read.open("goose.txt");
    ofstream write;
    write.open("goose_out.txt");
    string month = "";
    int days = 0;
    if (read.is_open()&& write.is_open()){
        write <<setw(10)<<"month"<<setw(20)<<"encounter"<<setw(20)<<"monthlyEnd"<<setw(20)<<"avgEng"<<endl; //analogous to cout<<
        while(read>>month>>days){ //reads first two items, month and number of days
            int monthlyEnc = 0;
            bool encounter = true;
            for (int i=0; i<days; i++){ //reads all the daily encounter numbers and adds them up
                read>>dailyEnc;
                monthlyEnc += dailyEnc;
            }
            if (monthlyEnc ==0){
                encounter = false;
            }
            totalEnc += monthlyEndl
            avgEnc = float(monthlyEnc)/days;
            write <<setw(10)<<month<<setw(20)<<encounters<<setw(20)<<monthlyEnc<<fixed<<setprecision(2)<<setw(20)<<avgEnc<<endl;
        }
        fileWriter<<totalEnc;
    }
    else{
        cout<<"error opening file"
    }
}