#include "../algorithms/Sorting.h"

void reportEmployeesBySalary() {
    vector<Employee*> temp;

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] != nullptr)
            temp.push_back(employees[i]);
    }

    quickSort(temp, 0, temp.size() - 1);

    cout << "\n=== EMPLOYEES SORTED BY SALARY ===\n";
    for (int i = 0; i < temp.size(); i++) {
        cout << "ID: " << temp[i]->id
             << ", Name: " << temp[i]->name
             << ", Salary: $" << temp[i]->baseSalary << endl;
    }

    temp.clear();
}

void reportEmployeesByAttendance() {
    vector<Employee*> temp;

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] != nullptr)
            temp.push_back(employees[i]);
    }

    quickSortByAttendance(temp, 0, temp.size() - 1);

    cout << "\n=== EMPLOYEES SORTED BY ATTENDANCE ===\n";
    for (int i = 0; i < temp.size(); i++) {
        cout << "ID: " << temp[i]->id
             << ", Name: " << temp[i]->name
             << ", Attendance Days: " << temp[i]->attendanceCount << endl;
    }

    temp.clear();
}

void reportLowAttendanceEmployees(int threshold) {
    vector<Employee*> temp;

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] != nullptr && employees[i]->attendanceCount < threshold)
            temp.push_back(employees[i]);
    }

    quickSortByAttendance(temp, 0, temp.size() - 1);

    cout << "\n=== EMPLOYEES WITH LOW ATTENDANCE ===\n";
    for (int i = 0; i < temp.size(); i++) {
        cout << "ID: " << temp[i]->id
             << ", Name: " << temp[i]->name
             << ", Attendance: " << temp[i]->attendanceCount << endl;
    }

    temp.clear();
}

void reportDepartmentEmployeeCount() {
    cout << "\n=== DEPARTMENT EMPLOYEE COUNT ===\n";

    for (int i = 0; i < departments.size(); i++) {
        if (departments[i] != nullptr) {
            cout << "Department: " << departments[i]->departmentName
                 << ", Employees: " << departments[i]->employeeCount << endl;
        }
    }
}

void reportActiveLeaveRequests() {
    cout << "\n=== ACTIVE LEAVE REQUESTS ===\n";

    LeaveRequest* current = leaveRequestFront;
    while (current != nullptr) {
        cout << "Employee ID: " << current->employeeId
             << ", Leave Type: " << current->leaveType
             << ", Period: " << current->startDate
             << " to " << current->endDate << endl;
        current = current->next;
    }
}
