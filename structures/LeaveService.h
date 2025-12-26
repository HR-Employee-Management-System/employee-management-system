#pragma once
#include <iostream>
#include <cassert>
#include "../algorithms/Hashing.h"
#include "./EmployeeService.h"
using namespace std;

LeaveRequest* retrieveLeaveRequest(int employeeId) {
    NodeRequest *node = leaveRequestNodes[hashFunction(employeeId)];
    while (node != nullptr) {
        if (node->request->employeeId == employeeId) {
            return node->request;
        }
        node = node->next;
    }
    return nullptr;
}

void CreateLeaveRequest(int employeeId, string startDate, string endDate, string leaveType) {
    Employee *emp = retrieveEmployee(employeeId);
    if (emp == nullptr) {
        cout << "Employee with ID: " << employeeId << " not found" << endl;
        return;
    }

    if (emp->leaveCount <= 0) {
        cout << "Employee with ID: " << emp->id << " has exhausted all leave days." << endl;
        return;
    }

    if (retrieveLeaveRequest(employeeId) != nullptr) {
        cout << "Employee already has an active leave request." << endl;
        return;
    }

    LeaveRequest *req = new LeaveRequest();
    req->next = nullptr;

    
    req->status = "Pending";
    req->employeeId = emp->id;
    req->startDate = startDate;
    req->endDate = endDate;
    req->leaveType = leaveType;
    req->requestDate = "2024-01-01"; // This would ideally be the current date

    if (leaveRequestFront == nullptr) {
        leaveRequestFront = leaveRequestRear = req;
    } else {
        leaveRequestRear->next = req;
        leaveRequestRear = req;
    }
    int index = hashFunction(emp->id);

    NodeRequest *p = new NodeRequest;
    p->request = req;
    p->next = leaveRequestNodes[index];
    leaveRequestNodes[index] = p;
    cout << "Leave request is created successfully for employee ID: " << emp->id << endl;
}

void updateLeaveRequest(int employeeId, string startDate, string endDate, string leaveType) {
    LeaveRequest *req = retrieveLeaveRequest(employeeId);
    if (req == nullptr) {
        cout << "Leave Request not found for Employee ID: " << employeeId << endl;
        return;
    }

    req->startDate = startDate;
    req->endDate = endDate;
    req->leaveType = leaveType;
    cout << "Leave Request updated successfully for Employee ID: " << employeeId << endl;
}

void deleteLeaveRequest(int employeeId) {
    LeaveRequest *req = retrieveLeaveRequest(employeeId);
    if (req == nullptr) {
        cout << "Leave Request not found for Employee ID: " << employeeId << endl;
        return;
    }

    if (leaveRequestFront == req) { 
        leaveRequestFront = leaveRequestFront->next;
    } else {
        LeaveRequest *prev = leaveRequestFront;
        while (prev->next != nullptr && prev->next != req) {
            prev = prev->next;
        }
        assert(prev->next == req && "List and hash table out of sync");
        prev->next = req->next;
    }

    int index = hashFunction(employeeId);
    NodeRequest *node = leaveRequestNodes[index];
    NodeRequest *prevNode = nullptr;
    while (node != nullptr) {
        if (node->request == req) {
            if (prevNode == nullptr) {
                leaveRequestNodes[index] = node->next;
            } else {
                prevNode->next = node->next;
            }
            delete node;
            break;
        }
        prevNode = node;
        node = node->next;
    }

    delete req;
    cout << "Leave Request deleted successfully for Employee ID: " << employeeId << endl;
}

void ProcessLeaveRequests() {
    LeaveRequest *temp = leaveRequestFront;
    while (temp != nullptr) { 
        LeaveRequest *req = temp;
        Employee* emp = retrieveEmployee(req->employeeId);
        temp = temp->next;
        cout << "Processing Leave Request for Employee ID: " << req->employeeId << endl;
        cout << "Leave Type: " << req->leaveType << endl;
        cout << "Start Date: " << req->startDate << endl;
        cout << "End Date: " << req->endDate << endl;
        string response;
        cin >> response;
        if (response == "approve") {
            req->status = "Approved";
            emp->leaveCount--;
            cout << "Leave request approved for employee ID: " << req->employeeId << endl;
        } else if (response == "reject") {
            req->status = "Rejected";
            cout << "Leave request rejected for employee ID: " << req->employeeId << endl;
        } else {
            cout << "Exiting processing...." << endl;
            return;
        }

        LeaveRequest *processedReq = new LeaveRequest(*req);
        processedReq->next = nullptr;
        if (processedLeaveRequestRear == nullptr) {
            processedLeaveRequestFront = processedLeaveRequestRear = processedReq;
        } else {
            processedLeaveRequestRear->next = processedReq;
            processedLeaveRequestRear = processedReq;
        }

        deleteLeaveRequest(req->employeeId);
    }
}

void displayAllProcessedLeaveRequests() {
    LeaveRequest *temp = processedLeaveRequestFront;
    while (temp != nullptr) {
        cout << "Employee ID: " << temp->employeeId << endl;
        cout << "Start Date: " << temp->startDate << endl;
        cout << "End Date: " << temp->endDate << endl;
        cout << "Leave Type: " << temp->leaveType << endl;
        cout << "Status: " << temp->status << endl;
        cout << "Request Date: " << temp->requestDate << endl;
        cout << "------------------------" << endl;
        temp = temp->next;
    }
}

void displayAllPendingLeaveRequests() {
    LeaveRequest *temp = leaveRequestFront;
    while (temp != nullptr) {
        if (temp->status == "Pending") {
            cout << "Employee ID: " << temp->employeeId << endl;
            cout << "Start Date: " << temp->startDate << endl;
            cout << "End Date: " << temp->endDate << endl;
            cout << "Leave Type: " << temp->leaveType << endl;
            cout << "Status: " << temp->status << endl;
            cout << "Request Date: " << temp->requestDate << endl;
            cout << "------------------------" << endl;
        }
        temp = temp->next;
    }
}
