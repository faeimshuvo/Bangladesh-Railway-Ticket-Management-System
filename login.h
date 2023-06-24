#include<stdio.h>

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
