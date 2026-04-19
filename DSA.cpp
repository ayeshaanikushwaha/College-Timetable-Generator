#include<bits/stdc++.h>
using namespace std;
  
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

