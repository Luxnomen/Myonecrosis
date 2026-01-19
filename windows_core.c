#include <windows.h>
#include <stdio.h>
#include "self_destruct.h"

unsigned char payload[] = {
    0xeb, 0xfe, 
    0x4E, 0x4F, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x4C, 0x49, 0x47, 0x48, 0x54, 0x2E,
    0x0D, 0x0A,
    0x4E, 0x4F, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x48, 0x4F, 0x50, 0x45, 0x2E
};

int main() {
    printf("--- MYONECROSIS RESEARCH LAB ---\n");
    
    if (GetFileAttributes("antidote.txt") == INVALID_FILE_ATTRIBUTES) {
        MessageBox(0, "The application was unable to start correctly (0xc0000005).", "System Error", MB_ICONERROR);
        return 0;
    }

    printf("[SUCCESS] Heartbeat detected. Simulation active.\n");

    for(int i = 0; i <= 10; i++) {
        if (GetFileAttributes("antidote.txt") == INVALID_FILE_ATTRIBUTES) {
            // Fake error to distract the user while we delete the files
            MessageBox(0, "Memory at 0x0045F21 could not be read. Terminating process.", "Windows Explorer", MB_ICONERROR);
            self_delete(); 
        }
        printf("Infecting system sectors... %d%%\r", i * 10);
        fflush(stdout);
        Sleep(1000);
    }

    printf("\n[DONE] Simulation finished.\n");
    self_delete();
    return 0;
}
