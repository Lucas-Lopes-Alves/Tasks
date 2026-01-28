# Tasks
A Linux terminal command to organize daily tasks.


## Description

Tasks is a simple Linux terminal command for managing daily tasks.

---

## Commands

### add
Adds a new task

Usage:
- `tasks add "[task]"`

The --important or -i flag define the task as an priority task and appear with an * in the list command

Usage:
- `tasks add "[task] --important"` or `tasks add "[task] -i"`

### remove
Remove a task based on its number, the number appears in the list command.

Usage:
- `tasks remove 1`

Remove can remove all the tasks just by using the flag --all.

Usage:
- `tasks remove --all`

### list
Lists all the tasks in the tasks file.

Usage:
- `tasks list`

With the --important or -i flag, it shows only the tasks marked as important

Usage:
- `tasks list --important` or `tasks list -i`

### change
Change a task based on its position on the file.

Usage:
- `tasks change 1 "new_task"`

## License

This project is for learning purposes only