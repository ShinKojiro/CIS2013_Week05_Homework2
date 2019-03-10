#include <iostream>
#include <string>

using namespace std;
int edocCount = 0;
int edocCandies = 0;
int margorpCount = 0;
/*Do Programming Project 14 from Chapter 3, the Edoc calculator, except write a function that takes the number of candy, 
  Edoc, and Margorp as input parameters and returns the amount of experience that can be earned. 
  Modify your program to give advice to the player using the following rules:

Catching an additional Edoc gives you three Edoc candy.
If you can’t get any experience points with the provided inputs then output “You can’t evolve any Edoc, catch more.”
If catching one or two additional Edoc will give you more experience points compared to evolving right now then output “Catch more Edoc before evolving.”
Otherwise output “You should evolve now.”*/

void countsInput(){

    cout << "Input the number of Edoc candies, Edocs, and Margorps you have right now." << endl;
    cout << "Edoc Candies: ";
    cin >> edocCandies;
    cout << endl << "Edocs: ";
    cin >> edocCount;
    cout << endl << "Margorps: ";
    cin >> margorpCount;
    cout << "You say you have have " << edocCandies << " Edoc Candies, " << edocCount << " Edocs and " << margorpCount << " Margorps?" << endl;
}

void calcAndRec(){
    int candyTemp = edocCandies;
    int edocTemp = edocCount;
    int margorpTemp = margorpCount;
    int experiencePossible = 0;

    
    while(edocCount > 0){
        while(edocCandies >= 12){
            edocCount--;
            margorpCount++;
            edocCandies++;
            experiencePossible+= 500;
            edocCandies-= 12;
        }
        if(edocCount > 0){
            edocCount--;
            edocCandies++;
        }
        while(margorpCount > 0){
            margorpCount--;
            edocCandies++;
        }
    }
    cout << "With this amount... ";
    if(experiencePossible < 500){
        cout << "you won't be able to earn any experience points.";
        if(edocTemp < 1){
            cout << " Well, you don't even have an Edoc! Go catch Edoc's and also get 3 candies each!" << endl;
            if(candyTemp >=9 ){
                cout << "And since you have " << candyTemp << " candies you will be able to evolve it right after you catch it!";
            }
        }
        else if(candyTemp >= 9){
            cout << " But, if you catch one more Edoc you will be able to evolve one and gain 500 EXP and a margorp!" << endl;
        }
        else if(candyTemp >= 6){
            cout << " But, if you catch two more Edocs you will be able to evolve one and gain 500 EXP and a margorp!" << endl;
        }
        

    }
    if(edocTemp >= 1 && candyTemp >= 12){
        cout << " you can evolve the Edoc you have now and gain " << experiencePossible << " experience points!";
    }
}

int main(){
    
    int experiencePossible = 0;
    bool notDone = true;
    char cont = 'y';

    countsInput();
    calcAndRec();
}