#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//functions
    //print menu function
    void PrintMenu(const char *menu1[]) {
            int i;
            for (i = 0; i < 4; ++i) {
                printf("%s\n", menu1[i]);
            }
        }

    // print to do list function
    void PrintTaskList(char menu2[][1000]) {
            int i;
            int k = 1;
            for (i = 0; i < 4; ++i) {
                printf("%d. %s\n", k, menu2[i]);
                k = k + 1;
            }
        }


    // clear input buffer function for SCANF
    void clearInputBufferScanF() {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }



// main 
    int main() {

        //variables
        char toDoList[4][1000] = {"empty", "empty", "empty", "empty"};
        const char *menu[4] = {"o - output current task list","n - create new task list","e - edit a task list","q - quit"}; // o = output current task list... n = create new task list.... e = edit a task list
        char menuSelection;
        int whichEdit = 7;
        //counter variables
        int i;
        //quit? variable
        bool isQuit = false;
        

        //print menu first on program start
        //PrintMenu(menu);

        // loop until user quits
        while (!isQuit) {
            int whichEdit = 7; // fixes bug
            //print menu first on program start
            PrintMenu(menu);
            
            printf("\nChoose an option:\n");
            scanf(" %c", &menuSelection);

            // Clear the input buffer
            clearInputBufferScanF();
            
            //output task list option
            if (menuSelection == 'o') {
                printf("\n\n");
                PrintTaskList(toDoList);
                printf("\n\n");

            }
            //create new task list option
            else if (menuSelection == 'n') {
                
                for (i = 0; i < 4; ++i) {
                    printf("\n\nEnter task %d:", i+1);
                    fgets(toDoList[i], 1000, stdin);
                    toDoList[i][strcspn(toDoList[i], "\n")] = '\0'; // remove newline character
                }
                printf("\n\n");
            }

            // edit a task option
            else if (menuSelection == 'e') {
                printf("\nWhich task do you want to edit? (Type '1' '2' '3' or '4'):\n");
                scanf("%d", &whichEdit);
                clearInputBufferScanF();
                printf("\n");

                // which task to choose from
                if (whichEdit == 1) {
                    printf("Type what you want in Task 1:\n");
                    fgets(toDoList[whichEdit - 1], 1000, stdin);
                    printf("\nSuccessfully Changed!\n\n");
                    // remove newline character
                    for (i = 0; i < 4; ++i) {
                        toDoList[i][strcspn(toDoList[i], "\n")] = '\0'; 
                    }
                }
                else if (whichEdit == 2) {
                    printf("Type what you want in Task 2:\n");
                    fgets(toDoList[whichEdit - 1], 1000, stdin);
                    printf("\nSuccessfully Changed!\n\n");
                    // remove newline character
                    for (i = 0; i < 4; ++i) {
                        toDoList[i][strcspn(toDoList[i], "\n")] = '\0'; 
                    }
                }
                else if (whichEdit == 3) {
                    printf("Type what you want in Task 3:\n");
                    fgets(toDoList[whichEdit - 1], 1000, stdin);
                    printf("\nSuccessfully Changed!");
                    // remove newline character
                    for (i = 0; i < 4; ++i) {
                        toDoList[i][strcspn(toDoList[i], "\n")] = '\0'; 
                    }
                }
                else if (whichEdit == 4) {
                    printf("Type what you want in Task 4:\n");
                    fgets(toDoList[whichEdit - 1], 1000, stdin);
                    printf("\nSuccessfully Changed!\n\n");
                    // remove newline character
                    for (i = 0; i < 4; ++i) {
                        toDoList[i][strcspn(toDoList[i], "\n")] = '\0'; 
                    }
                }
                else if (whichEdit != 1 || whichEdit != 2 || whichEdit != 3 || whichEdit != 4) {
                    printf("invalid option\n\n");
                }
            }
            // quit option
            else if (menuSelection == 'q') {
                isQuit = true;
            }

        }


    }

