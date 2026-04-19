#include<bits/stdc++.h>

using namespace std;

//Data Structures for subjects
struct Course {
    int id;
    string subjectName;
    string teacherName;
    int batchYear;
    string section; 
    
    int duration;
    int weeklyHours;
};

//Lecture
struct Lecture {
    int id;      
    int courseId;
    string subjectName;
    string teacherName;
    int batchYear;
    string section; 
    
    int duration; 
    
    int assignedDay = -1;      
    int assignedTimeslot = -1; 
    string assignedRoom = "";
};

//Helper Functions to check if teacher/room is free
bool isFree(const unordered_map<string, vector<bool>>& Map, const string& key, int day, int slot, int duration, int maxSlotsPerDay) {
    if (Map.find(key) == Map.end()) return true;
    for (int d = 0; d < duration; d++) {
        int globalSlot = day * maxSlotsPerDay + (slot + d);
        if (Map.at(key)[globalSlot]) return false;
    }
    return true;
}

//Helper function to mark teacher/room busy
void markBusy(unordered_map<string, vector<bool>>& Map, const string& key, int day, int slot, int duration, int totalSlots, int maxSlotsPerDay) {
    if (Map.find(key) == Map.end()) {
        Map[key] = vector<bool>(totalSlots, false);
    }
    for (int d = 0; d < duration; d++) {
        Map[key][day * maxSlotsPerDay + (slot + d)] = true;
    }
}

int main() {
    
     vector<Course> courses = {
        {0, "Mathematics I",  "Purva Rajwade",   1, "A", 1, 4},
        {1, "Applied Physics LAB",    "Vipin Kaushik", 1, "A", 2, 2}, 
        {2, "Physics Theory", "Vipin Kaushik", 1, "A", 1, 3}, 
        {3, "Engineering Drawing",    "Neeraj Gautam",    1, "A", 1, 3},
        {4, "Electrical Engineering", "R.S. Mandloi",  1, "A", 1, 3},
        {5, "Civil Engineering",      "Suninda Parmar",    1, "A", 1, 3},
        {6, "Electrical Eng LAB",     "R.S. Mandloi",  1, "A", 2, 2},
        
        {8, "Mathematics II",         "Purva Rajwade",   1, "B", 1, 4}, 
        {9, "Chemistry LAB",          "Sushma Sharma",   1, "B", 2, 2}, 
        {10, "Chemistry Theory",      "Sushma Sharma",   1, "B", 1, 3}, 
        {11, "Technical English",     "Sarika Tiwari",  1, "B", 1, 3},
        {12, "Language LAB",          "Sarika Tiwari",  1, "B", 2, 2},
        {13, "Electronics",           "Neeraj Malviya",  1, "B", 1, 3},
        {14, "Industrial Production", "Angurbala Jayant",   1, "B", 2, 2},
        {15, "Programming",           "Ranjeet Vishwakarma",     1, "B", 1, 3},
        {16, "Programming LAB",       "Ranjeet Vishwakarma",     1, "B", 2, 2},
        
        {17, "Data Structures",       "Surendra Gupta",     2, "A", 1, 3},
        {18, "Data Structures LAB",   "Surendra Gupta",     2, "A", 2, 2},
        {19, "Digital Communication", "Harshita Kushwaha",       2, "A", 1, 3},
        {20, "Agile Methodology",     "Swati Mishra", 2, "A", 1, 3},
        {21, "Discrete Structures",   "Ritambhara Patidar",       2, "A", 1, 3},
        {22, "Digital Comm LAB",      "Harshita Kushwaha",       2, "A", 2, 2},
        {23, "Software LAB",          "Swati Mishra", 2, "A", 2, 2},
        {24, "MAD",                   "Mamta Gupta",       2, "A", 1, 2},
        {25, "MAD LAB",               "Mamta Gupta",       2, "A", 2, 2},
        {26, "Mathematics IV",        "Purva Rajwade",       2, "A", 1, 4},
        {27, "Constitution",          "Krishnakant Sharma",    2, "A", 1, 2},
        {28, "Humanities",            "Prof. Kendrick",    2, "A", 1, 2},
        
        {29, "Mathematics III",       "Peeti Sengar",   2, "B", 1, 4},
        {30, "OOPs",                  "Vinod Sathe",   2, "B", 1, 3},
        {31, "OOPs LAB",              "Vinod Sathe",   2, "B", 2, 2},
        {32, "Economics",             "Neeraj Jain",   2, "B", 1, 3},
        {33, "COA",                   "Kavita Mulchandani",   2, "B", 1, 3},
        {34, "COA LAB",               "Kavita Mulchandani",   2, "B", 2, 2},
        {35, "Microprocessor",        "Manish Panchal",   2, "B", 1, 3},
        {36, "Microprocessor LAB",    "Manish Panchal",   2, "B", 2, 2},
        {37, "Electronics Workshop",  "Neeraj Malviya",   2, "B", 2, 2},
        {38, "Design Thinking LAB",   "Swati Mishra",   2, "B", 2, 2}
    };

    
    vector<Lecture> lectures;
    int lectureIdCounter = 0;
    
    for (const auto& c : courses) {
        int numberOfSessions = c.weeklyHours / c.duration;
        for (int s = 0; s < numberOfSessions; s++) {
            Lecture l;
            l.id = lectureIdCounter++;
            l.courseId = c.id;
            l.subjectName = c.subjectName;
            l.teacherName = c.teacherName;
            l.batchYear = c.batchYear;
            l.section = c.section;
            l.duration = c.duration;
            lectures.push_back(l);
        }
    }
    
    int numClasses = lectures.size();
    
    int maxSlotsPerDay = 9;
    int totalDays = 5;

    
    int totalSlots = totalDays * maxSlotsPerDay;

    //Unordered Map for teacher, batch and room
    unordered_map<string, vector<bool>> teacherBusy;
    unordered_map<string, vector<bool>> batchBusy;
    unordered_map<string, vector<bool>> roomBusy;
    
    //Unordered Set for check course schedule
    unordered_set<string> courseDayTracker;

    //Allocating time slots
    for (int i = 0; i < numClasses; i++) {
        int duration = lectures[i].duration;
        bool isAllocated = false;
        
        string teacher = lectures[i].teacherName;
        string batchGroup = to_string(lectures[i].batchYear) + "-" + lectures[i].section;
        
        int startDay = i % totalDays; 
        
        for (int d = 0; d < totalDays && !isAllocated; d++) {
            int day = (startDay + d) % totalDays;
            
            string dailyCourseKey = batchGroup + "-" + to_string(lectures[i].courseId) + "-" + to_string(day);
            if (courseDayTracker.count(dailyCourseKey)) continue;
            
            for (int timeslot = 0; timeslot <= maxSlotsPerDay - duration; timeslot++) {
                
                if (timeslot == 4) continue;
                if (timeslot < 4 && timeslot + duration > 4) continue;
                
                //Check if teacher and batch is free
                bool teacherFree = isFree(teacherBusy, teacher, day, timeslot, duration, maxSlotsPerDay);
                bool batchFree = isFree(batchBusy, batchGroup, day, timeslot, duration, maxSlotsPerDay);
                
                if (teacherFree && batchFree) {
                    lectures[i].assignedDay = day;
                    lectures[i].assignedTimeslot = timeslot;
                    
                    markBusy(teacherBusy, teacher, day, timeslot, duration, totalSlots, maxSlotsPerDay);
                    markBusy(batchBusy, batchGroup, day, timeslot, duration, totalSlots, maxSlotsPerDay);
                    courseDayTracker.insert(dailyCourseKey);
                    
                    isAllocated = true;
                    break;
                }
            }
        }
        
        if (!isAllocated) {
             cout << "Warning: Could not schedule session for " << lectures[i].subjectName 
                  << " (Year " << lectures[i].batchYear << " Sec " << lectures[i].section << ")\n";
        }
    }

    //Assign Room
    vector<string> availableRooms = {
        "Room 101", "Room 102", "Room 103", "Room 104", "Room 105", 
        "Lab A", "Lab B", "Chem Lab", "Comp Lab", "Media Room"
    };

    for (int i = 0; i < numClasses; i++) {
        if (lectures[i].assignedDay == -1) continue;
        
        int day = lectures[i].assignedDay;
        int timeslot = lectures[i].assignedTimeslot;
        int duration = lectures[i].duration;
        
        for (const string& room : availableRooms) {
            if (isFree(roomBusy, room, day, timeslot, duration, maxSlotsPerDay)) {
                lectures[i].assignedRoom = room;
                markBusy(roomBusy, room, day, timeslot, duration, totalSlots, maxSlotsPerDay); // mark the room as occupied for this time range!
                break;
            }
        }
        if (lectures[i].assignedRoom == "") {
           lectures[i].assignedRoom = "TBA Room";
        }
    }

    //Print Timetable
    vector<string> dayNames = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    vector<string> sectionsToPrint = {"A", "B"};
    
    for (int year = 1; year <= 4; year++) {
        for (string sec : sectionsToPrint) {
            bool hasClasses = false;
            for (const auto& l : lectures) {
                if (l.batchYear == year && l.section == sec) { hasClasses = true; break; }
            }
            
            if (!hasClasses) continue;

            cout << "\n====================== YEAR " << year << " | SECTION " << sec << " TIMETABLE ======================\n";
            
            for (int day = 0; day < totalDays; day++) {
                cout << "\n----------------------------------- " << dayNames[day] << " -----------------------------------\n";
                int maxTimeslot = -1;
                for (int i = 0; i < numClasses; i++) {
                    if (lectures[i].batchYear == year && lectures[i].section == sec && lectures[i].assignedDay == day) {
                        int endSlot = lectures[i].assignedTimeslot + lectures[i].duration - 1;
                        if (endSlot > maxTimeslot) {
                            maxTimeslot = endSlot;
                        }
                    }
                }
                
                if (maxTimeslot == -1) {
                    cout << "  No classes scheduled.\n";
                    continue; 
                }

                cout << left << setw(15) << "Time" 
                     << "| " << setw(25) << "Subject" 
                     << "| " << setw(20) << "Teacher" 
                     << "| " << setw(15) << "Room" << "\n";
                cout << "--------------------------------------------------------------------------------\n";
                
                for (int t = 0; t <= maxTimeslot; t++) {
                    bool foundClass = false;
                    
                    for (int i = 0; i < numClasses; i++) {
                        if (lectures[i].batchYear != year || lectures[i].section != sec || lectures[i].assignedDay != day) continue;
                        
                        int startSlot = lectures[i].assignedTimeslot;
                        int endSlot = startSlot + lectures[i].duration - 1;
                        
                        if (t >= startSlot && t <= endSlot) {
                            string timeStr = to_string(9+t) + ":00 AM"; 
                            if (9+t > 12) timeStr = to_string(9+t-12) + ":00 PM";
                            if (9+t == 12) timeStr = "12:00 PM";
                            
                            cout << left << setw(15) << timeStr 
                                 << "| " << setw(25) << lectures[i].subjectName 
                                 << "| " << setw(20) << lectures[i].teacherName 
                                 << "| " << setw(15) << lectures[i].assignedRoom << "\n";
                            
                            foundClass = true;
                            break; 
                        }
                    }
                    
                    if (!foundClass) {
                        string timeStr = to_string(9+t) + ":00 AM";
                        if (9+t > 12) timeStr = to_string(9+t-12) + ":00 PM";
                        if (9+t == 12) timeStr = "12:00 PM";
                         
                        if (t == 4) {
                            cout << left << setw(15) << timeStr 
                                 << "| " << setw(25) << "== LUNCH BREAK ==" 
                                 << "| " << setw(20) << "All" 
                                 << "| " << setw(15) << "Cafeteria" << "\n";
                        } else {
                            cout << left << setw(15) << timeStr 
                                 << "| " << setw(25) << "-- FREE --" 
                                 << "| " << setw(20) << "-" 
                                 << "| " << setw(15) << "-" << "\n";
                        }
                    }
                }
            }
            cout << "================================================================================\n";
        }
    }

    return 0;
}