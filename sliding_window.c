#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* min_window(const char *s, const char *t) {

    int need[128] = {0};   /* required frequency of each char */
    int have[128] = {0};   /* current window frequency */

    /* Build need[] from t */
    int t_len = (int)strlen(t);
    for (int i = 0; i < t_len; i++) need[(int)t[i]]++;

    /* Count distinct chars required */
    int t_distinct = 0;
    for (int i = 0; i < 128; i++)
        if (need[i] > 0) t_distinct++;

    int s_len = (int)strlen(s);
    int left   = 0;
    int formed = 0;           /* chars satisfying frequency */
    int min_len   = INT_MAX;
    int min_start = 0;

    for (int right = 0; right < s_len; right++) {

        /* Expand: add s[right] to window */
        int c = (int)s[right];
        have[c]++;

        /* Check if this char's requirement is now satisfied */
        if (need[c] > 0 && have[c] == need[c]) formed++;

        /* Shrink: while window is valid, try to minimise */
        while (formed == t_distinct) {

            /* Update minimum */
            int cur_len = right - left + 1;
            if (cur_len < min_len) {
                min_len   = cur_len;
                min_start = left;
            }

            /* Remove s[left] from window */
            int lc = (int)s[left];
            have[lc]--;
            if (need[lc] > 0 && have[lc] < need[lc]) formed--;
            left++;
        }
    }

    if (min_len == INT_MAX) return "";

    /* Return pointer into s — valid because s is caller's memory */
    /* For a heap copy: */
    char *result = (char*)malloc(min_len + 1);
    if (!result) return "";
    strncpy(result, s + min_start, min_len);
    result[min_len] = '\0';
    return result;
}

/* ── TRACED VERSION ── */
void min_window_trace(const char *s, const char *t) {

    printf("s=\"%s\" t=\"%s\"\n", s, t);

    int need[128] = {0}, have[128] = {0};
    int t_len = (int)strlen(t);
    for (int i = 0; i < t_len; i++) need[(int)t[i]]++;

    int t_distinct = 0;
    for (int i = 0; i < 128; i++)
        if (need[i] > 0) t_distinct++;

    int s_len = (int)strlen(s);
    int left = 0, formed = 0;
    int min_len = INT_MAX, min_start = 0;

    printf("%-6s %-6s %-10s %-10s %s\n",
           "left", "right", "window", "formed", "min");
    printf("------------------------------------------\n");

    for (int right = 0; right < s_len; right++) {

        int c = (int)s[right];
        have[c]++;
        if (need[c] > 0 && have[c] == need[c]) formed++;

        while (formed == t_distinct) {
            int cur_len = right - left + 1;
            if (cur_len < min_len) {
                min_len   = cur_len;
                min_start = left;
            }

            /* Print current window */
            printf("%-6d %-6d \"", left, right);
            for (int k = left; k <= right; k++)
                printf("%c", s[k]);
            printf("\" %-6d", formed);
            if (cur_len < min_len + 1)
                printf(" ← min so far");
            printf("\n");

            int lc = (int)s[left];
            have[lc]--;
            if (need[lc] > 0 && have[lc] < need[lc]) formed--;
            left++;
        }
    }

    if (min_len == INT_MAX) {
        printf("Result: \"\" (no valid window)\n\n");
    } else {
        printf("Result: \"");
        for (int i = min_start; i < min_start + min_len; i++)
            printf("%c", s[i]);
        printf("\" (len=%d)\n\n", min_len);
    }
}

int main() {

    printf("Minimum Window Substring:\n");
    printf("==========================\n\n");

    min_window_trace("ADOBECODEBANC", "ABC");

    /* Full tests */
    struct { const char *s, *t, *exp; } tests[] = {
        {"ADOBECODEBANC", "ABC",  "BANC"},
        {"a",             "a",    "a"},
        {"a",             "aa",   ""},
        {"aa",            "aa",   "aa"},
        {"ABCDEF",        "ACF",  "ABCDEF"},
    };
    int num = 5;

    printf("Test results:\n");
    for (int i = 0; i < num; i++) {
        char *r = min_window(tests[i].s, tests[i].t);
        printf("  s=\"%-15s\" t=\"%-4s\" → \"%-10s\" exp=\"%-10s\" %s\n",
               tests[i].s, tests[i].t, r, tests[i].exp,
               strcmp(r, tests[i].exp)==0?"✓":"✗");
        if (*r) free(r);
    }

    return 0;
}