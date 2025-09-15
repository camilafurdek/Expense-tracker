#include "../include/expense_include.h"

#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>

string get_current_date(){
    auto now = chrono::system_clock::now();
    time_t current = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << put_time(localtime(&current), "%Y-%m-%d");
     return ss.str();
}

string get_mon_string(int mon) {
    switch (mon){
        case 1:
           return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "Nobember";
        case 12:
            return "December";
    }
    return " ";
}