#include "FileManager.h"
#include "Workout.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void ViewCalendar(){
    //needs to read files
    //take date from each line
    //count streak
    //display
    //open file
    ifstream inFile("ApplicationONEFile.txt");
    //check if file opened
    if(!inFile.is_open()){
        cout << "Issue in View Calendar File Exchange :(" << endl;
        return;
    }
    vector<string> lines; //stores full lines
    vector<string> dates;// where we will store just dates
    string line;
    while (getline(inFile, line)){
        lines.push_back(line);
        dates.push_back(line.substr(0, line.find(' ')));//cuts to just store dates
    }
    inFile.close();

    //now we need to print it
    cout << "========================================" << endl;
    cout << "Workout Calendar: " << endl;
    for(int i = 0; i < lines.size(); i++){
        cout << lines[i] <<endl;
    }
    //streak
    cout << "Current Streak: " << CountStreak(dates) << " days" << endl;
    cout << "========================================" << endl;
};

void LogWorkout(vector<Workout> Workouts){

    int routine;
    cout << "========================================" <<endl;
    cout << "Chose Movement Routine to Log --- Available Routines: " <<endl;
    for(int i = 0; i < Workouts.size(); i++){
        cout << i+1 << ".)" << Workouts[i].name << endl;
    }
    //user can pick now
    int pick;
    cout << "Pick One (0 for Custom):";
    cin >> pick;
    cin.ignore(1000, '\n');

    //custom part
    string WorkoutName;
    Workout custom;
    if (pick == 0){
        custom = CreateWorkout();
    }else{
        WorkoutName = Workouts[pick-1].name; //grabs directly from bank
    }

    //create file to write to
    ofstream outFile("ApplicationONEFile.txt",ios::app);
    //check to be sure file opened
    if (!outFile.is_open()){
        cout << "Issues Writing to File :(" <<endl;
    }

    if(pick == 0){
        string Entry = custom.date + " - " + custom.name;
        for (const Exercise& E : custom.excercise){
            Entry = Entry + " | " + E.name + " " + to_string(E.sets) + "x" + to_string(E.reps);
        }
        outFile << Entry << endl;
        outFile.close();
    } else{
        outFile << GetDate() << " - " << WorkoutName << endl;
        outFile.close();
    }
};

//Deleting from file - C++ has no "erase" so we much rewrite
// entire file without unwanted lines
//1.) read every line into a vector
//2.) remove one that we dont want
//3.) rewrite the whole file from scratch

void DeleteEntry(string target){
    ifstream inFile("ApplicationONEFile.txt");
    vector<string> lines;
    string line;

    while(getline(inFile,line)){
        if(line != target) lines.push_back(line);
        //keep all but target
    }
    inFile.close();
    //overwrites
    ofstream outFile("ApplicationONEFile.txt");
    for(int i = 0; i < lines.size(); i++){
        outFile << lines[i] << endl;
    }
    outFile.close();
}

void ViewHistory(){
    //create the file
    ifstream inFile("ApplicationONEFile.txt");
    //check if file opened ok
    if (!inFile.is_open()){
        cout << "Issue Reading From File :(" <<endl;
        }
    //read history into vector for numbering /picking purposes
    vector<string> lines;
    string line;
    while(getline(inFile, line)){
        lines.push_back(line);
    }
    inFile.close();
    //display
    cout << "========================================" <<endl;
    cout << "Workout History: " << endl;
    for(int i = 0; i < lines.size(); i++){
        cout << i+1 << ".)" << lines[i] << endl;
    }
    cout << "========================================" <<endl;

    //ask if we want to delete
    cout << "Enter number to delete (0 to return): ";
    int pick;
    cin >> pick;
    cin.ignore();

    if (pick != 0 && pick <= lines.size()){
        DeleteEntry(lines[pick-1]); //Passes the tect here skips
        cout << "Deleted!" << endl;
    } else {
        cout << "Invalid Operation Try again!" << endl;
    }

};

//gets current date as a string must #include <ctime>




