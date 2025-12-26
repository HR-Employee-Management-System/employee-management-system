#pragma once
#include <iostream>
#include "../algorithms/Hashing.h"
#include "./EmployeeService.h"
using namespace std;

void CreateAttendanceRecord(AttendanceRecord *attend) {
    Employee *emp = retrieveEmployee(attend->employeeId);
    if (emp == nullptr) {
        cout << "Employee with ID: " << attend->employeeId << " not found" << endl;
        return;
    }    
    
    attendances.push_back(attend);
    
    int index = hashFunction(attend->employeeId);
    NodeAttendance *p = new NodeAttendance;

    p->attendance = attend;
    p->next = attendanceNodes[index];
    attendanceNodes[index] = p;

    emp->totalworkedHours += attend->hoursWorked;
    emp->attendanceCount++;
    cout << "Attendance record created successfully for Employee ID: " << attend->employeeId << endl;
}

void RetrieveAttendanceRecord(int employeeId, string startDate, string endDate) {
    bool listed = false;
    Employee *p = retrieveEmployee(employeeId);
    if (p == nullptr) {
        cout << "Employee with ID: " << employeeId << " not found" << endl;
        return;
    }
    int index = hashFunction(employeeId);

    NodeAttendance *current = attendanceNodes[index];
    cout << "\n=== ATTENDANCE RECORDS ===" << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << "Period: " << startDate << " to " << endDate << endl;
    cout << "----------------------------" << endl;
    while (current != nullptr) {
        if (current->attendance->employeeId == employeeId &&
            current->attendance->date >= startDate && 
            current->attendance->date <= endDate) {

            cout << "Date: " << current->attendance->date << endl;
            cout << "  Entry: " << current->attendance->entryTime;
            cout << ", Exit: " << current->attendance->exitTime << endl;
            cout << "  Status: " << current->attendance->status;
            cout << ", Hours: " << current->attendance->hoursWorked << endl;
            cout << "----------------------------" << endl;
            listed = true;
        }
        current = current->next;
    }

    if (!listed) {
        cout << "Attendance record for Employee ID: " << employeeId << " not found" << endl;
    }
}

