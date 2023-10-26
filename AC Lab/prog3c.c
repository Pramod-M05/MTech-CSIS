#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define mx 5
int choice;
void playfair(char ch1,char ch2,char key[mx][mx])
{

    int i,j,k,w,x,y,z;
    for(i=0;i<mx;i++)
    {
        for(j=0;j<mx;j++)
        {
           if(ch1==key[i][j])
           {
               w=i;
               x=j;
           }
           else if(ch2==key[i][j])
                   {
                       y=i;
                       z=j;

                   }
        }
    }
if(w==y)
{

    if(choice==1)
    {
        x=(x+1)%5;
        z=(z+1)%5;
    }
else{
    x=((x-1)%5+5)%5;
    z=((z-1)%5+5)%5;
}
printf("%c %c",key[w][x],key[y][z]);
}
if(x==z)
{

    if(choice==1)
    {
        w=(w+1)%5;
        y=(y+1)%5;
    }
else{
    w=((w-1)%5+5)%5;
    y=((y-1)%5+5)%5;
}
printf("%c %c",key[w][x],key[y][z]);
}
else
{

printf("%c %c ",key[w][z],key[y][x]);
}
}

void main()
{
int i,j,k=0,l,m=0,n;
    char key[mx][mx],keystr[10],keyminus[25],str[25]={0};
    char alpha[26] = {
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};
fflush(stdin);
printf("\n  Enter the key");
gets(keystr);
printf("\nEnter the plain  text");
gets(str);
n=strlen(keystr);
for (i = 0; i < n; i++) {
if (keystr[i] == 'j') keystr[i] = 'i';
else if (keystr[i] == 'J') keystr[i] = 'I';
keystr[i] = toupper(keystr[i]);
}
//convert all the characters of plaintext to uppertext
for (i = 0; i < strlen(str); i++) {
if (str[i] == 'j') str[i] = 'i';
else if (str[i] == 'J') str[i] = 'I';
str[i] = toupper(str[i]);

}
    j=0;
    for(i=0;i<26;i++)
    {
        for(k=0;k<n;k++){
            if(keystr[k]==alpha[i])
            break;
        else if(alpha[i]=='J')
            break;

    }
    if(k==n)
    {
        keyminus[j]=alpha[i];
        j++;
    }
    }
    k=0;
    for(i=0;i<mx;i++)
    {
        for(j=0;j<mx;j++)
        {
if(k<n){

        key[i][j] = keystr[k];
k++;
} else {
            key[i][j]=keyminus[m];
            m++;
        }
        printf("%c",key[i][j]);
    }
    printf("\n");
}

printf("\nEntered text :%s\nCipher Text :", str);
for(i=0;i<strlen(str);i++)
{
 if(str[i]=='J')str[i]=='I';
 if(str[i+1]=='\0')playfair(str[i],'X',key);


 else{
        if(str[i+1]=='J')str[i+1]=='I';
 if(str[i]==str[i+1])playfair(str[i],'X',key);

else{
   playfair(str[i],str[i+1],key);
   i++;
}
}
}
}
