#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateExpression(int grade) {
    int num1, num2, num3, result;
    char operator1, operator2;

    if (grade == 1) {
        num1 = generateRandomNumber(1, 20);
        num2 = generateRandomNumber(1, 20);
        operator1 = rand() % 2 == 0 ? '+' : '-';
        result = operator1 == '+' ? num1 + num2 : num1 - num2;
        printf("%d %c %d = %d\n", num1, operator1, num2, result);
    } else if (grade == 2) {
        num1 = generateRandomNumber(1, 20);
        num2 = generateRandomNumber(1, 20);
        operator1 = rand() % 4; 
        operator2 = rand() % 4;
        while (operator2 == operator1) {
            operator2 = rand() % 4;
        }
        printf("%d %c %d %c %d\n", num1, "+-*/"[operator1], num2, "+-*/"[operator2], generateRandomNumber(1, 20));
    } else if (grade == 3) {
        num1 = generateRandomNumber(1, 1000);
        num2 = generateRandomNumber(1, 1000);
        operator1 = rand() % 3 == 0 ? '+' : (rand() % 2 == 0 ? '-' : '*');
        if (operator1 == '+') {
            result = num1 + num2;
        } else if (operator1 == '-') {
            result = num1 - num2;
        } else {
            result = num1 * num2;
        }
        printf("%d %c %d = %d\n", num1, operator1, num2, result);
    } else {
        num1 = generateRandomNumber(1, 100);
        num2 = generateRandomNumber(1, 100);
        num3 = generateRandomNumber(1, 100);
        operator1 = rand() % 4;
        operator2 = rand() % 4;
        while (operator2 == operator1) {
            operator2 = rand() % 4;
        }
        printf("%d %c %d %c %d\n", num1, "+-*/"[operator1], num2, "+-*/"[operator2], num3);
    }
}

int main() {
    srand(time(NULL));

    int grade, num_questions;
    printf("请输入年级（1-6）：");
    scanf("%d", &grade);
    printf("请输入题目数量：");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_questions; i++) {
        generateExpression(grade);
    }

    return 0;
}
