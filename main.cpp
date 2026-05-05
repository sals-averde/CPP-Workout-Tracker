#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "Workout.h"
#include "FileManager.h"

using namespace std;

int main()
//GOAL: Gym application -
            //calendar for tracking days streaks etc.
            //recomend workouts n build routines (pre loaded list)
            //have options in menu.
{

    Workout PushDay = {"Push Day", {"Bench Press - 3x5","Overhead Press - 3x5", "Incline DB Press - 3x8-10", "Lateral Raises 3x12 -15", "Tricep Pushdown - 3x10-12" }};
    Workout PullDay = {"Pull Day", {"Pull-Ups - 3x6-10","Lat Pulldown - 3x6-10", "Seated Cable Row - 3x8", "Face Pulls - 3x12-15", "Bicep Curls - 3x10-12" }};
    Workout LegDay = {"Leg Day", {"Squat - 3x5", "Romanian Deadlifts - 3x6-8", "Calf Raise - 3x12-15", "Back Extension - 3 x 10-15", }};
    Workout PreGym = {"Pre Gym",{"Glute Bridge - 3x8", "Resistance Band Work",}};
    vector<Workout> Workouts ={PushDay, PullDay, LegDay, PreGym};

    cout <<"=========Welcome to the Application!========="<< endl;

    cout << " 1.) Calendar View (streaks/tracker)" << endl;
    cout << " 2.) Log Workout" << endl;
    cout << " 3.) Get Random Workout" << endl;
    cout << " 4.) History" << endl;
    cout << " 5.) Exit" << endl;
    cout <<"=============================================="<< endl;
    int choice;
    do{
    cout << "enter choice: ";
    cin >> choice;
    cin.ignore(); // this clears a lingering \n newline operator it broke our loop 3/30/2026 by skipping the inquirys asked in the function in case 2
        switch (choice){
            case 1:
                ViewCalendar();
                break;

            case 2:
                LogWorkout(Workouts);
                break;

            case 3:
                GetRandomWorkout(Workouts);
                break;

            case 4:
                ViewHistory();
                break;

            case 5:
                cout << "Exiting, Bye-bye" << endl;
                break;

            default:
                cout << "invalid. Try again " << endl;
        }
    } while(choice != 5);

    cout << "===============================================" << endl;

    return 0;
}

