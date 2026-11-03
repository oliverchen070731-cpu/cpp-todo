# C++ Command-Line To-Do List

A simple command-line app for adding to-do items and viewing them in the order they were added. The list is stored in memory and starts empty each time you run the program.

## Build and run

You need a version of Clang that supports C++17. From the project root, run:

```bash
clang++ -std=c++17 -Wall -Wextra -pedantic c++_project1_interface.cpp -o todo
./todo
```

## Example

1. Enter `1`, then type `Read C++ notes` and press Enter. The program displays `Added successfully`.
2. Enter `2` to view the list. The first item appears as `1.Read C++ notes`.
3. Enter `0` to quit. The program displays `Goodbye`.

The app rejects empty items and items made up only of ordinary spaces or tabs. It trims spaces and tabs from the start and end of each item and preserves spaces within the text. Full-width spaces (`U+3000`) are treated as item text.
