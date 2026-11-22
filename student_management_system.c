#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float fees;
    char course[10];

    struct Student *next;
};

struct Student *head = NULL;

/* Function to add a student */
void addStudent() {
    struct Student *newNode;
    newNode = (struct Student *)malloc(sizeof(struct Student));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Fees Paid: ");
    scanf("%f", &newNode->fees);

    printf("Enter Course (DS/AI/ML/Web): ");
    scanf("%s", newNode->course);

    newNode->next = NULL;

    /* Insert at the end */
    if (head == NULL) {
        head = newNode;
    } else {
        struct Student *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nStudent added successfully!\n");
}

/* Function to display all students */
void displayStudents() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-20s %-12s %-10s\n",
           "ID", "NAME", "FEES", "COURSE");
    printf("-------------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-10d %-20s %-12.2f %-10s\n",
               temp->id,
               temp->name,
               temp->fees,
               temp->course);

        temp = temp->next;
    }

    printf("-------------------------------------------------------------\n");
}

/* Function to search student by ID */
void searchStudent() {
    int id;
    struct Student *temp = head;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nStudent Found!\n");
            printf("ID     : %d\n", temp->id);
            printf("Name   : %s\n", temp->name);
            printf("Fees   : %.2f\n", temp->fees);
            printf("Course : %s\n", temp->course);
            return;
        }

        temp = temp->next;
    }

    printf("\nStudent not found.\n");
}

/* Function to update student details */
void updateStudent() {
    int id;
    struct Student *temp = head;

    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {

            printf("Enter New Name: ");
            scanf(" %[^\n]", temp->name);

            printf("Enter New Fees: ");
            scanf("%f", &temp->fees);

            printf("Enter New Course (DS/AI/ML/Web): ");
            scanf("%s", temp->course);

            printf("\nStudent details updated successfully!\n");
            return;
        }

        temp = temp->next;
    }

    printf("\nStudent not found.\n");
}

/* Function to delete a student */
void deleteStudent() {
    int id;
    struct Student *temp = head;
    struct Student *prev = NULL;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    /* If first node needs to be deleted */
    if (head != NULL && head->id == id) {
        head = head->next;
        free(temp);

        printf("\nStudent deleted successfully!\n");
        return;
    }

    /* Search for the student */
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nStudent not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("\nStudent deleted successfully!\n");
}

/* Function to display students according to course */
void displayByCourse() {
    char course[10];
    struct Student *temp = head;
    int found = 0;

    printf("\nEnter Course (DS/AI/ML/Web): ");
    scanf("%s", course);

    printf("\nStudents enrolled in %s:\n", course);

    printf("-------------------------------------------------------------\n");
    printf("%-10s %-20s %-12s %-10s\n",
           "ID", "NAME", "FEES", "COURSE");
    printf("-------------------------------------------------------------\n");

    while (temp != NULL) {
        if (strcmp(temp->course, course) == 0) {
            printf("%-10d %-20s %-12.2f %-10s\n",
                   temp->id,
                   temp->name,
                   temp->fees,
                   temp->course);

            found = 1;
        }

        temp = temp->next;
    }

    if (!found) {
        printf("No students found for this course.\n");
    }

    printf("-------------------------------------------------------------\n");
}

/* Main function */
int main() {
    int choice;

    while (1) {
        printf("\n========== STUDENT DATA MANAGEMENT ==========\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Display Students by Course\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                displayByCourse();
                break;

            case 7:
                printf("\nProgram terminated.\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
