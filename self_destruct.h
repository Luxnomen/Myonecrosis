#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void self_delete() {
    FILE *fp = fopen("cleanup.bat", "w");
    if (fp) {
        // This script waits 1 second, deletes the program, then deletes itself
        fprintf(fp, "@echo off\n");
        fprintf(fp, "timeout /t 1 /nobreak > nul\n");
        fprintf(fp, "del \"windows_core.exe\"\n"); 
        fprintf(fp, "del \"%%~f0\"\n");
        fclose(fp);

        // Run the script hidden
        ShellExecute(NULL, "open", "cleanup.bat", NULL, NULL, SW_HIDE);
        exit(0);
    }
}
