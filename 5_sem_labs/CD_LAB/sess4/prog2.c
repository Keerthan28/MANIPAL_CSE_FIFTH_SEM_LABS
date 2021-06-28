#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int curr = 0;
char str[100];
void S();
void U();
void V();
void W();
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
    U();
    V();
    W();
}
void U()
{
    if (str[curr] == '(')
    {
        curr++;
        S();
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
        S();
        if (str[curr] == 'b')
        {
            curr++;
            return;
        }
        else
            reject();
    }
    else if (str[curr] == 'd')
    {
        curr++;
        return;
    }
    else
        reject();
}
void V()
{
    if (str[curr] == 'a')
    {
        curr++;
        V();
        return;
    }
}
void W()
{
    if (str[curr] == 'c')
    {
        curr++;
        W();
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