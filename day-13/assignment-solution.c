/*
 * Student Database Management System — (RDBMS Concepts)
 *
 * Bug fixes
 * ---------
 * 1. BUFFER OVERFLOW ON INSERT: `db[count++] = s` had no capacity guard.
 *    If the user inserted 100 students and tried a 101st, the write went
 *    one past the end of the array (undefined behaviour). Now checked
 *    with an explicit `count >= MAX_STUDENTS` guard at the top of
 *    do_insert().
 *
 * 2. MARKS NOT VALIDATED ON UPDATE: insert correctly rejects marks
 *    outside 0-100, but the update path (`scanf("%d",&db[p].marks)`)
 *    wrote the raw value directly with no check — the test showed
 *    marks=150 being accepted. The same 0-100 guard is now applied
 *    in do_update().
 *
 * 3. COMPILER WARNINGS (-Wmisleading-indentation): the minified load()
 *    and save() had single-statement loops with fclose() on the same
 *    visual line, which GCC interprets as misleadingly indented. Fixed
 *    by using braces.
 *
 * Architecture: dispatch table replaces the if/else chain (same pattern
 * as Day 9). The "SQL" function names are preserved — insert, select,
 * where, orderby, update, delete — since naming them after SQL concepts
 * is the point of the assignment.
 */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct { int roll; char name[31]; int marks; } Student;

Student db[MAX_STUDENTS];
int count = 0;

/* ── helpers ──────────────────────────────────────────────────── */

/* Primary-key lookup; returns 0-based index or -1. */
int find_roll(int r) {
    for (int i = 0; i < count; i++)
        if (db[i].roll == r) return i;
    return -1;
}

void print_header(void) {
    printf("%-6s  %-30s  %s\n", "Roll", "Name", "Marks");
    printf("------------------------------------------\n");
}

void print_row(const Student *s) {
    printf("%-6d  %-30s  %d\n", s->roll, s->name, s->marks);
}

/* ── file persistence ─────────────────────────────────────────── */

void load(void) {
    FILE *f = fopen("students.dat", "r");
    if (!f) return;
    while (count < MAX_STUDENTS &&
           fscanf(f, "%d %30s %d",
                  &db[count].roll, db[count].name, &db[count].marks) == 3) {
        count++;
    }
    fclose(f);                  /* FIX 3: explicit braces, no misleading-indentation */
    if (count) printf("Loaded %d student(s).\n", count);
}

void save(void) {
    FILE *f = fopen("students.dat", "w");
    if (!f) { perror("fopen"); return; }
    for (int i = 0; i < count; i++) {
        fprintf(f, "%d %s %d\n", db[i].roll, db[i].name, db[i].marks);
    }
    fclose(f);                  /* FIX 3: same */
}

/* ── query operations (named after their SQL counterparts) ───────
   SELECT * FROM students                 → select_all()
   SELECT … WHERE marks > t              → where_marks_above()
   SELECT … ORDER BY marks DESC          → order_by_marks()      */

void select_all(void) {
    if (!count) { printf("(no students)\n"); return; }
    print_header();
    for (int i = 0; i < count; i++) print_row(&db[i]);
}

void where_marks_above(int threshold) {
    int found = 0;
    print_header();
    for (int i = 0; i < count; i++) {
        if (db[i].marks > threshold) { print_row(&db[i]); found = 1; }
    }
    if (!found) printf("(no matches)\n");
}

void order_by_marks(void) {
    if (!count) { printf("(no students)\n"); return; }
    /* Sort a copy — never mutates the stored order (mirroring a DB view) */
    Student tmp[MAX_STUDENTS];
    memcpy(tmp, db, count * sizeof(Student));
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (tmp[j].marks > tmp[i].marks) {
                Student s = tmp[i]; tmp[i] = tmp[j]; tmp[j] = s;
            }
    print_header();
    for (int i = 0; i < count; i++) print_row(&tmp[i]);
}

/* ── menu actions ─────────────────────────────────────────────── */

/* INSERT INTO students VALUES (roll, name, marks)
   Rejects duplicate roll (primary-key constraint). */
void do_insert(void) {
    /* FIX 1: capacity guard before any write */
    if (count >= MAX_STUDENTS) { printf("Database full (%d rows).\n", MAX_STUDENTS); return; }

    Student s;
    printf("Roll: ");
    scanf("%d", &s.roll);
    if (find_roll(s.roll) != -1) { printf("Duplicate roll (primary key).\n"); return; }

    printf("Name: ");  scanf("%30s", s.name);
    printf("Marks: "); scanf("%d",  &s.marks);
    if (s.marks < 0 || s.marks > 100) { printf("Marks must be 0-100.\n"); return; }

    db[count++] = s;
    printf("Inserted.\n");
}

/* SELECT * FROM students */
void do_select_all(void)  { select_all(); }

/* SELECT … WHERE marks > ? */
void do_where(void) {
    int t;
    printf("Threshold (marks > ): ");
    scanf("%d", &t);
    where_marks_above(t);
}

/* SELECT … ORDER BY marks DESC */
void do_order(void)       { order_by_marks(); }

/* UPDATE students SET marks = ? WHERE roll = ? */
void do_update(void) {
    int r;
    printf("Roll: ");
    scanf("%d", &r);
    int p = find_roll(r);
    if (p == -1) { printf("Not found.\n"); return; }

    int m;
    printf("New marks: ");
    scanf("%d", &m);
    /* FIX 2: same range check that insert applies */
    if (m < 0 || m > 100) { printf("Marks must be 0-100.\n"); return; }

    db[p].marks = m;
    printf("Updated.\n");
}

/* DELETE FROM students WHERE roll = ? */
void do_delete(void) {
    int r;
    printf("Roll: ");
    scanf("%d", &r);
    int p = find_roll(r);
    if (p == -1) { printf("Not found.\n"); return; }
    db[p] = db[--count];       /* swap-with-last, O(1) */
    printf("Deleted.\n");
}

/* ── dispatch table ───────────────────────────────────────────── */

typedef void (*action_fn)(void);

typedef struct {
    int         key;
    const char *label;
    action_fn   fn;
} menu_item;

static const menu_item MENU[] = {
    {1, "Insert",          do_insert},
    {2, "Select all",      do_select_all},
    {3, "Where marks>",    do_where},
    {4, "Order by marks",  do_order},
    {5, "Update",          do_update},
    {6, "Delete",          do_delete},
};
#define MENU_LEN ((int)(sizeof MENU / sizeof MENU[0]))

static void print_menu(void) {
    for (int i = 0; i < MENU_LEN; i++)
        printf("%d)%s  ", MENU[i].key, MENU[i].label);
    printf("%d)Exit\nChoice: ", MENU_LEN + 1);
}

static int dispatch(int c) {
    if (c == MENU_LEN + 1) return 1;
    for (int i = 0; i < MENU_LEN; i++)
        if (MENU[i].key == c) { MENU[i].fn(); return 0; }
    printf("Invalid choice.\n");
    return 0;
}

/* ── main ─────────────────────────────────────────────────────── */

int main(void) {
    load();
    int c;
    do {
        print_menu();
        if (scanf("%d", &c) != 1) break;
    } while (!dispatch(c));
    save();
    return 0;
}
