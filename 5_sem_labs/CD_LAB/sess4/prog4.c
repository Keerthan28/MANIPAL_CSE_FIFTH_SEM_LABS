#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int curr = 0;
char str[100];
void S();
void L();
void Lprime();
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
    if (str[curr] == '(')
    {
        curr++;
        L();
        if (str[curr] == ')')
        {
            curr++;
            return;
        }
        else
            reject();
    }
    else if (str[curr] == 'a')
    {
        curr++;
        return;
    }
    else
        reject();
}
void L()
{
    S();
    Lprime();
}
void Lprime()
{
    if (str[curr] == ',')
    {
        curr++;
        S();
        //Lprime();
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