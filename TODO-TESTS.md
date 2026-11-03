# To-Do List Test Report

The program was built with Clang using C++17 on macOS. All **12 Milestone 1 checks passed** on November 4, 2026.

```bash
clang++ -std=c++17 -Wall -Wextra -pedantic c++_project1_interface.cpp -o todo
./todo
```

## Results

Start a fresh process for each row. Use menu option `1` to add an item, `2` to view the list, and `0` to exit.

| # | Test | Steps | Expected result | Observed result |
|---|---|---|---|---|
| 1 | Empty list | View the list immediately after launch. | An empty-list message appears. | Pass. The program displayed an empty-list message. |
| 2 | Single item | Add `学习 vector`, then view the list. | The item appears as entry 1. | Pass. Entry 1 matched the input. |
| 3 | Order and repeated viewing | Add `A`, then `B`. View the list twice. | Both views show `A` first and `B` second. | Pass. Both views showed the same two entries in order. |
| 4 | Internal spaces | Add `Read C++ notes`, then view the list. | Spaces between words are preserved. | Pass. The full text appeared unchanged. |
| 5 | Leading and trailing whitespace | Add `A` with spaces and tabs on both ends. | Only `A` is stored. | Pass. Both ends were trimmed. |
| 6 | Blank items | Try an empty line, then try a line containing only spaces and tabs. View the list after each attempt. | Both inputs are rejected and the list stays empty. | Pass. Neither attempt added an entry or reported success. |
| 7 | Duplicate items | Add `A` twice, then view the list. | Two separate entries appear. | Pass. Both copies appeared with distinct numbers. |
| 8 | Invalid menu input | Enter a blank line, `abc`, `3`, and `1abc`. Then add and view `A`. | All four choices are rejected and the menu remains usable. | Pass. Four invalid-input messages appeared, and `A` was added and displayed. |
| 9 | Whitespace around a menu choice | Enter `2` with surrounding spaces and a tab. | The program opens the list. | Pass. The empty-list message appeared. |
| 10 | Exit and restart | Add `A`, enter `0`, then start a fresh process and view the list. | The first process exits after `Goodbye`. The new list is empty. | Pass. Both behaviors were observed. |
| 11 | End of input at the menu | End input while the program waits for a menu choice. | The program exits normally. | Pass. It exited with status 0. |
| 12 | End of input while adding | Enter `1`, then end input before entering an item. | The program exits normally without reporting an addition. | Pass. It exited with status 0 and printed no success message. |

## Known limitation

An additional check confirmed that a line containing only an ideographic space (`U+3000`, also called a full-width space) is accepted and stored as an item. The current whitespace check recognizes ordinary spaces and tabs. This additional check is outside the original Milestone 1 cases.
