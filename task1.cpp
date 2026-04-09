/* =================================================================
PROJECT: File Handling System
DESCRIPTION: Demonstrating Create, Read, Write, and Append in C.
DELIVERABLE: A C program showing various file operations.
=================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char content[100];

    // 1. CREATE & WRITE DATA
    fptr = fopen("internship_log.txt", "w");
    if (fptr == NULL) {
        printf("Error: Could not create file!\n");
        return 1;
    }
    fprintf(fptr, "Task 25: File Handling in C\n");
    fprintf(fptr, "Status: System initial data written.\n");
    fclose(fptr);
    printf("✅ Step 1: File created and initial data written successfully.\n");

    // 2. APPEND DATA (Adding without deleting old data)
    fptr = fopen("internship_log.txt", "a");
    if (fptr == NULL) {
        printf("Error: Could not open file for appending!\n");
        return 1;
    }
    fprintf(fptr, "Append: New log entry added at the end of file.\n");
    fclose(fptr);
    printf("✅ Step 2: Data appended to the file successfully.\n");

    // 3. READ DATA
    printf("\n--- 📄 READING FILE CONTENT ---\n");
    fptr = fopen("internship_log.txt", "r");
    if (fptr == NULL) {
        printf("Error: Could not open file for reading!\n");
        return 1;
    }

    while (fgets(content, 100, fptr)) {
        printf("%s", content);
    }
    fclose(fptr);
    printf("-------------------------------\n");
    printf("✅ Step 3: File read operation complete.\n");

    return 0;
}
