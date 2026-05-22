#include<stdio.h>
#include<string.h>

int main(){
    int table[126];
    char t[100],p[25];
    int n,m,i,j,k,flag=0;

    printf("Enter the text : ");
    scanf("%s",t);

    printf("Enter the pattern : ");
    scanf("%s",p);

    n=strlen(t);
    m=strlen(p);

    for(i=0;i<126;i++)
        table[i]=m;

    for(j=0;j<m-1;j++)
        table[p[j]]=m-1-j;

    i=m-1;

    while(i<=n-1){
        k=0;

        while(k<=m-1&&p[m-1-k]==t[i-k])
            k++;

        if(k==m){
            printf("The position of the pattern is %d\n",i-m+2);
            flag=1;
            break;
        }else{
            i=i+table[t[i]];
        }
    }

    if(!flag)
        printf("Pattern is not found in the given text");

    return 0;
}