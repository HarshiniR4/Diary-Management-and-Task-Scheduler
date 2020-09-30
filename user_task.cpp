#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include <fstream>
#include"user.h"
#include"login.h"
#include"user_task.h"

using namespace std;

//Task entry
struct task
{
    char date[15];
    char time[10];
    char name[50];
    char deadline[30];
    char status[10];
};

void add_task(string username)
{
    FILE *fp;
    struct task t;
    int n=username.length(),x=0;
    char filename[n+1], another='y', time[10];
    strcpy(filename, username.c_str());
    fp= fopen(filename, "ab+");
    if(fp==NULL)
    {
        fp=fopen(filename, "wb+");
        if(fp==NULL)
        {
            cout<<"\t\tSYSTEM FAIL\n";
            return;
        }
    }
    do
    {
        cout<<"\n\t\tEnter time of task:  ";
        fflush(stdin);
        gets(time);
        rewind(fp);
        while(fread(&t,sizeof(t),1,fp)==1)
        {
            if(strcmp(t.time,time)==0)
            {
                cout<<"\n\t\t------Task Clash------\n";
                x=1;
            }
        }
        if(x==0)
        {
            strcpy(t.time,time);
            cout<<"\n\t\tEnter Date of Task:  ";
            fflush(stdin);
            gets(t.date);
            cout<<"\n\t\tEnter Name of task:  ";
            fflush(stdin);
            gets(t.name);
            cout<<"\n\t\tEnter deadline for task:  ";
            fflush(stdin);
            gets(t.deadline);
            if(strcmp(t.deadline, t.time)<0)
            {
                cout<<"\n\t\tOops! Deadline set wrongly, enter again  ";
                gets(t.deadline);
            }
            cout<<"\n\t\tEnter Status of task:  ";
            fflush(stdin);
            gets(t.status);
            fwrite(&t, sizeof(t), 1, fp);
            cout<<"\n\t\t-------------Task Saved------------\n";
        }
        fclose(fp);
        cout<<"\n\t\tWould you like to enter another task for today?[y/n]   ";
        cin>>another;
    }while(another=='y'|| another=='Y');
    return;
}

//void view_sch(string username)
//{
//    FILE *fpt;
//    struct task s;
//    int n=username.length();
//    char filename[n+1], another='y', time[10];
//    strcpy(filename, username.c_str());
//
//}
void user_task(string username)
{
    cout<<"\t\t\t "<<username<<" TASK Scheduler\n";
    int ch;
    do
    {
        cout<<"\t\t\tMenu\n";
        cout<<"\t\t1.Add task\n";
        cout<<"\t\t2.Modify task\n";
        cout<<"\t\t3.Delete task\n";
        cout<<"\t\t4.Update Status\n";
        cout<<"\t\t5.View full schedule\n";
        cout<<"\t\t6.Return to User Home page\n";
        cout<<"\n\t\tEnter your choice:   ";
        cin>>ch;
        cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
        switch(ch)
        {
            case 1: add_task(username);
                    break;
            case 6: return;
        }
    }while(ch);
}

