#include "../include/expenses.h"
#include "../include/expense_include.h"
#include "../include/json.hpp"
#include <iostream>
#include <fstream>

Expenses::Expenses(){};

void Expenses::loadExpenses(){
    string FILE_NAME = "expenses.jso";
    ifstream file(FILE_NAME);
    if (file.is_open()) {
        nlohmann::json j;
        file >> j;
        for (auto &item : j)
        {
            expenses.push_back({item["id"], item["date"], item["description"], item["amount"]});
        }

    }
}

void Expenses::saveExpenses(){
    string FILE_NAME = "expenses.jso";
    nlohmann::json j;
    for (int i = 0; i < expenses.size(); i++){
        j.push_back({{"id", expenses[i].get_id()}, {"date", expenses[i].get_date()}, {"description", expenses[i].get_description()}, {"amount", expenses[i].get_amount()}});
    }
    ofstream file(FILE_NAME);
    file << setw(4) << j << endl;
}

void Expenses::list_Expenses() {
    if (expenses.size() == 0) {
        cout << "No expenses added yet \n";
    } else {
        cout << right << setw(2) << "ID" << " "
         << left  << setw(12) << "DATE"
         << left  << setw(20) << "DESCRIPTION"
         << right << setw(8)  << "AMOUNT"
         << "\n";
        for(int i = 0; i < expenses.size(); i ++){
            expenses[i].show_expense();
        }

    }
}

void Expenses::list_Expenses_Mon(int mon){
    if (expenses.size() == 0) {
        cout << "No expenses added yet";
    } else {
        cout << "ID Date    Description Amount\n";
        for (int i = 0; i < expenses.size(); i ++) {
            string mon_exp = expenses[i].get_date();
            int mon_exp_num = mon_exp[6] - '0';
            if (mon_exp_num == mon) {
                expenses[i].show_expense();
            }
        }
    }
}

void Expenses::delete_Expense(int id) {
    if (id < 1 || id > expenses.size()) {
        cout << "invalid id";
    } else {
        int i = id - 1;
        while( i + 1 < expenses.size()) {
            expenses[i] = expenses[i+1];
            i++;
        }
    }
}

void Expenses::add_Expense(string description, float amount) {
    string date = get_current_date();
    int id = expenses.size();
    Expense exp(id + 1,date,description,amount);
    expenses.push_back(exp);
}

float Expenses::summary(){
    float total = 0;
    for(int i = 0; i < expenses.size(); i ++){
        total += expenses[i].get_amount();
    }
    return total;
}

float Expenses::sumary_mon(int mon) {
    float total = 0;
    for (int i = 0; i < expenses.size(); i ++) {
        string mon_exp = expenses[i].get_date();
        int mon_exp_num = mon_exp[6] - '0';
        if (mon_exp_num == mon) {
            total += expenses[i].get_amount();
         }
    }
    return total;
}
