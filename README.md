# UART Communication Protocol Simulator

A modular **UART (Universal Asynchronous Receiver/Transmitter)** communication simulator developed entirely in **C** to demonstrate UART frame generation, transmission, buffering, validation, error detection, and communication workflow in embedded systems.

The project simulates UART communication completely in software without requiring physical hardware and follows a modular firmware-like architecture similar to real embedded systems.

---

# 📑 Table of Contents

- Project Overview
- Project Objectives
- Project Highlights
- Features
- Technologies Used
- Project Structure
- How It Works
- UART Communication Workflow
- Software Architecture
- Build & Run
- Sample Output
- Screenshots
- Key Learnings
- Future Enhancements
- Author
- License

---

# 📖 Project Overview

UART (Universal Asynchronous Receiver/Transmitter) is one of the most widely used asynchronous serial communication protocols in embedded systems. It enables communication between microcontrollers and peripheral devices such as sensors, GPS modules, Bluetooth modules, GSM modules, and debugging interfaces.

This project simulates the complete UART communication process entirely in software. It demonstrates how UART frames are created, transmitted, buffered, validated, and received while implementing several core embedded systems concepts including:

- UART Frame Generation
- Parity Generation and Verification
- Checksum Validation
- Circular Ring Buffer
- FIFO Frame Queue
- Runtime Error Injection
- Communication Statistics
- Logging System

The simulator follows a modular firmware architecture where every subsystem is implemented as an independent C module, making the project suitable for learning Embedded C, Embedded Software Design, Communication Protocols, and Firmware Development.

---

# 🎯 Project Objectives

This project was developed to:

- Understand UART communication at the frame level.
- Simulate UART communication without physical hardware.
- Learn modular firmware architecture using Embedded C.
- Implement UART error detection techniques.
- Practice FIFO queue and circular ring buffer implementation.
- Build a reusable UART communication simulator.
- Strengthen Embedded Systems programming concepts.

---

# ⭐ Project Highlights

- Modular Embedded C implementation
- Interactive command-line UART simulator
- Configurable UART parity modes
- Runtime error injection
- Start bit, stop bit, parity, and checksum validation
- Circular ring buffer implementation
- FIFO frame queue implementation
- Runtime communication statistics
- Platform independent (Windows & Linux)

---

# ✨ Features

## 📡 UART Communication

- UART Frame Generation
- UART Frame Parsing
- UART Frame Visualization
- Runtime Message Transmission
- Configurable UART Parameters
- Interactive Command Line Interface

---

## 🛡 Error Detection

- Even Parity
- Odd Parity
- No Parity Mode
- Checksum Generation
- Checksum Validation
- Start Bit Validation
- Stop Bit Validation
- Runtime Error Injection

---

## 📦 Buffer Management

- Circular Ring Buffer
- FIFO Frame Queue
- Buffer Overflow Handling

---

## 📊 Monitoring & Diagnostics

- Runtime Logger
- Transmission Statistics
- Reception Statistics
- Parity Error Counter
- Checksum Error Counter
- Dropped Frame Counter

---

## 🏗 Software Design

- Modular C Architecture
- Layered Driver Design
- Independent Functional Modules
- Firmware-like Project Structure

---

# 🛠 Technologies Used

| Category | Technology |
|-----------|------------|
| Language | C |
| Compiler | GCC |
| Platform | Windows / Linux |
| Programming Style | Modular Programming |
| Concepts | UART, Embedded Systems, Ring Buffer, FIFO Queue, Error Detection |

---

# 📂 Project Structure

```text
uart-communication-protocol-simulator/
│
├── include/
│   ├── checksum.h
│   ├── error_injector.h
│   ├── frame_queue.h
│   ├── logger.h
│   ├── ring_buffer.h
│   ├── statistics.h
│   ├── uart_channel.h
│   ├── uart_config.h
│   ├── uart_driver.h
│   └── uart_frame.h
│
├── src/
│   ├── checksum.c
│   ├── error_injector.c
│   ├── frame_queue.c
│   ├── logger.c
│   ├── main.c
│   ├── ring_buffer.c
│   ├── statistics.c
│   ├── uart_channel.c
│   ├── uart_config.c
│   ├── uart_driver.c
│   └── uart_frame.c
│
├── tests/
├── screenshots/
│   ├── simulator_menu.png
│   ├── uart_frame.png
│   ├── error_detection.png
│   └── statistics.png
│
├── README.md
├── LICENSE
└── Makefile
```

---

# ⚙️ How It Works

The simulator performs UART communication using the following sequence:

1. Configure UART settings.
2. Accept a user message.
3. Generate a UART frame for each byte.
4. Compute parity and checksum.
5. Inject transmission errors (optional).
6. Send the frame through the simulated UART channel.
7. Store received frames in the FIFO queue.
8. Validate the Start Bit, Stop Bit, Parity, and Checksum.
9. Recover the transmitted data.
10. Display communication statistics.

---

# 🔄 UART Communication Workflow

```text
                User Input
                     │
                     ▼
             UART Driver (TX)
                     │
                     ▼
          UART Frame Generation
                     │
                     ▼
        Generate Parity & Checksum
                     │
                     ▼
      Error Injection (Optional)
                     │
                     ▼
       UART Channel (FIFO Queue)
                     │
                     ▼
             UART Driver (RX)
                     │
                     ▼
          Frame Validation
(Start / Stop / Parity / Checksum)
                     │
                     ▼
          Recover Data Byte
                     │
                     ▼
     Update Statistics & Logger
```

---

# 🏗 Software Architecture

```text
            Application Layer
                    │
                    ▼
              UART Driver
        (Transmit / Receive)
                    │
                    ▼
              UART Frame
         (Pack / Unpack)
                    │
                    ▼
             UART Channel
                    │
                    ▼
             Frame Queue
             (FIFO Buffer)
                    │
                    ▼
             Ring Buffer
                    │
                    ▼
          Receiver & Statistics
```

---

# 🚀 Build & Run

## Prerequisites

- GCC Compiler
- Git

---

## Clone Repository

```bash
git clone https://github.com/adyasha-official/uart-communication-protocol-simulator.git

cd uart-communication-protocol-simulator
```

---

## Compile

```bash
gcc -Wall -Wextra -Iinclude \
src/main.c \
src/uart_driver.c \
src/uart_channel.c \
src/frame_queue.c \
src/uart_config.c \
src/uart_frame.c \
src/ring_buffer.c \
src/checksum.c \
src/logger.c \
src/error_injector.c \
src/statistics.c \
-o uart_simulator
```

---

## Run

### Windows

```bash
.\uart_simulator.exe
```

### Linux

```bash
./uart_simulator
```

---

# 📋 Sample Output

```text
========== UART Communication Simulator ==========

Select Parity Mode:
1. None
2. Even
3. Odd

Enter Choice : 2

Enable Error Injection? (y/n): n

Enter Message:

Hello

-----------------------------------
UART Frame
-----------------------------------
Start Bit : 0
Data      : 'H' (0x48)
Parity    : 1
Checksum  : 0x48
Stop Bit  : 1

Receiving...

Received Data:
Hello

========== UART Statistics ==========
Bytes Transmitted : 5
Bytes Received    : 5
Parity Errors     : 0
Checksum Errors   : 0
Frames Dropped    : 0
=====================================
```

---

# 📸 Screenshots

## Simulator Menu

Configure UART parameters, enable or disable error injection, and enter a custom message for transmission.

![Simulator Menu](screenshots/simulator_menu.png)

---

## UART Frame Visualization

Displays the generated UART frame including the start bit, data byte, parity bit, checksum, and stop bit.

![UART Frame](screenshots/uart_frame.png)

---

## Error Detection Demonstration

Shows runtime error injection, frame rejection, and error detection during UART communication.

![Error Detection](screenshots/error_detection.png)

---

## Communication Statistics

Displays transmission statistics including transmitted bytes, received bytes, parity errors, checksum errors, and dropped frames.

![UART Statistics](screenshots/statistics.png)

---

# 📚 Key Learnings

During the development of this project, the following Embedded Systems concepts were implemented:

- UART Communication Protocol
- UART Frame Structure
- Modular Embedded C Programming
- Layered Firmware Architecture
- Circular Ring Buffer
- FIFO Queue Implementation
- Parity Generation & Verification
- Checksum-Based Error Detection
- Runtime Error Injection
- Communication Statistics
- Embedded Logging

---

# 🚀 Future Enhancements

Possible future improvements include:

- CRC-8 Error Detection
- Configurable Baud Rate Timing Simulation
- Interrupt-Driven UART
- DMA-Based UART Simulation
- UART Packet-Based Communication
- Multi-UART Communication
- Binary File Transmission
- UART Loopback Mode
- Unit Test Suite
- STM32/AVR Hardware Integration

---

# 👩‍💻 Author

**Adyasha Priyadarshini Sahoo**

M.Tech in Software Engineering

National Institute of Technology Rourkela

- GitHub: https://github.com/adyasha-official
- Project Repository: https://github.com/adyasha-official/uart-communication-protocol-simulator

---

# 📄 License

This project is licensed under the **MIT License**.

See the `LICENSE` file for more information.
