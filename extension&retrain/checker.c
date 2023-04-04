#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool check[100];
char origin[100005], changed[200005];
bool IsNum(char c)
{
    if (c <= '9' && c >= '0')
        return true;
    else
        return false;
}
int converse(int i, char tmp[])
{
    int result = 0;
    result = (tmp[i] - '0') * 10 + (tmp[i + 1] - '0');
    return result;
}
int contra_converse(int i, char tmp[])
{
    int result = 0;
    result = (tmp[i] - '0')  + (tmp[i + 1] - '0')* 10;
    return result;
}
bool CheckIt(char origin[], char changed[], int n)
{
    int i = 0, j = 0, k = strlen(changed) - 1, tmp;
    int number_count=0;
    while (i < k)
    {
        if (changed[i] != changed[k])
        {
            return false;
        } // basic check:origin and changed,changed itself
        if (origin[j] == '?')
        {
            if (origin[n - 1 - j] != '?')
            {
                if (changed[i] != origin[n - 1 - j])
                    {
                        return false;
                    }
            }
        }
        else if (changed[i] != origin[j])
            {
                return false;
            }
        if (IsNum(changed[i])&&(!IsNum(origin[j])&&!IsNum(origin[n-1-j])))
        {   number_count++;
            if (!IsNum(changed[i + 1]) || origin[n - 1 - j] != '?')
                {
                    return false;
                }
            tmp = converse(i, changed);
            if (!check[tmp])
                check[tmp] = true;
            else
                {
                    tmp=contra_converse(i, changed);
                    if(!check[tmp])check[tmp] = true;
                    else return false;
                }
            i++;
            k--;
            if (changed[i] != changed[k])
                {
                    return false;
                }
        }
        i++;
        j++;
        k--;
    }
    if((strlen(changed)-number_count*2)!=n)
        return false;
    else return true;
}
int main()
{
    int group, n;
    scanf("%d", &group);
    for (int i = 1; i <= group; i++)
    {
        scanf("%d%s%s", &n, origin, changed);
        bool it = CheckIt(origin, changed, n);
        if (it)
            printf("Correct.\n");
        else
            printf("Wrong Answer!\n");
        memset(check,0,sizeof(check));
    }
    return 0;
}
/*
1
13
m?yi??k??iya?
mayi0001k1000iyam
*/
