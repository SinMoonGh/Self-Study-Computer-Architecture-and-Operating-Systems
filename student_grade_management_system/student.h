#include <stdio.h>

typedef struct grade {
    int korean;
    int math;
    int english;
} Grade;

typedef struct student {
    char name[20];
    int age;
    Grade grade;
} Student;


