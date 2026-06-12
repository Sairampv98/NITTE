/*


 * Inventory Management — (Dynamic Memory & Files)
 *
 * Bug fixes
 * ---------
 * 1. DUPLICATE ID ACCEPTED: adding an item with an already-used ID was
 *    silently allowed, producing two rows with the same ID. Now rejected
 *    with a message before any other input is read.
 *
 * 2. NEGATIVE QTY / PRICE ACCEPTED: the constraint "quantities and prices
 *    are non-negative" was not enforced. Both are now validated after
 *    input and the add is aborted if either fails.
 *
 * 3. SILENT REMOVE-MISS: removing a non-existent ID produced no output
 *    at all — the user had no way to know the operation did nothing.
 *    Now prints "Not found."
 *
 * Same fixes applied to Update: negative qty/price are now rejected there
 * too, not just on Add.
 *
 * Architecture: dispatch table (same pattern as Day 9) replaces the
 * if/else chain so adding a menu option is a one-line change to MENU[].
 */

#include <stdio.h>
#include <stdlib.h>

#define FNAME "inventory.dat"

typedef struct {
    int    id;
    char   name[31];
    int    qty;
    double price;
} Item;

Item *items = NULL;
int   count = 0, cap = 0;

/* ── memory management ────────────────────────────────────────── */

void ensure_cap(void) {
    if (count >= cap) {
        cap = cap ? cap * 2 : 4;
        Item *tmp = realloc(items, cap * sizeof(Item));
        if (!tmp) { perror("realloc"); exit(1); }
        items = tmp;
    }
}

/* ── file I/O ─────────────────────────────────────────────────── */

void load_data(void) {
    FILE *fp = fopen(FNAME, "r");
    if (!fp) return;            /* missing file = empty inventory, not an error */
    Item it;
    while (fscanf(fp, "%d %30s %d %lf",
                  &it.id, it.name, &it.qty, &it.price) == 4) {
        ensure_cap();
        items[count++] = it;
    }
    fclose(fp);
    printf("Loaded %d item(s) from %s.\n", count, FNAME);
}

void save_data(void) {
    FILE *fp = fopen(FNAME, "w");
    if (!fp) { perror("fopen"); return; }
    for (int i = 0; i < count; i++)
        fprintf(fp, "%d %s %d %.2f\n",
                items[i].id, items[i].name, items[i].qty, items[i].price);
    fclose(fp);
    printf("Saved %d item(s).\n", count);
}

/* ── helpers ──────────────────────────────────────────────────── */

int find_by_id(int id) {
    for (int i = 0; i < count; i++)
        if (items[i].id == id) return i;
    return -1;
}

void print_list_header(void) {
    printf("%-4s  %-20s  %-6s  %s\n", "ID", "Name", "Qty", "Price");
    printf("----------------------------------------------\n");
}

void print_item(const Item *it) {
    printf("%-4d  %-20s  %-6d  %.2f\n", it->id, it->name, it->qty, it->price);
}

/* ── menu actions ─────────────────────────────────────────────── */

void do_add(void) {
    Item it;
    printf("ID: ");
    scanf("%d", &it.id);

    /* FIX 1: duplicate ID check */
    if (find_by_id(it.id) != -1) { printf("Duplicate ID.\n"); return; }

    printf("Name: ");  scanf("%30s", it.name);
    printf("Qty: ");   scanf("%d",  &it.qty);
    printf("Price: "); scanf("%lf", &it.price);

    /* FIX 2: non-negative validation */
    if (it.qty < 0)   { printf("Quantity must be non-negative.\n"); return; }
    if (it.price < 0) { printf("Price must be non-negative.\n");    return; }

    ensure_cap();
    items[count++] = it;
    printf("Item #%d added.\n", it.id);
}

void do_update(void) {
    int id;
    printf("ID: ");
    scanf("%d", &id);
    int p = find_by_id(id);
    if (p == -1) { printf("Not found.\n"); return; }

    int    qty;
    double price;
    printf("New qty: ");   scanf("%d",  &qty);
    printf("New price: "); scanf("%lf", &price);

    /* FIX 2 (update path): same non-negative validation */
    if (qty < 0)   { printf("Quantity must be non-negative.\n"); return; }
    if (price < 0) { printf("Price must be non-negative.\n");    return; }

    items[p].qty   = qty;
    items[p].price = price;
    printf("Updated.\n");
}

void do_remove(void) {
    int id;
    printf("ID: ");
    scanf("%d", &id);
    int p = find_by_id(id);

    /* FIX 3: was silently silent when ID not found */
    if (p == -1) { printf("Not found.\n"); return; }

    items[p] = items[--count];   /* swap-with-last soft delete */
    printf("Item #%d removed.\n", id);
}

void do_list(void) {
    if (count == 0) { printf("(empty inventory)\n"); return; }
    print_list_header();
    for (int i = 0; i < count; i++) print_item(&items[i]);
}

/* ── dispatch table ───────────────────────────────────────────── */

typedef void (*action_fn)(void);

typedef struct {
    int         key;
    const char *label;
    action_fn   fn;
} menu_item;

static const menu_item MENU[] = {
    {1, "Add",    do_add},
    {2, "Update", do_update},
    {3, "Remove", do_remove},
    {4, "List",   do_list},
};
#define MENU_LEN ((int)(sizeof MENU / sizeof MENU[0]))

static void print_menu(void) {
    for (int i = 0; i < MENU_LEN; i++)
        printf("%d)%s  ", MENU[i].key, MENU[i].label);
    printf("%d)Save&Exit\nChoice: ", MENU_LEN + 1);
}

/* Returns 1 when the user chooses Save&Exit, 0 otherwise. */
static int dispatch(int c) {
    if (c == MENU_LEN + 1) return 1;
    for (int i = 0; i < MENU_LEN; i++)
        if (MENU[i].key == c) { MENU[i].fn(); return 0; }
    printf("Invalid choice.\n");
    return 0;
}

/* ── main ─────────────────────────────────────────────────────── */

int main(void) {
    load_data();
    int c;
    do {
        print_menu();
        if (scanf("%d", &c) != 1) break;
    } while (!dispatch(c));
    save_data();   /* always save — on normal exit and on bad-input break */
    free(items);
    return 0;
}
