# 📚 Student Record System (C Language)

A simple terminal-based Student Record Management System written in C. This project allows you to **add**, **view**, **search**, **update**, and **delete** student records. It demonstrates file handling, structures, and basic CRUD operations in C.

## 🚀 Features

- Add new student records
- View all student records
- Search for a student by ID or name
- Update existing student details
- Delete a student record
- Data persistence using file handling

## 🛠️ Technologies Used

- C Programming Language
- File Handling in C (`fopen`, `fwrite`, `fread`, etc.)
- GCC Compiler

## 📁 File Structure

```
student-record/
│
├── student_record.c         # Main source code file
├── students.dat             # Binary file where student data is stored (created at runtime)
└── README.md                # Project documentation
```

## 🧑‍💻 How to Run

### Step 1: Compile the Code

Using GCC:
```bash
gcc student_record.c -o student_record
```

### Step 2: Run the Program

```bash
./student_record
```

### Note:
- On Windows, use `student_record.exe` instead of `./student_record`.

## 📝 Record Structure

Each student record includes:
- ID (Integer)
- Name (String)
- Branch (String)
- Percentage (Float)

## 🌟 Sample Output

```
===== Student Record System =====

1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit

Enter your choice:
```

## 🧠 Concepts Covered

- File I/O in C
- Structures (`struct`)
- Functions
- Basic menu-driven programming
- Error handling

## 📌 To-Do / Future Improvements

- Password protection for the system
- Export data to CSV
- Better input validation
- GUI version using C++ or Java

 for details.

## 🙌 Acknowledgments

Inspired by beginner-level C programming projects to help students strengthen their understanding of file handling and struct usage.
