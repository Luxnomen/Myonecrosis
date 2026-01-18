#include <windows.h>
#include <stdio.h>

int main() {
    // This is a Windows "Message Box" - it won't work on Mac!
    // It is just for testing once you move to Windows.
    MessageBox(0, "Myonecrosis is initializing...", "System Warning", MB_ICONERROR);

    // This is how Windows handles the MBR drive
    // In a real attack, it opens "\\.\PhysicalDrive0"
    printf("Windows Core ready for MBR testing.\n");
    
    return 0;
}
