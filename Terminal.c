
#include <stdio.h>
#include <string.h>

char string[500];
char string2[500];
char string3[500];
char string4[500];

int num = 1;

int main() {
    FILE *fptr;

    while (1) {
        printf("|%d|", num);
        scanf("%s", string);

        if (strcmp(string, "readf()") == 0) {
            char filename[500];
            printf("What File Do You Want To Read: ");
            scanf("%s", filename);
            fptr = fopen(filename, "r");
            if (fptr == NULL) {
                printf("Failed to open the file.\n");
                continue;
            }
            while (fgets(string, 500, fptr) != NULL) {
                printf("|%d|%s", num, string);
                num++;
            }
            fclose(fptr);
        }
        else if (strcmp(string, "addf()") == 0) {
            printf("What File Do You Want To Access: ");
            scanf("%s", string3);
            fptr = fopen(string3, "a");
            if (fptr == NULL) {
                printf("Failed to open the file.\n");
                continue;
            }
            printf("What would you like to write: ");
            scanf(" %[^\n]", string3);
            fprintf(fptr, "%s\n", string3);
            fclose(fptr);
        }
        else if (strcmp(string, "startf()") == 0) {
            printf("What would you like to name the file: ");
            scanf("%s", string);
            fptr = fopen(string, "w");
            fclose(fptr);
        }
        else if (strcmp(string, "terminatef()") == 0) {
            return 1;
        }
        else if (strcmp(string, "delf()") == 0) {
            printf("What File Do You Want To Delete: ");
            scanf("%s", string);
            if (remove(string) == 0) {
                printf("File has been deleted.\n");
            }
            else {
                printf("Failed to delete the file.\n");
            }
        }
        else if (strcmp(string, "binf()") == 0) {
            printf("What Is The Name Of The Folder");
            scanf("%s", string4);
            printf("What file do you want to bin: ");
            scanf("%s", string);
            strcat(string4, string);
            if (rename(string, string4) == 0) {
                printf("%s has been binned.\n", string);
            }
            else {
                printf("Failed to bin the file.\n");
            }
        }
        else if (strcmp(string, "renamef()") == 0) {
            printf("What File Would You Like To Rename:");
            scanf("%s", string);
            printf("What Would You Like To Name It:");
            scanf("%s", string2);
            rename(string, string2);
        }
        else if (strcmp(string, "restoref()") == 0) {
            p
            printf("What file do you want to restore: ");
            scanf("%s", string);
            char destination[300] = "/workspaces/codespaces-blank/";
            strcat(destination, string);
            if (rename(string, destination) == 0) {
                printf("%s has been Restored.\n", string);
            }
            else {
                printf("Failed to restore the file.\n");
            }
            
            num++;
            printf("|%d|", num);
        }
    }

    return 0;
} 
