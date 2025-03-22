#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
structure which represents a hand
*/
struct hand 
{
    //d:for the data of the hand ,S:for the spades, H:for the hearts, D:for the diamonds, C: for the clubs
    char d[40],S[13],H[13],D[13],C[13]; 
    bool kat; //indicates whether the hand follows a balanced distribution
    int oner,pontoi; //oner:high card points, pontoi:normal points
};

/* 
The function takes a specific hand 'xeri' as input and displays the hand on the
screen
*/
void printHand(struct hand xeri)
{
    //plS:number of spades, plH:number of hearts, plD:number of diamonds, plC: number of clubs
    int i,plS=0,plH=0,plD=0,plC=0; 
    
    //loop through each character in the hand data
    for (i=0;i<strlen(xeri.d);i+=3) //each card is represented by 3 characters: rank, suit, and separator (if any)
    {
        //if the suit is Spades (S), add the card's rank to the Spades array
        if (xeri.d[i+1]=='S')
        {
            xeri.S[plS]=xeri.d[i];
            plS++; //increment the counter for Spades
        }
        //if the suit is Hearts (H), add the card's rank to the Hearts array
        else if (xeri.d[i+1]=='H')
        {
            xeri.H[plH]=xeri.d[i];
            plH++; //increment the counter for Hearts
        }
        //if the suit is Diamonds (D), add the card's rank to the Diamonds array
        else if (xeri.d[i+1]=='D')
        {
            xeri.D[plD]=xeri.d[i];
            plD++; //increment the counter for Diamonds
        }
        //if the suit is Clubs (C), add the card's rank to the Clubs array
        else
        {
            xeri.C[plC]=xeri.d[i];
            plC++; //increment the counter for Clubs
        }
    }
    xeri.S[plS]='\0';
    xeri.D[plD]='\0';
    xeri.H[plH]='\0';
    xeri.C[plC]='\0';
    
    printf ("SPADES:   ");
    for (i=0;i<strlen(xeri.S);i++)
        printf ("%c ",xeri.S[i]);

    printf ("\nHEARTS:   ");
    for (i=0;i<strlen(xeri.H);i++)
        printf ("%c ",xeri.H[i]);

    printf ("\nDIAMONDS: ");
    for (i=0;i<strlen(xeri.D);i++)
        printf ("%c ",xeri.D[i]);

    printf ("\nCLUBS:    ");
    for (i=0;i<strlen(xeri.C);i++)
        printf ("%c ",xeri.C[i]);
    printf ("\n");
}

/*
The function takes a specific hand 'xeri' and returns a boolean value (true/false)
depending on whether the hand received as input follows a balanced distribution. 
A hand follows a balanced distribution if both of the following conditions are met:
-> It contains at least 2 cards of each suit.
-> It has at most one suit with exactly 2 cards.
*/
bool balanced(struct hand xeri)
{
    //plS:number of spades, plH:number of hearts, plD:number of diamonds, plC: number of clubs
    int i,plS=0,plH=0,plD=0,plC=0;
    //loop through the hand data
    for (i=0;i<strlen(xeri.d);i+=3) //each card consists of 3 characters: rank, suit, separator
    {
        //if the suit is Spades (S), add the card's rank to the Spades array
        if (xeri.d[i+1]=='S')
        {
            xeri.S[plS]=xeri.d[i];
            plS++; //increment the counter for Spades
        }
        //if the suit is Hearts (H), add the card's rank to the Hearts array
        else if (xeri.d[i+1]=='H')
        {
            xeri.H[plH]=xeri.d[i];
            plH++; //increment the counter for Hearts
        }
        //if the suit is Diamonds (D), add the card's rank to the Diamonds array
        else if (xeri.d[i+1]=='D')
        {
            xeri.D[plD]=xeri.d[i];
            plD++; //increment the counter for Diamonds
        }
        //if the suit is Clubs (C), add the card's rank to the Clubs array
        else
        {
            xeri.C[plC]=xeri.d[i];
            plC++; //increment the counter for Clubs
        }
    }
    xeri.S[plS]='\0';
    xeri.D[plD]='\0';
    xeri.H[plH]='\0';
    xeri.C[plC]='\0';

    //check if the hand follows a balanced distribution based on the conditions
    //each condition checks if a suit has exactly 2 cards and the others have more than 2 cards
    if (strlen(xeri.S)==2&&strlen(xeri.H)>2&&strlen(xeri.D)>2&&strlen(xeri.C)>2)
        xeri.kat=true;
    else if (strlen(xeri.S)>2&&strlen(xeri.H)==2&&strlen(xeri.D)>2&&strlen(xeri.C)>2)
        xeri.kat=true;
    else if (strlen(xeri.S)>2&&strlen(xeri.H)>2&&strlen(xeri.D)==2&&strlen(xeri.C)>2)
        xeri.kat=true;
    else if (strlen(xeri.S)>2&&strlen(xeri.H)>2&&strlen(xeri.D)>2&&strlen(xeri.C)==2)
        xeri.kat=true;
    else if (strlen(xeri.S)>2&&strlen(xeri.H)>2&&strlen(xeri.D)>2&&strlen(xeri.C)>2)
        xeri.kat=true;
    else 
        xeri.kat=false;

    return xeri.kat;
}

/*
The function takes a specific hand 'xeri' and returns the high card points of 
the input hand. High card points are calculated aw follows:
-> Each Ace (A) contributes 4 high card points.
-> Each King (K) contributes 3 high card points.
-> Each Queen (Q) contributes 2 high card points.
-> Each Jack (J) contributes 1 high card point.
The remaining cards do not contribute any high card points.
*/
int hcp(struct hand xeri)
{
    int i;
    xeri.oner=0;
    //loop through the hand data
    for (i=0;i<=36;i+=3) //each card consists of 3 characters: rank, suit, separator
    {
        if (xeri.d[i]=='A')
            xeri.oner+=4;
        else if (xeri.d[i]=='K')
            xeri.oner+=3;
        else if (xeri.d[i]=='Q')
            xeri.oner+=2;
        else if (xeri.d[i]=='J')
            xeri.oner++;
    }
    return xeri.oner;
}

/*
The function takes a specific hand 'xeri' and returns the declarer points of the
given hand in addition to the high card points. The declarer points are determined 
based on the hand's distribution as follows: 
for each suit that contains 5 or more cards, one point is added for each card 
beyond the fourth. 
For example, if a hand has 5 spades, 3 hearts, 4 diamonds, and 1 club, then the 
hand is evaluated with an additional 1 distribution point (due to the five-card 
spade suit).
*/
int declarer(struct hand xeri)
{
    int i,plS=0,plH=0,plD=0,plC=0;
    //loop through the hand data
    for (i=0;i<strlen(xeri.d);i+=3) //each card consists of 3 characters: rank, suit, separator
    {
        //αssign each card to its respective suit array
        if (xeri.d[i+1]=='S')
        {
            xeri.S[plS]=xeri.d[i];
            plS++;
        }
        else if (xeri.d[i+1]=='H')
        {
            xeri.H[plH]=xeri.d[i];
            plH++;
        }
        else if (xeri.d[i+1]=='D')
        {
            xeri.D[plD]=xeri.d[i];
            plD++;
        }
        else
        {
            xeri.C[plC]=xeri.d[i];
            plC++;
        }
    }
    xeri.S[plS]='\0';
    xeri.D[plD]='\0';
    xeri.H[plH]='\0';
    xeri.C[plC]='\0';

    xeri.pontoi=0;

    //add distribution points for suits with 5 or more cards
    if (strlen(xeri.S)>=5)
        xeri.pontoi+=strlen(xeri.S)-4;
    if (strlen(xeri.H)>=5)
        xeri.pontoi+=strlen(xeri.H)-4;
    if (strlen(xeri.D)>=5)
        xeri.pontoi+=strlen(xeri.D)-4;
    if (strlen(xeri.C)>=5)
        xeri.pontoi+=strlen(xeri.C)-4;

    return xeri.pontoi;
}

/*
The function takes a specific hand 'xeri' and displays the appropriate opening 
bid that the player holding the given hand should make. The bid depends on the 
hand's distribution (balanced/unbalanced) and the evaluation points (high card 
points and declarer points) based on the following rules:
-> If the hand has a balanced distribution and 15-17 high card points, the 
   opening bid is 1NT.
-> If the hand has a balanced distribution and 20-21 high card points, the 
   opening bid is 2NT.
-> If the hand has 22 or more high card points (regardless of distribution), 
   the opening bid is 2 CLUBS.
-> If the hand has fewer than 22 high card points and the total points (high
   card points + declarer points) are at least 13, then the opening bid is:
   -> 1 SPADES if spades are at least 5 and hearts are not more than 5.
   -> 1 HEARTS if hearts are at least 5 and spades are fewer.
   -> 1 DIAMONDS if diamonds are at least 4 and no other suit has 5 or more cards.
   -> 1 CLUBS if the hand has fewer than 5 spades, fewer than 5 hearts, and fewer 
      than 4 diamonds.
-> If the total points (high card points + declarer points) are fewer than 13, 
   the opening bid is PASS.

NOTE: The 1NT and 2NT bids take precedence over a 1-level suit bid. For example, 
if a hand has 16 high card points, 5 spades, 3 hearts, 3 diamonds, and 2 clubs 
(balanced distribution), the correct bid is 1NT, not 1 SPADES!

General rules for balanced distributions:
-> PASS if total points are fewer than 13.
-> 1NT if high card points are between 15 and 17.
-> 2NT if high card points are between 20 and 21.
-> 2 CLUBS if high card points are 22 or more.
-> 1 in a suit if high card points are between 18 and 19, or if high card points 
   are fewer than 15 but the total points are at least 13.
*/
void response (struct hand xeri)
{
    int i,plS=0,plH=0,plD=0,plC=0;
    bool k; //for the balanced distributions
    int oner1,pontoi1; //oner1:for high card points, pontoi1:for declarer points

    //loop through the hand data
    for (i=0;i<strlen(xeri.d);i+=3) //each card consists of 3 characters: rank, suit, separator
    {
        //αssign each card to its respective suit array
        if (xeri.d[i+1]=='S')
        {
            xeri.S[plS]=xeri.d[i];
            plS++;
        }
        else if (xeri.d[i+1]=='H')
        {
            xeri.H[plH]=xeri.d[i];
            plH++;
        }   
        else if (xeri.d[i+1]=='D')
        {
            xeri.D[plD]=xeri.d[i];
            plD++;
        }
        else
        {
            xeri.C[plC]=xeri.d[i];
            plC++;
        }
    }
    xeri.S[plS]='\0';
    xeri.D[plD]='\0';
    xeri.H[plH]='\0';
    xeri.C[plC]='\0';

    k=balanced(xeri);  //determine if the hand has a balanced distribution
    oner1=hcp(xeri);  //calculate high card points
    pontoi1=declarer (xeri); //calculate declarer points

    //determine the appropriate opening bid based on hand evaluation
    if (k&&(oner1>=15&&oner1<=17))
        printf ("1NT"); //balanced hand with 15-17 HCP → 1NT
    else if (k&&(oner1>=20&&oner1<=21))
        printf ("2NT"); //balanced hand with 20-21 HCP → 2NT
    else if (oner1>=22)
        printf ("2 CLUBS"); //22+ HCP regardless of distribution → 2♣
    else if (oner1<22&&(oner1+pontoi1)>=13)
    {
        //if spades are at least 5 and hearts are fewer than 5 → 1♠
        if (strlen(xeri.S)>=5&&strlen(xeri.H)<5)
            printf ("1 SPADES");
        //if hearts are at least 5 and spades are fewer → 1♥
        else if (strlen(xeri.H)>=5&&strlen(xeri.S)<strlen(xeri.H))
            printf ("1 HEARTS");
        //if diamonds are at least 4 and no other suit has 5+ → 1♦
        else if (strlen(xeri.D)>=4&&strlen(xeri.S)<5&&strlen(xeri.H)<5&&strlen(xeri.C)<5)
            printf ("1 DIAMONDS");
        //if no suit meets other criteria → 1♣
        else if (strlen(xeri.S)<5&&strlen(xeri.H)<5&&strlen(xeri.D)<4)
            printf("1 CLUBS");
    }
    else if ((xeri.oner+xeri.pontoi)<13)
        printf ("PASS"); //fewer than 13 total points → PASS
    printf ("\n");
}

/*
The function takes all the hands '*A' and reads a string (S) from the keyboard, 
which will contain the name of a text file. Then, it opens the file S for 
reading and reads an integer (N) from the file, which represents the number of hands. 
After that, the function reads the data for N hands from the file in the same way 
as the "readFromInput function". The function returns the number of hands read.
*/
int readFromFile(struct hand *A,char *S)
{
    int N,i=0;
    char *A1; //A1:for the hand data
    //char S[10];
    
    //scanf ("%s",S); //read the filename from the keyboard
    //S[strcspn(S,"\n")]='\0'; //remove any trailing newline character
    FILE *fp=fopen(S,"r"); //open the file for reading
    if (fp!=NULL)
    {
        fscanf (fp,"%d",&N); //read the number of hands (N) from the file
        fscanf(fp," "); //consume any leading whitespace
        for (i=0;i<N;i++) //read N hands from the file
        {
            fgets (A[i].d,40,fp); //read a line (hand data) from the file
            fscanf(fp," "); //consume any leading whitespace
            A[i].d[(strcspn(A[i].d,"\r\n"))]='\0';
        } 
    }  
    fclose (fp); //close the file
    return N;
}

/*
The function takes all the hands '*A' and reads a string (S) from the keyboard, 
which will contain the name of a text file. Then, it opens the file S for writing 
and writes all the hands into the file. The writing process will be done in the 
same way as the "printHand" function displayed the hands on the screen.
*/
/*
void saveData(struct hand *A,int N)
{
    int i,plS,plH,plD,plC,xeri;
    char S[10];
    
    scanf ("%s",S); //read the filename from the keyboard
  
    fp=fopen(S,"w"); //open the file for writing
    if (fp!=NULL)
    {
        //loop through each hand
        for (xeri=0;xeri<N;xeri++)
        {
            plS=0;
            plH=0;
            plD=0;
            plC=0;
            //loop through the hand data
            for (i=0;i<strlen(A[xeri].d);i+=3) //each card consists of 3 characters: rank, suit, separator
            {
                //assign cards to the corresponding suit array
                if (A[xeri].d[i+1]=='S')
                {
                    A[xeri].S[plS]=A[xeri].d[i];
                    plS++;
                }
                else if (A[xeri].d[i+1]=='H')
                {
                    A[xeri].H[plH]=A[xeri].d[i];
                    plH++;
                }
                else if (A[xeri].d[i+1]=='D')
                {
                    A[xeri].D[plD]=A[xeri].d[i];
                    plD++;
                }
                else
                {
                    A[xeri].C[plC]=A[xeri].d[i];
                    plC++;
                }
            }
            A[xeri].S[plS]='\0';
            A[xeri].D[plD]='\0';
            A[xeri].H[plH]='\0';
            A[xeri].C[plC]='\0';
      
            //write the hand details to the file
            fprintf (fp,"SPADES:   ");
            for (i=0;i<plS;i++)
            fprintf (fp,"%c ",A[xeri].S[i]);
  
            fprintf (fp,"\nHEARTS:   ");
            for (i=0;i<plH;i++)
                fprintf (fp,"%c ",A[xeri].H[i]);
  
            fprintf (fp,"\nDIAMONDS: ");
            for (i=0;i<plD;i++)
                fprintf (fp,"%c ",A[xeri].D[i]);
  
            fprintf (fp,"\nCLUBS:    ");
            for (i=0;i<plC;i++)
                fprintf (fp,"%c ",A[xeri].C[i]);
                
            fprintf (fp,"\n\n"); //separate hands with blank lines
        }
    }  
    fclose(fp); //close the file
}
*/
