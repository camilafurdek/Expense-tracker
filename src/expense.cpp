#include "../include/expense.h"
#include <iostream>
#include <iomanip>


Expense::Expense(int id,string date,string description,float amount): id(id), date(date), description(description), amount(amount){};

int Expense::get_id() {
    return id;
}

string Expense::get_date(){
    return date;
}

float Expense::get_amount(){
    return amount;
}

string Expense::get_description(){
    return description;
}

void Expense::update_id(int id_new){
    id = id_new;
}

void Expense::update_description(string description_new){
    description =description_new;
}

void Expense::update_amount(float amount_new){
    amount = amount_new;
}

void Expense::show_expense(){
      cout << right << setw(2) << id << " "
      << left  << setw(12) << date
      << left  << setw(20) << description
      << right << setw(8)  << amount
      << "\n";
}
