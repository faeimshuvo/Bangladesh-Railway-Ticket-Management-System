#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<dos.h>

#define MAX_TICKETS 100

void addTicket();
void viewTicket(int ticketNumber);
void cancelTicket(int ticketNumber);
void printAllTickets();

//splash.c:
void showSplashScreen() {

printf("                              .  .:=+=:           \n");
printf("                     . .-#+...   :   -  -:        \n");
printf("               .-+:::           .   ::: . -       \n");
printf("         -.-=   .:. .-= <BR> =-: :  :     :.      \n");
printf("    :.  ::.:::..::=+ WELCOME TO  +=  =  :   .     \n");
printf("   ..   . .::::   :  BANGLADESH   :  #. .  :.     \n");
printf("   :  ........:. :+=:  RAILWAY  :=  ..-*..:..     \n");
printf("      :..  . :  .  . : ::  :.  :.   : =- .  .-    \n");
printf("          .:* . .    .........  :. . : := : .:    \n");
printf("              +:.   :                .   + - -    \n");
printf("                      .*  =   .   =   - .  :. -   \n");
printf("                            *..=  .   _ _   . =   \n");
printf("                                  +.::..:====..   \n");





}

//login.c:
void login(void)
{

    char username[50],password[25],userfile[50],passwordfile[25];

    FILE *log;
    log=fopen("login.txt","r");



        fscanf(log,"%s%s", userfile,passwordfile);//storing the username and password from file

        while(1)
        {

    printf("\t\t\t\t_______________________________________\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t|      Welcome to the Login page      |\n");
    printf("\t\t\t\t|_____________________________________|\n");


          printf("Enter user name\n");
          fflush(stdin);
          fgets(username,sizeof(username),stdin);
        username[strlen(username)-1]='\0'; //remove the new line charecter


        printf("Enter password\n");
        fflush(stdin);
        fgets(password,sizeof(password),stdin);
        password[strlen(password)-1]='\0';


       //matching password and username
        if(strcmp(username, "Fahim") == 0 && strcmp(password, "password") == 0)

         {
             system("cls");
            printf(".........Login Successful..........\n\n\n\n\n\n");
            sleep(1);
            system("cls");
            break;

         }
        else
         {
             system("cls");
            printf(">>>>> Login Unsuccessful!!!!!!!!!!!\n\n\n");
            printf("Try Again.!!!!!!!!!\n\n\n");
            sleep(3);
            system("cls");
         }
        }
        fclose(log);

    }

//menu.c:
int main(void)
{
    int choice;
    int ticketNumber;

    do {
        showSplashScreen();
        printf("1. Log In\n");
        printf("2. Add Ticket\n");
        printf("3. View Ticket\n");
        printf("4. Print All Tickets\n");
        printf("5. Cancel Ticket\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                addTicket();
                break;
            case 3:
                printf("Enter ticket number: ");
                scanf("%d", &ticketNumber);
                viewTicket(ticketNumber);
                break;
            case 4:
                printAllTickets();
                break;
            case 5:
                printf("Enter ticket number: ");
                scanf("%d", &ticketNumber);
                cancelTicket(ticketNumber);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}
//database.h:
struct Ticket {
    int ticketNumber;
    char passengerName[50];
    char trainName[50];
    int seatNumber;


};

struct Ticket tickets[MAX_TICKETS];
int numTickets = 0;

//database.c:
void addTicket() {
    if (numTickets >= MAX_TICKETS) {
        printf("Ticket limit reached!\n");
        return;
    }

    struct Ticket newTicket;

    printf("\nEnter ticket number: ");
    scanf("%d", &newTicket.ticketNumber);

    printf("\nEnter passenger name: ");
    scanf(" %[^\n]s", newTicket.passengerName);

    printf("\nEnter train name: ");
    scanf(" %[^\n]s", newTicket.trainName);

    printf("\nEnter seat number: ");
    scanf("%d", &newTicket.seatNumber);

    tickets[numTickets++] = newTicket;

    printf("Ticket added successfully!\n");
}
void viewTicket(int ticketNumber) {
    int i;
    for (i = 0; i < numTickets; i++) {
        if (tickets[i].ticketNumber == ticketNumber) {
            printf("Ticket Number: %d\n", tickets[i].ticketNumber);
            printf("Passenger Name: %s\n", tickets[i].passengerName);
            printf("Train Name: %s\n", tickets[i].trainName);
            printf("Seat Number: %d\n", tickets[i].seatNumber);
            return;
        }
    }

    printf("Ticket not found!\n");
}
void cancelTicket(int ticketNumber) {
    int i;
    for (i = 0; i < numTickets; i++) {
        if (tickets[i].ticketNumber == ticketNumber) {
            printf("Ticket Number: %d\n", tickets[i].ticketNumber);
            printf("Passenger Name: %s\n", tickets[i].passengerName);
            printf("Train Name: %s\n", tickets[i].trainName);
            printf("Seat Number: %d\n", tickets[i].seatNumber);
            printf("Ticket Cancelled!\n");
            return;
        }

    }
    printf("Ticket not found!\n");

}

void printAllTickets() {
    int i;
    for (i = 0; i < numTickets; i++) {
        printf("Ticket Number: %d\n", tickets[i].ticketNumber);
        printf("Passenger Name: %s\n", tickets[i].passengerName);
        printf("Train Name: %s\n", tickets[i].trainName);
        printf("Seat Number: %d\n\n", tickets[i].seatNumber);
    }
}




