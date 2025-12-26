#pragma once
#include <iostream>
#include "../algorithms/Hashing.h"
#include "./DepartmentService.h"
using namespace std;

void createEmployee(Employee *emp) {
    Department* dept = retrieveDepartment(emp->departmentId);

    if (dept == nullptr) {
        cout << "Error: Department with ID: " << emp->departmentId << " not found. Employee creation failed." << endl;
        return; 
    }

    employees.push_back(emp);
    int index = hashFunction(emp->id);
    NodeEmployee *p = new NodeEmployee;

    p->employee = emp;
    p->next = employeeNodes[index];
    employeeNodes[index] = p;
    dept->employeeCount++;

    cout << "Employee created successfully with ID: " << emp->id << endl;
    cout << "Employee count updated for Department: " << dept->departmentName << endl;
}

Employee* retrieveEmployee(int id) {
    int index = hashFunction(id);
    NodeEmployee *current = employeeNodes[index];

    while (current != nullptr) {
        if (current->employee->id == id) {
            return current->employee;
        }
        current = current->next;
    }
    return nullptr;
}

void updateEmployee(Employee *emp) {
    int index = hashFunction(emp->id);
    NodeEmployee *current = employeeNodes[index];

    while (current != nullptr) {
        if (current->employee->id == emp->id) {
            current->employee->name = emp->name;
            current->employee->departmentId = emp->departmentId;
            current->employee->position = emp->position;
            current->employee->baseSalary = emp->baseSalary;
            current->employee->joinDate = emp->joinDate;
            current->employee->leaveCount = emp->leaveCount;
            current->employee->attendanceCount = emp->attendanceCount;
            current->employee->totalworkedHours = emp->totalworkedHours;
            cout << "Employee with ID: " << emp->id << " updated successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee with ID: " << emp->id << " not found" << endl;
}

void deleteEmployee(int id) {
    int index = hashFunction(id);
    NodeEmployee* current = employeeNodes[index];
    NodeEmployee* prev = nullptr;

    while (current != nullptr) {
        if (current->employee->id == id) {

            Employee* emp = current->employee;
            Department* dept = retrieveDepartment(emp->departmentId);
            dept->employeeCount--;  
            cout << "Decremented employee count for Department: " << dept->departmentName << endl;

            // Remove from hash table
            if (prev == nullptr)
                employeeNodes[index] = current->next;
            else
                prev->next = current->next;

            delete current;

            for (int i = 0; i < employees.size(); i++) {
                if (employees[i] == emp) {
                    employees.erase(employees.begin() + i);
                    break;
                }
            }

            delete emp;

            cout << "Employee with ID: " << id << " deleted successfully\n";
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "Employee with ID: " << id << " not found\n";
}


void displayAllEmployees() {
    cout << "All Employees:" << endl;
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] != nullptr) {
            cout << "ID: " << employees[i]->id 
            << ", Name: " << employees[i]->name 
            << ", Department ID: " << employees[i]->departmentId 
            << ", Position: " << employees[i]->position 
            << ", Salary: $" << employees[i]->baseSalary 
            << ", Join Date: " << employees[i]->joinDate 
            << ", Leaves: " << employees[i]->leaveCount << " days"
            << ", Attendance: " << employees[i]->attendanceCount << " days" << endl;
        }
    }
}

