# 🔐 XOR Shellcode Encoder

> **⚠️ FOR EDUCATIONAL AND RESEARCH PURPOSES ONLY**
> Use only in controlled lab environments on shellcode you own.

---

## 📌 Overview

A simple C++ tool that XOR-encodes a shellcode byte array using a rolling key and outputs the encoded result as a ready-to-use `.h` header file. Designed for security researchers and students studying shellcode obfuscation techniques.

---

## 🔬 How It Works

```
shellcode[] (raw bytes)
      │
      ▼
XOR(key, shellcode, size)   ← rolling key XOR — each byte XOR'd with key[i % keylen]
      │
      ▼
encoded_shellcode.h         ← output header with encoded bytes ready to embed
```

Each byte is encoded as:
```
encoded[i] = shellcode[i] ^ key[i % key.length()]
```

The same function decodes it — XOR is symmetric, so running `XOR()` again with the same key restores the original bytes.

---

## 📁 Files

| File | Description |
|---|---|
| `XorEncoder.cpp` | Main encoder — XORs shellcode and writes output header |
| `encoded_shellcode.h` | Auto-generated output containing the encoded byte array |

---

## ⚙️ Setup

### Prerequisites

- Windows or Linux
- Any C++ compiler:
  - **Windows:** Visual Studio 2022 or `g++` via MinGW
  - **Linux:** `g++`

---

## 🚀 How to Use

### Step 1 — Add your shellcode

Open `XorEncoder.cpp` and replace the placeholder shellcode with your own bytes:

```cpp
unsigned char shellcode[] = {
    0xFC, 0x48, 0x83, ...    // paste your raw shellcode bytes here
};
```

### Step 2 — Set your XOR key

```cpp
std::string key = "mysecretkey";   // replace with your own key
```

> The key can be any string. Longer keys are harder to brute-force.
> You must use the **same key** when decoding.

### Step 3 — Build

**Visual Studio:**
```
Build → Build Solution  (Ctrl+Shift+B)
```

**g++ (Windows/Linux):**
```bash
g++ XorEncoder.cpp -o XorEncoder
```

### Step 4 — Run

**Windows:**
```cmd
XorEncoder.exe
```

**Linux:**
```bash
./XorEncoder
```

### Step 5 — Use the output

The tool generates `encoded_shellcode.h`:

```cpp
unsigned char shellcode[] = { 0xdd, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d };
```

Copy this file into your project and include it:

```cpp
#include "encoded_shellcode.h"
```

To decode at runtime, call `XOR()` again with the same key before execution:

```cpp
XOR(key, shellcode, sizeof(shellcode));
```

---

## 📊 Example

**Input shellcode** (NOP sled):
```
0x90, 0x90, 0x90, 0x90
```

**Key:** `"mysecretkey"`

**Encoded output:**
```
0x90 ^ 'm' = 0xFD
0x90 ^ 'y' = 0x09
0x90 ^ 's' = 0x03
0x90 ^ 'e' = 0xF5
```

---

## ⚠️ Limitations

| Issue | Detail |
|---|---|
| No key validation | Empty key causes division by zero in `key.length()` — always set a non-empty key |
| XOR only | Single-layer obfuscation — combine with AES for stronger protection |
| Key stored in plaintext | The key is visible in the binary — consider obfuscating it |

---

## 🛡️ What This Teaches

| Topic | Detail |
|---|---|
| XOR obfuscation | How rolling-key XOR works at byte level |
| Shellcode encoding | How encoded payloads evade static signature detection |
| File I/O in C++ | Writing formatted output to `.h` header files |
| Symmetric encoding | Why XOR is its own inverse with the same key |

---

## 👤 Author

**Khalid** — Cybersecurity Student
GitHub: [@khalid609](https://github.com/khalid609)

---

## 📄 License

For educational and authorized security research use only.
