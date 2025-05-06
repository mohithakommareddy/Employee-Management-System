# Employee Management System (C++)

This is a console-based **Employee Management System** developed in C++. It demonstrates core Object-Oriented Programming (OOP) concepts such as **inheritance**, **abstraction**, **polymorphism**, and **dynamic memory management**.

---

## 📝 Features

- ✅ Add employees:
  - Manager
  - Engineer
  - Intern
- ✅ Display all employee details (ID, Name, Salary, Bonus)
- ✅ Delete an employee by ID
- ✅ Bonus calculation based on employee type:
  - Manager: 10%
  - Engineer: 5%
  - Intern: 2%
- ✅ Uses dynamic memory (`new` and `delete`) and ensures cleanup
- ✅ Abstract base class with pure virtual function

---

## 📂 Project Structure
EmployeeManagementSystem/
│
├── emplyoee management system.cpp          # Main source code file
├── README.md                               # This documentation

---

## 🔧 Prerequisites

- A C++ compiler (like `g++`)
- Terminal or an IDE (Code::Blocks, VS Code, Dev C++, etc.)

---

## 🚀 How to Compile and Run

### 🖥️ Using Terminal

```bash
g++ -o EmployeeManagementSystem main.cpp
./EmployeeManagementSystem

## Output of this file

Employee Management System Menu:
1. Add Manager
2. Add Engineer
3. Add Intern
4. Display All Employees
5. Delete Employee by ID
6. Exit
Select an option:



