#include "../include/expense_include.h"
#include "../include/expenses.h"

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    std::cout << "Expense tracker \n";
    std::cout << "type 'menu' for a list of optionds ir 'exit' to quit \n";
    string input;
    Expenses expenses_v;
    expenses_v.loadExpenses();
    while (true) {
        getline(cin, input);
        stringstream ss(input);
        string comando;
        ss >> comando;
        if (comando == "exit") {
            expenses_v.saveExpenses();
            std::cout << "Good bye";
            break;
        } else if (comando == "menu"){
            std::cout << "\nMenu:\n"
            << "  add <description> <amount>  - Add a new expense\n"
            << "  list                        - List all expenses\n"
            << "  list <month>                - List expenses by month\n"
            << "  delete <id>                 - Delete an expense by ID\n"
            << "  summary                     - Show total expenses\n"
            << "  summary <month>             - Show expenses for a specific month\n"
            << "  exit                        - Quit the program\n";
        }  // Add expense
         else if (comando == "add") {
            string description;
            float amount;
            if (ss >> quoted(description) >> amount) {
                expenses_v.add_Expense(description,amount);
                cout << "Expense added successfully\n";
            } else cout << "Usage: add \"description\"amount\n";
        }  // list expense 
        else if (comando == "list") {
            int mon;
            if (ss >> mon) {
                 if (mon >= 1 && mon <= 12) {
                    expenses_v.list_Expenses_Mon(mon);
                } else cout << "Invalid month";
            } else expenses_v.list_Expenses();  
        } // delete
        else if (comando == "delete") {
            int id;
            if (ss >> id) {
                expenses_v.delete_Expense(id);
                cout << "Expense deleted successfully\n";
            } else std::cout << "Invalid id \n";
        } // summary
        else if (comando == "summary") {
            int mon;
            if (ss >> mon) {
                if (mon >= 1 && mon <= 12) {
                    float total = expenses_v.sumary_mon(mon);
                    string mon_s = get_mon_string(mon);
                    cout << "Total expenses for: " << mon_s <<" " << total << "\n"; 
                } else cout << "Invalid month";
            } else {
               float total = expenses_v.summary();
                cout << "Total expenses: " << total << "\n"; 
            }
        } 
        else std::cout << "command not found\n";
    }
    return 0;
}

/*#include "../include/expense_include.h"
#include <string>
#include <iostream>
#include "../include/expense.h"

using namespace std;

int main() {
    string k = get_current_date();
    cout << k << "\n";
    int n = (k[5] - '0')*10 + (k[6] - '0');
    cout << k[6];
    cout << n << "\n";
    /*Expense exp(1,k,"hola",40);
    exp.show_expense();
    exp.update_amount(50);
    exp.show_expense();
    exp.update_description("k");
    exp.show_expense();
    return 0;

}*/
