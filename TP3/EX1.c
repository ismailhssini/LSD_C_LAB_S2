#include <stdio.h>
#include <string.h>

struct palindrome {
    char *data;
    struct palindrome* next;
} palindrome;

int        is_palindome(char *data)
{
    int        right = strlen(data) - 1;
    int        left  = 0;
    while (left < right)
    {
        if (data[left] != data[right])
                return (0);
        left++;
        right--;
    }
    return (1);
}

int        main(int argc, char *argv[])
{
    palindrome.data = argv[1];
    palindrome.next = NULL;
    if (argc == 2)
    {
        if (is_palindome(palindrome.data))
            printf("true\n");
        else
            printf("false\n");
    }
    else
        printf("Error: you must have 2 arguments!\n");
    return (0);
}
