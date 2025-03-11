#include <stdio.h> 
#include <stdbool.h> 
#define MAX 100 //define the maximum number of hands that can be stored
#include "project2023a.h" 

/*
This is a menu-driven program that allows a user to input bridge hands, process 
them, and save them. The user enters a command character, and the program performs 
the corresponding action:
-> 'i': Reads hands from the keyboard.
-> 's': Prints a specific hand.
-> 'r': Suggests an opening bid based on the hand.
-> 'p': Calculates and displays the High Card Points and declarer points.
-> 'd': Determines if the hand is balanced or unbalanced.
-> 'f': Reads hands from a file.
-> 'o': Saves hands to a file.
-> 'q': Quits the program.
The program runs in a loop until the user enters 'q' to quit.
*/
int main() 
{ 
    int n=0,i,temp; //n:number of hands, temp:temporary variable
    struct hand A[MAX]; //array to store hands
    char k,c; //k:user's command, c:unused character variable
     
    do 
    { 
        scanf(" %c",&k); //read user input (command character)
        switch (k) 
        {             
            case 'i': //read hands from user input
                n = readFromInput(A); 
                break; 
            case 's': //print a specific hand
                scanf ("%d",&i); 
                if (i>=0 && i<n) 
                    printHand(A[i]); 
                printf ("\n"); 
                break; 
            case 'r': //display the appropriate opening bid for a given hand 
                scanf ("%d",&i); 
                if (i>=0 && i<n) 
                    response(A[i]); 
                printf ("\n"); 
                break; 
            case 'p': //print the High Card Points and declarer points for a hand
                scanf ("%d",&i); 
                if (i>=0 && i<n) 
                { 
                    temp = hcp(A[i]); 
                    printf ("%d HCP (%d total)\n",temp,temp+declarer(A[i])); 
                } 
                printf ("\n"); 
                break; 
            case 'd': //check if a hand has a balanced distribution
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
            case 'f': //read hands from a file
                n = readFromFile(A); 
                break; 
            case 'o': //save hands to a file
                saveData(A,n); 
                break;                         
        } 
    } 
    while (k!='q'); //continue until the user inputs 'q' (quit)
    return 0; 
} 
