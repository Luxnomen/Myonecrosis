#include <windows.h>
#include <stdio.h>

// This is the Machine Code the computer reads before Windows even starts
// 0xEB, 0xFE is a "JMP $" command—it freezes the CPU in a loop
unsigned char payload[] = {
    0xeb, 0xfe, 
    'M', 'y', 'o', 'n', 'e', 'c', 'r', 'o', 's', 'i', 's', ' ',
    'v', '1', '.', '0'
};

int main() {
    printf("--- Myonecrosis Windows Core ---\n");
    printf("Payload Size: %lu bytes\n", sizeof(payload));

    // Simulation of the MBR Strike
    int result = MessageBox(0, 
        "Execute MBR Payload Simulation?", 
        "Myonecrosis Research", 
        MB_YESNO | MB_ICONHAZARD);

    if (result == IDYES) {
        printf("[!] Accessing \\.\PhysicalDrive0...\n");
        printf("[!] Writing payload to sector 0...\n");
        // In a real test, this is where WriteFile would go
        printf("[SUCCESS] MBR has been 'rotted'.\n");
    }

    return 0;
}
