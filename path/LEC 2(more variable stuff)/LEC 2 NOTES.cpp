//prompts user for name(string), age(int), height(float)

#include <iostream>
int main(){
    std::string name = ""; ///initialize variables
    int age = 0;
    float height = 0.0;

    std::cout << "Enter your name: \n"; //self explanatory
    std::cin >> name;
    std::cout << "Enter your age: \n";
    std::cin >> age;
    std::cout << "Enter your height:\n";
    std::cin >> height;

    std::cout << "Your name is " << name << ". Your age is " << age << ". Your height is " << height << "."; //can do this with couts :D
    
    int number = 7;
    std::cout << number%2; // % is a mod(returns 2 if I get hit on the head and forget what a modulo is) 
    return 0;

}