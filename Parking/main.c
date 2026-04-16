#include <stdio.h>
#include <string.h>

#define MAX 3

char parking[MAX][30];
int top = -1;

char waiting[10][30];
int front = -1, rear = -1;

void carEntry()
{
    char car[30];

    printf("Enter Car Number: ");
    scanf(" %[^\n]", car);   // takes full line input

    if(top == MAX-1)
    {
        printf("Parking Full! Car added to waiting queue.\n");

        if(rear == 9)
        {
            printf("Waiting queue also full!\n");
        }
        else
        {
            if(front == -1)
                front = 0;

            rear++;
            strcpy(waiting[rear], car);
        }
    }
    else
    {
        top++;
        strcpy(parking[top], car);
        printf("Car %s parked successfully.\n", car);
    }
}

void carExit()
{
    if(top == -1)
    {
        printf("Parking Empty!\n");
        return;
    }

    printf("Car %s exited.\n", parking[top]);
    top--;

    if(front != -1)
    {
        top++;
        strcpy(parking[top], waiting[front]);

        printf("Waiting car %s moved to parking.\n", waiting[front]);

        front++;

        if(front > rear)
            front = rear = -1;
    }
}

void display()
{
    int i;

    printf("\n--- Parked Cars ---\n");

    if(top == -1)
        printf("No cars parked\n");
    else
    {
        for(i=top;i>=0;i--)
            printf("%s\n", parking[i]);
    }

    printf("\n--- Waiting Cars ---\n");

    if(front == -1)
        printf("No waiting cars\n");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%s\n", waiting[i]);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== Smart Parking System =====\n");
        printf("1. Car Entry\n");
        printf("2. Car Exit\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                carEntry();
                break;

            case 2:
                carExit();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
