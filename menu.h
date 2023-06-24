#include<stdio.h>

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
