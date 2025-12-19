# Wearable Device Power Management Firmware

A C++ firmware library designed to calculate the minimum runtime for wearable devices. This solution optimizes the scheduling of "Idle" (charging) states to ensure continuous task execution without battery depletion.

## 🚀 Design Overview
This project is implemented as a **Header-Only Library** to demonstrate modularity and ease of integration in embedded systems.

### Key Architectural Decisions:
- **Encapsulation:** Used a `powerScheduler` class to manage hardware states (Capacity, Charge Rate).
- **Namespace Isolation:** Logic is wrapped in the `firmware` namespace to prevent naming collisions in production environments.
- **Safety Guards:**
  - Detects if a single task's energy demand exceeds physical battery capacity.
  - Prevents division-by-zero errors by validating the `chargeRate`.
- **Optimization:** Implements a **Greedy Algorithm** to minimize idle time by charging exactly the amount needed for the immediate next task.

## 🛠 Setup and Execution

### Prerequisites
- A C++11 (or later) compatible compiler (e.g., GCC, Clang, or MSVC).

### Build Instructions
Open your terminal in the project root directory and run:
```bash
g++ -Iinclude src/main.cpp -o firmware_tool
```

### Execution Instructions
On Linux or macOS
```bash
./firmware_tool
```
On Windows
```bash
firmware_tool.exe
```

firmware_tool.exe
## 📂 Project Structure
```text
├── include/
│   └── POWERSCHEDULER_H.h  # Core firmware library (Namespace: firmware)
├── src/
│   └── main.cpp            # Driver program for technical assessment
├── README.md               # Technical documentation
└── Name-Links.txt          # Submission metadata