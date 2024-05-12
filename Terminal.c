#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fptr;
    char filename[500];
    int num = 1;

    while (1) {
        char command[20];
        printf("|%d| ", num);
        scanf("%s", command);

        if (strcmp(command, "readf()") == 0) {
            printf("Enter the filename: ");
            scanf("%s", filename);
            fptr = fopen(filename, "r");
            if (fptr == NULL) {
                printf("Failed to open the file.\n");
                continue;
            }
            char line[500];
            while (fgets(line, sizeof(line), fptr) != NULL) {
                printf("|%d| %s", num, line);
                num++;
            }
            fclose(fptr);
        }
        else if (strcmp(command, "addf()") == 0) {
            printf("Enter the filename: ");
            scanf("%s", filename);
            fptr = fopen(filename, "a");
            if (fptr == NULL) {
                printf("Failed to open the file.\n");
                continue;
            }
            char data[500];
            printf("Enter data to append: ");
            scanf(" %[^\n]", data);
            fprintf(fptr, "%s\n", data);
            fclose(fptr);
        }
        else if (strcmp(command, "startf()") == 0) {
            printf("Enter the filename: ");
            scanf("%s", filename);
            fptr = fopen(filename, "w");
            fclose(fptr);
        }
        else if (strcmp(command, "terminatef()") == 0) {
            break; // Exit the loop and terminate the program
        }
        // Implement other commands similarly...
    }

    return 0;
}

