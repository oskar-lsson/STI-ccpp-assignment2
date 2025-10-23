# 📘 Assignment 2: Object-Oriented Measurement Data Manager

## Contents
- [Setup Instructions](#-setup)
- [System Overview](#-system)
- [Background](#-background)
- [Task](#-task)
- [Requirements Specification](#-requirements)
  - [Program Structure](#-1-program-structure)
  - [Data Handling](#-2-data-handling)
  - [File I/O](#-3-file-io)

---

## 🔧 Setup Instructions
- Clone the repo: `git clone https://github.com/oskar-lsson/STI-ccpp-assignment2.git`
- Open `.sln` in Visual Studio
- Build and run the project

---

## 🖥️ System Overview
A C++ console application that:
- Stores and analyzes measurement data
- Uses classes and structs for structure
- Saves and loads data from file
- Offers a menu-based interface

---

## 📚 Background
This assignment builds on the first one by introducing object-oriented programming.  
The goal is to improve structure and maintainability using classes, structs, and file handling.

---

## 🎯 Task
Extend the previous program to:
- Use at least one class and one struct
- Move logic into methods
- Add file reading/writing functionality

---

## 📐 Requirements Specification

### 1. Program Structure
- Use a class (e.g. `DataManager`) and a struct (`Measurement`)
- Split code into multiple files: `main.cpp`, `data_manager.h/.cpp`, `measurement.h`

### 2. Data Handling
- Store data in `std::vector<Measurement>`
```cpp
struct Measurement {
    float value;
    std::string timestamp;
};
Include methods to add data, calculate statistics, and print results
```
###3. File I/O
- Read data from file at startup
- Save data to file on exit
- Format: YYYY-MM-DD HH:MM,value
