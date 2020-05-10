#include "films2_header.h"

int Compare(string a, string b)
{
    //Returns 1 in case year in the film "a" <= than the year in the film 'b' and 0 in other case.
    /*if(( a.size()==0 )||( b.size()==0))
    {
        cout<<"Пустые строки сравниваем, командир."<<endl;
    }*/
    int i;
    for(i=0;a[i]!='(';++i);
    int ya=1000*(a[i+1]-'0')+100*(a[i+2]-'0')+10*(a[i+3]-'0')+(a[i+4]-'0');
    for(i=0;b[i]!='(';++i);
    int yb=1000*(b[i+1]-'0')+100*(b[i+2]-'0')+10*(b[i+3]-'0')+(b[i+4]-'0');
    /*if(ya==2014 || yb==2014)
        cout<<"Т"<<endl;*/
    return(ya<=yb);
}

void Razval(char* st)
{
    string st1,st2;
    int f=1,e=1;
    //cout<<"r";
    ifstream src(st);
    ofstream f1("file1.txt");
    ofstream f2("file2.txt");

    getline(src, st1);
    getline(src, st2);
    f1<<st1<<endl;
    while(!src.eof())
    {
        if(Compare(st1,st2))
        {
            if(f==1)
                f1<<st2<<endl;
            else
                f2<<st2<<endl;
        }
        else
        {
            if(f==1)
                f2<<st2<<endl;
            else
                f1<<st2<<endl;
            f+=e;
            e*=-1;
        }
        st1=st2;
        getline(src, st2);
        if(st2=="")
            break;
    }
    if(Compare(st1,st2))
        {
            if(f==1)
                f1<<st2<<endl;
            else
                f2<<st2<<endl;
        }
        else
        {
            if(f==1)
                f2<<st2<<endl;
            else
                f1<<st2<<endl;
            f+=e;
            e*=-1;
        }
    //cout<<"e";
    src.close();
    f1.close();
    f2.close();

    Shozhdenie(st);
}

void Shozhdenie(char* st)
{
    string st1,st2,SeriesSignal="(0000";

    ifstream f1("file1.txt");
    ifstream f2("file2.txt");
    ofstream yama(st);

    getline(f1,st1);
    if(!f2.eof()) getline(f2,st2);
    if(f2.eof())
        while(!f1.eof())
        {
            if(st1.size()) yama<<st1<<endl;
            if(!f1.eof()) getline(f1,st1);

        }

    else
    {

        while((!f1.eof())&&(!f2.eof()))
        {
            //cout<<"a";
            if(Compare(st1,st2))
            {
                if(Compare(SeriesSignal,st1))
                {
                    if(st1.size()) yama<<st1<<endl;
                    SeriesSignal=st1;
                    if(!f1.eof()) getline(f1,st1);
                    //cout<<"F";
                }
                else
                {

                    while(Compare(SeriesSignal,st2))
                    {
                        /*if(!Compare(SeriesSignal,st2))
                            break;*/
                        if(st2.size()) yama<<st2<<endl;
                        SeriesSignal=st2;
                        if(!f2.eof()) getline(f2,st2);
                        /*cout<<"D";
                        cout<<endl<<SeriesSignal<<endl<<st2;*/
                        if(st2=="")
                            break;

                    }
                    SeriesSignal="(0000";
                }
            }

            else

            {
                if(Compare(SeriesSignal,st2))
                {
                    if(st2.size()) yama<<st2<<endl;
                    SeriesSignal=st2;
                    if(!f2.eof()) getline(f2,st2);
                    //cout<<"G";
                }
                else
                {

                    while(Compare(SeriesSignal,st1))
                    {
                        /*if(!Compare(SeriesSignal,st1))
                            break;*/
                        if(st1.size()) yama<<st1<<endl;
                        SeriesSignal=st1;
                        if(!f1.eof()) getline(f1,st1);
                        //cout<<"E";
                        if(st1=="")
                            break;
                    }
                    SeriesSignal="(0000";
                }
            }
        }

        while(!f1.eof())
        {
            if(st1.size()) yama<<st1<<endl;
            if(!f1.eof()) getline(f1,st1);
            //cout<<"b";
        }

        while(!f2.eof())
        {
            if(st2.size()) yama<<st2<<endl;
            if(!f2.eof()) getline(f2,st2);
            //cout<<"c";
        }

        Razval(st);
    }
    /*yama.close();
    f2.close();
    f1.close();*/
}
