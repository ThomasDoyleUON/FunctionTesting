
#include<stdio.h>
#include<string.h>

char ccencrypt(char* str, int key);

char ccdecrypt(char* str, int key);

char scencrypt(char* str, char* keystr);

char scdecrypt(char* str, char* keystr);

int main()
{
    int key;
    char str[100];
    int choice;
    char keystr[100];
    
    printf("~~Ceaser Cipher~~\n 0 = Encrypt\n 1 = Decrypt\n");
    printf("~~Subsitution Cipher~~\n 2 = Encrypt\n 3 = Decrypt\n");
    printf("Enter Choice For Processing: ");
    scanf("%d\n", choice);
    
    
    
    
    switch(choice)
    {
    case 0 : 
        {
        printf("Choosen Ceaser Cipher Encrypt\n");
        printf("Enter String: ");
        scanf("%s\n", str);
        printf("Enter Key: ");
        scanf("%d\n", key);
        ccencrypt(str, key);
        break;
        }
    case 1 :
        {
        printf("Choosen Ceaser Cipher Decrypt\n");
        printf("Enter String: ");
        scanf("%s", str);
        printf("Enter Key: ");
        scanf("%d", key);
        ccdecrypt(str, key);
        break;
        }

    case 2 :
        {
        printf("Choosen Subsitution Cipher Encrypt\n");
        printf("Enter String: ");
        scanf("%s\n", str);
        printf("Enter Key String: ");
        scanf("%d\n", keystr);
        scencrypt(str, keystr);
        break;
        }
    case 3 :
        {
        printf("Choosen Subsitution Cipher Decrypt\n");
        printf("Enter String: ");
        scanf("%s\n", str);
        printf("Enter Key String: ");
        scanf("%d\n", keystr);
        scdecrypt(str, keystr);
        break;
        }

    default:
        printf("ERROR\n");
    }
    
    
    
   
}
//Ceasear Cipher Encrypt
char ccencrypt(char* str, int key)
    {

    char ccestr[100];
    int ccestrsize = strlen(str);
    for(int i = 0; (i < ccestrsize); i++)
        {      
        if (str[i] == ' ')
        {
            ccestr[i] = ' ';
        }
        else
        {
            ccestr[i] = ((((str[i] + key) - 65) % 26) + 65); 
        }
        }  
    printf("%s", ccestr);
    return 0;
    }
    
//Ceasear Cipher Decrypt    
    
    char ccdecrypt(char* str, int key)
    {    
        char ccunstr[100]; //Initalises Caesar Cipher Decrypted String
        int ccdstrsize = strlen(str); 
        
        for(int i = 0; i < (ccdstrsize); ++i)
            { //Runs through string until it reaches end of string     
            if (str[i] == ' ') // Checks if character is a space
            {
                ccunstr[i] = ' '; // If true makes a space. 
            }
            else
            {
                ccunstr[i] = ((((str[i] - key + 26) - 65) % 26) + 65); // Takes string takes away key and adds 26 to return to values. Then uses mod to place into Caesar Cipher Decrypted String.
            }  
        
            }

        printf("%s", ccunstr);
        return 0;

    }

    //Subsitution Cipher Encrypt
    
    char scencrypt(char* str, char* keystr)
    {
    char escestr[100]; //Initalises Substitution Cipher Encrypted String 
    int alphatemp; // Initalises temp alpha interger.
    int escstrsize = strlen(str); // Gets string size of inital string.
    
   
    for(int x = 0; x < (escstrsize); x++)
    { 
    if (str[x] == ' ') // Checks if character is a space
        {
            escestr[x] = ' '; // If true makes a space. 
        }
        else
        {
            alphatemp = str[x] - 65; //Turns number to index of 0
            escestr[x] = keystr[alphatemp]; //Takes alphatemp number and subsitutes with esckeystr
        } 
        
    }
    
    printf("%s\n", escestr);
    return 0;
    }
    
    //Subsitution Cipher Decryption
    char scdecrypt(char* str, char* keystr)
    {
    
    char alphabetstr[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //Initalises alphabet for subsititution.
    char dscestr[100]; //Initalises Decrpyted Substitution Cipher
    int dscstrsize = strlen(str); //Finds length of Inital string
    int positiontemp; //Temp variable for position in string
    int alphatemp = 0;
    
 

    
    for(int x = -1; x < (dscstrsize); x++) // Runs through intial string until end
    {
    if (str[x] == ' ') // Checks if character is a space
        {
        dscestr[x] = ' '; // If true makes a space. 
        }
        else
        {
        positiontemp = str[x] - 65 ; //Takes string and turns to 0-25 numbers for string and places in temp.
        //printf("PV: %d\n", positiontemp); //Testing Purposes
            for(int y = 0; positiontemp != (keystr[y] - 65); ++y ) //Takes temp variable and runs through dsckeystr.
            {
                alphatemp = alphatemp + 1; // Adds up to give place in string value
                //printf("AT: %d\n", alphatemp); // Testing Purposes
            }
            dscestr[x] = alphabetstr[alphatemp];//Puts value found for for decryption into string
            alphatemp = 0;// Reintialises value to zero for reuse.   
        }
    }    
    
    printf("%s\n", dscestr);
    return 0;
    }