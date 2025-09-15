# Expense Tracker

A simple **command-line expense tracker** application built in **C++** that allows users to manage their personal finances.  
The application supports adding, updating, deleting, and viewing expenses, as well as generating summaries. 

This project is implemented in C++ and uses a **Makefile** for building and running.

---

## Project URL
```bash
https://roadmap.sh/projects/expense-tracker
```

## Features

- **Add expense** with description and amount  
- **Update expense** by ID  
- **Delete expense** by ID  
- **List expenses**
  - total expenses
  - Monthly expenses  
- **Summary of expenses**:
  - Total expenses
  - Monthly expenses
- **Data persistence** using a simple text file (JSONformat)
 
---

## Prerequisites
- C++ compiler
- Make
- nlohmann/json library for JSON handling

  --

## Build the project
```bash
make
```
--
## Run the application
```bash
./bin/expense-tracker
```

## Example Usage

```bash
type 'menu' for a list of optionds ir 'exit' to quit

menu
Menu:
  add <description> <amount>  - Add a new expense
  list                        - List all expenses
  list <month>                - List expenses by month
  delete <id>                 - Delete an expense by ID
  summary                     - Show total expenses
  summary <month>             - Show expenses for a specific month
  exit                        - Quit the program

add  Lunch 20
Expense added successfully

Dinner 10
Expense added successfully

list
ID  Date       Description  Amount
1   2024-08-06  Lunch        $20
2   2024-08-06  Dinner       $10

summary
Total expenses: $30

delete 2
Expense deleted successfully

summary
Total expenses: $20

summary 8
Total epenses for August: $20

