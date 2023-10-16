#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// To-Do List.
// You can add up tasks, delete tasks, mark task as completed and display the list.


#define MAX_TASKS 100


struct Task{
        char name[100];
        char description[100];
        int completed;
    };

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void addTasks(){
    if(taskCount < MAX_TASKS) {
        struct Task newTask;
        printf("Enter your new task name: ");
        scanf(" %99[^\n]", newTask.name);
        printf("Enter the description of the task: ");
        scanf(" %99[^\n]", newTask.description);
        newTask.completed = 0; // This means that to represent that a newly added task is initially not completed. The value 0 serves as a conventional indicator for tasks that are in an "incomplete" or "not done" state.
        //You still need to this new task to show up in the display array (console)
        tasks[taskCount] = newTask; //The new task is stored inside of this line of code
        taskCount++; // taskCount + 1
        printf("The task was added successfully.\n");
    } else {
        printf("The To-Do list is full. You have reached the limit of 100 tasks.\n");
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void markTaskAsCompleted(int taskNumber){
    int index = taskNumber - 1;

    if (taskNumber <= taskCount && taskNumber > 0) {
        if (tasks[index].completed == 1) {
            printf("The task is already marked as completed.\n");
        } else {
            tasks[index].completed = 1;
            printf("The task %d is marked as completed successfully.\n", taskNumber);
        }
    } else {
        printf("Invalid number. Try again.\n");
    }
}

void removeTask(){
    int taskNumber;
    printf("Enter the task number to be deleted: ");
    scanf("%d", &taskNumber);
    if(taskNumber >=1 && taskCount >= taskNumber){
        printf("The task %d was removed succesfully: %s\n", taskNumber, tasks[taskNumber - 1].name);
        for(int i = taskNumber - 1; i < taskCount - 1; i++){
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
    } else {
        printf("Invalid number. Try again.\n");
    }
}

int main(){
    int choice;
    while (1) {
        printf("Welcome to my first project, the To-Do List!\n");
        printf("To-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Remove Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);



        switch(choice){
            case 1:
                addTasks();
                break;
            case 2:
                if (0 < taskCount) {
                    for(int i = 0; i < taskCount; i++) {
                        printf("Task %d\n", i + 1);
                        printf("Name: %s\n", tasks[i].name);
                        printf("Description: %s\n", tasks[i].description);
                        printf("Completed: %s\n", tasks[i].completed ? "Yes" : "No");
                    }
                } else {
                    printf("The To-Do List is empty.\n");
                }
                break;
            case 3: {
                int taskIndex;
                printf("Enter the task number to mark as completed: ");
                scanf("%d", &taskIndex);
                if (taskIndex >= 1 && taskIndex <= taskCount) {
                markTaskAsCompleted(taskIndex);
                } else if (taskCount == 0) {
                    printf("The To-Do List is empty.\n");
                    } else {
                        printf("Invalid task number. Try again.\n");
                    }
            }
                break;
            case 4:
                removeTask();
                break;
            case 5:
                printf("Closing the To-Do List...");
                return 0;
                break;


            default:
                printf("Invalid number. Try again.\n");

        }

    }
    return 0;
}
