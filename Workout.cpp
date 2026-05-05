#include "Workout.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<vector>
#include<sstream>

using namespace std;

string GetDate(){
    time_t now  = time(0); // this gets thr current time
    tm *ltm = localtime(&now);//breaks it into day/month/year

    //build string date manually
    string date = to_string(1900 + ltm->tm_year) + "-" +
                  to_string(1 + ltm->tm_mon) + "-" +
                  to_string(ltm->tm_mday);
    return date;
    //connected to log workout
}
//takes our date vector(made in view calendar)
//returns a number (streak count)
int CountStreak(vector<string> dates){
    //if no workouts logged, streak is 0. stop.
    if(dates.empty()) return 0;
    //after start at 1 always
    int streak = 1;
    //Start at LAST entry and go BACKWARDS
    //dates.size()-1 = LAST INDEX
    //i>0 stops before first entry since we compare pairs
    for(int i = dates.size()-1; i>0; i--){
        //tm is time struct crom ctime
        //start it empty
        //two dates for compare
        tm t1 = {}, t2 = {};
        //6 variable to hold pieces of each date
        int y1, m1, d1, y2, m2, d2;

        //scanf reads formatted string and pulls numbers INTO variables
        //dates[i] is a string like '2026-03-31'
        //.c_str() converts it to a format sscanf can read
        //"%d-%d-%d" is teh pattern (number-number-number)
        //use & to tell WHERE to store each
        sscanf(dates[i].c_str(), "%d-%d-%d", &y1, &m1, &d1);

        //same thing but for previous day data
        sscanf(dates[i-1].c_str(), "%d-%d-%d", &y2, &m2, &d2);

        //now we must load those numbers into tm struct w offset...google this shit i really dunno
        t1.tm_year = y1-1900; t1.tm_mon = m1-1; t1.tm_mday = d1;
        t2.tm_year = y2-1900; t2.tm_mon = m2-1; t2.tm_mday = d2;
        //=================IMPORTED: RESEARCH ON OWN======================
        // mktime() converts a tm struct into a giant seconds number (like time(0))
        // difftime() subtracts two of those giant numbers
        // result is the difference between the two dates IN SECONDS
        double diff = difftime(mktime(&t1), mktime(&t2));

        // 86400 = 60seconds x 60minutes x 24hours = exactly one day in seconds
        // if the difference is exactly one day, dates are consecutive → keep counting
        if(diff == 86400)
            streak++;
        else
            break; // difference is more than one day = gap in workouts = stop counting
    }
    //send the final streak number back to wherever called this function
    return streak;
}

void GetRandomWorkout(vector<Workout> Workouts){
    srand(time(0));//use current time as a starting point to get random number each run
    int i = rand() % Workouts.size(); //rand() - generated giant random number
        //which workout              //Workouts.size() - how many workouts we have encoded
                                    //% modulo just keeps our numbers between 0-3
    cout << "========================================" <<endl;
    cout << Workouts[i].name << endl;
    for (int j = 0; j < Workouts[i].excercise.size(); j++){
        cout << Workouts[i].excercise[j] << endl;
    }
    cout << "========================================" <<endl;
};






