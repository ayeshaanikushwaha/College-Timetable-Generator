/*
Anshu Lakshkar
0801CS241020
Assignment number -  8 (Tree-II)
Problem number - 3
Date of submission - 1st March 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node25 {
    char DA25;
    struct Node25 *LF25, *RT25;
};

struct Node25* NEW25(char DA25) {
    struct Node25* ND25 = (struct Node25*)malloc(sizeof(struct Node25));
    ND25->DA25 = DA25;
    ND25->LF25 = ND25->RT25 = NULL;

    return ND25;
}

int ISOP25(char C25) {
    return (C25 == '+' || C25 == '-' || C25 == '*' || C25 == '/');
}

struct Node25* BUILD25(char POST25[]) {
    struct Node25* ST25[100];
    int TP25 = -1;

    for (int I25 = 0; POST25[I25]; I25++) {
        if (!ISOP25(POST25[I25])) {
            ST25[++TP25] = NEW25(POST25[I25]);
        }
        else {
            struct Node25* R25 = ST25[TP25--];
            struct Node25* L25 = ST25[TP25--];
            struct Node25* ND25 = NEW25(POST25[I25]);
            ND25->LF25 = L25;
            ND25->RT25 = R25;

            ST25[++TP25] = ND25;
        }
    }

    return ST25[TP25];
}

void INO25(struct Node25* RT25) {
    if (!RT25) return;

    if (ISOP25(RT25->DA25)) printf("(");

    INO25(RT25->LF25);
    printf("%c", RT25->DA25);
    INO25(RT25->RT25);

    if (ISOP25(RT25->DA25)) printf(")");
}

void PRE25(struct Node25* RT25) {
    if (!RT25) return;

    printf("%c ", RT25->DA25);
    PRE25(RT25->LF25);
    PRE25(RT25->RT25);
}

void POST25(struct Node25* RT25) {
    if (!RT25) return;

    POST25(RT25->LF25);
    POST25(RT25->RT25);
    printf("%c ", RT25->DA25);
}

int EVAL25(struct Node25* RT25) {
    if (!ISOP25(RT25->DA25))
        return RT25->DA25 - '0';

    int L25 = EVAL25(RT25->LF25);
    int R25 = EVAL25(RT25->RT25);

    switch (RT25->DA25) {
        case '+': return L25 + R25;
        case '-': return L25 - R25;
        case '*': return L25 * R25;
        case '/': return L25 / R25;
    }

    return 0;
}

int main() {
    char POSTFIX25[] = "53+62-*";
    struct Node25* ROOT25 = BUILD25(POSTFIX25);

    printf("Inorder   : ");
    INO25(ROOT25);
    printf("\nPreorder  : ");
    PRE25(ROOT25);
    printf("\nPostorder : ");
    POST25(ROOT25);

    printf("\nEvaluation Result = %d\n", EVAL25(ROOT25));

    return 0;
}