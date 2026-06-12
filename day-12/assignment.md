## Banking System with Error Logs _(Error Handling & Debugging)_

**Scenario.** A bank program must never silently misbehave: every bad operation should be rejected cleanly and recorded, and any system failure should be reported precisely.

**Build this.** A simple banking program over a handful of accounts, where the emphasis is on **defensive checks and an error log file**, not on fancy features.

**Required features.**

1. Accounts with an id and a balance. Operations: deposit, withdraw, transfer between accounts, and check balance.
2. Validate everything: reject negative amounts, withdrawals/transfers that exceed the balance, and operations on an account id that doesn't exist. Each rejection returns a clear status, it does not crash.
3. Maintain an **error log file**: every failed operation appends a line describing what was attempted and why it failed.
4. When a file operation itself fails, report it with `perror`/`errno`. Use an `assert` for at least one "this should never happen" invariant (e.g. balance never goes negative after a successful withdrawal).

**Input / output.** Menu-driven; successful operations print the new balance; failures print a short reason and are logged.

**Sample run.**

```
Choice: Withdraw   Account: 1001   Amount: 9999
Declined: insufficient funds.
(logged to errors.log)

```

**Constraints.** Balances and amounts are non-negative. The program must not terminate on a user error — only on Exit.

**You may use.** `errno`/`perror`, `assert`, `goto` for cleanup paths, file writing for the log. Structures and files from earlier days.

**Plan on paper first.** List every way each operation can fail, and write the exact log line you'd produce for each. Decide where a single `goto cleanup` would tidy up an operation that opens a file and then hits an error.

