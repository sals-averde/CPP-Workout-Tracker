# CPP-Workout-Tracker
A terminal-based workout tracking application built in C++ that allows users to log workouts, track consistency, and generate structured routines.

### Features

### Workout Logging
  - Log workouts with the current date
  - Supports predefined routines and custom entries
  - Automatically storesdata in a persistent file

### Calendar + Streak Tracking
  - displays all logged workouts in chronological order
  - calculates current workout streak based on consecutive days
  - Uses date parsing and time comparison to determine streak accuracy

### Predefined workout system
Includes built-in routines:

- Push Day
- Pull Day
- Leg Day
- Pre-Gym

Each routine contains structured exercises and rep ranges.

### Random Workout Generator
- Selects a random workout routine
- Displays all exercises for that routine
- Useful for quick decision-making before gym

### Workout History Management 
- View full workout history
- Delete specific entries
- File rewriting system ensures data consistency

### How it works
- The user chooses an option deom a terminal menu.
- the program can log a workout using the current date.
- workout entries are saved into 'ApplicationONEFile.txt'.
- The Program reads from that file to display workout history.
- The streak system checks saved workout dates and counts consecutive workout days.
- when deleting an entry, the program rewrites the file without the selected workout.

### Concepts Used
- File IO (ifstream , offstream)
- structs and vectors
- Time Handling(Ctime, tm, mktime, diftime)
- String parsing(substr, sscanf)
- Menu-Driven Program design
- Data persistence and file rewriting

### project Purpose
- This project was built to go beyond basic c++ syntax and practice building a small, functional system with:
            - Persistent data storage
            - User interaction
            - Real-world logic (streak tracking, logging systems)
  
### Future Improvements
- Improve date formating (Leading zeroes)
- Add PR tracking
- Addd exercise-level logging (sets/reps per movement)
- Convert to GUI or web-based application
- Add user profiles and authentication
- Add visual calendar for easier tracking
  
### Images
 - Application flow in picture order:
    
<img width="1713" height="909" alt="Screenshot 2026-05-01 225647" src="https://github.com/user-attachments/assets/ed2d5707-a8aa-4615-861a-4004f86c1cf4" />
<img width="1722" height="919" alt="Screenshot 2026-05-01 225725" src="https://github.com/user-attachments/assets/00cd296c-c9bd-49ff-b473-9628d24d12d2" />
<img width="1726" height="921" alt="Screenshot 2026-05-01 225753" src="https://github.com/user-attachments/assets/488b48f1-3365-4570-93c9-16d1bad0f6e0" />
<img width="1717" height="924" alt="Screenshot 2026-05-01 225818" src="https://github.com/user-attachments/assets/0c7f5704-768b-4ea5-99e4-bc1e5fd3b888" />
<img width="1724" height="921" alt="Screenshot 2026-05-01 225839" src="https://github.com/user-attachments/assets/14b22934-c52e-4786-8b40-397934c293f9" />





