// Hailey Simpson
// June 21, 2026

#include <stdio.h>
#include "roster.h"

void add_student(Roster *roster);
void remove_student(Roster *roster);
void find_student_by_id(Roster *roster);
void find_student_by_name(Roster *roster);
void sort_by_name(Roster *roster);
void sort_by_gpa(Roster *roster);
void print_roster_menu(const Roster *roster);

int main(void) {
    Roster roster;
    roster.count = 0;
     
    int choice;

    do {
        printf("\n= Student Roster System =\n");
        printf("1. Add student\n");
        printf("2. Remove student (by ID)\n");
        printf("3. Find student (by ID)\n");
        printf("4. Find student (by last name)\n");
        printf("5. Sort by name\n");
        printf("6. Sort by GPA\n");
        printf("7. Print roster\n");
        printf("8. Quit\n");

        do {
            printf("Enter choice (1-8): ");
            fscanf(stdin, "%d", &choice);

            if (choice < 1 || choice > 8) {
                printf("Invalid choice. Try again.\n");
            }
        } while (choice < 1 || choice > 8);

        switch (choice) {
            case 1: add_student(&roster); break;
            case 2: remove_student(&roster); break;
            case 3: find_student_by_id(&roster); break;
            case 4: find_student_by_name(&roster); break;
            case 5: sort_by_name(&roster); break;
            case 6: sort_by_gpa(&roster); break;
            case 7: print_roster_menu(&roster); break;
            case 8: printf("Goodbye!\n"); break;
        }

    } while (choice != 8);

}

void add_student(Roster *roster) {
    char first[32];
    char last[32];
    int id;
    double gpa;

    printf("First name: ");
    fscanf(stdin, "%31s", first);

    printf("Last name: ");
    fscanf(stdin, "%31s", last);

    printf("Student ID: ");
    fscanf(stdin, "%d", &id);

    printf("GPA: ");
    fscanf(stdin, "%lf", &gpa);

    Student s = create_student(first, last, id, gpa);

    int result = roster_add(roster, s);

    if (result == 1) {
        printf("Student added.\n");
    } else if (result == 0) {
        printf("Roster Full, Student Not Added\n");
    } else {
        printf("ID Already Exists, Student Not Added\n");
    }
}

void remove_student(Roster *roster) {
    int id;

    printf("Enter student ID: ");
    fscanf(stdin, "%d", &id);

    if (roster_remove(roster, id)) {
        printf("Student removed.\n");
    } else {
        printf("Student Not Found\n");
    }
}

void find_student_by_id(Roster *roster) {
    int id;

    printf("Enter student ID: ");
    fscanf(stdin, "%d", &id);

    Student *s = roster_find_by_id(roster, id);

    if (s != NULL) {
        print_student(s);
    } else {
        printf("Student not found.\n");
    }
}

void find_student_by_name(Roster *roster) {
    char last[32];

    printf("Enter last name: ");
    fscanf(stdin, "%31s", last);

    Student *s = roster_find_by_name(roster, last);

    if (s != NULL) {
        print_student(s);
    } else {
        printf("Student not found.\n");
    }
}

void sort_by_name(Roster *roster) {
    roster_sort_by_name(roster);
    printf("Roster sorted by name.\n");
}

void sort_by_gpa(Roster *roster) {
    roster_sort_by_gpa(roster);
    printf("Roster sorted by GPA.\n");
}

void print_roster_menu(const Roster *roster) {
    print_roster(roster);
}