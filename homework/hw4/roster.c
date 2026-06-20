// Hailey Simpson
// June 21, 2026

#include <stdio.h>
#include <string.h>
#include "roster.h"

Student  create_student(const char *first, const char *last, int id, double gpa) {
    Student s;
    
    strncpy(s.first_name, first, sizeof(s.first_name) - 1);
    s.first_name[sizeof(s.first_name) - 1] = '\0';

    strncpy(s.last_name, last, sizeof(s.last_name) - 1);
    s.last_name[sizeof(s.last_name) - 1] = '\0';

    s.student_id = id;
    s.gpa = gpa;

    if (gpa < 0.0 || gpa > 4.0) {
        s.standing = GRADE_INCOMPLETE;
    } else if (gpa >= 3.5) {
        s.standing = GRADE_A;
    } else if (gpa >= 3.0) {
        s.standing = GRADE_B;
    } else if (gpa >= 2.0) {
        s.standing = GRADE_C;
    } else if (gpa >= 1.0) {
        s.standing = GRADE_D;
    } else {
        s.standing = GRADE_F;
    }

    return s;
}

int roster_add(Roster *r, Student s) {
    if (r->count >= MAX_STUDENTS) {
        return 0;
    }

    for (int i = 0; i < r->count; i++) {
        if (r->students[i].student_id == s.student_id) {
            return -1;
        }
    }

    r->students[r->count] = s;
    r->count++;

    return 1;
}

int roster_remove(Roster *r, int student_id) {
    for (int i = 0; i < r->count; i++) {
        if (r->students[i].student_id == student_id) {
            for (int j = i; j < r->count - 1; j++) {
                r->students[j] = r->students[j + 1];
            }
            r->count--;
            return 1;
        }
    }
    return 0;
}

Student *roster_find_by_id(Roster *r, int student_id) {
    for (int i = 0; i < r->count; i++) {
        if (r->students[i].student_id == student_id) {
            return &r->students[i];
        }
    }
    return NULL;
}

Student *roster_find_by_name(Roster *r, const char *last_name) {
    for (int i = 0; i < r->count; i++) {
        if (strcmp(r->students[i].last_name,last_name) == 0) {
            return &r->students[i];
        }
    }
    return NULL;
}

void roster_sort_by_name(Roster *r) {
    for (int i = 0; i < r->count - 1; i++) {
        for (int j = 0; j < r->count - i - 1; j++) {
            int swap_needed = 0;

            int last_cmp = strcmp(r->students[j].last_name, r->students[j + 1].last_name);

            if (last_cmp > 0) {
                swap_needed = 1;
            } else if (last_cmp == 0) {
                if (strcmp(r->students[j].first_name, r->students[j + 1].first_name) > 0) {
                    swap_needed = 1;
                }
            }

            if (swap_needed)
            {
                Student temp = r->students[j];
                r->students[j] = r->students[j + 1];
                r->students[j + 1] = temp;
            }
        }
    }
}

void roster_sort_by_gpa(Roster *r) {
    for (int i = 0; i < r->count - 1; i++) {
        for (int j = 0; j < r->count - i - 1; j++) {
            if (r->students[j].gpa < r->students[j + 1].gpa) {
                Student temp = r->students[j];
                r->students[j] = r->students[j + 1];
                r->students[j + 1] = temp;
            }
        }
    }
}
    
const char *grade_to_string(Grade g) {
    switch (g) {
        case GRADE_A: return "A";
        case GRADE_B: return "B";
        case GRADE_C: return "C";
        case GRADE_D: return "D";
        case GRADE_F: return "F";
        case GRADE_INCOMPLETE: return "Incomplete";
        default: return "Incomplete";
    }
}

double roster_average_gpa(const Roster *r) {
    double total = 0.0;

    if (r->count == 0) {
        return 0.0;
    }

    for (int i = 0; i < r->count; i++) {
        total += r->students[i].gpa;
    }

    return total / r->count;
}

void print_student(const Student *s) {
    if (s == NULL) {
        printf("No Student to Print\n");
        return;
    }

    printf("[%06d] %-15s, %-15s GPA: %.2f  Standing: %s\n", s->student_id, s->last_name, s->first_name, s->gpa, grade_to_string(s->standing));
}

void print_roster(const Roster *r) {
    printf("\n=============================================\n");
    printf("Student Roster (%d students)\n", r->count);
    printf("=============================================\n");

    for (int i = 0; i < r->count; i++) {
        print_student(&r->students[i]);
    }

    printf("---------------------------------------------\n");
    printf("Class average GPA: %.2f\n", roster_average_gpa(r));
    printf("=============================================\n");
}
