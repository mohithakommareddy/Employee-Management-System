#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class Employee
class Employee {
protected:
    int id;
    string name;
    double salary;

public:
    Employee(int id, const string& name, double salary)
        : id(id), name(name), salary(salary) {}

    int getID() const { return id; } // Getter for ID

    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << endl;
    }

    virtual double calculateBonus() const = 0; // Pure virtual function

    virtual ~Employee() {}
};

// Derived class for Manager
class Manager : public Employee {
public:
    Manager(int id, const string& name, double salary)
        : Employee(id, name, salary) {}

    double calculateBonus() const override {
        return salary * 0.10; // Manager gets a 10% bonus
    }

    void displayInfo() const override {
        cout << "Manager - ";
        Employee::displayInfo();
        cout << "Bonus: $" << calculateBonus() << endl;
    }
};

// Derived class for Engineer
class Engineer : public Employee {
public:
    Engineer(int id, const string& name, double salary)
        : Employee(id, name, salary) {}

    double calculateBonus() const override {
        return salary * 0.05; // Engineer gets a 5% bonus
    }

    void displayInfo() const override {
        cout << "Engineer - ";
        Employee::displayInfo();
        cout << "Bonus: $" << calculateBonus() << endl;
    }
};

// Derived class for Intern
class Intern : public Employee {
public:
    Intern(int id, const string& name, double salary)
        : Employee(id, name, salary) {}

    double calculateBonus() const override {
        return salary * 0.02; // Intern gets a 2% bonus
    }

    void displayInfo() const override {
        cout << "Intern - ";
        Employee::displayInfo();
        cout << "Bonus: $" << calculateBonus() << endl;
    }
};

// Employee Management System
class EmployeeManagementSystem {
private:
    vector<Employee*> employees;

public:
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void displayAllEmployees() const {
        if (employees.empty()) {
            cout << "No employees to display.\n";
            return;
        }
        for (const auto& employee : employees) {
            employee->displayInfo();
            cout << "-------------------" << endl;
        }
    }

    bool deleteEmployeeById(int id) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if ((*it)->getID() == id) {
                delete *it; // Free allocated memory
                employees.erase(it); // Remove from vector
                return true; // Successfully deleted
            }
        }
        return false; // Employee not found
    }

    ~EmployeeManagementSystem() {
        for (auto& employee : employees) {
            delete employee;
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\nEmployee Management System Menu:\n";
    cout << "1. Add Manager\n";
    cout << "2. Add Engineer\n";
    cout << "3. Add Intern\n";
    cout << "4. Display All Employees\n";
    cout << "5. Delete Employee by ID\n";
    cout << "6. Exit\n";
    cout << "Select an option: ";
}

// Function to add an employee based on user selection
void addEmployee(EmployeeManagementSystem &ems, int employeeType) {
    int id;
    string name;
    double salary;

    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Employee Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Employee Salary: ";
    cin >> salary;

    if (employeeType == 1) {
        ems.addEmployee(new Manager(id, name, salary));
        cout << "Manager added successfully.\n";
    } else if (employeeType == 2) {
        ems.addEmployee(new Engineer(id, name, salary));
        cout << "Engineer added successfully.\n";
    } else if (employeeType == 3) {
        ems.addEmployee(new Intern(id, name, salary));
        cout << "Intern added successfully.\n";
    }
}

int main() {
    EmployeeManagementSystem ems;
    int option;

    do {
        displayMenu();
        cin >> option;

        switch (option) {
            case 1: // Add Manager
            case 2: // Add Engineer
            case 3: // Add Intern
                addEmployee(ems, option);
                break;
            case 4: // Display All Employees
                cout << "\nDisplaying All Employees:\n";
                ems.displayAllEmployees();
                break;
            case 5: { // Delete Employee by ID
                int id;
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                if (ems.deleteEmployeeById(id)) {
                    cout << "Employee deleted successfully.\n";
                } else {
                    cout << "Employee with ID " << id << " not found.\n";
                }
                break;
            }
            case 6: // Exit
                cout << "Exiting the Employee Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (option != 6);

    return 0;
}
