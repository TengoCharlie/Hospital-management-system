// A header file is a file with extension . h which contains C function declarations and macro definitions to be shared between several source files. There are two types of header files: the files that the programmer writes and the files that comes with your compiler.

// The "#include" directive tells the C preprocessor to include the contents of the file specified in the input stream to the compiler and then continue with the rest of the original file. ... A header file may contain any valid C program fragment.

// The #include preprocessor directive is used to paste code of given file into current file. It is used include system-defined and user-defined header files. If included file is not found, compiler renders error.

// The C preprocessor is a micro processor that is used by compiler to transform your code before compilation.It is called micro preprocessor because it allows us to add macros.

/* A macro is defined at the top of your program.
for
eg : #define PI 3.14 Now whenever you write PI in your program 'PI' is replaced by 3.14 Actually this replacement is done by the preprocessor before the source code is compiled */

#include <stdio.h>
#include <windows.h> //gotoxy()
#include <conio.h>   //use for delay(), getch() etc
#include <ctype.h>   //use for toupper(), tolower()etc..
#include <string.h>  //use for strcmp(), strcpy(), strlen(), etc
#include <stdlib.h>  //stdlib. h is the header of the general purpose standard library of C programming language which includes functions involving memory allocation, process control, conversions and others.
//  Global Variable declaration
char ans = 0;
int ok;
int b, valid = 0;

// FUNCTION DECLARATION

void WelcomeScreen(void); //welcome screen function declarations
void Title(void);         //Title function declarations
void MainMenu(void);      //main menu function declarations
void LoginScreen(void);   //login screen function declarations
void Add_rec(void);       //add record function declarations
void func_list(void);     //Function to list function declarations
void Search_rec(void);    //Search record function declarations
void Edit_rec(void);      //Edit record function declarations
void Dlt_rec(void);       //Delete record fucntion declerations
void ex_it(void);         // Exit record function declarations

void gotoxy(short x, short y)
{
    COORD pos = {x, y}; //set co-ordinated in (x, y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct patient
{
    int age;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char Address[30];
    char Email[30];
    char Docter[20];
    char Problem[20];
};
struct patient p, temp_c;

int main(void)
{
    WelcomeScreen();
    Title();
    LoginScreen();
}

/*****************************************************/

void WelcomeScreen(void)
{
    printf("\n\n\n\n\n\n\n\n\t\t\t\t############################################");
    printf("\n\t\t\t\t#                WELCOME                   #");
    printf("\n\t\t\t\t#  TENGURIYA HOSPITAL MANAGEMENT SYSTEM    #");
    printf("\n\t\t\t\t############################################");
    printf("\n\n\n\n\npress any key to continue...\n");
    getch();
    system("cls");
}

void Title(void)
{
    printf("\n\n\t\t----------------------------------------------------------------------------");
    printf("\n\t\t\t\t                Tenguriya Hospital");
    printf("\n\t\t----------------------------------------------------------------------------");
}

void LoginScreen(void)
{
    int e = 0;
    char Username[15];
    char Password[15];
    char original_Username[25] = "harsh";
    char original_Password[25] = "12345";
    do
    {
        printf("\n\n\n\n\t\t\t\tEnter your Username and Password");
        printf("\n\n\n\t\t\t\t\tUSERNAME: ");
        scanf("%s", &Username);
        printf("\n\n\t\t\t\t\tPASSWORD: ");
        scanf("%s", &Password);
        if (strcmp(Username, original_Username) == 0 && strcmp(Password, original_Password) == 0)
        {
            printf("\n\n\n\t\t\t\t...Login Successfully...");
            getch();
            MainMenu();
            break;
        }
        else
        {
            printf("\n\t\t\tPassword is incorrect: (Try Again :) ");
            e++;
            getch();
        }

    } while (e <= 2);

    if (e > 2)
    {
        printf("You have crossed the limit. Please try again later. :( ");
        getch();
        ex_it();
    }
    system("cls");
}

void MainMenu(void)
{
    system("cls");
    int choose;
    Title();
    printf("\n\n\n\n\n\t\t\t1. Add Patients Record\n");
    printf("\n\t\t\t2. List Patients Record\n");
    printf("\n\t\t\t3. Search Patients Record\n");
    printf("\n\t\t\t4. Edit Patients Record\n");
    printf("\n\t\t\t5. Delete Patients Record\n");
    printf("\n\t\t\t6. Exit\n");
    printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:\n");
    scanf("%i", &choose);
    switch (choose)
    {
    case 1:
        Add_rec();
        break;
    case 2:
        func_list();
        break;
    case 3:
        Search_rec();
        break;
    case 4:
        Edit_rec();
        break;
    case 5:
        Dlt_rec();
        break;
    case 6:
        ex_it();
        break;
    default:
        printf("\t\t\tInvalid entry. Please enter right option.");
        getch();
    }
}

void Add_rec(void)
{
    system("cls");
    Title();

    char ans;

    FILE *ek;                       //File pointer
    ek = fopen("Record2.dat", "a"); //File open in write mode
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!! ADD PATIENTS RECORD !!!!!!!!!!!!!!!!\n");

A:
    printf("\n\t\t\tFirst Name: ");
    scanf("%s", p.First_Name);
    p.First_Name[0] = toupper(p.First_Name[0]);
    if (strlen(p.First_Name) > 20 || strlen(p.First_Name) < 2)
    {
        printf("\n\t Invalid :( First name must be minimum of 2 character and maximum of 20 characters");
        goto A;
    }
    else
    {
        for (b = 0; b < strlen(p.First_Name); b++)
        {
            if (isalpha(p.First_Name[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }

        if (!valid)
        {
            printf("\n\t\t First Name contains Invalid character :( Please try again.");
            goto A;
        }
    }

    // Lastname================================================================

B:
    printf("\n\t\t\tLast Name: ");
    scanf("%s", p.Last_Name);
    p.Last_Name[0] = toupper(p.Last_Name[0]);
    if (strlen(p.Last_Name) > 20 || strlen(p.Last_Name) < 2)
    {
        printf("\n\t Invalid :( \t Last name must be between 2 to 20 character please try again\n");
        goto B;
    }
    else
    {
        for (b = 0; b > strlen(p.Last_Name); b++)
        {
            if (isalpha(p.Last_Name[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\t Last name containes Invalid characters:( Please try again");
            goto B;
        }
    }

    // Gender============================================================

    do
    {
        printf("\n\t\t\tGender[F/M]: ");
        scanf(" %c", &p.Gender);
        if (toupper(p.Gender) == 'M' || toupper(p.Gender) == 'F')
        {
            ok = 1;
        }
        else
        {
            ok = 0;
        }
        if (!ok)
        {
            printf("\n\t\t Gender contains invalid characters :) Please try again");
        }
    } while (!ok);

    // Age============================================================================

    printf("\n\t\t\tAge: ");
    scanf(" %i", &p.age);

    // Address============================================================================

    do
    {
    C:
        printf("\n\t\t\tAddress: ");
        scanf("%s", p.Address);
        p.Address[0] = toupper(p.Address[0]);
        if (strlen(p.Address) > 20 || strlen(p.Address) < 4)
        {
            printf("\n\t Invalid :( The max range for address is 20 and min range is 4 : Please try a valid address");
            goto C;
        }
    } while (!valid);

    // Contact ============================================================

    do
    {
    D:
        printf("\n\t\t\tContact No.: ");
        scanf("%s", p.Contact_no);
        if (strlen(p.Contact_no) > 10 || strlen(p.Contact_no) < 2)
        {
            printf("\n\t Sorry :( Invalid Contact no. must contain 10 numbers. Enter a valid Contact no");
            goto D;
        }
        else
        {
            for (b = 0; b < strlen(p.Contact_no); b++)
            {
                if (!isalpha(p.Contact_no[b]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n\t\t Contact no. must contain 10 numbers. Enter a valid Contact : Please try again");
                goto D;
            }
        }
    } while (!valid);

    // Email =================================================================================

    do
    {
        printf("\n\t\t\tEmail: ");
        scanf("%s", p.Email);
        if (strlen(p.Email) > 30 || strlen(p.Email) < 8)
        {
            printf("\n\tInvalid Email Id:( Please enter a valid Email in between 8 to 30 characters)");
        }
    } while (strlen(p.Email) > 30 || strlen(p.Email) < 8);

    // Problem ====================================================================================
E:
    printf("\n\t\t\tProblem: ");
    scanf("%s", p.Problem);
    p.Problem[0] = toupper(p.Problem[0]);
    if (strlen(p.Problem) > 15 || strlen(p.Problem) < 3)
    {
        printf("\n\tInvalid :( \t please enter problem in between 3 to 15 character");
        goto E;
    }
    else
    {
        for (b = 0; b < strlen(p.Problem); b++)
        {
            if (isalpha(p.Problem[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\t Problem contain invalid charaters. Enter a valid problem : Please try again");
            goto E;
        }
    }

// Prescribed docters =============================================================
F:
    printf("\n\t\t\tPrescribed Docter: ");
    scanf("%s", p.Docter);
    p.Docter[0] = toupper(p.Docter[0]);
    if (strlen(p.Docter) > 15 || strlen(p.Docter) < 3)
    {
        printf("\n\tInvalid :( \t please enter Docter in between 3 to 30 character");
        goto F;
    }
    else
    {
        for (b = 0; b < strlen(p.Docter); b++)
        {
            if (isalpha(p.Docter[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\t Prescribed Docter contain invalid charaters. Enter a valid Name : Please try again");
            goto F;
        }
    }

    fprintf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter);

    printf("\n\n\t\t\t.... Information Record Successfully ...");
    fclose(ek); //ek file is closed
sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]??\n");
    scanf("%c", &ans);
    if (toupper(ans) == 'Y')
    {
        Add_rec();
    }
    else if (toupper(ans) == 'N')
    {
        printf("\n\t\t Thank You :) :) ");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\t\tInvalid Input \n");
        goto sd;
    }
}

// View Records ===============================================
void func_list(void)
{
    int row;
    system("cls");
    Title();
    FILE *ek;
    ek = fopen("Record2.dat", "r");
    printf("\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!! List Of Patients Records !!!!!!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(1, 15);
    printf("Full Name");
    gotoxy(20, 15);
    printf("Gender");
    gotoxy(32, 15);
    printf("Age");
    gotoxy(37, 15);
    printf("Address");
    gotoxy(49, 15);
    printf("Contact");
    gotoxy(64, 15);
    printf("Email");
    gotoxy(98, 15);
    printf("Problem");
    gotoxy(118, 15);
    printf("Prescribed Docter\n");
    printf("============================================================================================================================================\n");
    row = 17;
    while (fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter) != EOF)
    {
        gotoxy(1, row);
        printf("%s %s", p.First_Name, p.Last_Name);
        gotoxy(20, row);
        printf("%c ", p.Gender);
        gotoxy(32, row);
        printf("%i ", p.age);
        gotoxy(37, row);
        printf("%s", p.Address);
        gotoxy(49, row);
        printf("%s ", p.Contact_no);
        gotoxy(64, row);
        printf("%s ", p.Email);
        gotoxy(98, row);
        printf("%s ", p.Problem);
        gotoxy(118, row);
        printf("%s ", p.Docter);
        row++;
    }
    fclose(ek);
    getch();
    MainMenu();
}

void Search_rec(void)
{
    char name[20];
    system("cls");
    Title();
    FILE *ek;
    ek = fopen("Record2.dat", "r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!! Search Patient !!!!!!!!!!!!!!!!!!!!!!!");

    //gotoxy(12,8);
    printf("\n Enter patient name : ");
    scanf("%s", name);
    fflush(stdin);
    name[0] = toupper(name[0]);
    while (fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter) != EOF)
    {
        if (strcmp(p.First_Name, name) == 0)
        {
            gotoxy(1, 15);
            printf("Full Name");
            gotoxy(20, 15);
            printf("Gender");
            gotoxy(32, 15);
            printf("Age");
            gotoxy(37, 15);
            printf("Address");
            gotoxy(49, 15);
            printf("Contact");
            gotoxy(64, 15);
            printf("Email");
            gotoxy(88, 15);
            printf("Problem");
            gotoxy(98, 15);
            printf("Prescribed Docter");
            printf("\n ==================================================================================================\n");
            gotoxy(1, 18);
            printf("%s %s", p.First_Name, p.Last_Name);
            gotoxy(20, 18);
            printf("%c ", p.Gender);
            gotoxy(32, 18);
            printf("%i ", p.age);
            gotoxy(37, 18);
            printf("%s", p.Address);
            gotoxy(49, 18);
            printf("%s ", p.Contact_no);
            gotoxy(64, 18);
            printf("%s ", p.Email);
            gotoxy(98, 18);
            printf("%s ", p.Problem);
            gotoxy(118, 18);
            printf("%s ", p.Docter);
            printf("\n");
            break;
        }
    }
    if (strcmp(p.First_Name, name) != 0)
    {
        gotoxy(5, 10);
        printf("Record not found");
        getch();
    }
    fclose(ek);
L:
    getch();
    printf("\n\n\t\t\tDo you want to search more[Y/N]??");
    scanf("%c", &ans);
    if (toupper(ans) == 'Y')
    {
        Search_rec();
    }
    else if (toupper(ans) == 'N')
    {
        printf("\n\t\t Thank you :) :)");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\tInvalid Input!\n");
        goto L;
    }
}

void Edit_rec(void)
{
    FILE *ek, *ft;
    int i, b, valid = 0;
    char ch;
    char name[20];
    system("cls");
    Title();
    ft = fopen("temp2.dat", "w+");
    ek = fopen("Record2.dat", "r");
    if (ek == NULL)
    {
        printf("\n\t Can not open file!\n");
        getch();
        MainMenu();
    }

    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(12, 13);
    printf("Enter the First Name of the Patient: ");
    scanf(" %s", name);
    fflush(stdin);
    name[0] = toupper(name[0]);
    gotoxy(12, 15);
    if (ft == NULL)
    {
        printf("\n Can not open file\n");
        getch();
        MainMenu();
    }
    while (fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter) != EOF)
    {
        if (strcmp(p.First_Name, name) == 0)
        {
            valid = 1;
            gotoxy(25, 17);
            printf("*** Existing Records ***\n");
            gotoxy(10, 19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter);
            gotoxy(12, 22);
            printf("Enter New First Name: ");
            scanf("%s", p.First_Name);
            gotoxy(12, 24);
            printf("Enter Last Name: ");
            scanf("%s", p.Last_Name);
            gotoxy(12, 26);
            printf("Enter Gender: ");
            scanf(" %c", &p.Gender);
            p.Gender = toupper(p.Gender);
            gotoxy(12, 28);
            printf("Enter Age: ");
            scanf("%i", &p.age);
            gotoxy(12, 30);
            printf("Enter Address: ");
            scanf("%s", p.Address);
            p.Address[0] = toupper(p.Address[0]);
            gotoxy(12, 32);
            printf("Enter Contact No: ");
            scanf("%s", p.Contact_no);
            gotoxy(12, 34);
            printf("Enter Email: ");
            scanf("%s", p.Email);
            gotoxy(12, 36);
            printf("Enter Problem: ");
            scanf("%s", p.Problem);
            p.Problem[0] = toupper(p.Problem[0]);
            gotoxy(12, 38);
            printf("Enter Docter: ");
            scanf("%s", p.Docter);
            p.Docter[0] = toupper(p.Docter[0]);
            printf("\nPress U character for updating operation : ");
            ch = getche();
            if (ch == 'u' || ch == 'U')
            {
                fprintf(ft, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter);
                printf("\n\n\t\t\tPatient record updated successfully... ");
            }
        }
        else
        {
            fprintf(ft, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter);
        }
    }
    if (!valid)
    {
        printf("\n\t\tNo Record Found....");
    }
    fclose(ft);
    fclose(ek);
    remove("Record2.dat");
    rename("temp2.dat", "Record2.dat");
    getch();
    MainMenu();
}

void Dlt_rec(void)
{
    char name[20];
    int found = 0;
    system("cls");
    Title();
    FILE *ek, *ft;
    ft = fopen("temp_file2.dat", "w+");
    ek = fopen("Record2.dat", "r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    gotoxy(12, 8);
    printf("\n Enter Patient Name to delete: ");
    fflush(stdin);
    gets(name);
    name[0] = toupper(name[0]);
    while (fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter) != EOF)
    {

        if (strcmp(p.First_Name, name) != 0)
        {
            fprintf(ft, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter);
        }
        else
        {
            printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Docter);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("\n\n\t\t\t Record Not found......");
        getch();
        MainMenu();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Record2.dat");
        rename("temp_file2.dat", "Record2.dat");
        printf("\n\n\t\t\t Record Deleted successfully...:)  ");
        getch();
    }
}

void ex_it(void)
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\t\t\tThanks You Visiting :) ");
    getch();
}