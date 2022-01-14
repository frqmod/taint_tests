#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

const char password[] = "passwordpasswordpasswordpassword";

int main()
{
    char *userInput = (char *)mmap((void *)0x1337000, 32, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    char *taintBuffer = (char *)mmap((void *)0x2337000, 32, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    scanf("%32s", userInput);
    strcpy(taintBuffer, userInput);

    printf("STRCPY TEST\n");
    printf("Original Input Buffer (source of taint):\n");
    printf("%p - %p\n", userInput, userInput + 32);
    printf("Taint Buffer (tainted via strcpy(taintBuffer, userInput)):\n");
    printf("%p - %p\n", taintBuffer, taintBuffer + 32);

    if (strcmp(password, taintBuffer))
    {
        puts("Incorrect!");
        return -1;
    }
    puts("Correct!");
    return 0;
}