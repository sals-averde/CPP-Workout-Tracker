#ifndef WORKOUT_H_INCLUDED
#define WORKOUT_H_INCLUDED
#include <string>
#include <vector>
using namespace std;

struct Workout{
    string name;
    vector <string> excercise;
};

string GetDate();
int CountStreak(vector<string> dates);
void GetRandomWorkout(vector<Workout> Workouts);




#endif // WORKOUT_H_INCLUDED
