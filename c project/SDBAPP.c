#include "SDB.h"
#include <stdio.h>
#include "SDBAPP.h"

void SDB_action(uint8 choice);

void SDB_APP() {
    uint8 choice;

    do {
        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get the list of all student IDs\n");
        printf("5. Check if ID is existed\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%hhu", &choice);

        if (choice != 0) {
            SDB_action(choice);
        }
    } while (choice != 0);
}

void SDB_action(uint8 choice) {
    uint32 id;

    switch (choice) {
        case 1:
            if (SDB_AddEntry()) {
                printf("Entry added successfully.\n");
            } else {
                printf("Failed to add entry. Database might be full.\n");
            }
            break;
        case 2:
            printf("Used size in database: %d\n", SDB_GetUsedSize());
            break;
        case 3:
            printf("Enter student ID to read: ");
            scanf("%u", &id);
            SDB_ReadEntry(id);
            break;
        case 4: {
            uint8 count;
            uint32 list[MAX_STUDENTS];
            SDB_GetList(&count, list);
            printf("List of student IDs:\n");
            for (int i = 0; i < count; i++) {
                printf("%u ", list[i]);
            }
            printf("\n");
            break;
        }
        case 5:
            printf("Enter student ID to check: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id)) {
                printf("Student ID %u exists in the database.\n", id);
            } else {
                printf("Student ID %u does not exist in the database.\n", id);
            }
            break;
        case 6:
            printf("Enter student ID to delete: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
        case 7:
            if (SDB_IsFull()) {
                printf("Database is full.\n");
            } else {
                printf("Database is not full.\n");
            }
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
    }
}