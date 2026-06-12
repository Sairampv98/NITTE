/*
 * Banking System with Error Logs (Error Handling & Debugging)
 *
 * Bug fixes
 * ---------
 * 1. NEW BALANCE NOT PRINTED: the requirement says "successful operations
 *    print the new balance." The original printed only "OK." after a
 *    deposit, withdrawal, or transfer. All three now show the updated
 *    balance(s) on success.
 *
 * 2. CONTEXTLESS LOG ENTRIES: every log line said e.g. "withdraw:
 *    insufficient funds" with no account ID, no amount, no balance.
 *    A log file with no context is nearly useless for debugging. All
 *    error paths now include account ID, amount requested, and — where
 *    relevant — the current balance.
 *
 * 3. printf() WITH NON-LITERAL FORMAT: the original used
 *    printf(flag ? "str1" : "str2") which is technically valid C but
 *    triggers -Wformat-nonliteral on strict builds and is a bad habit.
 *    Replaced with puts() in every action function.
 *
 * Everything else — the assert invariant, perror on fopen failure,
 * the timestamp logic, and the find/deposit/withdraw/transfer structure
 * — was correct and is left intact.
 */

#include <stdio.h>
#include <assert.h>
#include <time.h>

typedef struct { int id; double balance; } Account;

Account accts[] = {{1001, 5000.0}, {1002, 1200.0}, {1003, 0.0}};
int n = 3;

/* ── error logging ────────────────────────────────────────────── */

/* Appends one timestamped line to errors.log.
   If the file itself can't be opened, reports via perror. */
void log_error(const char *msg) {
    FILE *f = fopen("errors.log", "a");
    if (!f) { perror("fopen errors.log"); return; }
    time_t t  = time(NULL);
    char  *ts = ctime(&t);
    if (ts) ts[24] = '\0';          /* strip trailing newline */
    fprintf(f, "[%s] %s\n", ts ? ts : "?", msg);
    fclose(f);
}

/* ── account access ───────────────────────────────────────────── */

Account *find_account(int id) {
    for (int i = 0; i < n; i++)
        if (accts[i].id == id) return &accts[i];
    return NULL;
}

/* ── operations (return 1 = success, 0 = rejected + logged) ─────  */

int deposit(int id, double a) {
    char msg[128];
    Account *x = find_account(id);
    if (!x) {
        snprintf(msg, sizeof msg, "deposit: account %d not found", id);
        log_error(msg); return 0;
    }
    if (a < 0) {
        snprintf(msg, sizeof msg,
                 "deposit: negative amount %.2f on account %d", a, id);
        log_error(msg); return 0;
    }
    x->balance += a;
    return 1;
}

int withdraw(int id, double a) {
    char msg[128];
    Account *x = find_account(id);
    if (!x) {
        snprintf(msg, sizeof msg, "withdraw: account %d not found", id);
        log_error(msg); return 0;
    }
    if (a < 0) {
        snprintf(msg, sizeof msg,
                 "withdraw: negative amount %.2f on account %d", a, id);
        log_error(msg); return 0;
    }
    if (a > x->balance) {
        snprintf(msg, sizeof msg,
                 "withdraw: insufficient funds on account %d "
                 "(balance %.2f, requested %.2f)",
                 id, x->balance, a);
        log_error(msg); return 0;
    }
    x->balance -= a;
    assert(x->balance >= 0);    /* invariant: successful withdrawal never goes negative */
    return 1;
}

int transfer(int from, int to, double a) {
    char msg[128];
    Account *x = find_account(from), *y = find_account(to);
    if (!x || !y) {
        snprintf(msg, sizeof msg,
                 "transfer: account %d or %d not found", from, to);
        log_error(msg); return 0;
    }
    if (a < 0) {
        snprintf(msg, sizeof msg, "transfer: negative amount %.2f", a);
        log_error(msg); return 0;
    }
    if (a > x->balance) {
        snprintf(msg, sizeof msg,
                 "transfer: insufficient funds on account %d "
                 "(balance %.2f, requested %.2f)",
                 from, x->balance, a);
        log_error(msg); return 0;
    }
    x->balance -= a;
    y->balance += a;            /* both sides update or neither (sequential, no rollback needed here) */
    return 1;
}

/* ── menu actions ─────────────────────────────────────────────── */

void do_deposit(void) {
    int id; double a;
    printf("Account: "); scanf("%d",  &id);
    printf("Amount: ");  scanf("%lf", &a);
    if (deposit(id, a)) {
        Account *x = find_account(id);
        /* FIX 1: print new balance on success, not just "OK." */
        printf("OK. New balance for %d: %.2f\n", id, x->balance);
    } else {
        puts("Declined (see errors.log).");
    }
}

void do_withdraw(void) {
    int id; double a;
    printf("Account: "); scanf("%d",  &id);
    printf("Amount: ");  scanf("%lf", &a);
    if (withdraw(id, a)) {
        Account *x = find_account(id);
        /* FIX 1: print new balance on success */
        printf("OK. New balance for %d: %.2f\n", id, x->balance);
    } else {
        puts("Declined (see errors.log).");
    }
}

void do_transfer(void) {
    int from, to; double a;
    printf("From: ");   scanf("%d",  &from);
    printf("To: ");     scanf("%d",  &to);
    printf("Amount: "); scanf("%lf", &a);
    if (transfer(from, to, a)) {
        Account *x = find_account(from);
        Account *y = find_account(to);
        /* FIX 1: print both new balances on success */
        printf("OK. %d balance: %.2f  |  %d balance: %.2f\n",
               from, x->balance, to, y->balance);
    } else {
        puts("Declined (see errors.log).");
    }
}

void do_balance(void) {
    int id;
    printf("Account: ");
    scanf("%d", &id);
    Account *x = find_account(id);
    if (x) {
        printf("Balance: %.2f\n", x->balance);
    } else {
        char msg[64];
        snprintf(msg, sizeof msg, "balance: account %d not found", id);
        log_error(msg);
        puts("Declined (see errors.log).");
    }
}

/* ── dispatch table ───────────────────────────────────────────── */

typedef void (*action_fn)(void);

typedef struct {
    int         key;
    const char *label;
    action_fn   fn;
} menu_item;

static const menu_item MENU[] = {
    {1, "Deposit",  do_deposit},
    {2, "Withdraw", do_withdraw},
    {3, "Transfer", do_transfer},
    {4, "Balance",  do_balance},
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
    int c;
    do {
        print_menu();
        if (scanf("%d", &c) != 1) break;
    } while (!dispatch(c));
    return 0;
}
