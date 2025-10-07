  # Crypto CLI

This project implements a simple cryptosystem supporting **Caesar** and **Vigenère** ciphers.

---

## Cryptography

The project implements the cryptosystem described in the **Cryptography** section of the requirements:

- **Caesar cipher:** shifts letters by a global integer key.
- **Vigenère cipher:** shifts letters using a repeating alphabetic key.
- Non-alphabetic characters are preserved in both ciphers.
- Encryption and decryption are supported.

---

## Flowchart

A flowchart describing the program flow is included

---

## Command-Line Interface (CLI)

The program provides a CLI with the following usage:

./crypto caesar -e|-d <key:int> "text"   # Caesar encryption/decryption
./crypto vigenere -e|-d <key:string> "text" # Vigenère encryption/decryption

## Example Usage:


./crypto caesar -e 3 "Hello, World!"    # → Khoor, Zruog!
./crypto caesar -d 3 "Khoor, Zruog!"   # → Hello, World!
./crypto vigenere -e LEMON "ATTACK AT DAWN" # → LXFOPV EF RNHR
./crypto vigenere -d LEMON "LXFOPV EF RNHR" # → ATTACK AT DAWN

## Modularization Approach:
CLI (main.c + cli.h): Handles argument parsing and dispatches commands to the appropriate cipher functions. Modularized to separate usage printing and main logic.

Caesar cipher (caesar.c + caesar.h): Encapsulates encryption/decryption with a global key. Header provides a clean API. Returns malloc’ed strings to avoid modifying input.

Vigenère cipher (vigenere.c + vigenere.h): Implements key normalization and encryption/decryption in functions using caller-provided buffers. Header provides a simple, reusable API.

This modularization ensures separation of concerns: CLI, Caesar, and Vigenère are independent and testable.

## Project Structure:

crypto/
├─ include/
│  ├─ caesar.h       # Caesar cipher API (Doxygen documented)
│  ├─ vigenere.h     # Vigenère cipher API (Doxygen documented)
│  └─ cli.h          # CLI helper
├─ src/
│  ├─ caesar.c       # Caesar implementation
│  ├─ vigenere.c     # Vigenère implementation
│  └─ main.c         # CLI + dispatch
├─ Makefile
└─ README.md

## Build:

make          # builds ./crypto
make clean    # removes binary and object files

## Memory & Safety:
Caesar functions return malloc’ed strings → must free() after use. Handled in main.c.

Vigenère functions use a caller-provided buffer (MAX_TEXT).

Test for leaks with:

valgrind --leak-check=full ./crypto caesar -e 3 "Hello"

## Doxygen Documentation:
All header files in include/ are documented using Doxygen syntax. Generate docs with:


doxygen -g Doxyfile   # create config
# edit INPUT = include
doxygen Doxyfile
