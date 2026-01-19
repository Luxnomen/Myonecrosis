# Myonecrosis (Research Project)

## ⚠️ FOR TESTING PURPOSES ONLY
This repository contains code designed to demonstrate the Master Boot Record (MBR) overwrite process on Windows systems. 

### Disclaimer
**I am not responsible for any damage caused by this software.** This code is for cybersecurity researchers and students who want to understand boot-level vulnerabilities. 

**DO NOT run this on your main machine. Use a Virtual Machine (VM) for all testing.**

## Features
- Windows MBR access logic
- Background process simulation
- Educational "Safety Demo" mode

## Technical Analysis
1. **MBR Exploitation**: The program targets Sector 0 of the Physical Drive. By overwriting the first 512 bytes, the BIOS fails to find the Windows Boot Manager.
2. **Payload Analysis**:
   - `0xEB 0xFE`: CPU Infinite Loop (JMP instruction).
   - **ASCII-to-Hex**: Custom string data converted to Hexadecimal for low-level display.
3. **Anti-Forensics**: The `self_delete` function utilizes a secondary batch process to bypass file-lock restrictions on Windows, ensuring the executable is removed post-execution.

## How to Run the Research Lab
To prevent accidental execution, Myonecrosis requires a 'Safety Key'.
1. Create a file named `antidote.txt` in the program directory.
2. Run the executable.
3. **Emergency Stop**: Deleting `antidote.txt` while the program is running will trigger an immediate shutdown and self-deletion sequence.
