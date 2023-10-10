

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 25
#define SPECIAL_VAlUE -9999

int main(int argc, char *argv[])
{

    char input[10];
    char storage[MAX_ENTRY][10];
    int sum = 0;
    double average;
    char longstr[10 * MAX_ENTRY];

    printf("   hello, world!\n");
    for (int i = 0; i < MAX_ENTRY; i++)
    {
        printf("\n  enter an integer: ");
        // scanf("%d", &input[i]);
        fgets(input, 10, stdin);
        if (atoi(input) == SPECIAL_VAlUE)
        {
            printf("\n closing program");
            break;
        }
        printf("\n     got: %s", input);
        strcat(storage[i], input);
        storage[i][strlen(input) - 1] = '\0';
        sum += atoi(input);
    }
    printf("\n         total sum: %d", sum);
    average = sum / MAX_ENTRY;
    printf("\n         average: %f", average);

    for (int i = 0; i < MAX_ENTRY; i++)
    {
        storage[i][strlen(storage[i] - 1)] = '\0';
        for (int j = 0; j < 10; j++)
        {
            if (storage[i][j] != '\n')
            {
                strcat(longstr, storage[i][j]);
            }
        }
    }

    printf("\n         my essay: %s", longstr);
}
