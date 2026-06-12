## Student Database Management System _(Day 13 — Advanced Coding + RDBMS Concepts)_

**Scenario.** Before touching a real database, you'll build a tiny one in C and apply database thinking to it: a table, a primary key, and simple queries.

**Build this.** A program that manages student records as if they were rows in a database "table," enforcing a primary key and answering simple query-style requests.

**Required features.**

1. A student record (a "row") has: roll number (the **primary key** — must be unique), name, and marks (or GPA).
2. Implement the four core table operations, and name them after the SQL ideas they mirror: **insert** (reject a duplicate roll number, like a primary-key constraint), **select** (print all rows, or rows matching a condition), **update** (change a student's marks by roll number), **delete** (remove a row by roll number).
3. Support at least one **query with a condition**, mirroring `SELECT ... WHERE` — for example, "show all students with marks above X" — and one **ordered listing**, mirroring `ORDER BY` — for example, list students sorted by marks.
4. Persist the table to a file so the data survives between runs.

**Input / output.** Menu-driven; print query results as a neat table with a header row.

**Sample run.**

```
1) Insert  2) Select all  3) Where marks >  4) Order by marks  5) Update  6) Delete  7) Exit
Choice: 3   Threshold: 75
Roll  Name     Marks
12    Meera    88
07    Karthik  79

```

**Constraints.** Roll numbers are unique positive integers; marks are 0–100; reject duplicate inserts and operations on a roll number that doesn't exist.

**You may use.** Structures, files, dynamic memory, functions, and the validation/error habits from Day 11. The "SQL" parts are _concepts_ you implement in C, not actual SQL.

**Plan on paper first.** Write your table's column list and mark the primary key. For the `WHERE`\-style query, write the single yes/no test each row must pass to be included. For `ORDER BY`, decide which simple sort you'll use.

_RDBMS vocabulary (table, row, primary key, SELECT/WHERE/ORDER BY, constraints) onto C data structures and CRUD logic._