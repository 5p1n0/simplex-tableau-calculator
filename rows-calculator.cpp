#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <boost/rational.hpp>
using namespace std;
using R = boost::rational<int>;

class rows
{
    R* mainRow;
    R* secondaryRow;
    R* resultRow;
    R coef;
    int n, i;

    public:
        void acquire_cols();
        void acquire_main_row();
        void acquire_changing_row();
        void acquire_coefficient();
        void calc();
};

void rows::acquire_cols()
{
    cout<<"\nEnter the number of columns\n";
    cin>>n;

    mainRow = new R[n];
    secondaryRow = new R[n];
    resultRow = new R[n];
}


void rows::acquire_changing_row() 
{
    cout<<"\nEnter the row to change\n";

    for (i = 0; i < n; i++)
    {
        cout<<"\nEnter the column value n/d:\n";

        int n, d;
        string val;
        cin>>val;
        int pos = val.find('/');


        if (pos != string::npos)
        {
            string tmp(val.begin(), find(val.begin(), val.end(), '/'));
            n = stoi(tmp);
            d = stoi(val.substr(pos + 1));
            secondaryRow[i] = R(n, d);
        }
        else
        {
            n = stoi(val);
            secondaryRow[i] = R(n);
        }
    }

    cout<<"\nDone\n";
}

void rows::acquire_main_row() 
{
    cout<<"\nEnter the pivot row\n";

    for (i = 0; i < n; i++)
    {
        cout<<"\nEnter the column value n/d:\n";

        int n, d;
        string val;
        cin>>val;
        int pos = val.find('/');

        if (pos != string::npos)
        {
            string tmp(val.begin(), find(val.begin(), val.end(), '/'));
            n = stoi(tmp);
            d = stoi(val.substr(pos + 1));
            mainRow[i] = R(n, d);
        }
        else
        {
            n = stoi(val);
            mainRow[i] = R(n);
        }
    }

    cout<<"\nDone \n";
}

void rows::acquire_coefficient() 
{
    cout<<"\nEnter the coefficient\n";

    int n, d;
    string val;
    cin>>val;
    int pos = val.find('/');

    if (pos != string::npos)
    {
        string tmp(val.begin(), find(val.begin(), val.end(), '/'));
        n = stoi(tmp);
        d = stoi(val.substr(pos + 1));
        coef = R(n, d);
    }
    else
    {
        n = stoi(val);
        coef = R(n);
    }

    cout<<"\nDone \n";
}

void rows::calc() 
{
    cout<<"Result \n";
    for (i = 0; i < n; i++)
    {
        resultRow[i] = secondaryRow[i] + coef*mainRow[i];
        cout<<" \n"<<resultRow[i]<<" \n";
    }
    cout<<"\n";
}


int main()
{
    rows rows;
    rows.acquire_cols();
    rows.acquire_main_row();
    rows.acquire_changing_row();
    rows.acquire_coefficient();
    rows.calc();

    while(1)
    {
        rows.acquire_changing_row();
        rows.acquire_coefficient();
        rows.calc();
    }

    return 0;

}
