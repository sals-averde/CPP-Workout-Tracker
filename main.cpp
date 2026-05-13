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
//UPDATE 05/05/2026 in progres............................................................................................
{
    Workout PushDay = {
            "Pre-Built",
            "Push-Day",
        {
                {"Bench Press", 3, 8},
                {"Overhead Press", 3, 5},
                {"Incline DB Press", 3, 8},
                {"Lateral Raises", 3, 12},
                {"Tricep Pushdown", 3, 10},
        }
    };

    Workout PullDay = {
        "Pre-Built",
        "Pull-Day",
        {
            {"Pull Ups", 3, 10},
            {"Lat Pulldowns", 3, 10},
            {"Seated Cable Row", 3, 8},
            {"Face Pulls", 3, 12},
            {"Bicep Curls", 3, 12},
        }
    };

    Workout LegDay = {
        "Pre-Built",
        "Leg Day",
        {
            {"Squat", 3, 5},
            {"Romanian Deadlifts", 3, 8},
            {"Calf Raise", 3, 15},
            {"Back Extension", 3, 10},
        }
    };

    Workout PreGym = {
        "Pre-Built",
        "Pre-Gym",
        {
            {"Glute Bridges", 3, 8},
            {"Resistance Band Work", 2, 10},

        }
    };

//GOAL: Gym application -
            //calendar for tracking days streaks etc.
            //recomend workouts n build routines (pre loaded list)
            //have options in menu.
    vector<Workout> Workouts ={PushDay, PullDay, LegDay, PreGym};
    Workout capture;

    cout <<"=========Welcome to the Application!========="<< endl;

    cout << " 1.) Calendar View (streaks/tracker)" << endl;
    cout << " 2.) Log Workout" << endl;
    cout << " 3.) Get Random Workout" << endl;
    cout << " 4.) History" << endl;
    //reworking cout << " 5.) Create Workout" << endl;
   //reworking cout << " 6.) Display Workout" << endl;
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

