#ifndef EXPENSES_H
#define EXPENSES_H

#include <string>
#include <vector>
#include "expense.h"

using namespace std;

class Expenses {
    private:
    vector<Expense> expenses;

    public:

    Expenses();

    void loadExpenses();
    void saveExpenses();

    void list_Expenses();
    void list_Expenses_Mon(int mon);

    void delete_Expense(int id);
    void add_Expense(string description, float amount);

    float summary();
    float sumary_mon(int mon);


};


#endif // EXPENSES_H