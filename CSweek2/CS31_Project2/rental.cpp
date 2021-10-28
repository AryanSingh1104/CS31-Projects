//
//  main.cpp
//  CS31_Project2
//
//  Created by Sprint on 12/10/21.
//
#include <string>
#include <iostream>
using namespace std;
int main(){
    
    
    int StartReading ;                                //Initiating all the integer variables
    int EndReading ;
    int Days;
    int Month;
    int Distance;
 
    
  
    double TotalDaily;
    string CustomerName;                             // Initiating all the string variables
    string LuxuryCar;
    
    cout << "Odometer at start: ";                   // Taking all the inputs for sta
    cin >> StartReading;
    cout << "Odometer at end: ";
    cin >> EndReading;
    cout << "Rental days: ";
    cin >> Days;
    cin.ignore(10000, '\n');                        // Clearing to avoid new line error after entering an intger
    cout << "Customer name: ";
    getline(cin,CustomerName);
    cout << "Luxury car? (y/n): ";
    getline(cin,LuxuryCar);
    cout << "Month (1=Jan, 2=Feb, etc.): ";
    cin >> Month;
    
    //Printing 3 hyphens
    
    cout << "---" << endl;
    
    //Checking for errors
    
    if (StartReading<0){
        cout << "The starting odometer reading must not be negative." << endl;
        return 1;
    }
    if (StartReading>EndReading){
        cout << "The ending odometer reading must be at least as large as the starting reading." << endl;
        return 1;
    }
    if (Days<=0){
        cout << "The number of rental days must be positive." << endl;
        return 1;
    }
    if (CustomerName==""){
        cout << "You must enter a customer name." << endl;
        return 1;
    }
    if (LuxuryCar != "y" && LuxuryCar != "n"){
        cout << "You must enter y or n." << endl;
        return 1;
    }
    if (Month<1 || Month>12){
        cout << "The month number must be in the range 1 through 12." << endl;
        return 1;
    }
    
    double base400=0;
    double baseCost = 0.27;
    Distance=EndReading-StartReading;
    if (Month > 11 || Month < 4)                    // Checking for winter months and alloting per mile price
        base400=0.27;
    else
        base400=0.21;

    
    int DailyPrice = 0;                     // Declared variables to calculate the total price
    double TotalPrice = 0;
    double Amount;
    
    //Checking if the user has choosen Luxury Car
    
    if (LuxuryCar=="y"){
        DailyPrice=71;
        
    }
    else if (LuxuryCar=="n"){
        DailyPrice=43;
        
    }
    //Calculating the price based on distance
    
    if (Distance<=100){
        TotalPrice = baseCost * Distance;
    }
    //Adding cost for first 100 and subtracting the distance already charged from the total distance before multiplying it by per mile price
    
        else if (Distance>100 && Distance<=500){
            TotalPrice=((baseCost*100)+((Distance-100)*base400));
            }
    // Adding all the previous costs and multiplying the distance after 500 miles by 0.17
    
        else if(Distance>500){
            TotalPrice=((baseCost*100)+((400*base400))+((Distance-500)*0.17));
            
        }
    TotalDaily=DailyPrice*Days;                     //Calculating the rental day price
    Amount=TotalPrice + TotalDaily;          //Calculating the total price: rental day and total mile driven price
    cout.setf(ios::fixed);                          // Setting compiler to present numbers upto 2 decimal places
    cout.precision(2);
    
    // Final Output
    
    cout <<"The rental charge for " << CustomerName<<" is $"<< Amount << endl;
    
}
    
