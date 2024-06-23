#include "SDB.h"
#include "SDBAPP.h"

#include <stdio.h>

static student database[MAX_STUDENTS];
static uint8 usedSize = 0;

bool SDB_IsFull() {
    return (usedSize >= MAX_STUDENTS) ? true : false;
}

uint8 SDB_GetUsedSize() {
    return usedSize;
}

bool SDB_AddEntry() {
    if (!SDB_IsFull()) {
        printf("Enter Student ID: ");
        scanf("%d", &database[usedSize].Student_ID);
        printf("Enter Student Year: ");
        scanf("%d", &database[usedSize].Student_year);
        printf("Enter Course1 ID: ");
        scanf("%d", &database[usedSize].Course1_ID);
        printf("Enter Course1 Grade: ");
        scanf("%d", &database[usedSize].Course1_grade);
        printf("Enter Course2 ID: ");
        scanf("%d", &database[usedSize].Course2_ID);
        printf("Enter Course2 Grade: ");
        scanf("%d", &database[usedSize].Course2_grade);
        printf("Enter Course3 ID: ");
        scanf("%d", &database[usedSize].Course3_ID);
        printf("Enter Course3 Grade: ");
        scanf("%d", &database[usedSize].Course3_grade);
        usedSize++;
        return true;
    } else {
        printf("Database is full.\n");
        return false;
    }
}

void SDB_DeleteEntry(uint32 id) {
    for (uint8 i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            for (uint8 j = i; j < usedSize - 1; j++) {
                database[j] = database[j + 1];
            }
            usedSize--;
            printf("Entry with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Entry with ID %d not found.\n", id);
}

bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %d\n", database[i].Student_ID);
            printf("Student Year: %d\n", database[i].Student_year);
            printf("Course1 ID: %d\n", database[i].Course1_ID);
            printf("Course1 Grade: %d\n", database[i].Course1_grade);
            printf("Course2 ID: %d\n", database[i].Course2_ID);
            printf("Course2 Grade: %d\n", database[i].Course2_grade);
            printf("Course3 ID: %d\n", database[i].Course3_ID);
            printf("Course3 Grade: %d\n", database[i].Course3_grade);
            return true;
        }
    }
    printf("Entry with ID %d not found.\n", id);
    return false;
}

void SDB_GetList(uint8 *count, uint32 *list) {
    *count = usedSize;
    for (uint8 i = 0; i < usedSize; i++) {
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}
