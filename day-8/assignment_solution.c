/*
 * Dynamic Employee Record Access — (Pointers)
 *
 * Bug fixes
 * ---------
 * 1. WRONG OUTPUT (indexing): positions were 0-based but the sample run
 *    shows 1-based ("Position: 2" → Asha, the 2nd employee, not Karthik
 *    the 3rd). Prompts now accept 1-based input; all paths convert to
 *    0-based internally before touching the arrays.
 *
 * 2. DATA MISMATCH: Asha's initial salary was 50000 in the code but the
 *    sample output shows 45000 + 5000 raise = 50000. Fixed to 45000.
 *
 * 3. SILENT SALARY CORRUPTION: no validation on raise amount — a negative
 *    value silently cut the salary. Now rejected with a message.
 *
 * 4. UX: bounds range not shown in the prompt. User had no idea what valid
 *    positions were. Now shown as "(1-N):".
 *
 * No structural changes — Day 7 uses if/switch, not function pointers
 * . giveRaise() is kept exactly as-is; it's the objective.
 */

#include <stdio.h>
#include <string.h>

#define MAX 10

int  ids[MAX];
char names[MAX][31];
int  salaries[MAX];
int  count = 0;

/* ── core helpers ─────────────────────────────────────────────── */

/* The whole point of the assignment: salary changed through its address.
   main never touches the salary directly — only through this function. */
void giveRaise(int *salary, int amount) {
    *salary += amount;
}

int findById(int id) {
    for (int i = 0; i < count; i++)
        if (ids[i] == id) return i;
    return -1;
}

/* idx is always 0-based; callers handle the 1→0 conversion. */
void viewEmployee(int idx) {
    printf("ID: %d | Name: %s | Salary: %d\n",
           ids[idx], names[idx], salaries[idx]);
}

/* ── main ─────────────────────────────────────────────────────── */

int main(void) {
    /* Pre-load 5 employees. Asha starts at 45 000 so a 5 000 raise
       hits the sample output of 50 000. */
    int         pid[] = {101, 102, 103, 104, 105};
    const char *pn[]  = {"Ravi", "Asha", "Karthik", "Meera", "Sam"};
    int         ps[]  = {60000, 45000, 55000, 48000, 70000};

    for (int i = 0; i < 5; i++) {
        ids[i] = pid[i];
        strcpy(names[i], pn[i]);
        salaries[i] = ps[i];
    }
    count = 5;

    int choice;
    do {
        printf("\n1) View  2) Raise  3) Find by ID  4) Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: {
                int p;
                printf("Position (1-%d): ", count);
                scanf("%d", &p);
                /* FIX: validate 1-based range before converting */
                if (p < 1 || p > count) { printf("Invalid position.\n"); break; }
                viewEmployee(p - 1);
                break;
            }

            case 2: {
                int p, amt;
                printf("Position (1-%d): ", count);
                scanf("%d", &p);
                printf("Amount: ");
                scanf("%d", &amt);
                if (p < 1 || p > count) { printf("Invalid position.\n"); break; }
                if (amt <= 0)            { printf("Amount must be positive.\n"); break; }
                /* Pass the ADDRESS of the slot — this is the objective */
                giveRaise(&salaries[p - 1], amt);
                printf("New salary for %s: %d\n", names[p - 1], salaries[p - 1]);
                break;
            }

            case 3: {
                int id;
                printf("ID: ");
                scanf("%d", &id);
                int p = findById(id);
                if (p == -1) printf("No employee found.\n");
                else         viewEmployee(p);
                break;
            }

            case 4:
                break;      /* exit — the while condition handles it */

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
