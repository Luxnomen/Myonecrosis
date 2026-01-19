#include <stdio.h>
#include <windows.h>

int main() {
    printf("--- MYONECROSIS ANTIDOTE TOOL ---\n");
    printf("[*] Attempting to neutralize research lab...\n");

    // 1. Create the antidote file to trigger the code's internal killswitch
    FILE *file = fopen("antidote.txt", "w");
    if (file == NULL) {
        printf("[!] Error: Could not create antidote.txt\n");
        return 1;
    }
    fprintf(file, "SAFETY_KEY_ACTIVATED");
    fclose(file);
    printf("[SUCCESS] Antidote.txt created. Killswitch is now ACTIVE.\n");

    // 2. Force close the malware process if it's running
    // This is like a 'Police Override'
    system("taskkill /F /IM windows_core.exe /T");

    printf("[DONE] System is now safe. Research neutralized.\n");
    return 0;
}
