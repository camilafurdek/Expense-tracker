#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

using namespace std;

class Expense {
    private:
    int id;
    string date;
    string description;
    float amount;
    
    public:
    Expense(int id,string date,string description,float amount);

    int get_id();
    string get_date();
    float get_amount();
    string get_description();

    void show_expense();

    void update_id(int id_new);
    void update_description(string description_new);
    void update_amount(float amount_new);


};

#endif // EXPENSE_H