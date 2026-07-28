# 📅 Date & Time Utility Library (C++)

![C++ Version](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Platform](https://img.shields.io/badge/platform-Cross--Platform-lightgrey.svg)

A high-performance, modular C++ Object-Oriented library designed to handle complex date and time manipulation, calendar algorithms, date arithmetic, period validations, and workday scheduling with precision and safety.

Developed by **Eng. Abdulhamid AbuSaada** ([@abdelhamid021](https://github.com/abdelhamid021)).

---

## 📌 Table of Contents

- [Overview](#-overview)
- [Architecture & Design](#-architecture--design)
- [Features](#-features)
- [Repository Structure](#-repository-structure)
- [Getting Started & Compilation](#-getting-started--compilation)
- [Code Examples & Usage](#-code-examples--usage)
  - [1. Date Creation & Formatting](#1-date-creation--formatting)
  - [2. Leap Year & Calendar Operations](#2-leap-year--calendar-operations)
  - [3. Date Arithmetic & Manipulation](#3-date-arithmetic--manipulation)
  - [4. Differences & Age Calculation](#4-differences--age-calculation)
  - [5. Business Days & Vacation Logic](#5-business-days--vacation-logic)
  - [6. Period Overlap & Range Detection](#6-period-overlap--range-detection)
- [API Reference](#-api-reference)
- [Contributing](#-contributing)
- [Author & License](#-author--license)

---

## 🛠️ Overview

Working with dates and times in standard C++ can often be cumbersome and error-prone. The **Date & Time Utility Library** provides an intuitive, robust, and full-featured Object-Oriented solution (`clsDate` & `clsPeriod`) that abstracts underlying algorithmic complexity into clean, reusable, and type-safe methods.

Whether you need to compute business days excluding weekends, calculate accurate age differences, render interactive ASCII calendars, or check for period overlaps in scheduling applications, this library delivers full support with minimal overhead.

---

## 🏗️ Architecture & Design

The library is built following strong OOP principles, encapsulation, and clear separation of concerns:

1. **Header Files (`include/`)**: Contains clean declaration and implementation of core components:
   - `clsDate.h`: Core date operations, conversions, calendar algorithms, and arithmetic.
   - `clsPeriod.h`: Represents date intervals and handles range checking, overlap logic, and period lengths.
   - `clsString.h`: String parsing and manipulation helper utilities used for custom date formatting.
2. **Implementation & Entry Point (`Impelement-DateTimeLibrary.cpp`)**: Demonstrates comprehensive test cases, real-world execution, and interactive CLI demonstrations of the library features.

---

## ✨ Features

### 📅 1. Date Construction & Conversions
- Multiple constructor overloads:
  - Default constructor (fetches current local system date/time).
  - String constructor (`"DD/MM/YYYY"`).
  - Structured constructor (`Day`, `Month`, `Year`).
  - Day order constructor (`DayOrderInYear`, `Year`).
- Seamless conversion between string formats and structured date objects.

### 🗓️ 2. Calendar Algorithms
- Precise Leap Year evaluation using standard modulo rules.
- Fast day-of-week calculation using Zeller’s Congruence algorithm.
- Interactive monthly and annual ASCII calendar generator.
- Calculation of total days, hours, minutes, and seconds in any month or year.

### ➕ 3. Date Arithmetic & Adjustments
- Add or subtract arbitrary numbers of days, weeks, months, or years.
- Increment/Decrement functions (`AddOneDay`, `IncreaseDateByOneMonth`, `DecreaseDateByXDays`, etc.).
- Auto-adjustment for month-end boundaries and leap years.

### ⏱️ 4. Difference & Age Computation
- Precise day difference algorithm between any two dates (taking leap years into account).
- Exact age calculation in total days, hours, minutes, and seconds.
- Date ordering and comparison methods (`IsBefore`, `IsEqual`, `IsAfter`, `Compare`).

### 💼 5. Business Days & Vacation Management
- Identify weekends and business days based on configurable weekend rules.
- Calculate net working days between two dates.
- Compute vacation return dates automatically based on requested vacation days.

### 🔄 6. Period Range & Overlap Detection
- `clsPeriod` class to define start and end dates.
- Check if a date falls within a specific period.
- Detect overlapping time intervals for booking or scheduling systems.
- Calculate overlap duration in days.

---

## 📁 Repository Structure

```text
Date-Time-Project/
├── include/
│   ├── clsDate.h                      # Primary Date class definition & static helpers
│   ├── clsPeriod.h                    # Period management & interval algorithms
│   └── clsString.h                    # Helper class for string splitting & parsing
├── Impelement-DateTimeLibrary.cpp     # Execution entry point & feature test runner
└── README.md                          # Project documentation
```

🚀 Getting Started & CompilationPrerequisitesA C++17 (or later) compliant compiler (e.g., g++, clang++, or Microsoft Visual C++ MSVC).Compilation CommandsUsing GCC / G++ (Linux / macOS / MinGW):Bash# Clone the repository
git clone [https://github.com/abdelhamid021/Date-Time-Project.git](https://github.com/abdelhamid021/Date-Time-Project.git)

# Navigate into the project folder
cd Date-Time-Project

# Compile the project including the header directory
g++ -std=c++17 Impelement-DateTimeLibrary.cpp -Iinclude -o DateTimeApp

# Run the executable
./DateTimeApp
Using Clang++:Bashclang++ -std=c++17 Impelement-DateTimeLibrary.cpp -Iinclude -o DateTimeApp
./DateTimeApp
Using MSVC (Developer Command Prompt on Windows):DOScl /EHsc /std:c++17 /Iinclude Impelement-DateTimeLibrary.cpp /Fe:DateTimeApp.exe
DateTimeApp.exe
💡 Code Examples & Usage1. Date Creation & FormattingC++#include <iostream>
#include "clsDate.h"

int main() {
    // 1. Get current system date
    clsDate CurrentDate;
    std::cout << "Current Date: " << CurrentDate.DateToString() << std::endl;

    // 2. Construct from string
    clsDate EventDate("28/07/2026");
    std::cout << "Event Date: ";
    EventDate.Print();

    // 3. Custom Date Formatting
    std::cout << "Formatted (YYYY-MM-DD): " << clsDate::FormatDate(EventDate, "YYYY-MM-DD") << std::endl;

    return 0;
}
2. Leap Year & Calendar OperationsC++#include <iostream>
#include "clsDate.h"

int main() {
    short Year = 2026;

    if (clsDate::IsLeapYear(Year)) {
        std::cout << Year << " is a Leap Year.\n";
    } else {
        std::cout << Year << " is NOT a Leap Year.\n";
    }

    // Print calendar grid for July 2026
    clsDate::PrintMonthCalendar(7, 2026);

    return 0;
}
3. Date Arithmetic & ManipulationC++#include <iostream>
#include "clsDate.h"

int main() {
    clsDate Date(15, 3, 2026);

    // Add 45 days
    Date.AddDays(45);
    std::cout << "After adding 45 days: " << Date.DateToString() << std::endl;

    // Add 2 Years
    Date.AddYears(2);
    std::cout << "After adding 2 years: " << Date.DateToString() << std::endl;

    return 0;
}
4. Differences & Age CalculationC++#include <iostream>
#include "clsDate.h"

int main() {
    clsDate BirthDate(15, 5, 2002);
    clsDate Today = clsDate::GetSystemDate();

    int TotalDays = clsDate::GetDifferenceInDays(BirthDate, Today, true);
    std::cout << "Total Days Lived: " << TotalDays << " days.\n";

    return 0;
}
5. Business Days & Vacation LogicC++#include <iostream>
#include "clsDate.h"

int main() {
    clsDate VacationStart(1, 8, 2026);
    clsDate VacationEnd(15, 8, 2026);

    // Count business days excluding weekends
    short WorkingDays = clsDate::CalculateBusinessDays(VacationStart, VacationEnd);
    std::cout << "Actual Business Days: " << WorkingDays << std::endl;

    // Calculate return date for a 10 business-day vacation
    clsDate ReturnDate = clsDate::CalculateVacationReturnDate(VacationStart, 10);
    std::cout << "Return to Work Date: " << ReturnDate.DateToString() << std::endl;

    return 0;
}
6. Period Overlap & Range DetectionC++#include <iostream>
#include "clsPeriod.h"

int main() {
    clsPeriod Period1(clsDate(1, 8, 2026), clsDate(10, 8, 2026));
    clsPeriod Period2(clsDate(5, 8, 2026), clsDate(15, 8, 2026));

    if (clsPeriod::IsOverlapPeriods(Period1, Period2)) {
        std::cout << "The two periods overlap!\n";
    }

    return 0;
}
🤝 Contributing
Contributions, issues, and feature requests are highly appreciated!
1_ Fork the Repository
2_ Create your Feature Branch (git checkout -b feature/AmazingFeature)
3_ Commit your Changes (git commit -m 'Add AmazingFeature')
4_ Push to the Branch (git push origin feature/AmazingFeature)
5_ Open a Pull Request


👨‍💻 Author
Eng. Abdulhamid AbuSaada

📜 License
This project is open-source and licensed under the MIT License.
