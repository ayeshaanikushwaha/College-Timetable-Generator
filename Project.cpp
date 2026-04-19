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
    return 0;
}
