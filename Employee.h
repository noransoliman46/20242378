#pragma once
#include <string>
using namespace std;

//  MODEL

class Employee {
private:
    int    workerCode;
    string workerName;
    string workerMail;

public:
    Employee(int workerCode, string workerName, string workerMail)
        : workerCode(workerCode), workerName(workerName), workerMail(workerMail) {}

    // Setters
    void setWorkerName(const string& nm)  { workerName = nm;  }
    void setWorkerMail(const string& ml)  { workerMail = ml;  }
    void setWorkerCode(int cd)            { workerCode = cd;  }

    // Getters
    string getWorkerName() const { return workerName; }
    string getWorkerMail() const { return workerMail; }
    int    getWorkerCode() const { return workerCode; }
};
