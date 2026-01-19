#include <windows.h>
#include <stdio.h>
#include "self_destruct.h"

// Your custom MBR message
unsigned char payload[] = {
    0xeb, 0xfe, 
    0x4E, 0x4F, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x4C, 0x49, 0x47, 0x48, 0x54, 0x2E,
    0x0D, 0x0A,
    0x4E, 0x4F, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x48, 0x4F, 0x50, 0x45, 0x2E
};

int main() {
    printf("--- MYONECROSIS RESEARCH LAB ---\n");
    printf("[*] Checking for antidote.txt heartbeat...\n");

    if (GetFileAttributes("antidote.txt") == INVALID_FILE_ATTRIBUTES) {
        printf("[!] ERROR: antidote.txt not found. Program will not run without safety key.\n");
        return 0;
    }

    printf("[SUCCESS] Safety key detected. Starting simulation...\n");
    printf("Keep 'antidote.txt' in the folder to stay running.\n");

    // This is a simple simulation of the program running
    for(int i = 0; i < 10; i++) {
        if (GetFileAttributes("antidote.txt") == INVALID_FILE_ATTRIBUTES) {
            printf("\n[!] HEARTBEAT LOST! Stopping Myonecrosis...\n");
            self_delete(); // Delete the evidence!
        }
        printf("Simulating background rot... %d%%\r", i * 10);
        fflush(stdout);
        Sleep(1000);
    }

    printf("\n[DONE] Simulation complete. Cleaning up...\n");
    self_delete();
    return 0;
}
