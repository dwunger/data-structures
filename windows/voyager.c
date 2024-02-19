#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

//typedef unsigned long DWORD, *PDWORD, *LPDWORD;
DWORD pid;

int main(int argc, char *argv[])
{

    printf("Hello from process %zu", (pid = GetCurrentProcessId()));
    return 0;
}

