#include <stdio.h>
#define LINE 256
#define WORD 30
#define MAXROWS 250


int getword(char w[])
{
    char c;
    for(int i=0;i<WORD;i++)
    {
        scanf("%c", &c);
        if(c==EOF)
        {
            *(w+i)='\0';
            printf("eof");
             return -1;
        }
        if(c==' '|| c=='\n' || c=='\t' || c=='\0')
        {
            *(w+i)='\0';
            return i;
        }
        else
        {
         *(w+i)=c;
        }
    }
}
int getLine(char line[])
{
    char c;
    for(int i=0;i<LINE;i++)
    {
        scanf("%c", &c);
        if(c==EOF)
        {
            *(line+i)='\0';
            return -1;
        }
        if(c!='\n')
        {
            *(line+i)=c;
        }
        else
        {
            *(line+i)='\0';
            return i;
            break;
        }
    }
}

int substring( char * str1, char * str2)//checking if str2 is inside str1
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

int similar (char *s, char *t, int n)
{
   int s_len=str_len(s);
   int t_len=str_len(t);
    if(t_len>s_len)
    {
        return 0;
    }
    int i,j=0;
    while(i<s_len)
    {
        if(*(s+i)==*(t+j))
        {
            i++;
            j++;
        }
        else
        {
            i++;
            n--;
            if(n<0)
            {
                return 0;
            }
        }
    }
        return 1;
}

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

void a(char* str)
{
    for(int i=0;i<MAXROWS;i++)
    {
        char line[LINE];
        int boolean1=getLine(line);
        if(boolean1==-1)
        {
            break;
        }
        int boolean2=substring(line,str);
        if(boolean2==1)
        {
            print_str(line);
        }
    }
}


void b(char* str)
{
    char word[WORD];
    int boolean1=getword(word);
    int i=0;
    while(boolean1!=-1&& i<35)
    {
       printf("%s\n",word);//print_str(word);
       boolean1= getword(word);
       i++;
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