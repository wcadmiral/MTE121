#include <iostream>
#include <climits>

using namespace std;

int main(){
    //initialize variables
    float distance = 0.0;
    int items = 0;
    int day = 0;
    int counter = 0;
    int cost_cents = 0;
    float cost = 0.0;
    float MAX = 0.0;

    for (int i=1; i<=20; i++){
        cout <<endl << "enter your distance, items, and day" << endl;
        cin >> distance;
        cin >> items;
        cin >> day;
        
        cost_cents = 2000 + distance*25;

        if (items <=5){
            cost_cents = cost_cents + 2000*items;
        }
        else if (items <=10){
            cost_cents = cost_cents + 2000*5 + 1000*(items-5);
        }
        else{
            cost_cents = cost_cents + 2000*5 + 1000*5 + 500*(items-10);
        }

        if (day == 6){
            cost_cents = cost_cents*1.1;
        }
        else if (day ==7){
            cost_cents= cost_cents*1.2;
        }

        if (counter==3 && cost_cents>10000){
            cost_cents=cost_cents * 0.95;
            counter = 1;
            cost = cost_cents/100;
            cout << "Total cost: " << cost << "with discount";
        }
        else if (cost_cents >10000){
            counter=counter+1;
            cost = cost_cents/100;
            cout << "Total cost: " << cost;
        }
        else {
            cost=cost_cents/100;
            cout << "Total cost: " << cost;
        }
        if (cost>MAX){
            MAX = cost;
        }
    }
    cout << "max cost was: " << MAX;


}