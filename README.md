# Minitalk

Minitalk is a project from 42 school (École 42) in C designed to send messages between processes using UNIX signals.

## Overview

`Minitalk` is a small messaging system implemented in C, enabling two separate processes (a server and one or more clients) to communicate using UNIX signals (`SIGUSR1`, `SIGUSR2`).  
It aims to teach:
- Inter–process communication at a low level  
- Bit‑by‑bit data encoding and decoding via signals  
- Robust error‑handling and synchronization under constrained resources  

---

## Features

- A **server** process that opens and waits for client messages  
- A **client** process that sends text messages to the server, character by character, encoded in signals  
- Supports sending strings from client to server and printing them on the server side  
- Handles multiple clients (depending on bonus part) by tracking PID and acknowledging receipt  
- Gracefully handles errors (invalid PID, failed signal sending, etc.)

---

## Usage

### Build

```bash
make
```

This will compile the following executables:  
- `server` – the server program  
- `client` – the client program  

### Run

1. Start the server in one terminal:

   ```bash
   ./server
   ```

   It will print its PID (process ID), e.g.:

   ```
   Server PID: 12345
   ```

2. In another terminal, send a message via client:

   ```bash
   ./client 12345 "Hello from client!"
   ```

   Replace `12345` with the PID printed by the server.

---

## Functionality Details

- The client encodes each character into a sequence of 8 bits.  
- For each bit, it sends a signal to the server:  
  - `SIGUSR1` for bit **0**  
  - `SIGUSR2` for bit **1**  
- The server receives signals and reconstructs the bits into characters, building the message string.  
- Once the message is complete, the server prints it.

---

## Project Structure

```
minitalk/
├── src/
│   ├── server.c
│   └── client.c
├── include/
│   └── minitalk.h
├── Makefile
└── README.md
```

---

## Bonus

- Multi‑client support  
- Acknowledgement signal from server to client  

---

## Testing

- Use `valgrind` to check for memory leaks.
- Test with long messages and multiple clients.

---

## Author

**BabiDrummond** – Student at École 42.
