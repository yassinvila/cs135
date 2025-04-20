/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Lab 10A

Description: Simple functions for time.
Calculates minutes since midnight and interval between two times.
meow
meow
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time {
public:
    int h;
    int m;
};
class Movie { 
 public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};
class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printTimeSlot(TimeSlot ts);
void printMovie(Movie mv);

int main() {
    Time now;
    cout << "Enter first time (hours minutes): ";
    cin >> now.h >> now.m;

    Time later;
    cout << "Enter second time (hours minutes): ";
    cin >> later.h >> later.m;

    int nowMin = minutesSinceMidnight(now);
    int laterMin = minutesSinceMidnight(later);

    cout << "These moments of time are " << nowMin << " and "
    << laterMin << " minutes after midnight.\n";
    
    cout << "The interval between them is " << minutesUntil(now, later) 
    << " minutes.\n";
    
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Random Acts of Violence", THRILLER, 80};
    Movie movie4 = {"Random Encounters", ROMANCE, 93};
    
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot afternoon = {movie3, {13, 30}}; 
    TimeSlot evening = {movie2, {16, 45}}; 
    TimeSlot night = {movie4, {20, 20}};
    
    return 0;
}

int minutesSinceMidnight(Time time) {
    return (time.h * 60) + time.m;
}

int minutesUntil(Time earlier, Time later) {
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min) {
    int totalMin = minutesSinceMidnight(time0);
    totalMin = totalMin + min;
    time0.h = totalMin / 60;
    time0.m = totalMin % 60;
    return time0;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts) {
    printMovie(ts.movie);
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    
    cout << "[starts at " << ts.startTime.h << ":" << ts.startTime.m << 
    ", ends by " << endTime.h << ":" << endTime.m << "]" << endl;
}