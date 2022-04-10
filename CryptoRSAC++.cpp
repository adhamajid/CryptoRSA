#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//#include<conio.h>
#include<stdio.h>

using namespace std;

long int p,q,n,r,t,i,s,flag,e[100],d[100],temp[100],j,m[100],en[100],x,y;
char kata[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
int hitmod(int a,int b,int n);
int phi(int n);
int GCD(int x,int y);

int main()
{
cout << ":::::::::::::::::::Chinese Remainder Theorem:::::::::::::::::::"<< endl << endl;
 cout << "\n Masukkan bilangan prima p : ";
 cin>>p;
 flag=prime(p);
  if(flag == 0)
  {cout<<"\n inputan anda salah \n";
   exit(1); }



 cout<<"\n Masukkan bilangan prima q : ";
 cin>>q;
 flag=prime(q);
  if(flag == 0 || p == q)
  {cout<<"\n inputan anda salah \n";
   exit(1); }

 n=p*q;
 cout<<"\n Diperoleh bilangan n = "<<n<<endl;

 cout<<"\n Masukkan kata : ";
 fflush(stdin);
 cin>>kata;

    for(i=0;kata[i] !=__null;i++)
       m[i]=kata[i];

    hitmod(p,q,n);
    cout<<"\n ::::Hasil CRT:::: \n";
    cout<<"\n Nilai untuk x yang diperoleh adalah : "<<hitmod(p,q,n)<<endl;
    encrypt();

 //getch();
}

int prime(long int pr)
{ int i;
 j=sqrt(pr);
 for(i=2;i<=j;i++)
 {  if(pr%i == 0)
   return 0; }
  return 1; }

long int cd(long int x)
{ long int k = 1;
 while (1)
 {  k=k+t;
  if(k%x == 0)
  return(k/x); } }

void encrypt()
{ long int pt, ct, key = hitmod(p,q,n), k, len;
 i = 0;
 len = strlen(kata);
 while (i != len)
 {  pt=m[i];
  pt=pt-96;
  k=1;
   for(j=0;j<key;j++)
   {    k=k*pt;
    k=k%n;   }
    temp[i]=k;
    ct=k+96;
    en[i]=ct;
     i++;  }
  en[i] = -1;
  cout << "\n Hasil enkripsi : ";
   for (i = 0; en[i] != -1; i++)
    printf("%c", en[i]);
}

int hitmod(int a,int b,int n)
{ int p,q,r;
   p=a%n;
   q=b%phi(n);
   r=pow(p,q);
   r=r%n;
   return r; }

int phi(int n)
{ int i,s=0;
   for (i=1;i<n;i++){
   if (GCD(i,n)==1)
    s++;   }
   return s;}

int GCD(int x,int y)
{ int t,s;
   if (x<y)
{   t=x;
      x=y;
      y=t;   }
   s=x%y;
   while(s!=0)
{    x=y;
      y=s;
      s=x%y;   }
   return y;
}
