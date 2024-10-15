#include <iostream>
#include <string>
using namespace std;

typedef struct ToDo todo;
struct ToDo
{
    char buffer[100];

    todo *next;

    int count;
};

todo *start = NULL;
void interface()
{

    cout << "\n\n\n\n";
    cout << "\t~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~\n";

    cout << "\t~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~\n\n";

    cout << "\t\t\tWelcome to ToDo App\n\n";

    cout << "\t~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~\n";

    cout << "\t~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~~~~~~~~~~~~"
            "~~~~~~~~~~\n\n";

    system("pause");
}

void seetodo()
{
    system("cls");

    todo *temp;

    temp = start;

    if (start == NULL)
    {
        cout << "\n\nEmpty ToDo\n\n";
    }

    while (temp != NULL)
    {
        cout << temp->count;
        // cout << temp->buffer;
         puts(temp->buffer);

        fflush(stdin);

        temp = temp->next;
    }

    cout << "\n\n\n";
    system("pause");
}

// Function to adjust the numbering of nodes
void adjustCount()
{
    todo *temp;
    int i = 1;
    temp = start;

    while (temp != NULL)
    {
        temp->count = i;
        i++;
        temp = temp->next;
    }
}

// function to create ToDO
void createtodo()
{
    // Choose choice from user
    char c;

    // Pointers to node
    todo *add, *temp;
    system("cls");

    // Infinite loop which will
    // break if "n" is pressed
    while (1)
    {

        cout << "Enter the ToDo | n to exit\n\t\t";

        fflush(stdin);

        // Input from user
        cin >> c;
        if (c == 'n')
            break;
        else
        {

            if (start == NULL)
            {

                add = (todo *)calloc(1, sizeof(todo));

                // Using add pointer to
                // create linked list
                start = add;
                cout << "\nType it.....\n";

                // Input from user
                fflush(stdin);
                gets(add->buffer);

                add->count = 1;

                start->next = NULL;
            }
            else
            {
                temp = (todo *)calloc(1, sizeof(todo));
                printf("\nType it.....\n");
                fflush(stdin);
                gets(temp->buffer);

                // Insertion is at last
                // so pointer part is NULL
                temp->next = NULL;

                // add is now pointing
                // newly created node
                add->next = temp;
                add = add->next;
            }

            adjustCount();
        }
    }
}

// Function to delete the todo
void deletetodo()
{
    system("cls");

    // getting number from user to delete
    int x;

    todo *del, *temp;
    cout << "\nEnter the ToDo's number"
            " that you want to remove.\n\t\t";

    // Checking empty condition
    if (start == NULL)
        cout << "\n\nThere is no ToDo"
                " for today :-)\n\n\n";
    else
    {
        scanf("%d", &x);

        del = start;

        temp = start->next;

        while (1)
        {

            // When the values matches,
            // delete the node
            if (del->count == x)
            {

                // When the node to be
                // deleted is first node
                start = start->next;

                // Deallocating the memory
                // of the deleted node
                free(del);

                // Adjusting the count when
                // node is deleted
                adjustCount();
                break;
            }

            if (temp->count == x)
            {
                del->next = temp->next;
                free(temp);
                adjustCount();
                break;
            }
            else
            {
                del = temp;
                temp = temp->next;
            }
        }
    }
    system("pause");
}
int main()
{

    int choice;
    interface();

    while (1)
    {
        system("cls");
        cout << "1. To see your ToDo list\n";
        cout << "2. To create new ToDo \n";
        cout << "3. To Delete ToDo \n";
        cout << "4. Exit \n";
        cout << "\n\n Enter your choice\t:\t";

        // taking input from user
        cin >> choice;

        switch (choice)
        {

            // Calling functions

        case 1:
            seetodo();
            break;
        case 2:
            createtodo();
            break;
        case 3:
            deletetodo();
            break;
        case 4:
            exit(1);
            break;
        default:
            cout << "\nInvalid Choice :-(\n";
            system("pause");
        }
    }
}