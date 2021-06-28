#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int curr = 0;
char str[100];
void S();
void A();
void Aprime();
void B();
void reject()
{
    printf("reject\n");
    exit(0);
}
void accept()
{
    printf("accept\n");
    exit(0);
}
void S()
{
    if (str[curr] == 'a')
    {
        curr++;
        A();
        if (str[curr] == 'c')
        {
            curr++;
            B();
            if (str[curr] == 'e')
            {
                curr++;
                return;
            }
            else
                reject();
        }
        else
            reject();
    }
    else
        reject();
}
void A()
{
    if (str[curr] == 'b')
    {
        curr++;
        Aprime();
    }
    else
        reject();
}
void Aprime()
{
    if (str[curr] == 'b')
    {
        curr++;
        Aprime();
        return;
    }
}
void B()
{
    if (str[curr] == 'd')
    {
        curr++;
        return;
    }
}
int main()
{
    printf("enter string\n");
    scanf("%s", str);
    S();
    if (str[curr] == '$')
    {
        accept();
    }
    else
        reject();
}