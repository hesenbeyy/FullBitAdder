# Full-Adder Logic Simulator

A portable C-based simulation of a digital logic **Full-Adder**. This project was developed as part of our coursework as **2nd-year Computer Engineering students** to demonstrate the bridge between high-level programming and low-level digital logic.

## Features
* **Multi-Base Input Support**: Enter data in Binary (base 2), Octal (base 8), or Hexadecimal (base 16).
* **Input Validation**: Ensures inputs stay within the 3-bit range ($0-7_{10}$).
* **Logical Mapping**: Accurately simulates the truth table logic of a Full-Adder circuit.

## Logical Implementation

The program simulates a Full-Adder by treating any input as a 3-bit value representing $A$, $B$, and $C_{in}$ (Carry-in). 

### 1. Bit Extraction
Regardless of the input base, the program decomposes the value into three individual bits. For example, in the Hexadecimal and Octal modules, we use bitwise-style arithmetic to isolate the bits:

* **Bit 1 (MSB):** $(Input / 4) \pmod 2$
* **Bit 2:** $(Input / 2) \pmod 2$
* **Bit 3 (LSB):** $(Input / 1) \pmod 2$

### 2. Summation and Mapping
The core logic calculates the total number of active "high" bits:
$$Total = Bit_1 + Bit_2 + Bit_3$$

This $Total$ value (ranging from 0 to 3) is then mapped to the standard Full-Adder truth table:

| Total Bits High | Sum Bit ($S$) | Carry-out ($C_{out}$) | Logic Case |
| :--- | :---: | :---: | :--- |
| **0** | 0 | 0 | All inputs are 0 |
| **1** | 1 | 0 | Single input is 1 |
| **2** | 0 | 1 | Two inputs are 1 |
| **3** | 1 | 1 | All three inputs are 1 |

## Building the Project
This project uses **CMake**, allowing it to be built on any operating system.

1. **Clone the repository**:
   ```bash
   git clone https://github.com/hesenbeyy/FullBitAdder.git
   cd FullBitAdder
   ```
2. **Create a build directory and compile**:
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

## Usage Examples

### Example: Binary Input
1. Select `(1) Compute and display the outputs`.
2. Choose base `2`.
3. Input `110`.
* **Result**: `Sum is 0, Carry-out is 1.` (Since $1 + 1 + 0 = 2_{10}$)
  
