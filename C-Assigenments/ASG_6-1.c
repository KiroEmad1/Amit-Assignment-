#include <stdio.h>
#include <string.h>

// Define a struct for student
struct Student {
    char name[50];
    int age;
    char degree[20];
    char section;
};

// Function to print data of all students
void print(struct Student *students, int size) {
    printf("Student Data:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Degree: %s\n", students[i].degree);
        printf("Section: %c\n", students[i].section);
        printf("\n");
    }
}

int main() {
    // Create an array of struct Student to store data of 5 students
    struct Student students[5];

    // Fill the data for each student
    strcpy(students[0].name, "name.");
    students[0].age = 18;
    strcpy(students[0].degree, "Engineering");
    students[0].section = 'A';

    strcpy(students[1].name, "name..");
    students[1].age = 19;
    strcpy(students[1].degree, "Medicine");
    students[1].section = 'B';

    strcpy(students[2].name, "name...");
    students[2].age = 20;
    strcpy(students[2].degree, "Computer Science");
    students[2].section = 'A';

    strcpy(students[3].name, "name....");
    students[3].age = 21;
    strcpy(students[3].degree, "Business");
    students[3].section = 'C';

    strcpy(students[4].name, "name.....");
    students[4].age = 22;
    strcpy(students[4].degree, "Arts");
    students[4].section = 'B';

    // Call the print function to print data of all students
    print(students, 5);

    return 0;
}
