#ifndef WORKOUT_H_INCLUDED
#define WORKOUT_H_INCLUDED
#include <string>
#include <vector>
using namespace std;

struct Exercise{
    string name;
    int sets;
    int reps;
};

struct Workout{
    string date;
    string name;
    vector <Exercise> excercise;
};

Workout CreateWorkout();
void DisplayWorkout(const Workout& W);


string GetDate();
int CountStreak(vector<string> dates);
void GetRandomWorkout(vector<Workout> Workouts);




#endif // WORKOUT_H_INCLUDED
