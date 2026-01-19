#include <windows.h>
#include <stdio.h>
#include "self_destruct.h"

// This payload contains your secret message in Hexadecimal
unsigned char payload[] = {
    0xeb, 0xfe, // The infinite loop (Freeze)
    0x4E, 0x4F, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x4C, 0x49, 0x47, 0x48, 0x54, 0x2E, // NO MORE LIGHT.
    0x0D, 0x0A, // New line
    0x4E, 0x4F, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x48, 0x4F, 0x50, 0x45, 0x2E      // NO MORE HOPE.
};

int main() {
    printf("--- MYONECROSIS RESEARCH LAB ---\n");
    printf("Preparing Payload: NO MORE LIGHT / NO MORE HOPE\n");

    int result = MessageBox(0, 
        "CRITICAL: Ready to write MBR Payload. This will make the system unbootable.\n\nContinue with simulation?", 
        "Myonecrosis v1.0", 
        MB_YESNO | MB_ICONERROR);

    if (result == IDYES) {
        printf("[!] Simulation: Targeting Master Boot Record...\n");
        printf("[!] Simulation: Message injected successfully.\n");
        printf("[SUCCESS] Computer will display 'NO MORE LIGHT' on next boot.\n");
    }

    printf("\nProject complete. Cleaning up traces...\n");
    self_delete();

    return 0;
}
