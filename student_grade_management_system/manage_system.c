#include "student.h"
#include <string.h>  // strcpy를 위한 헤더

#define average_count 3.0

int print_menu() {
    int choice;
    printf("1. 학생 정보 추가\n");
    printf("2. 전체 학생 정보 출력\n");
    printf("3. 학생 정보 검색\n");
    printf("4. 프로그램 종료\n");

    scanf("%d", &choice);
    return choice;
}

void add_student(Student list[], int *count) {
    printf("학생의 이름을 입력하세요: ");
    scanf("%s", list[*count].name);
    printf("학생의 나이를 입력하세요: ");
    scanf("%d", &list[*count].age);
    printf("학생의 국어 점수를 입력하세요: ");
    scanf("%d", &list[*count].grade.korean);
    printf("학생의 수학 점수를 입력하세요: ");
    scanf("%d", &list[*count].grade.math);
    printf("학생의 영어 점수를 입력하세요: ");
    scanf("%d", &list[*count].grade.english);
    (*count)++;
}

void print_info(Student list[], int count) {        
    for(int i = 0; i < count; i++) {
        printf("이름: %s\n", list[i].name);
        printf("나이: %d\n", list[i].age);
        printf("국어: %d\n", list[i].grade.korean);
        printf("수학: %d\n", list[i].grade.math);
        printf("영어: %d\n", list[i].grade.english);
        printf("평균: %f\n", (list[i].grade.korean + list[i].grade.math + list[i].grade.english) / average_count); 
        printf("\n");
    }
}

void search_student(Student list[], int count) {
    char student_name[20];
    printf("학생의 이름을 입력하세요: ");
    scanf("%s", student_name);
    for(int i = 0; i < count; i++) {
        if(strcmp(list[i].name, student_name) == 0) {
            printf("이름: %s\n", list[i].name);
            printf("나이: %d\n", list[i].age);
            printf("국어: %d\n", list[i].grade.korean);
            printf("수학: %d\n", list[i].grade.math);
            printf("영어: %d\n", list[i].grade.english);
            printf("\n");
        }
    }
}

int main() {
    Student list[10] = {0};
    int count = 0;

    // 민지 정보 추가
    strcpy(list[0].name, "민지");
    list[0].age = 20;
    list[0].grade.korean = 90;
    list[0].grade.math = 95;
    list[0].grade.english = 88;
    count++;
    
    // 하영 정보 추가
    strcpy(list[1].name, "하영");
    list[1].age = 19;
    list[1].grade.korean = 92;
    list[1].grade.math = 88;
    list[1].grade.english = 95;
    count++;

    while(1) {
        int choice = print_menu();
        if(choice == 4) {
            break;
        }
        else if(choice == 1) {
            add_student(list, &count);
        }
        else if(choice == 2) {
            print_info(list, count);
        }
        else if(choice == 3) {
            search_student(list, count);
        }
    }
    
    return 0;
}
