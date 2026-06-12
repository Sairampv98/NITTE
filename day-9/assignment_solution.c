/*
 * Menu-Driven Calculator — (Function Pointers)
 *
 * The original code was logically correct. This version adds the
 * improvements the problem's bonus section explicitly asks for:
 *
 * 1. STRUCT DISPATCH TABLE: instead of two parallel arrays (ops[], labels[])
 *    that can drift out of sync, a single array of op_entry structs keeps
 *    each label and its function pointer as one inseparable unit.
 *
 * 2. NULL GUARD: check the pointer isn't NULL before calling through it —
 *    good habit even when the table is statically initialised.
 *
 * 3. SELF-DESCRIBING MENU: the menu loop prints itself by iterating the
 *    table, so adding a new operation means one new row in OPS[] and
 *    nothing else.
 *
 * Core arithmetic and divide-by-zero logic are identical to the original.
 */

#include <stdio.h>

/* ── operation type ───────────────────────────────────────────── */

typedef double (*op_fn)(double, double);

double op_add(double a, double b) { return a + b; }
double op_sub(double a, double b) { return a - b; }
double op_mul(double a, double b) { return a * b; }
double op_div(double a, double b) { return a / b; }   /* caller guards b != 0 */

/* ── dispatch table: label + fn in one struct ─────────────────── */

typedef struct {
    const char *label;
    op_fn       fn;
} op_entry;

static const op_entry OPS[] = {
    {"Add",      op_add},
    {"Subtract", op_sub},
    {"Multiply", op_mul},
    {"Divide",   op_div},
};
#define OPS_LEN ((int)(sizeof OPS / sizeof OPS[0]))

/* ── main ─────────────────────────────────────────────────────── */

int main(void) {
    int choice;
    do {
        /* Menu prints itself from the table — add an op, menu updates too */
        for (int i = 0; i < OPS_LEN; i++)
            printf("%d)%s  ", i + 1, OPS[i].label);
        printf("%d)Quit\nChoice: ", OPS_LEN + 1);

        if (scanf("%d", &choice) != 1) break;

        if (choice >= 1 && choice <= OPS_LEN) {
            double a, b;
            printf("a: ");  scanf("%lf", &a);
            printf("b: ");  scanf("%lf", &b);

            /* Divide-by-zero guard before touching the pointer */
            if (choice == 4 && b == 0.0) {
                printf("Error: cannot divide by zero.\n");
                continue;
            }

            op_fn fn = OPS[choice - 1].fn;
            if (fn == NULL) {                          /* NULL guard */
                printf("Operation not available.\n");
                continue;
            }

            /* Single dispatch line — the whole point of the exercise */
            printf("%s result: %g\n", OPS[choice - 1].label, fn(a, b));

        } else if (choice != OPS_LEN + 1) {
            printf("Invalid choice.\n");
        }

    } while (choice != OPS_LEN + 1);

    return 0;
}
