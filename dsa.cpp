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
//Lecture structure
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
    return 0;
}
