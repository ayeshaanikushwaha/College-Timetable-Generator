/*
Anshu Lakshkar
0801CS241020
Assignment number - 5 (Stack)
Problem number - 6
Date of submission - 8th Feb 2026
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LIM25 100
char OP25_ST[LIM25];
int TP25 = -1;

void PU25SH(char x) { OP25_ST[++TP25] = x; }
char PO25P() { return OP25_ST[TP25--]; }
char PEE25K() { return OP25_ST[TP25]; }
int EM25PTY() { return TP25 == -1; }
int PRE25(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
void INF25_POST25(char IN25[], char PO25[]) {
    int b = 0;
    TP25 = -1;

    for (int a = 0; IN25[a]; a++) {
        char C25 = IN25[a];

        if (isalnum(C25)) {
            PO25[b++] = C25;
        }
        else if (C25 == '(') {
            PU25SH(C25);
        }
        else if (C25 == ')') {
            while (!EM25PTY() && PEE25K() != '(')
                PO25[b++] = PO25P();
            PO25P();
        }
        else {
            while (!EM25PTY() && PRE25(PEE25K()) >= PRE25(C25))
                PO25[b++] = PO25P();
            PU25SH(C25);
        }
    }

    while (!EM25PTY())
        PO25[b++] = PO25P();

    PO25[b] = '\0';
}
void REV25(char S25[]) {
    int N25 = strlen(S25);
    for (int I25 = 0; I25 < N25/2; I25++) {
        char T25 = S25[I25];
        S25[I25] = S25[N25-I25-1];
        S25[N25-I25-1] = T25;
    }
}
void INF25_PRE25(char IN25[], char PR25[]) {
    char TMP25[LIM25];

    strcpy(TMP25, IN25);
    REV25(TMP25);

    for (int a = 0; TMP25[a]; a++) {
        if (TMP25[a] == '(') TMP25[a] = ')';
        else if (TMP25[a] == ')') TMP25[a] = '(';
    }

    INF25_POST25(TMP25, PR25);
    REV25(PR25);
}

int EVA25_POST25(char P25[], int VAL25[]) {
    int ST25[LIM25], TT25 = -1;

    for (int I25 = 0; P25[I25]; I25++) {
        char C25 = P25[I25];

        if (isalpha(C25)) {
            ST25[++TT25] = VAL25[C25 - 'A'];
        }
        else {
            int B25 = ST25[TT25--];
            int A25 = ST25[TT25--];

            switch (C25) {
                case '+': ST25[++TT25] = A25 + B25; break;
                case '-': ST25[++TT25] = A25 - B25; break;
                case '*': ST25[++TT25] = A25 * B25; break;
                case '/': ST25[++TT25] = A25 / B25; break;
                case '^': ST25[++TT25] = (int)pow(A25, B25); break;
            }
        }
    }
    return ST25[TT25];
}
int EVA25_PRE25(char PR25[], int VAL25[]) {
    int ST25[LIM25], TT25 = -1;

    for (int I25 = strlen(PR25)-1; I25 >= 0; I25--) {
        char C25 = PR25[I25];

        if (isalpha(C25)) {
            ST25[++TT25] = VAL25[C25 - 'A'];
        }
        else {
            int A25 = ST25[TT25--];
            int B25 = ST25[TT25--];

            switch (C25) {
                case '+': ST25[++TT25] = A25 + B25; break;
                case '-': ST25[++TT25] = A25 - B25; break;
                case '*': ST25[++TT25] = A25 * B25; break;
                case '/': ST25[++TT25] = A25 / B25; break;
                case '^': ST25[++TT25] = (int)pow(A25, B25); break;
            }
        }
    }
    return ST25[TT25];
}
int main() {
    char INF25[LIM25], POST25[LIM25], PRE25X[LIM25];
    int VAL25[26] = {0};

    strcpy(INF25, "(A+B)*(C-D)");
    // strcpy(INF25, "(A-B+C)");
    // strcpy(INF25, "(A-B)*(C-D)");
    VAL25['A'-'A'] = 2;
    VAL25['B'-'A'] = 3;
    VAL25['C'-'A'] = 5;
    VAL25['D'-'A'] = 1;
    INF25_POST25(INF25, POST25);
    INF25_PRE25(INF25, PRE25X);

    printf("Infix   : %s\n", INF25);
    printf("Postfix : %s\n", POST25);
    printf("Prefix  : %s\n", PRE25X);
    printf("Postfix Eval = %d\n", EVA25_POST25(POST25, VAL25));
    printf("Prefix  Eval = %d\n", EVA25_PRE25(PRE25X, VAL25));

    return 0;
}
