#include <stdio.h>

#define LINE 256
#define WORD 30
#define MAXROWS 250

//function which gets a char pointer and put inside that arr the next word 
int getword(char w[])
{
    char c;
    int i;
    for(i=0;i<WORD;i++)  //maximun iteration is the max word length
    {
        if(scanf("%c", &c) != 1)
        {
            // *(w+i)='\0';
            return -1;
        }
       
       if(c==' '|| c=='\n' || c=='\t' || c=='\0' || c == EOF) //if the char isn't a letter from the word
        {
            *(w+i)='\0';  //end the word by putting \0
            return i;  //return the word's length 
        }
        else  //if this is the next word letter
        {
         *(w+i)=c;  //put it in the next place in the arr
        }
    }
    return i;
}

//function that read a line and insert it to the line char array
int getLine(char line[])
{
    char c;
    int i;
    for(i=0;i<LINE;i++)  //maximun iteration is the max line length
    {
        scanf("%c", &c);  //get the next chat input
        if(c==EOF)  //if this is the end of file
        {
            *(line+i)='\0';  //end the line by putting \0
            return -1;  //return -1
        }
        if(c!='\n')  //if we got the next letter in the line  
        {
            *(line+i)=c;  //add it to the next empty place in the array
        }
        else  //if c is \n
        {
            *(line+i)='\0';  //finish the line array by putting \0
            return i;  //retrun the line length 
        }
    }
    return i;
}

//function that check if str2 is a substring of str1
int substring( char * str1, char * str2)
{
    char c;
    for(int i=0;i<LINE;i++)//while(c!='\0')
    {
        c=*(str1+i);
        if(c=='\0')//if we finished to read the line 
        {
            return 0;
        }
        if(c==*(str2))//if this is the first letter of str2, than we check if str2 is inside str1
        {
            int boolean=1;
            char c2;
            for(int j=0;j<WORD;j++)
            {
                c2=*(str2+j);
                if(c2=='\0')
                {
                    break;
                }
    
                if(c2!=*(str1+i+j))
                {
                    boolean=0;
                    break;
                }

            }
            if(boolean==1)
            {
                return 1;
            }
        }
    }
return 0;
}

//function that gets a char pointer and return the length of the word
int str_len(char* s)
{
    int count=0;
    char c=*s;
    while(c!='\0')
    {
        count++;
        c=*(s+count);
    }
    return count;
}

//function that gets 2 strings (2 chars pointers) and n (number of posibble changes between the two)
int similar (char *s, char *t, int n)
{
   int s_len=str_len(s) - 1;
   int t_len=str_len(t) - 1;
    if(t_len>s_len)  //quick checking 
    {
        return 0;
    }
    int i = 0;
    int j = 0;
    while(i<s_len)  //go through the s pointer word
    {
        // if(*(s+i)==*(t+j))  //if they are similar 
        if(s[i] == t[j])  //if they are similar 
        {
            i++;
            j++;
        }
        else  //if the latters arn not similar
        {
            i++;
            n--;  //decrease the number of changes that we have left
            if(n<0)  //if we over step our changes limit
            {
                return 0;  
            }
        }
    }
    return 1;
}

//function that gets a str (char pointer) and print the all str
void print_str(char* str)
{
    char c=*str;
    int count=0;
     while(c!='\0')
    {
        printf("%c",c);
        count++;
        c=*(str+count);
    }
    printf("\n");
}

//function for a choise 
void a(char* str)
{
    for(int i=0;i<MAXROWS;i++)  //maximun iteration is the number of max number of posibble lines
    {
        char line[LINE];
        if(getLine(line)==-1)
        {
            break;
        }
        if(substring(line,str)==1)
        {
            print_str(line);
        }
    }
}


void b(char* str)
{
    char word[WORD];

    char dummy;
    scanf("%c", &dummy);
    scanf("%c", &dummy);
    scanf("%c", &dummy);
   
//    printf("%s", str);   for debugging needs

    while(getword(word) != -1)
    {
        // printf("%s\n",word);
        if(similar(word, str, 1) == 1)
        {
            printf("%s\n",word);
        }
    }
    if(similar(word, str, 1) == 1)
    {
        printf("%s\n",word);
    }
}



int main()
{
    char temp;
    char str[30];
    getword(str);//gets the string
    char func;
    scanf("%c", &func);
    scanf("%c",&temp);//passes the empty line
    if(func=='a')
    {
        a(str);
    }
    else if(func=='b')
    {
        b(str);
    }
}




