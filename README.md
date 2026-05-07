# Set Implementation Performance Analyzer

## 📋 Project Description

Course project for the "Programming of Dynamic Data Structures" discipline. This program compares the performance of set data structure implementations using six different approaches: custom singly linked list, custom list class (wrapper), `std::list`, `std::set`, `std::stack`, and `std::unordered_multimap`. The analysis includes timing measurements of fundamental set operations.

## ✨ Features

### 🧩 **Tested Set Implementations**
- **Custom singly linked list** – manual node-based set (C-style)
- **Custom list class** – object-oriented wrapper around linked list
- **`std::list`** – standard doubly linked list container
- **`std::set`** – standard balanced binary search tree container
- **`std::stack`** – stack container (adapted for set semantics)
- **`std::unordered_multimap`** – hash-based associative container

### 📊 **Measured Operations**
- **Creation** – generating sets of size N (user‑defined for A and B)
- **Cardinality** – getting the number of elements in a set
- **Subset checks** – A ⊆ A, B ⊆ A
- **Equality checks** – A = A, B = A
- **Union** – A ∪ B
- **Intersection** – A ∩ B
- **Difference** – A \ B, B \ A
- **Symmetric difference** – A ∆ B

### 📈 **Output Format**
- Console table with execution times for each operation and each implementation
- Times shown in milliseconds with 6‑digit precision
- UTF‑8 support for proper Cyrillic display
- Centered text layout for readability

### ⚙️ **Input Options**
- Separate size (cardinality) for set A and set B
- Input validation with range checks (0–10000)
- Automatic adjustment if requested size exceeds available value range

## 🛠 Technologies

- **Programming Language**: C++17
- **Containers**: Standard Template Library (list, set, stack, unordered_multimap)
- **Time Measurement**: `<chrono>` high_resolution_clock
- **Console I/O**: Windows API (`SetConsoleCP`, `SetConsoleOutputCP`)
- **Random Generation**: `rand()` with deterministic seeding
- **Build Environment**: Visual Studio / MSVC compatible

## 🚀 Project Setup

### Prerequisites
- Windows OS (due to console code page settings)
- C++17 compatible compiler (MSVC, GCC, Clang)
- For GCC/Clang: replace `windows.h` and console CP functions with alternative UTF‑8 handling if needed

### Installation Steps
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Open the solution file `PDSD_CourseWork_Chernetsov_24VP1.slnx` in Visual Studio (or any compatible IDE).
3. Ensure all source files are included:
   - `PDSD_CourseWork_Chernetsov_24VP1.cpp`
   - `additional.cpp`, `additional.h`
   - `SetOnNodes.cpp`, `SetOnNodes.h`
   - `SetOnNodeClass.cpp`, `SetOnNodeClass.h`
   - `SetOnList.cpp`, `SetOnList.h`
   - `SetOnSet.cpp`, `SetOnSet.h`
   - `SetOnStack.cpp`, `SetOnStack.h`
   - `SetOnUnorderedMultimap.cpp`, `SetOnUnorderedMultimap.h`
4. Build and run (Ctrl+F5).

## 🎮 Usage

1. **Start the program** – a console window appears with a table header.
2. **Enter the size of the first set (A)** – follow the prompt, type an integer between 0 and 10000.
3. **Enter the size of the second set (B)** – similar input.
4. **Wait for the results** – the program performs all operations for each of the six implementations and prints a table with timing results in milliseconds.
5. **Analyze** – compare how each implementation behaves for creation, subset checking, union, intersection, etc.
6. **Press any key** – the console pauses before exiting.

> ⚠️ **Note**: For large set sizes (e.g., > 5000), some implementations (especially `std::stack` and the linked list‑based ones) may be significantly slower. The program does not enforce a hard limit, but you are warned if you exceed 5000 elements.

## 📁 Project Structure

```
PDSD_CourseWork_Chernetsov_24VP1.slnx                        # Visual Studio solution file
README.md                                                    # This file
PDSD_CourseWork_Chernetsov_24VP1/                            # Project folder
├── PDSD_CourseWork_Chernetsov_24VP1.vcxproj                 # Visual Studio project file
├── PDSD_CourseWork_Chernetsov_24VP1.vcxproj.filters         # Project filters
├── PDSD_CourseWork_Chernetsov_24VP1.cpp                     # Main program with benchmarking logic
├── additional.cpp                                           # Input validation functions
├── additional.h                                             # Input interface header
├── SetOnNodes.cpp                                           # C-style singly linked list set
├── SetOnNodes.h                                             # Header for C-style linked list
├── SetOnNodeClass.cpp                                       # OOP linked list class
├── SetOnNodeClass.h                                         # Header for OOP list class
├── SetOnList.cpp                                            # Wrapper for std::list
├── SetOnList.h                                              # Header for std::list wrapper
├── SetOnSet.cpp                                             # Wrapper for std::set
├── SetOnSet.h                                               # Header for std::set wrapper
├── SetOnStack.cpp                                           # Wrapper for std::stack (set semantics)
├── SetOnStack.h                                             # Header for stack wrapper
├── SetOnUnorderedMultimap.cpp                               # Wrapper for std::unordered_multimap
└── SetOnUnorderedMultimap.h                                 # Header for unordered_multimap wrapper
```

## 📊 Implementation Details

### Set Representation
- **Nodes / lists** – elements stored in insertion order (no sorting, duplicates prevented).
- **`std::set`** – elements stored in sorted order (red‑black tree).
- **`std::stack`** – elements stored in LIFO order; membership check requires linear search.
- **`std::unordered_multimap`** – elements stored as keys (value‑bool pairs); hash table.

### Operation Complexity (theoretical)

| Implementation | Creation | Member check | Subset | Union | Intersection |
|----------------|----------|--------------|--------|-------|---------------|
| Singly linked list | O(N) | O(N) | O(N*M) | O(N+M) | O(N*M) |
| `std::list` | O(N) | O(N) | O(N*M) | O(N+M) | O(N*M) |
| `std::set` | O(N log N) | O(log N) | O(N log M) | O(N log (N+M)) | O(N log M) |
| `std::stack` | O(N) | O(N) | O(N*M) | O(N+M) | O(N*M) |
| `std::unordered_multimap` | O(N) avg | O(1) avg | O(N) avg | O(N+M) avg | O(N) avg |

### Measurement Methodology
- Each operation is executed once and timed using `std::chrono::high_resolution_clock`.
- Results are printed in milliseconds with 6 decimal places.
- The same random seed (`time(NULL)`) is used for all implementations to ensure identical input data.
- For `std::stack` and `std::unordered_multimap`, additional copies are made during operations (reflected in timings).

### UTF‑8 Handling
- Console code pages are set to `CP_UTF8` for correct Cyrillic output.
- Custom `utf8_length()` and `center_utf8()` functions properly align text containing multibyte characters.

## ⚠️ Error Handling

The program handles the following errors:
- Non‑integer input – prompts user to re‑enter.
- Out‑of‑range sizes (outside 0–10000) – prompts again.
- When the requested set size exceeds the number of available values in the range `[0, 10*N]`, the program reduces the size to the maximum available (silently, to avoid memory issues).

No exceptions are thrown; all errors are managed via input validation loops.

## 💻 Example Console Output

```
Чернецов А.М. 24ВП1. Курсовая работа.

Введите размер первого множества (целое от 0 до 10000): 1000
Введите размер второго множества (целое от 0 до 10000): 500
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|                         |   Односвязный список    |     Класс 'Список'      |          List           |           Set           |          Stack          |   unordered_multimap    |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|   Создание множества    |        2.259600         |        2.235400         |        11.360900        |        1.277500         |       271.724300        |        2.218800         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|        Мощность         |        0.028500         |        0.029300         |        0.000300         |        0.000400         |        0.000600         |        0.000200         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|    Подмножество A-A     |        2.484200         |        1.954400         |        10.461800        |        0.756700         |       471.677200        |        0.467900         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|    Подмножество B-A     |        0.049100         |        0.051400         |        0.000800         |        0.001300         |        0.001000         |        0.000500         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|      Равенство A-A      |        3.934900         |        4.246300         |        20.960500        |        1.315300         |       920.995000        |        0.687400         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|      Равенство B-A      |        0.041400         |        0.042500         |        0.000800         |        0.001100         |        0.000900         |        0.000500         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|       Объединение       |        4.936600         |        5.610000         |        28.154000        |        2.203100         |       541.041300        |        1.928500         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|       Пересечение       |        1.552400         |        2.068100         |        10.508600        |        0.867500         |       236.041800        |        0.883000         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|      Разность A-B       |        4.688400         |        4.977700         |        19.835300        |        2.398300         |       440.741500        |        1.600800         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|      Разность B-A       |        2.494200         |        4.624900         |        12.273300        |        1.304300         |       274.934200        |        1.108800         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|  Симметричная разность  |        10.941900        |        12.657600        |        57.489300        |        7.024200         |       1317.245900       |        5.256200         |
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
```

> **Interpretation**: `std::set` and `std::unordered_multimap` are significantly faster for subset checks, equality, and intersection due to O(log N) and O(1) membership testing. However, creation of `std::set` is slightly slower (O(N log N)) compared to list-based approaches (O(N)). `std::stack` performs worst for most operations because membership checks require full traversal.

## 🎓 Author

**Aleksandr Chernetsov**  
Group: 24VP1  
Course work for "Programming of Dynamic Data Structures"

## 📄 License

Educational project. Free use, modification, and distribution are permitted with attribution.
