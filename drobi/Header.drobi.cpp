#include "Header.drobi.h"
#include<iostream>
#include<cmath>
#include<locale.h>

using namespace std;

int NOD(int a, int b){
    if(b == 0)
        return a;
    return NOD(b, a % b);
}

void Input_1(int &ch1, int &zn1)
{
    setlocale(LC_ALL, "Russian");
    cout<<"Введите числитель первой дроби "<<endl;
    cin>>ch1;
    do
    {
        cout<<"Введите знаменатель первой дроби"<<endl;
        cin>>zn1;
    }while(zn1==0);
}

void Input_2(int &ch1, int &zn1,int &ch2, int &zn2)
{
    cout<<"Введите числитель первой дроби "<<endl;
    cin>>ch1;
    do
    {
        cout<<"Введите знаменатель первой дроби"<<endl;
        cin>>zn1;
    }while(zn1==0);
    cout<<"Введите числитель второй дроби "<<endl;
    cin>>ch2;
    do
    {
        cout<<"Введите знаменатель второй дроби"<<endl;
        cin>>zn2;
    }while(zn2==0);
}

void Reduction(int &ch_new, int &zn_new)
{
    int k = NOD(abs(ch_new), abs(zn_new));
    ch_new/=k;
    zn_new/=k;
}

void Reduction_1(int &ch_new, int &zn_new)
{

    cout<<ch_new<<"/"<<zn_new<<" = ";
    int k = NOD(abs(ch_new), abs(zn_new));
    ch_new/=k;
    zn_new/=k;
    cout << ch_new<<"/"<<zn_new << endl;
}

void Summa(int ch1, int zn1,int ch2, int zn2)
{
    int ch_new = (ch1*zn2) + (ch2*zn1);
    int zn_new = (zn1*zn2);
    Reduction(ch_new, zn_new);
    if(ch_new<0 && zn_new<0)
    {
        ch_new=-ch_new;
        zn_new=-zn_new;
    }
    cout<<ch1<<"/"<<zn1<<" + "<<ch2<<"/"<<zn2<<" = "<<ch_new<<"/"<<zn_new<<endl;
}

void Raznost(int ch1, int zn1,int ch2, int zn2)
{
    int ch_new = (ch1*zn2) - (ch2*zn1);
    int zn_new = (zn1*zn2);
    Reduction(ch_new, zn_new);
    if(ch_new<0 && zn_new<0)
    {
        ch_new=-ch_new;
        zn_new=-zn_new;
    }
    cout<<ch1<<"/"<<zn1<<" - "<<ch2<<"/"<<zn2<<" = "<<ch_new<<"/"<<zn_new<<endl;
}

void Chastnoe(int ch1, int zn1,int ch2, int zn2)
{
    int ch_new = ch1*zn2;
    int zn_new = zn1*ch2;
    Reduction(ch_new, zn_new);
    if(ch_new<0 && zn_new<0)
    {
        ch_new=-ch_new;
        zn_new=-zn_new;
    }
    cout<<"("<<ch1<<"/"<<zn1<<")"<<" / "<<"("<<ch2<<"/"<<zn2<<")"<<" = "<<ch_new<<"/"<<zn_new<<endl;
}

void Proizvedenie(int ch1, int zn1,int ch2, int zn2)
{
    int ch_new = ch1*ch2;
    int zn_new = zn1*zn2;
    Reduction(ch_new, zn_new);
    if(ch_new<0 && zn_new<0)
    {
        ch_new=-ch_new;
        zn_new=-zn_new;
    }
    cout<<ch1<<"/"<<zn1<<" * "<<ch2<<"/"<<zn2<<" = "<<ch_new<<"/"<<zn_new<<endl;
}

void Des_drob(int ch, int zn)
{
    double C_rez=ch*1.0 / zn;
    cout<<ch<<"/"<<zn<<" = "<< C_rez << endl;
}

void Sravnenie(int ch1, int zn1,int ch2, int zn2)
{
    int ch1_new = ch1*zn2;
    int ch2_new = ch2*zn1;
    int zn_new = (zn1*zn2);
    if(ch1_new<ch2_new) cout<<ch1<<"/"<<zn1<<" < "<<ch2<<"/"<<zn2<<endl;
    else
    {
        if(ch1_new==ch2_new) cout<<ch1<<"/"<<zn1<<" == "<<ch2<<"/"<<zn2<<endl;
        else cout<<ch1<<"/"<<zn1<<" > "<<ch2<<"/"<<zn2<<endl;
    }
}

