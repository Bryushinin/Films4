#include "films2_header.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Enter the file name with \".txt\"."<<endl;

    char st[24];

    cin.getline(st,24);
    cout<<endl;

    Razval(st);

    return 0;
}
