#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{

    char plain[10],cipher[10];
    int key,i,length;
    printf("Enter the plain text\n");
    scanf("%s",plain);
    printf("\nEnter the key value\n");
    scanf("%d",&key);
    printf("\n\nPlain text:%s",plain);
    printf("\n\n\tEncrypted text");

    for(i=0,length=strlen(plain);i<length;i++)
    {
        cipher[i]=plain[i]+key;
        if(isupper(plain[i]) && cipher[i]>'Z')
            cipher[i]=cipher[i]-26;
        if(islower(plain[i])  && cipher[i]>'z')
            cipher[i]=cipher[i]-26;
        printf("%c",cipher[i]);
    }
    printf("\n\nAfter Decryption\n");
    for(i=0;i<length;i++)
    {

        plain[i]=cipher[i]-key;
        if(isupper(cipher[i]) && plain[i] < 'A')
            plain[i]=plain[i]+26;
        if(islower(cipher[i]) && plain[i] < 'a')
            plain[i]=plain[i]+26;
        printf("%c",plain[i]);
    }
    return 0;
    }



