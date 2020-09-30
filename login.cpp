#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include <fstream>
#include <fstream>
#include "admin.h"
#include"user.h"
using namespace std;

string user, pass;


//Login Checker
int LoginCheck (string user, string pass)
{
    ifstream file;
    string username, password;
    int n=0;
    file.open("users.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> username >> password;
            n++;
            if (user==username && pass==password)
                return n;
        }
    }
    else
    {
        cout << "file not open" << endl;
    }

    return 0;
    file.close();
}

//Setting account username and password
void Register()
{
    ifstream file;
    ofstream newuser;
    string username;
    char pass[32]={0}, passwordconfirm[32]={0};
    int i;
    file.open("users.txt", ios::app);
    newuser.open("users.txt", ios::app);
    bool uservalid=false;
    while (!uservalid)
    {
        cout << "\tUsername: ";
        cin >> username;
        cout << "\tPassword: ";
        i=0;
        pass[0]=getch();
        while(pass[i]!='\r')
        {
            if(pass[i]=='\b')
            {
                i--;
                cout<<"\b";
                cout<<" ";
                cout<<"\b";
                pass[i]=getch();
            }
            else
            {
                cout<<"*";
                i++;
                pass[i]=getch();
            }
        }
        pass[i]='\0';
        cout << "\n\tConfirm password: ";
        i=0;
        passwordconfirm[0]=getch();
        while(passwordconfirm[i]!='\r')
        {
            if(passwordconfirm[i]=='\b')
            {
                i--;
                cout<<"\b";
                cout<<" ";
                cout<<"\b";
                passwordconfirm[i]=getch();
            }
            else
            {
                cout<<"*";
                i++;
                passwordconfirm[i]=getch();
            }
        }
        passwordconfirm[i]='\0';
        int m=0;
        int k=0;
        while (file >> user >> pass)
        {
            m++;
            if (username!=user)
                k++;
        }
        if (m==k && strcmp(pass,passwordconfirm)==0)
            uservalid=true;
        else if (m!=k)
            cout << "\n\t\tThere is already a user with this username.\n" << endl;
        else
            cout << "\n\t\tThe passwords given do not match\n" << endl;
    }
    newuser << username << " " << pass << endl;;
    newuser.close();
    file.close();
}



int ad_login()
{
        int loginattempts=0,l=0,i;
        ifstream userfile;
        userfile.open("users.txt");
        char pass[32]={0};
        string user, password;
        while (LoginCheck(user, password)==0)
        {
            loginattempts++;
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            i=0;
            pass[0]=getch();
            while(pass[i]!='\r')
            {
                if(pass[i]=='\b')
                {
                    i--;
                    cout<<"\b";
                    cout<<" ";
                    cout<<"\b";
                    pass[i]=getch();
                }
                else
                {
                    cout<<"*";
                    i++;
                    pass[i]=getch();
                }
            }
            pass[i]='\0';
            std::string password(pass);
            if (LoginCheck(user, password)!=0)
            {
                cout << "\t\t\t\tWelcome " << user << "." << endl;
                l=1;
                break;
            }
            else if (loginattempts==3)
            {
                cout << "Maximum login attempts exceeded.Sorry!" << endl;
                l=0;
                break;
            }
            else
            {
                cout << "Invalid username/password combination" << endl;
                l=0;
            }
        }
        userfile.close();
        return l;
}


string user_login()
{
        int loginattempts=0,l=0,i;
        ifstream userfile;
        userfile.open("users.txt");
        char pass[32]={0};
        string user, password, nil="NIL";
        while (LoginCheck(user, pass)==0)
        {
            loginattempts++;
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            i=0;
            pass[0]=getch();
            while(pass[i]!='\r')
            {
                if(pass[i]=='\b')
                {
                    i--;
                    cout<<"\b";
                    cout<<" ";
                    cout<<"\b";
                    pass[i]=getch();
                }
                else
                {
                    cout<<"*";
                    i++;
                    pass[i]=getch();
                }
            }
            pass[i]='\0';
            std::string password(pass);
            if (LoginCheck(user, password)!=0)
            {
                cout << "\t\t\t\tWelcome " << user << "." << endl;
                l=1;
                break;
            }
            else if (loginattempts==3)
            {
                cout << "Maximum login attempts exceeded.Sorry!" << endl;
                l=0;
                break;
            }
            else
            {
                cout << "Invalid username/password combination" << endl;
                l=0;
            }
        }
        userfile.close();
        if(l=1)
        {
            return user;
        }
        else
        {
            return nil;
        }
}
