# Expense Tracker

A simple **command-line expense tracker** application built in **C++** that allows users to manage their personal finances.  
The application supports adding, updating, deleting, and viewing expenses, as well as generating summaries.  

This project is implemented in C++ and uses a **Makefile** for building and running.

---

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
$ add  Lunch 20
# Expense added successfully (ID: 1)

$ add Dinner 10
# Expense added successfully (ID: 2)

$ list
# ID  Date       Description  Amount
# 1   2024-08-06  Lunch        $20
# 2   2024-08-06  Dinner       $10

$ summary
# Total expenses: $30

$ delete --id 2
# Expense deleted successfully

$ summary
# Total expenses: $20

$ summary --month 8
# Total expenses for August: $20

