#include <iostream>
#include "Employee.h"
#include "view.h"
#include "controller.h"
#include "utils.h"
using namespace std;


int main() {
    EmployeeView       screen;
    EmployeeController mgr(screen);

    // Seed with sample data
    mgr.addRecord("Omar ",   "omar@company.com");
    mgr.addRecord("Sara ",   "sara@company.com");
    mgr.addRecord("Youssef ", "youssef@company.com");

    int choice = 0;
    while (true) {

        cout << " Employee MVC System         \n";
        cout << " 1. Add Employee             \n";
        cout << " 2. Edit Employee            \n";
        cout << " 3. Display Employee by ID   \n";
        cout << " 4. Display All Employees    \n";
        cout << " 5. Delete Employee          \n";
        cout << " 6. Exit                     \n";

        choice = promptReadInt("  Choose an option: ");

        if (choice == 6) {
            cout << "\nGoodbye!\n";
            break;

        } else if (choice == 1) {
            string typedName  = promptReadLine("  Name  : ");
            string typedEmail = promptReadLine("  Email : ");
            mgr.addRecord(typedName, typedEmail);

        } else if (choice == 2) {
            int searchCode = promptReadInt("  Employee ID to edit: ");
            cout << "  Leave blank to keep current value.\n";
            string revisedName  = promptReadLine("  New Name  : ");
            string revisedMail  = promptReadLine("  New Email : ");
            mgr.updateRecord(searchCode, revisedName, revisedMail);

        } else if (choice == 3) {
            int searchCode = promptReadInt("  Employee ID: ");
            mgr.fetchRecord(searchCode);

        } else if (choice== 4) {
            mgr.fetchAllRecords();

        } else if (choice == 5) {
            int searchCode = promptReadInt("  Employee ID to delete: ");
            mgr.removeRecord(searchCode);

        } else {
            cout << "  Invalid option. Try again.\n";
        }
    }

    return 0;
}