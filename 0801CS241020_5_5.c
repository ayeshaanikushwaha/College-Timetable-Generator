/*
Anshu Lakshkar
0801CS241020
Assignment number - 5 (Stack)
Problem number - 5
Date of submission - 8th Feb 2026
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char OA_ST[MAX][MAX];
char OO_ST[MAX];
int AT = -1;
int OT = -1;
void pushOperand(char *str) {
    strcpy(OA_ST[++AT], str);
}
char* popOperand() {
    return OA_ST[AT--];
}

void pushOperator(char op) {
    OO_ST[++OT] = op;
}

char popOperator() {
    return OO_ST[OT--];
}
int PRECE25DENCE(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void EXP25() {
    char R[MAX], L[MAX], T[MAX];
    strcpy(R, popOperand());
    strcpy(L, popOperand());
    char op = popOperator();
    sprintf(T, "(%s%c%s)", L, op, R);
    pushOperand(T);
}

int main() {
    //CASE 1
    char exp[] = "2+2*3/2-2";
    // //CASE 2/
    // char exp[] = "5+3*2-4/2";
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            char num[2] = {exp[i], '\0'};
            pushOperand(num);
        }
        else { 
            while (OT != -1 &&
                   PRECE25DENCE(OO_ST[OT]) >= PRECE25DENCE(exp[i])) {
                EXP25();
            }
            pushOperator(exp[i]);
        }
    }
    while (OT != -1) {
        EXP25();
    }

    printf("Parenthesized Expression: %s\n", OA_ST[AT]);
    return 0;
}

