# 🧮 Arbitrary Precision Calculator

## 📌 Description

Arbitrary Precision Calculator (APC) is a **C-based calculator for performing arithmetic operations on very large numbers** that cannot be handled directly by standard C integer data types.

The project represents numbers using a **Doubly Linked List**, allowing arithmetic operations to be performed digit by digit.

## 🚀 Features

* Addition of large numbers
* Subtraction of large numbers
* Multiplication of large numbers
* Division of large numbers
* Supports numbers larger than standard C integer limits
* Command-line based interface
* Uses Doubly Linked List for number representation

## 🛠️ Technologies Used

* **Language:** C
* **Platform:** Linux
* **Compiler:** GCC
* **Data Structure:** Doubly Linked List
* **Build Tool:** Make

## 🧠 Concepts Demonstrated

* Doubly Linked Lists
* Dynamic Memory Allocation
* Structures
* Pointers
* String Handling
* Command Line Arguments
* Arithmetic Operations
* Modular Programming
* Memory Management

## ⚙️ How It Works

Instead of storing the complete number in an `int` or `long long` variable, the calculator stores the digits of the number using a **Doubly Linked List**.

For example:

```text
12345678901234567890

9 <-> 8 <-> 7 <-> 6 <-> 5 <-> ... <-> 1
```

Arithmetic operations are then performed on the individual digits while handling carry and borrow operations.

## ➕ Supported Operations

| Operation      | Operator |
| -------------- | -------- |
| Addition       | `+`      |
| Subtraction    | `-`      |
| Multiplication | `*`      |
| Division       | `/`      |

## ⚙️ How to Compile

```bash
make
```

## ▶️ How to Run

```bash
./apc <number1> <operator> <number2>
```

### Example

```bash
./apc 99999999999999999999 + 88888888888888888888
```

Output:

```text
Result : 188888888888888888887
```

## 📚 What I Learned

Through this project, I gained practical experience with:

* Implementing arithmetic operations using linked lists
* Handling numbers larger than standard C data types
* Working with dynamic memory allocation
* Manipulating pointers and structures
* Processing command-line arguments
* Implementing mathematical operations at digit level
* Managing memory in a larger C project

## 🎯 Key Skills

**C Programming • Doubly Linked Lists • Pointers • Dynamic Memory Allocation • Data Structures • Command Line Arguments • Memory Management • Arithmetic Algorithms**
