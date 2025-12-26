#pragma once
#include <iostream>
#include "../algorithms/Hashing.h"
using namespace std;

void createDepartment(Department *dept) {
    departments.push_back(dept);
    int index = hashFunction(dept->departmentId);
    NodeDepartment *p = new NodeDepartment;

    p->department = dept;
    p->next = departmentNodes[index];
    departmentNodes[index] = p;
    cout << "Department created successfully with ID: " << dept->departmentId << endl;
}

Department* retrieveDepartment(int departmentId) {
    int index = hashFunction(departmentId);
    NodeDepartment *current = departmentNodes[index];

    while (current != nullptr) {
        if (current->department->departmentId == departmentId) {
            return current->department;
        }
        current = current->next;
    }
    return nullptr;
}

void updateDepartment(Department *dept) {
    int index = hashFunction(dept->departmentId);
    NodeDepartment *current = departmentNodes[index];

    while (current != nullptr) {
        if (current->department->departmentId == dept->departmentId) {
            current->department->departmentName = dept->departmentName;
            current->department->managerId = dept->managerId;
            current->department->managerName = dept->managerName;
            current->department->employeeCount = dept->employeeCount;
            cout << "Department with ID: " << dept->departmentId << " updated successfully" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Department with ID: " << dept->departmentId << " not found" << endl;
}

void deleteDepartment(int departmentId) {
    int index = hashFunction(departmentId);
    NodeDepartment* current = departmentNodes[index];
    NodeDepartment* prev = nullptr;

    while (current != nullptr) {
        if (current->department->departmentId == departmentId) {

            Department* dept = current->department; // save pointer

            // Remove from hash table
            if (prev == nullptr)
                departmentNodes[index] = current->next;
            else
                prev->next = current->next;

            delete current; // delete node only

            // Remove from vector safely
            for (int i = 0; i < departments.size(); i++) {
                if (departments[i] == dept) {
                    departments.erase(departments.begin() + i);
                    break;
                }
            }

            delete dept; // delete ONCE

            cout << "Department with ID: " << departmentId << " deleted successfully\n";
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "Department with ID: " << departmentId << " not found\n";
}


void displayAllDepartments() {
    cout << "\n=== ALL DEPARTMENTS ===" << endl;
    for (int i=0; i < departments.size(); i++) {
        if (departments[i] != nullptr) {
            cout << "ID: " << departments[i]->departmentId
                 << ", Name: " << departments[i]->departmentName
                 << ", Manager ID: " << departments[i]->managerId
                 << ", Manager Name: " << departments[i]->managerName
                 << ", Employee Count: " << departments[i]->employeeCount << endl;
        }
    }
}