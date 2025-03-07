// 랜덤한 하나의 숫자를 생성
// 사용자가 숫자를 입력
// 만약 입력한 숫자가 생성된 숫자보다 크면 크다고, 작으면 작다고 출력
// 5번의 기회를 준다.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number() {
    int answer;

    // 랜덤 시드 초기화
    srand(time(NULL));
    
    // 1부터 100 사이의 랜덤한 숫자 생성
    answer = rand() % 100 + 1;
    return answer;
}

int check_answer(int answer, int guess) {
    if (guess == answer) {
        return 1;
    }
    else if (guess > answer) {
        printf("Down!\n");
    }
    else {
        printf("Up!\n");
    }
    return 0;
}

int main() {
    int answer;
    int guess;
    int count = 0;

    answer = random_number();
    // printf("answer: %d\n", answer);

    while (count < 5) {
        printf("숫자를 입력하세요: ");
        scanf("%d", &guess);

        if (check_answer(answer, guess) == 1) {
            printf("정답입니다.\n");
            break;
        }
        count++;
    }

    printf("5번의 기회를 모두 사용했습니다.\n");
    printf("정답은 %d였습니다.\n", answer);
}
    

