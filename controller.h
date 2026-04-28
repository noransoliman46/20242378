#pragma once
#include <vector>
#include <string>
#include "Employee.h"
#include "view.h"
using namespace std;

//  CONTROLLER

class EmployeeController {
private:
    vector<Employee> staffList;
    EmployeeView&    display;
    int              codeGen;

public:
    EmployeeController(EmployeeView& display) : display(display), codeGen(1) {}

    void addRecord(const string& workerName, const string& workerMail) {
        staffList.emplace_back(codeGen++, workerName, workerMail);
        display.renderMessage("Employee added successfully.");
    }

    bool updateRecord(int searchCode, const string& revisedName, const string& revisedMail) {
        for (auto& entry : staffList) {
            if (entry.getWorkerCode() == searchCode) {
                if (!revisedName.empty()) entry.setWorkerName(revisedName);
                if (!revisedMail.empty()) entry.setWorkerMail(revisedMail);
                display.renderMessage("Employee updated successfully.");
                return true;
            }
        }
        display.renderMessage("Employee with ID " + to_string(searchCode) + " not found.");
        return false;
    }

    bool fetchRecord(int searchCode) const {
        for (const auto& entry : staffList) {
            if (entry.getWorkerCode() == searchCode) {
                display.renderEmployeeDetails(entry);
                return true;
            }
        }
        display.renderMessage("Employee with ID " + to_string(searchCode) + " not found.");
        return false;
    }

    void fetchAllRecords() const {
        display.renderAllEmployees(staffList);
    }

    bool removeRecord(int searchCode) {
        for (auto pos = staffList.begin(); pos != staffList.end(); ++pos) {
            if (pos->getWorkerCode() == searchCode) {
                staffList.erase(pos);
                display.renderMessage("Employee deleted.");
                return true;
            }
        }
        display.renderMessage("Employee with ID " + to_string(searchCode) + " not found.");
        return false;
    }

    int getTotalCount() const { return (int)staffList.size(); }
};
