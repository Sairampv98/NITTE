/*
#include<stdio.h>
#include<string.h>

typedef enum {HR,ENG,ACC}dep;
const char *deptName[] = {"HR", "ENG", "ACC"};
typedef struct{
    int id; 
    char name[31]; 
    dep dept; 
    int salary; 
    int is_active;
}employee;

employee emp[10];
int count =0;
int c;
int first_time = 1;

int find_by_id(int id){
    for(int i=0; i<count; i++){
        if(emp[i].is_active && emp[i].id == id){
            return i;
        }
        return -1;
    }
}

void print_emp(employee e){
    printf("%d  %s  %s  %d\n",e.id,e.name, deptName[e.dept],e.salary);
}

void update_emp(employee *e,int newsalary){
    e->salary = newsalary;
}

void menu(){
    printf("1)Add 2)List 3)Find 4)Update 5)Remove 6)Exit\n");
    scanf("");
}

void sub_menu(){
    printf("1)Previous Menu 2)Exit\n");
}

int choice(int choice){
    if(first_time==0){
        employee e;
        int d;
        printf("ID: ");
        scanf("%d", &e.id);           
        printf("\nName: ");
        scanf("%30s", e.name);
        printf("\nDept (0:HR, 1:ENG, 2:ACC): ");
        scanf("%d",&d);
        e.dept = (dep)d;
        printf("\nSalary: ");
        scanf("%d", e.salary);
        e.is_active = 1;
        emp[count++]=e;
        count++;
        first_time = 1;
    }
    if(choice==1){
        if(count>10){
            printf("Database full Force exit");
        }
        employee e;
        int d;
        printf("ID: ");
        scanf("%d", &e.id);
        if(find_by_id(e.id)!=-1){
            printf("duplicate ID");
            menu();
        }           
        printf("\nName: ");
        scanf("%30s", e.name);
        printf("\nDept (0:HR, 1:ENG, 2:ACC): ");
        scanf("%d",&d);
        e.dept = (dep)d;
        printf("\nSalary: ");
        scanf("%d", e.salary);
        e.is_active = 1;
        emp[count++]=e;
    }else if(choice==2){
        printf("\nID  Name                        Dept    Salary\n");
        for(int i=0; i<count; i++){
            if(emp[i].is_active){
                print_emp(emp[i]);
            }
        }
    }else if(choice==3){
        int id;
        printf("\nID: ");
        scanf("%d", id);
        int p=find_by_id(id);
        if(p==-1){
            printf("Employee Not Found\n"); 
        }else{
            print_emp(emp[p]);
        }
    }else if(choice == 4){
        int id, s;
        printf("\nID: ");
        scanf("%d", &id);
        int p = find_by_id(id);
        if(p==-1){
            printf("Employee Not Found\n"); 
        }else{
            printf("\nNew Salary: ");
            scanf("%d", &s);
            update_emp(&emp[p], s);
        }
    }else if(choice==5){
        int id;
        printf("\nID: ");
        scanf("%d",&id);
        int p=find_by_id(id);
        if(p==-1){
            printf("Employee Not Found\n"); 
        }else{
            emp[p].is_active = 0;
        }
    }
    return -1;
}

int main(){
    menu();
    scanf("%d", &c);
    int exit = choice(c);
    if(exit == -1)
    return 0;
    /*
    do{
        printf("1)Add 2)List 3)Find 4)Update 5)Remove 6)Exit\n");
        if(scanf("%d",&choice)!=1){
            printf("Empty Database Force Exit");
            break;
        }
        if(choice==1){
            if(count>10){
                printf("Database full Force exit");
                break;
            }
            employee e;
            int d;
            printf("ID: ");
            scanf("%d", &e.id);
            
            //if(find_by_id(e.id)!=-1){
            //    printf("duplicate ID");
            //    continue;
            //}
            
            printf("\nName: ");
            scanf("%30s", e.name);
            printf("\nDept (0:HR, 1:ENG, 2:ACC): ");
            scanf("%d",&d);
            e.dept = (dep)d;
            printf("\nSalary: ");
            scanf("%d", e.salary);
            e.is_active = 1;
            emp[count++]=e;
            continue;
        }else if(choice==2){
            printf("\nID  Name                        Dept    Salary\n");
            for(int i=0; i<count; i++){
                if(emp[i].is_active){
                    print_emp(emp[i]);
                }
            }
            continue;
        }else if(choice==3){
            int id;
            printf("\nID: ");
            scanf("%d", id);
            int p=find_by_id(id);
            if(p==-1){
                printf("Employee Not Found\n"); 
                continue;
            }else{
                print_emp(emp[p]);
                continue;
            }
        }else if(choice == 4){
            int id, s;
            printf("\nID: ");
            scanf("%d", &id);
            int p = find_by_id(id);
            if(p==-1){
                printf("Employee Not Found\n"); 
                continue;
            }else{
                printf("\nNew Salary: ");
                scanf("%d", &s);
                update_emp(&emp[p], s);
                continue;
            }
        }else if(choice==5){
            int id;
            printf("\nID: ");
            scanf("%d",&id);
            int p=find_by_id(id);
            if(p==-1){
                printf("Employee Not Found\n"); 
                continue;
            }else{
                emp[p].is_active = 0;
                continue;
            }
        }
    }while(choice!=6);
    return 0;

*/
//Old code is commented out for reference, contains bugs and is not working as expected. 
//The idea was to use a dipatch table to have a menu cli tool here is corrected & updated code.

/*
 * Employee Management System
 * Built on the user's draft; bugs fixed, dispatch-table loop added.
 *
 * Bug fixes applied
 * -----------------
 * 1. find_by_id : return -1 moved OUTSIDE the loop (was inside → never
 *                 searched past index 0).
 * 2. do_add     : & added to scanf("%d", &e.salary)  — was missing.
 * 3. do_find    : & added to scanf("%d", &id)         — was missing.
 * 4. do_add     : duplicate-ID check now returns early instead of
 *                 falling through into the rest of the add logic.
 * 5. capacity   : guard changed to count >= MAX (was count > 10 with
 *                 a 10-element array — off-by-one OOB write).
 * 6. main       : proper do-while loop replacing the single-shot call.
 * 7. menu()     : stray scanf("") removed.
 * 8. first_time : entire dead block removed.
 */

#include <stdio.h>
#include <string.h>

#define MAX 50

/* ── types (your originals, untouched) ───────────────────────────────── */

typedef enum { HR, ENG, ACC } dep;
const char *deptName[] = {"HR", "ENG", "ACC"};

typedef struct {
    int  id;
    char name[31];
    dep  dept;
    int  salary;
    int  is_active;
} employee;

employee emp[MAX];
int count = 0;

/* ── core helpers (your originals, bugs fixed) ───────────────────────── */

int find_by_id(int id) {
    for (int i = 0; i < count; i++) {
        if (emp[i].is_active && emp[i].id == id)
            return i;
    }
    return -1;   /* FIX: was inside the loop body — only ever checked emp[0] */
}

/* Takes employee BY VALUE — caller gets a read-only copy.
   Fine for printing; would be wasteful if the struct were huge. */
void print_emp(employee e) {
    printf("%-4d  %-30s  %-6s  %d\n",
           e.id, e.name, deptName[e.dept], e.salary);
}

/* Takes employee BY POINTER — needed so the change persists in the array. */
void update_emp(employee *e, int newsalary) {
    e->salary = newsalary;
}

/* ── one function per menu action ────────────────────────────────────── */

void do_add(void) {
    if (count >= MAX) { printf("Database full.\n"); return; }

    employee e;
    int d;

    printf("ID: ");
    scanf("%d", &e.id);

    if (find_by_id(e.id) != -1) {          /* FIX: return early, not fall-through */
        printf("Duplicate ID — aborting.\n");
        return;
    }

    printf("Name: ");
    scanf("%30s", e.name);

    printf("Dept (0:HR  1:ENG  2:ACC): ");
    scanf("%d", &d);
    e.dept = (dep)d;

    printf("Salary: ");
    scanf("%d", &e.salary);                 /* FIX: & was missing */

    e.is_active = 1;
    emp[count++] = e;
    printf("Employee added.\n");
}

void do_list(void) {
    printf("\n%-4s  %-30s  %-6s  %s\n", "ID", "Name", "Dept", "Salary");
    printf("----------------------------------------------------\n");
    int any = 0;
    for (int i = 0; i < count; i++) {
        if (emp[i].is_active) { print_emp(emp[i]); any = 1; }
    }
    if (!any) printf("(no active employees)\n");
}

void do_find(void) {
    int id;
    printf("ID: ");
    scanf("%d", &id);                       /* FIX: & was missing */
    int p = find_by_id(id);
    if (p == -1) printf("Employee not found.\n");
    else         print_emp(emp[p]);
}

void do_update(void) {
    int id, s;
    printf("ID: ");
    scanf("%d", &id);
    int p = find_by_id(id);
    if (p == -1) { printf("Employee not found.\n"); return; }
    printf("New salary: ");
    scanf("%d", &s);
    update_emp(&emp[p], s);                 /* passes pointer — mutation persists */
    printf("Salary updated.\n");
}

void do_remove(void) {
    int id;
    printf("ID: ");
    scanf("%d", &id);
    int p = find_by_id(id);
    if (p == -1) printf("Employee not found.\n");
    else { emp[p].is_active = 0; printf("Employee removed.\n"); }
}

/* ── dispatch table ──────────────────────────────────────────────────── */

typedef void (*action_fn)(void);

typedef struct {
    int         key;
    const char *label;
    action_fn   fn;
} menu_item;

static const menu_item MENU[] = {
    {1, "Add",    do_add},
    {2, "List",   do_list},
    {3, "Find",   do_find},
    {4, "Update", do_update},
    {5, "Remove", do_remove},
};
#define MENU_LEN ((int)(sizeof MENU / sizeof MENU[0]))

static void print_menu(void) {
    for (int i = 0; i < MENU_LEN; i++)
        printf("%d)%s  ", MENU[i].key, MENU[i].label);
    printf("6)Exit\nChoice: ");
}

/* Returns 1 when the user chose Exit, 0 otherwise. */
static int dispatch(int c) {
    if (c == 6) return 1;
    for (int i = 0; i < MENU_LEN; i++) {
        if (MENU[i].key == c) {
            MENU[i].fn();
            return 0;
        }
    }
    printf("Invalid choice.\n");
    return 0;
}

/* ── main ────────────────────────────────────────────────────────────── */

int main(void) {
    int c;
    do {
        print_menu();
        if (scanf("%d", &c) != 1) {       /* guard against non-numeric input */
            printf("Bad input — exiting.\n");
            break;
        }
    } while (!dispatch(c));
    return 0;
}

