## Inventory Management using Files _(Dynamic Memory & Files)_

**Scenario.** A shop needs its stock list to **survive between runs** of the program, and to grow as large as needed.

**Build this.** An inventory program that loads items from a file at startup, lets the user manage them, and saves back to the file on exit — with the item list held in memory you allocate yourself.

**Required features.**

1. Each item is a structure: id, name, quantity, price.
2. On startup, read existing items from a data file (if it exists). Hold them in a **dynamically allocated** array; grow it with `realloc` as items are added. Free everything before exiting.
3. Menu: add item, update quantity/price, remove item, list all, and save. On exit, write the current list back to the file.

**Input / output.** Menu-driven; list items in a table. The data file format is your choice (text or binary) — just be consistent for reading and writing.

**Sample run.**

```
Loaded 3 items from inventory.dat
1) Add  2) Update  3) Remove  4) List  5) Save & Exit
Choice: 1   Name: Bolts   Qty: 500   Price: 2.50
Added item #4.

```

**Constraints.** Quantities are non-negative integers; prices are non-negative. Handle a missing/empty file gracefully (start with an empty inventory). Every `malloc`/`realloc` result must be checked, and all memory freed at the end.

**You may use.** `malloc`/`calloc`/`realloc`/`free`, `fopen`/`fclose`, and reading/writing your structs (`fread`/`fwrite` or `fprintf`/`fscanf`). Structures from Day 9.

**Plan on paper first.** Decide your file format and write one example line/record. Sketch how the array grows: what capacity do you start with, and when do you `realloc`?

_exercises the full dynamic-memory lifecycle plus file persistence of structured records._