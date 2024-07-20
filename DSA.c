/*
21BCE247-parth Rana
21BCE248-Ranpara Shubh
21BCE249-Abhishek Rathod
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int bookedTicket=0;
typedef struct node
{
    struct node *next;
    struct node *prev;
    char name[50];
    long long int contact_no;
    int seat_no;
    char book;
    int pin;
} node;

node *hn = NULL;

void create()
{
    node *nn, *cn;
    int j = 1;
    int y = 1;
    //volatile int k = 2;
    int k = 1;

    for (int i = 1; i <= 55; i++)
    {

        if(i>=1 && i<=9)
        k = 11*i;
        else
        k = 101*i;

        nn = (node *)malloc(sizeof(node));
        nn->next = NULL;
        nn->prev = NULL;
        nn->seat_no = i;
        nn->pin = k;
        nn->book = 'a';

        if (hn == NULL)
        {
            hn = nn;
            nn->next = nn->prev = hn;
        }

        else
        {
            cn = hn;
            while (cn->next != hn)
                cn = cn->next;

            cn->next = nn;
            nn->prev = cn;
            nn->next = hn;
            hn->prev = nn;
        }
    }
}

void displaySeatArrangement()
{
    node *cn;
    cn = hn;
    printf("\n\t\t<<---Seat Status--->>\n-----------------------------------------------------------\n");
    while (cn->next != hn)
    {
        if (cn->seat_no == 6 || cn->seat_no == 11 || cn->seat_no == 16 || cn->seat_no == 21 || cn->seat_no == 26 || cn->seat_no == 31 || cn->seat_no == 36 || cn->seat_no == 41 || cn->seat_no == 46 || cn->seat_no == 51)
        {
            printf("\n");
        }

        if(cn->book=='a'){
            printf("| %2d -> - |", cn->seat_no);
        }else{
            printf("| %2d -> * |", cn->seat_no);
        }

        cn = cn->next;
    }

    if(cn->book=='a'){
        printf("| %2d -> - |", cn->seat_no);
    }else{
        printf("| %2d -> * |", cn->seat_no);
    }

    printf("\n");
    printf("\n - = Available seats, * = Booked seats");
    printf("\n-----------------------------------------------------------\n");
}

void printTicket(int n,node *temp[n])
{
        printf("------------------------------------------------------\n");
        printf("\nTHANK YOU..!\n\nYOU HAVE SUCCESFULLY BOOKED THE SEATS\n");

        printf("\nHERE IS YOUR TICKET...\n");

        printf("\n\tName : %s",temp[0]->name);

        printf("\n\tContact Number : %lld",temp[0]->contact_no);

        for (int i = 0; i < n; i++)
        {
            printf("\n");
            printf("\tSeat No.(%d) ", temp[i]->seat_no);
            printf("PIN : %d", temp[i]->pin);
            printf("\n");
        }

        printf("\n!!!!!!!!!!!!!!!!!...KEEP PIN SAFELY...!!!!!!!!!!!!!!!\n");
        printf("\nPINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\n");
        printf("------------------------------------------------------\n");
}

void book_seat()
{
    node *cn, *temp[20];
    int n, z, flag;
    char row;
    int seat;
    char ch;
    int a;
    char buffer;
    //char name[50];
    long long int number;

    do
    {
        z = 0;

        printf("\nEnter your name : ");
        //scanf("%c", &buffer); // buffer statement to clear buffer
        //scanf("%[^\n]", cn->name);
        fflush(stdin);
        gets(cn->name);

        printf("\nEnter No of Tickets You Want to Buy : ");
        scanf("%d", &n);

        if(n<1 || n>55){
            printf("\nEnter valid number of tickets you want to book (available seats are 1 to 55)\n");
            break;
        }

        printf("\nEnter your mobile number : ");
        scanf("%lld", &cn->contact_no);

        printf("\nEnter seat number(s) :-\n");

        for (int i = 1; i <= n; i++)
        {
            printf("\n\tSelect Seat Number(%d) = ", i);
            scanf("%d", &seat);

            cn = hn;

            if (seat >= 1 && seat <= 55)
            {
                while (cn->next != hn)
                {
                    if (cn->seat_no == seat)
                    {
                        if (cn->book == 'a')
                        {
                            cn->book = 'b';
                            temp[z] = cn;
                            z++;
                            bookedTicket++;
                        }
                        else
                        {
                            printf("\nINVALID CHOICE..!!\n");
                            printf("\nSeat number %d is already reserved\n", seat);
                            i--;
                        }
                    }
                    cn = cn->next;
                }

                if (cn->seat_no == seat)
                {
                    if (cn->book == 'a')
                    {
                        cn->book = 'b';
                        temp[z] = cn;
                        z++;
                    }
                    else
                    {
                        printf("\nINVALID CHOICE..!!\n");
                        printf("\nSeat number %d is already reserved\n", seat);
                        i--;
                    }
                }
            }

            else
            {
                printf("\nENTER CORRECT CHOICE\n");
                i--;
            }

        } // end of for loop

        printTicket(z ,temp);
        printf("\n\nPRESS 1 to check Seat Status \n");
        printf("PRESS 2 to Book other seat\n");
        printf("PRESS 3 to Exit Booking Portal\n");
        printf("Enter Your choice : ");
        scanf("%s", &ch);

        if (ch == 1)
            displaySeatArrangement();
        else if(ch=='3')
            return;

    } while (ch == '2'); // end of do-while loop
}

void cancel()
{

    if(bookedTicket==0){
        printf("\nNOT BOOKED ANY TICKET YET...\nPLEASE BOOK SOME TICKET FIRST...\n");
        return;
    }

    char ch;
    char c;
    int seat, pin;
    node *cn;
    printf("\nSEAT CANCELATION\n");

    do
    {
        ch = 'a';
        cn = hn;
        char name[50];
        long long int contact;
        printf("\nEnter your name : ");
        fflush(stdin);
        gets(name);
        printf("\nEnter your contact number : ");
        scanf("%lld", &contact);
        printf("\nEnter the SEAT NUMBER you want to delete : ");
        scanf("%d", &seat);

        if (seat >= 1 && seat <= 55)
        {
            printf("\nEnter PIN of the SEAT NUMBER : ");
            scanf("%d", &pin);
            while (cn->next != hn)
            {
                if (cn->seat_no == seat && cn->pin == pin)
                {
                    printf("\nAre you sure u want to cancel the seat (y/n) ");

                    scanf("%s", &c);

                    if (c == 'y' || c == 'Y')
                    {
                        printf("\nSEAT CANCELED SUCCUESFULLY..!\n");
                        cn->book = 'a';
                    }
                }
                else if (cn->seat_no == seat && cn->pin != pin)
                {
                    printf("\nSeat No. and PIN combination didn't match!\n");
                }
                cn = cn->next;
            }
            if (cn->seat_no == seat && cn->pin == pin)
            {
                printf("\nAre you sure u want to cancel the seat (y/n) ");
                scanf("%s", &c);

                if (c == 'y' || c == 'Y')
                {
                    printf("\nSEAT CANCELED SUCCUESFULLY..!\n");
                    cn->book = 'a';
                }
            }
            else if (cn->seat_no == seat && cn->pin != pin)
            {
                printf("\nInvalid Seat number & PIN combination..!\n");
            }
        }

        else
        {
            printf("\nENTER VALID INPUT\n");
        }

        printf("\n\nPRESS 1 to check seat status\n");
        printf("PRESS 2 to cancel more tickets\n");
        printf("PRESS 3 to exit cancellation portal\n");
        printf("Enter your choice : ");
        scanf("%s", &ch);

        if (ch == 1)
            displaySeatArrangement();

    } while (ch == '2');
}

int main()
{
    int choice;
    int c;
    system("COLOR 02");
    printf("\n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("             WELCOME TO BUS BOOKING SYSTEM\n");
    printf("--------------------------------------------------------------------------\n");
    create();

    do
    {
        printf("\n\n");
        printf("PRESS 1 -> BOOK TICKETS\n");
        printf("PRESS 2 -> CANCLE TICKETS\n");
        printf("PRESS 3 -> DISPLAY\n");
        printf("PRESS 4 -> EXIT\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("COLOR 06");
            displaySeatArrangement();
            book_seat();
            displaySeatArrangement();
            break;
        case 2:
            system("COLOR 04");
            displaySeatArrangement();
            cancel();
            displaySeatArrangement();
            break;

        case 3:
            system("COLOR 01");
            displaySeatArrangement();
            break;

        case 4:
            system("COLOR 0F");
            printf("--------------------------------------------------------------------------\n");
            printf("                    EXIT SUCESSFULLY                                       \n");
            printf("--------------------------------------------------------------------------\n");
            break;

        default:
            system("COLOR 04");
            printf("Enter Correct option\n");
            break;
        }

        if (choice != 4)
        {
            system("COLOR 0B");
            printf("\n\nPRESS 1 to Main Menu\n");
            printf("PRESS 2 To EXIT BOOKING SYSTEM\n");
            printf("Enter your choice\n");
            scanf("%d", &c);
        }
    } while (c == 1);

    system("COLOR 0F");
    printf("\n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("                    EXIT SUCESSFULLY                                       \n");
    printf("--------------------------------------------------------------------------\n");
    return 0;
}
