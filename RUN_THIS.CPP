#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include"function.h"

struct output{
	char student[30];
	char teacher[30];
	int subject_no;
	int mean;
	int sd;
	int fail_count;
	int subject[10];
};

void output_processing(struct student stu[], struct teacher tea[], struct subject sub[], int sn, int tn, int sbn)
{
	//Run this loop for all students
	for(int n=0;n<sn;n++)
	{
		cout << "Student Name: " << stu[n].name << endl;
		for(int a=0; a<stu[n].sub_no;a++) //searching for all student subjects
		{
			randomize();
			int subject = stu[n].sublist[a];  //Total students students
			//See which teacher is teaching subject
			int teacher_teaching[10];
			int b=0;
			int flag=0;
			for(int c=0;c<tn;c++)    //teacher loop
			{
				for(int d=0;d<tea[c].sub_no;d++) //searching teacher matching to student subjects
				{
					//int tea[c].sublist[d]<< endl;
					if(subject==tea[c].sublist[d])
					{
						//cout << "Subject: " << subject << " ,tea[c].sublist[d]: "<< tea[c].sublist[d]  << endl;
						teacher_teaching[b]=c;
						b++;
						flag=1;
					}
				}
			}//we got which teacher teaches which subject in teacher_teaching array
			if(flag==1)
			{
				int num = random(b);
				//teacher name -> tea[teacher_teaching[num]].name
				cout << " Sub No: "<< subject << " ,Tcher: " << tea[teacher_teaching[num]].name << " ,Sub: " << sub[subject-1].name << endl;
				//cout << "student ability "<< stu[n].ability << " ,sub diffculty: " <<  (sub[subject-1].dif) << " ,teacer toughness: " <<  (tea[teacher_teaching[num]].tough)<< endl;
				int m = stu[n].ability - (sub[subject-1].dif) - (tea[teacher_teaching[num]].tough);
				int std = (stu[n].cons) + (sub[subject-1].var) + (tea[teacher_teaching[num]].var);
				cout << "Mean: " << m << " ,Std dev: " << std << endl;
				getch();
				b=0;flag=0;
			}
		}
	}
}


void main()
{
clrscr();

student s[10];
subject sub[10];
teacher tea[10];

FILE *sfile;
char line[100];

sfile = fopen("student.txt","r");
int sn=0;
while(fgets(line, sizeof(line), sfile) != NULL)
{
	//cout <<"LINE: " << line << endl;
	s[sn] = stuseprate(line, strlen(line));
	sn++;
	//getch();
}
fclose(sfile);

//cout << endl;
cout << "Total Students: " << sn << endl;
//printstudent(s,sn);


sfile = fopen("Subjects.txt","r");
int subn=0;
while(fgets(line, sizeof(line), sfile) != NULL)
{
	//cout <<"LINE: " << line << endl;
	sub[subn] = subseprate(line, strlen(line));
	subn++;
	//getch();
}
fclose(sfile);

//cout << endl;
cout << "Total Subjects: " << subn << endl;
//printsubject(sub,subn);


sfile = fopen("teachers.txt","r");
int tean=0;
while(fgets(line, sizeof(line), sfile) != NULL)
{
	//cout <<"LINE: " << line << endl;
	tea[tean] = teachseprate(line, strlen(line));
	tean++;
	//getch();
}
fclose(sfile);

//cout << endl;
cout << "Total Teachers: " << tean << endl;
//printteacher(tea,tean);

output_processing(s, tea, sub, sn, tean, subn);

getch();
}