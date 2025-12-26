# ![Employee Management System](https://readme-typing-svg.demolab.com?font=Fira+Code&size=40&pause=1000&color=1E90FF&width=600&height=70&lines=Employee+Management+System+%28DSA+Project%29)

## Group Members

![Dawit Lulie](https://readme-typing-svg.demolab.com?font=Fira+Code&size=30&pause=0&color=1E90FF&width=400&height=50&lines=Dawit+Lulie)
![Emran Seid](https://readme-typing-svg.demolab.com?font=Fira+Code&size=30&pause=0&color=FF8C00&width=400&height=50&lines=Emran+Seid)  
![Kirubel Anteneh](https://readme-typing-svg.demolab.com?font=Fira+Code&size=30&pause=0&color=8A2BE2&width=400&height=50&lines=Kirubel+Anteneh)  
![Kidus Tessema](https://readme-typing-svg.demolab.com?font=Fira+Code&size=30&pause=0&color=FF1493&width=400&height=50&lines=Kidus+Tessema)  
![Feven Tassew](https://readme-typing-svg.demolab.com?font=Fira+Code&size=30&pause=0&color=32CD32&width=400&height=50&lines=Feven+Tassew)

---

## 1. Introduction
This project is an **Employee Management System** developed as part of a **Data Structures and Algorithms (DSA)** course.  
The system manages employees, attendance, leaves, salary calculation, and reporting, while demonstrating the correct use of DSA concepts.  

It is designed to be simple, clear, and justifiable, suitable for a 3rd-year software engineering student.

---

## 2. System Goals
- Apply DSA concepts correctly and naturally
- Store data permanently using CSV files
- Load data into memory for efficient processing
- Support basic employee management operations
- Generate meaningful reports
- Keep the design easy to understand and explain

---

## 3. Overall System Design
The system is divided into three layers:

### 3.1 Storage Layer
- Uses CSV files for permanent storage:
  - `employees.csv`
  - `attendance.csv`
  - `leaves.csv`
  - `departments.csv`
- Data is loaded at program start and updated when changes occur.

### 3.2 In-Memory Data Layer (DSA Layer)
- Data is loaded into memory using **linked lists** and **queues**.
- Allows efficient searching, sorting, and updates.

### 3.3 Application Layer
- Menu-driven interface
- Handles operations like add, update, search, sort, and report generation

---

## 4. Core Data Structures

### 4.1 Employee Management
- **Data Structure:** Linked List
- **Algorithms:** Linear search, traversal
- **Features:** Add, update, delete, view employee

### 4.2 Department Management
- **Data Structure:** Array / List
- **Algorithms:** Linear search, Shell Sort or Quick Sort
- **Reasoning:** Small number of departments

### 4.3 Attendance Management
- **Data Structure:** Linked List (per employee)
- **Algorithms:** Traversal, linear search
- **Reasoning:** Records are stored permanently and reused

### 4.4 Leave Management
- **Data Structure:** Queue
- **Algorithms:** Enqueue, dequeue, traversal
- **Reasoning:** Fair processing (FIFO) of leave requests

### 4.5 Salary Calculation
- **Based On:** Base salary, attendance, leaves, overtime
- **Algorithms:** Traversal, arithmetic calculations
- **Sorting:** Quick Sort by salary

---

## 5. Searching and Sorting Strategy

| Feature | Algorithm | Reason |
|---------|----------|-------|
| Find employee by ID | Linear Search | Small dataset, simple |
| Find department | Linear Search | Few departments |
| Sort employees by name | Shell Sort | Efficient for medium lists |
| Sort employees by salary | Quick Sort | Fast and commonly used |
| Sort departments | Shell Sort | Simple and readable |

---

## 6. Report Generation
- **Employee Summary Report:** ID, Name, Department, Attendance, Leaves, Salary
- **Salary Report:** Employees sorted by salary
- **Attendance Report (Optional):** Monthly or individual summaries

---

## 7. Data Loading Strategy
- CSV files loaded at startup
- Stored in memory for efficient operations
- Changes written back to CSV
- Efficient for 500–1000 records

---

## 8. Folder Structure

```bash

EmployeeManagementSystem/
├── data/
│   ├── employees.csv
│   ├── attendance.csv
│   ├── leaves.csv
│   └── departments.csv
├── models/
│   ├── Employee/
│   ├── AttendanceRecord/
│   ├── LeaveRequest/
│   └── Department/
├── structures/
│   ├── LinkedList/
│   ├── Queue/
│   └── Stack/  # optional
├── algorithms/
│   ├── Searching/
│   └── Sorting/
├── services/
│   ├── EmployeeService/
│   ├── AttendanceService/
│   ├── LeaveService/
│   └── ReportService/
├── utils/
│   ├── CSVReader/
│   └── CSVWriter/
└── main/
    └── MainMenu/
```
