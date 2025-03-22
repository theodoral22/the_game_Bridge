#include <stdio.h> 
#include <stdbool.h> 
#define MAX 100 //define the maximum number of hands that can be stored
#include "functions.h" 

/*
This is a menu-driven program that allows a user to input bridge hands, process 
them, and save them. The user enters a command character, and the program performs 
the corresponding action:
-> 's': Prints a specific hand.
-> 'r': Suggests an opening bid based on the hand.
-> 'p': Calculates and displays the High Card Points and declarer points.
-> 'd': Determines if the hand is balanced or unbalanced.
-> 'o': Saves hands to a file.
-> 'q': Quits the program.
The program runs in a loop until the user enters 'q' to quit.
*/
int main() 
{ 
    int n=0,i,temp; //n:number of hands, temp:temporary variable
    struct hand A[MAX]; //array to store hands
    char k,c; //k:user's command, c:unused character variable
    char S[9]="hands.txt";
     
    n = readFromFile(A,S); //start by reading the file with the hands
    do 
    { 
        //loop until the user gives the correct letter
        do {
            printf("Select one of the following characters:\n");
            printf("-> 's': Prints a specific hand.\n");
            printf("-> 'r': Suggests an opening bid based on the hand.\n");
            printf("-> 'p': Calculates and displays the High Card Points and declarer points.\n");
            printf("-> 'd': Determines if the hand is balanced or unbalanced.\n");
            printf("-> 'o': Saves hands to a file.\n");
            printf("-> 'q': Quits the program.\n");
            scanf(" %c",&k); //read user input (command character)
            if (k!='s' && k!='r' && k!='p' && k!='d' && k!='o' && k!='q')
                printf ("Wrong answer. Try again.\n");
        } while (k!='s' && k!='r' && k!='p' && k!='d' && k!='o' && k!='q');
        
        switch (k) 
        {   
            case 's': //print a specific hand
                printf ("You selected to print a specific hand.\n");
                
                //loop until the user gives the correct number
                do {
                    printf ("Give me the number of the hand that you want to see.\n");
                    scanf ("%d",&i);
                    if (i<=0 || i>n)
                        printf ("Wrong answer. Try a number which is greater than 0 and less than %d\n",n+1);
                } while (i<=0 || i>n);
                
                printHand(A[i-1]); 
                printf ("\n"); 
                break; 
            case 'r': //display the appropriate opening bid for a given hand 
                printf ("You selected to suggest an opening bid based on the hand.\n");
                scanf ("%d",&i); 
                if (i>=0 && i<n) 
                    response(A[i]); 
                printf ("\n"); 
                break; 
            case 'p': //print the High Card Points and declarer points for a hand
                printf("You selected to calculate and display the High Card Points and declarer points.\n");
                scanf ("%d",&i); 
                if (i>=0 && i<n) 
                { 
                    temp = hcp(A[i]); 
                    printf ("%d HCP (%d total)\n",temp,temp+declarer(A[i])); 
                } 
                printf ("\n"); 
                break; 
            case 'd': //check if a hand has a balanced distribution
                printf("You selected to determine if the hand is balanced or unbalanced.\n");
                scanf ("%d",&i); 
                if (i>=0 && i<n) 
                { 
                    if (balanced(A[i])) 
                        printf ("Balanced distribution\n"); 
                    else 
                        printf ("Unbalanced distribution\n"); 
                } 
                printf ("\n"); 
                break;
            /*
            case 'o': //save hands to a file
                printf("You selected to save hands to a file.\n");
                saveData(A,n); 
                break;    
            */
        } 
    } 
    while (k!='q'); //continue until the user inputs 'q' (quit)
    printf("End of the game. Goodbye!");
    return 0; 
}
