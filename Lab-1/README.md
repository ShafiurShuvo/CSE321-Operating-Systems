# 🐧 Linux Shell Commands – Lab 1

This document provides an organized overview of basic **Linux Shell Commands** used for file management, permissions, redirection, text processing, and more.

---

## 🧩 Table of Contents

1. [Creating Files](#1-creating-files)  
2. [Copy File](#2-copy-file)  
3. [Remove a File](#3-remove-a-file)  
4. [Move or Rename a File](#4-move-or-rename-a-file)  
5. [List File or Directory Information](#5-list-file-or-directory-information)  
6. [Security Groups and Permissions](#6-security-groups-and-permissions)  
7. [Edit Permissions (chmod)](#7-edit-permissions-chmod)  
8. [Using `bc` (Calculator)](#8-using-bc-calculator)  
9. [Working with Floats](#9-working-with-floats)  
10. [Working with Different Bases](#10-working-with-different-bases)  
11. [Working with Functions](#11-working-with-functions)  
12. [Working with Variables](#12-working-with-variables)  
13. [Factor Command](#13-factor-command)  
14. [Input Redirection](#14-input-redirection)  
15. [Output Redirection](#15-output-redirection)  
16. [Append Output](#16-append-output)  
17. [Calendar](#17-calendar)  
18. [File Viewing](#18-file-viewing)  
19. [Output First Lines (head)](#19-output-first-lines-head)  
20. [Output Last Lines (tail)](#20-output-last-lines-tail)  
21. [Sort Command](#21-sort-command)  
22. [Print Number of Lines (wc)](#22-print-number-of-lines-wc)  
23. [Piping](#23-piping)  
24. [Grep Command](#24-grep-command)  
25. [Find Command](#25-find-command)  
26. [Manual and Identity Commands](#26-manual-and-identity-commands)

---

## 1. Creating Files

- **Commands:**  
  `touch filename` – Creates an empty file.  
  `cat > filename` – Creates a file and allows text input until `Ctrl + D` (EOF).  
- **Combine files:**  
  `cat file1 file2 > newfile` – Concatenates contents of `file1` and `file2`.

---

## 2. Copy File

- **Command:** `cp source destination`  
- **Options:**  
  - `-i` → Prompt before overwrite  
  - `-r` → Copy directories recursively  
  - `-u` → Copy only if source is newer than destination

---

## 3. Remove a File

- **Command:** `rm filename`  
- **Options:**  
  - `-f` → Force remove, ignore nonexistent files  
  - `-i` → Prompt before removal  
  - `-r` → Remove directories recursively  
  - `-v` → Show what’s being removed

---

## 4. Move or Rename a File

- **Command:** `mv source destination`  
- **Options:**  
  - `-i` → Prompt before overwrite  
  - `-u` → Move only if source is newer  
  - `-v` → Show actions  

---

## 5. List File or Directory Information

- **Command:** `ls`  
- **Options:**  
  - `-a` → Show hidden files  
  - `-A` → Exclude `.` and `..`  
  - `-h` → Human-readable sizes  
  - `-l` → Long listing format  
  - `-S` → Sort by file size  

---

## 6. Security Groups and Permissions

- Each file/directory has **three groups:**
  - Owner  
  - Group  
  - Others  

- Each group has **three permissions:**
  - `r` – Read  
  - `w` – Write  
  - `x` – Execute  

Example:  
`rwxr-xr--` → Owner can read/write/execute, group can read/execute, others can read.

---

## 7. Edit Permissions (chmod)

- **Command:** `chmod [who][+/-/=][permissions] filename`  
- **Who:** `u` (user), `g` (group), `o` (others), `a` (all)  
- **Examples:**
  - `chmod go+rw file1` → Add read/write to group & others  
  - `chmod a+rwx file1` → Give all permissions to everyone  
  - `chmod 555 file1` → Read & execute only

---

## 8. Using `bc` (Calculator)

- **Command:** `bc`  
  Opens an interactive calculator in the shell.  
  Exit with `quit`.

---

## 9. Working with Floats

- Use variable `scale` to control precision:
  ```bash
  scale=5
  10/3
  ```
  ➤ This sets precision to 5 decimal places for division results.

---

## 10. Working with Different Bases

- You can change the input and output number bases using `ibase` and `obase` in `bc`.

- **Example:**
  ```bash
  ibase=2
  obase=16
  1010
  ```
  ➤ Converts the binary number `1010` to hexadecimal.

---

## 11. Working with Functions

- `bc` includes several math functions (like `s()`, `c()`, `sqrt()`, `l()`, `e()`).
- Trigonometric functions use radians, not degrees.
- **Example:**
  ```bash
  s(3.1416/2)
  ```
  ➤ Calculates sin(π/2) = 1.

---

## 12. Working with Variables

- You can assign variables in `bc` and reuse them:
  ```bash
    x=10
    y=5
    x*y
    ```
    ➤ Output: 50

---

## 13. Factor Command

- **Command:** `factor number`  
  Prints the prime factors of a given number (< 2⁴⁶).
    ```bash
    factor 60
    ```
    ➤ Output: `60: 2 2 3 5`

---

## 14. Input Redirection

- **Symbol:** `<`  
  Takes input from a file instead of the keyboard.
  ```bash
  bc < input.txt
  ```
  ➤ Executes the commands from `input.txt`.

---

## 15. Output Redirection

  - **Symbol:** `>`  
    Sends output to a file instead of displaying it on the screen.
    ```bash
    echo "Hello" > output.txt
    ```
    ➤ Writes “Hello” into `output.txt`.

---

## 16. Append Output

  - **Symbol:** `>>`  
    Appends new output to the end of an existing file.
    ```bash
    echo "More text" >> output.txt
    ```
    ➤ Adds “More text” to `output.txt` without overwriting previous data.

---

## 17. Calendar

  - **Command:** `cal`
    Displays a calendar in the terminal.
    ```bash
    cal
    ```
    ➤ Shows the current month’s calendar.

---

## 18. File Viewing

- Common commands for viewing file contents:
  - `head` → View first n lines.
  - `tail` → View last n lines.
  - `sort` → Sort file content alphabetically.
  - `wc` → Count lines, words, and bytes.
 
---

## 19. Output First Lines (head)

  - **Command:** `head filename`  
    Displays the first 10 lines by default.  
    ```bash
    head -n 5 file.txt
    ```
    ➤ Shows the first 5 lines of `file.txt`.

---

## 20. Output Last Lines (tail)

  - **Command:** `tail filename`  
    Displays the last 10 lines by default.
    ```bash
    tail -n 20 file.txt
    ```
    ➤ Shows the last 20 lines of `file.txt`.

---

## 21. Sort Command

  - **Command:** `sort filename`  
    Sorts the lines of the file in ascending (alphabetical) order.
    ```bash
    sort names.txt
    ```
    ➤ Displays the file in sorted order.

---

## 22. Print Number of Lines (wc)

  - **Command:** `wc filename`  
    Counts lines, words, and bytes in a file.
    
  - **Options:**
    
      - `-l` → Show only line count.
      
      - `-w` → Show only word count.
      ```bash
      wc -l notes.txt
      ```
      ➤ Displays number of lines in `notes.txt`.

---

## 23. Piping

  - **Symbol:** `|`  
    Sends output of one command as input to another.
    ```bash
    head -20 a.txt | tail -5
    ```
    ➤ Displays lines 15–20 of `a.txt`.

---

## 24. Grep Command

  - **Command:** `grep pattern filename`  
    Searches for matching text patterns in files.
  - **Common Options:**
      - `i` → Ignore case
      - `c` → Count matches
      - `E` → Use regular expressions
      - `n` → Show line numbers
      ```bash
      grep -n "error" logfile.txt
      ```
      
      ➤ Finds lines containing “error” with line numbers.

---

## 25. Find Command

  - **Command:** `find [path] [options]`  
    Searches for files and directories within a hierarchy.
  - **Examples:**
    ```bash
    find -name "*.txt"              # find all text files
    find -type d                    # find directories
    find -type f -exec ls -l {} \;  # run command on each file
    find /home -name "myfile"       # search a path
    find -user username             # find files owned by a user
    ```
    ➤ Powerful tool for locating and acting on files.
  
---

## 26. Manual and Identity Commands

  - `uname` → Displays system or kernel name.
  - `whoami` → Shows the current logged-in username.
  - `man command` → Displays manual/help for a command.
  ```bash
  man ls
  ```
  ➤ Opens the manual for `ls`.

## ⚙️ Quick Command Summary

```bash
ls        🠮 list files and directories
cd        🠮 change directory
cd ..     🠮 go back to previous directory
touch     🠮 create an empty file
cat       🠮 display or create files
cp        🠮 copy files or directories
mv        🠮 move or rename files
rm        🠮 remove files or directories
chmod     🠮 change file permissions
cal       🠮 display calendar
bc        🠮 open calculator
head      🠮 show first 10 lines of a file
tail      🠮 show last 10 lines of a file
sort      🠮 sort lines in a file
wc        🠮 count lines, words, and bytes
grep      🠮 search for a pattern in a file
find      🠮 search files or directories
| (pipe)  🠮 send output of one command to another
>         🠮 redirect output to a file
>>        🠮 append output to a file
<         🠮 take input from a file
whoami    🠮 display current username
uname     🠮 show system information
```

## End of Lab 1 – Linux Shell Commands 🔚
