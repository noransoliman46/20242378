#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include "Employee.h"
using namespace std;

//  VIEW

class EmployeeView {
public:
    void renderEmployeeDetails(const Employee& entry) const {

        cout << " Employee Details      \n";
        cout << " ID    : " << entry.getWorkerCode() << "\n";
        cout << " Name  : " << entry.getWorkerName() << "\n";
        cout << " Email : " << entry.getWorkerMail() << "\n";

    }

    void renderAllEmployees(const vector<Employee>& staffList) const {
        if (staffList.empty()) {
            cout << "\n  (No employees on record)\n";
            return;
        }

        cout << " ID   Name    Email  \n";
        for (const auto& entry : staffList) {
            printf("%4d ║ %-20s ║ %-26s ║\n",
                   entry.getWorkerCode(),
                   entry.getWorkerName().c_str(),
                   entry.getWorkerMail().c_str());
        }
    }

    void renderMessage(const string& txt) const {
        cout << "\n  >> " << txt << "\n";
    }
};