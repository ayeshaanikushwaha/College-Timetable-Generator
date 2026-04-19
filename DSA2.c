#include <stdio.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_SUBJECTS 20
#define MAX_TEACHERS 20
#define DAYS 5
#define PERIODS 6
#define MAX_QUEUE 100

char timetable[MAX_CLASSES][DAYS][PERIODS][50];
int teacherBusy[MAX_TEACHERS][DAYS][PERIODS];

char teacherNames[MAX_TEACHERS][50];
int teachers = 0;

char dayNames[DAYS][10] = {"Mon","Tue","Wed","Thu","Fri"};

int classes;

struct Subject
{
    char name[50];
    int teacherId;
    int hours;
    int isLab;
};
typedef struct Subject Subject;

Subject classSubjects[MAX_CLASSES][MAX_SUBJECTS];
int subjectCount[MAX_CLASSES];

struct Queue
{
    Subject arr[MAX_QUEUE];
    int front;
    int rear;
};
typedef struct Queue Queue;

void initialize()
{
    for(int c=0;c<MAX_CLASSES;c++)
        for(int d=0;d<DAYS;d++)
            for(int p=0;p<PERIODS;p++)
                strcpy(timetable[c][d][p], "-");

    for(int t=0;t<MAX_TEACHERS;t++)
        for(int d=0;d<DAYS;d++)
            for(int p=0;p<PERIODS;p++)
                teacherBusy[t][d][p] = 0;
}
int getTeacherId(char name[])
{
    for(int i=0;i<teachers;i++)
    {
        if(strcmp(teacherNames[i], name) == 0)
            return i;
    }

    strcpy(teacherNames[teachers], name);
    teachers++;

    return teachers - 1;
}


void enqueue( Queue *q, Subject s)
{
    q->rear++;
    q->arr[q->rear] = s;
}

Subject dequeue(Queue *q)
{
    return q->arr[q->front++];
}

int isEmpty( Queue *q)
{
    return q->front > q->rear;
}


void sortSubjects(int classId)
{
    Subject temp;

    for(int i=0;i<subjectCount[classId]-1;i++)
    {
        for(int j=i+1;j<subjectCount[classId];j++)
        {
            if(classSubjects[classId][i].hours < classSubjects[classId][j].hours)
            {
                temp = classSubjects[classId][i];
                classSubjects[classId][i] = classSubjects[classId][j];
                classSubjects[classId][j] = temp;
            }
        }
    }
}

int canAssign(int classId, int teacher, int day, int period, char subjectName[])
{
    if(strcmp(timetable[classId][day][period], "-") != 0)
        return 0;

    if(teacherBusy[teacher][day][period] == 1)
        return 0;

    if(period > 0 && strcmp(timetable[classId][day][period-1], subjectName) == 0)
        return 0;

    return 1;
}

void inputData()
{
    printf("Enter number of classes: ");
    scanf("%d",&classes);
    getchar();

    for(int c=0;c<classes;c++)
    {
        int n;
        int index = 0;

        printf("\nEnter number of subjects for Class %d: ",c+1);
        scanf("%d",&n);
        getchar();

        for(int s=0;s<n;s++)
        {
            char name[50];
            char teacherName[50];
            int theory, lab;

            printf("\n----------------------------\n");

            printf("Enter Subject name: ");
            scanf(" %[^\n]", name);

            printf("Enter Teacher name: ");
            scanf(" %[^\n]", teacherName);

            printf("Enter Theory hours: ");
            scanf("%d", &theory);

            printf("Enter Lab hours (0 or 2): ");
            scanf("%d", &lab);

            printf("----------------------------\n");

            int teacher = getTeacherId(teacherName);

            if(theory > 0)
            {
                strcpy(classSubjects[c][index].name,name);
                classSubjects[c][index].teacherId = teacher;
                classSubjects[c][index].hours = theory;
                classSubjects[c][index].isLab = 0;
                index++;
            }

            if(lab > 0)
            {
                strcpy(classSubjects[c][index].name,name);
                strcat(classSubjects[c][index].name,"_LAB");
                classSubjects[c][index].teacherId = teacher;
                classSubjects[c][index].hours = lab;
                classSubjects[c][index].isLab = 1;
                index++;
            }
        }

        subjectCount[c] = index;
    }
}

void generateTimetable()
{
    for(int c=0;c<classes;c++)
    {
        Queue q;
        q.front = 0;
        q.rear = -1;

        sortSubjects(c);

        for(int i=0;i<subjectCount[c];i++)
            enqueue(&q,classSubjects[c][i]);

        while(!isEmpty(&q))
        {
            Subject sub = dequeue(&q);

            int remaining = sub.hours;
            int teacher = sub.teacherId;

            while(remaining > 0)
            {
                int placed = 0;

                for(int d=0;d<DAYS && !placed;d++)
                {
                    for(int p=0;p<PERIODS && !placed;p++)
                    {
                        if(sub.isLab)
                        {
                            if(p < PERIODS-1 && canAssign(c,teacher,d,p,sub.name) && canAssign(c,teacher,d,p+1,sub.name))
                            {
                                strcpy(timetable[c][d][p],sub.name);
                                strcpy(timetable[c][d][p+1],sub.name);

                                teacherBusy[teacher][d][p] = 1;
                                teacherBusy[teacher][d][p+1] = 1;

                                remaining -= 2;
                                placed = 1;
                            }
                        }
                        else
                        {
                            if(canAssign(c,teacher,d,p,sub.name))
                            {
                                strcpy(timetable[c][d][p],sub.name);
                                teacherBusy[teacher][d][p] = 1;

                                remaining--;
                                placed = 1;
                            }
                        }
                    }
                }

                if(!placed)
                {
                    printf("\nCould not place %s in Class %d\n",
                           sub.name,c+1);
                    break;
                }
            }
        }
    }
}


void printTimetable()
{
    for(int c=0;c<classes;c++)
    {
        printf("\n=============================\n");
        printf(" Timetable for Class %d\n",c+1);
        printf("=============================\n");

        printf("      ");
        for(int p=0;p<PERIODS;p++)
            printf("P%-33d",p+1);

        printf("\n");

        for(int d=0;d<DAYS;d++)
        {
            printf("%s   ",dayNames[d]);

            for(int p=0;p<PERIODS;p++)
                printf("%-33s",timetable[c][d][p]);

            printf("\n");
        }
    }
}



int main()
{
    initialize();
    inputData();
    generateTimetable();
    printTimetable();
    return 0;
}