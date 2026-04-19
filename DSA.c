#include <stdio.h>
#include <string.h>

#define MAX 10
#define MAX_NAME 20
#define DAYS 5
#define PERIODS 5

typedef struct {
    char subject[MAX_NAME];
    char teacher[MAX_NAME];
    int isLab;   // 1 = Lab, 0 = Normal
} Subject;

Subject subjects[MAX];
int graph[MAX][MAX];
int color[MAX];
int n;

// Check conflict
int isSafe(int node, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

// Graph coloring
int solve(int node, int maxSlots) {
    if (node == n)
        return 1;

    for (int c = 1; c <= maxSlots; c++) {
        if (isSafe(node, c)) {
            color[node] = c;

            if (solve(node + 1, maxSlots))
                return 1;

            color[node] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter number of subjects: ");
    scanf("%d", &n);

    // Input
    for (int i = 0; i < n; i++) {
        printf("\nSubject name: ");
        scanf("%s", subjects[i].subject);

        printf("Teacher name: ");
        scanf("%s", subjects[i].teacher);

        printf("Is it Lab? (1=Yes, 0=No): ");
        scanf("%d", &subjects[i].isLab);
    }

    // Build graph (same teacher conflict)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && strcmp(subjects[i].teacher, subjects[j].teacher) == 0)
                graph[i][j] = 1;
            else
                graph[i][j] = 0;
        }
    }

    // Init
    for (int i = 0; i < n; i++)
        color[i] = 0;

    int maxSlots = DAYS * PERIODS;

    if (solve(0, maxSlots)) {

        char timetable[DAYS][PERIODS][MAX_NAME];

        // Initialize
        for (int d = 0; d < DAYS; d++)
            for (int p = 0; p < PERIODS; p++)
                strcpy(timetable[d][p], "Free");

        // Assign slots
        for (int i = 0; i < n; i++) {
            int slot = color[i] - 1;
            int day = slot / PERIODS;
            int period = slot % PERIODS;

            if (subjects[i].isLab == 1) {
                // Check if next slot exists
                if (period + 1 < PERIODS &&
                    strcmp(timetable[day][period], "Free") == 0 &&
                    strcmp(timetable[day][period + 1], "Free") == 0) {

                    strcpy(timetable[day][period], subjects[i].subject);
                    strcpy(timetable[day][period + 1], subjects[i].subject);
                }
            } else {
                strcpy(timetable[day][period], subjects[i].subject);
            }
        }

        // Print timetable
        printf("\nFinal Timetable:\n");

        for (int d = 0; d < DAYS; d++) {
            printf("\nDay %d:\n", d + 1);
            for (int p = 0; p < PERIODS; p++) {
                printf("Period %d: %s\n", p + 1, timetable[d][p]);
            }
        }

    } else {
        printf("No valid timetable possible\n");
    }

    return 0;
}