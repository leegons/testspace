#include<stdio.h>
#include<stdlib.h>
#include <algorithm>

using namespace std;
char fh[]="<=>";
typedef unsigned long BigInt;

struct nod{
    BigInt a,b,c;
    int f,d;
}as[10010];

int cmp(nod a,nod b){
    if(a.c>b.c)return 1;
    if(a.c<b.c)return 0;
    if(a.f>b.f)return 1;
    if(a.f<b.f)return 0;
    return a.d>b.d;
}

int ff(BigInt a,BigInt b){
    if(a>b)return 2;
    if(a<b)return 0;
    return 1;
}

int main(){
    freopen("data.in","r",stdin);
    int tcase,n;
    scanf("%d", &tcase);
    while(tcase-->0 && scanf("%d",&n) != EOF) {
        for(int i=0;i<n;i++){
            scanf("%ld%ld", &as[i].a, &as[i].b);
            as[i].c=as[i].a+as[i].b;
            as[i].f=ff(as[i].a,as[i].b);
            as[i].d=i;
        }
        sort(as,as+n,cmp);
        for(int i=0;i<n;++i){
            printf("%ld+%ld=[%c%ld]\n",as[i].a,as[i].b,fh[as[i].f],as[i].c);
        }puts("");
    }
    fclose(stdin);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
