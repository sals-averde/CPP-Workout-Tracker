#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED
#include <string>
#include <vector>
#include"Workout.h"
using namespace std;

void ViewCalendar();
void LogWorkout(vector<Workout> Workouts);
void DeleteEntry(string target);
void ViewHistory();


#endif // FILEMANAGER_H_INCLUDED
