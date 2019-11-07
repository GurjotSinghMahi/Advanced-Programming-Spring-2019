#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>

struct student{
	char name[20];
	int code[6];
	int ability;
	int cons;
	char pname[50];
	int sublist[10];
	int sub_no;
};

struct subject{
	char name[30];
	int dif;
	int var;
};

struct teacher{
	char name[30];
	int tough;
	int var;
	int sublist[10];
	int sub_no;
};

int concat(int v, int a)
{
	int b = (v*10) + a;
	return b;
}

struct student stuseprate(char line[], int size)
{
	int count=0;
	int chap=0;
	int comma[4];
	int colon;
	int chaplist[10];
	for (int s=0;s<size;s++)
	{
		//ASCII value of "," is 44, and ":" is 58
		int value = line[s];
		if(value==44)
		{
			comma[count]=s;
			count=count+1;
		}
		if(value==58)
		{	colon=s;
			for(int i=s;i<size;i++)
			{
				int val = line[i];
				if(val==44)
				{
					chaplist[chap]=i;
					chap=chap+1;
				}
			}
		break;
		}
	}
	/*
	for (int j=0;j<count;j++)
		cout << "simple comma: " <<comma[j] << endl;
	cout << "colon " << colon << endl;
	for(int f=0;f<chap;f++)
		cout << "chapter comma: "<<chaplist[f] << endl;
	*/

	int v=0;
	struct student stu;
	for(int n=0;n<size;n++)
	{
		if(n<comma[0])
		{
			//Put Student Name is Structure
			stu.name[v]=line[n];
			v++;
		}
		else if(n==comma[0])
		{
			stu.name[v]='\0';
			v=0;
			//cout << "Name: "<< stu.name << endl;
		}
		else if(n>comma[0] && n<comma[1])
		{
			//Put student 6 digit code in struct
			int f= line[n] - '0';
			stu.code[v]=f;
			v++;
		}
		else if(n==comma[1])
		{
			v=0;
			//cout << "Student Code: " << stu.code << endl;
		}
		else if(n>comma[1] && n<comma[2])
		{
			//Put Ability in stuct
			int a = line[n] - '0';
			v = concat(v,a);
		}
		else if(n==comma[2])
		{
			if(v>=0 && v<=100)
			{
				stu.ability = v;
				v=0;
			}
			else
			{
				cout << "The Ability range of "<< stu.name << " should be between 0-100"<< endl;
				getch();
				exit(0);

			}
			//v=0;
			//cout << "Ability: "<< stu.ability << endl;
		}
		else if(n>comma[2] && n<comma[3])
		{
			int a = line[n] - '0';
			v = concat(v,a);
			//cout << line[n];
		}
		else if(n==comma[3])
		{
			if(v>=1 && v<=15)
			{
				stu.cons = v;
				v=0;
			}
			else
			{
				cout << "The consistency range of "<< stu.name << " should be between 1-15"<< endl;
				getch();
				exit(0);
			}
			//v=0;
			//cout << "Consistency: "<< stu.cons << endl;
			//cout << endl;
		}
		else if(n>comma[3] && n<colon)
		{
			stu.pname[v]=line[n];
			v++;
			//cout << line[n];
		}
		else if (n==colon)
		{
			stu.pname[v]='\0';
			v=0;
			//cout << "Program Name: "<< stu.pname << endl;
			//cout << endl;
		}
		else
		{
			//cout << "v: " << v << endl;getch();
			int j=n;
			int number = 0;
			while(j<size-1)
			{
				int val = line[j];
				if(val == 44)
				{
					v=0;
					j++;
				}
				else
				{
					int a = line[j] - '0';
					v = concat(v,a);
					//cout << line[j];
					stu.sublist[number]= v;
					//cout << "Subject List Number: " << number << endl;
					j++;
					number++;
				}
			}
		stu.sub_no= number;
		break;
		}
	}


return stu;
}


struct subject subseprate(char line[], int size)
{
	int count=0;
	//int chap=0;
	int comma[3];
	for (int s=0;s<size;s++)
	{
		//ASCII value of "," is 44, and ":" is 58
		int value = line[s];
		if(value==44)
		{
			comma[count]=s;
			count=count+1;
		}
	}

	int v=0;
	int flag=0;
	struct subject sub;
	for(int n=0;n<size;n++)
	{
		if(n<comma[0])
		{
			//Put Student Name is Structure
			sub.name[v]=line[n];
			v++;
		}
		else if(n==comma[0])
		{
			sub.name[v]='\0';
			v=0;
			//cout << "Name: "<< stu.name << endl;
		}
		else if(n>comma[0] && n<comma[1])
		{
			int value = line[n];
			if(value==45)
			{
				flag=1;
				//cout << "v: " << v << endl;
			}
			else
			{
				int a = line[n] - '0';
				v = concat(v,a);
				//cout << "a: " << a << " , v: " << v << endl; getch();
			}
		}
		else if(n==comma[1])
		{
				if(flag==1)
				{
					int f=-v;
					if(f <=15 && f>=-15)
					{
						sub.dif = -v;
						flag = 0;
						v=0;
					}
					else
					{
						cout << "THE DIFFICULTY OF " << sub.name << " SHOULD BE BETWEEN -15 AND 15" << endl;
						flag=0;
						v=0;
						getch();
						exit(0);
					}
				}
				else
				{
					if(v <=15 && v >=-15)
					{
						sub.dif = v;
						v=0;
					}
					else
					{
							cout << "THE DIFFICULTY OF " << sub.name <<" SHOULD BE BETWEEN -15 AND 15" << endl;
							v=0;
							getch();
							exit(0);
					}
				}
		}
		else
		{
			int c=n;
			while(c<size-1)
			{
				int val = line[c];
				if(val==45)
				{
					flag = 1;
					c++;
				}
				else
				{
					int a = line[c] - '0';
					v = concat(v,a);
					//cout << "c: " << c << " ,word: " << line[c] << endl;
					c++;
				}
			}
			if(flag==1)
				{
					int f = -v;
					if(f <=3 && f >=-3)
					{
						sub.var = -v;
						flag = 0;
						v=0;
						break;
					}
					else
					{
						cout << "THE VARIABILTY OF " << sub.name <<" SHOULD BE BETWEEN -3 AND 3" << endl;
						flag=0;
						v=0;
						getch();
						exit(0);
					}
				}
			else
				{
					if(v <=3 && v >=-3)
					{
						sub.var = v;
						v=0;
						break;
					}
					else
					{
						cout << "THE VARIABILTY OF " << sub.name <<" SHOULD BE BETWEEN -3 AND 3" << endl;
						v=0;
						getch();
						exit(0);
					}
				}
		}
	}

return sub;
}

struct teacher teachseprate(char line[], int size)
{
	int count=0;
	int chap=0;
	int comma[2];
	int colon;
	int chaplist[10];
	for (int s=0;s<size;s++)
	{
		//ASCII value of "," is 44, and ":" is 58
		int value = line[s];
		if(value==44)
		{
			comma[count]=s;
			count=count+1;
		}
		if(value==58)
		{	colon=s;
			for(int i=s;i<size;i++)
			{
				int val = line[i];
				if(val==44)
				{
					chaplist[chap]=i;
					chap=chap+1;
				}
			}
		break;
		}
	}
	/*
	cout << line << endl;
	for (int j=0;j<count;j++)
		cout << "simple comma: " <<comma[j] << endl;
	cout << "colon " << colon << endl;
	for(int f=0;f<chap;f++)
		cout << "chapter comma: "<<chaplist[f] << endl;
	*/


	int v=0;
	int flag=0;
	struct teacher sub;
	for(int n=0;n<size;n++)
	{
		if(n<comma[0])
		{
			//Put Student Name is Structure
			sub.name[v]=line[n];
			v++;
		}
		else if(n==comma[0])
		{
			sub.name[v]='\0';
			v=0;
			//cout << "Name: "<< stu.name << endl;
		}
		else if(n>comma[0] && n<comma[1])
		{
			int value = line[n];
			if(value==45)
			{
				flag=1;
				//cout << "v: " << v << endl;
			}
			else
			{
				int a = line[n] - '0';
				v = concat(v,a);
				//cout << "a: " << a << " , v: " << v << endl; getch();
			}
		}
		else if(n==comma[1])
		{
				if(flag==1)
				{
					int f = -v;
					if(f <=15 && f >=-15)
					{
						sub.tough = -v;
						flag = 0;
						v=0;
						//break;
					}
					else
					{
						cout << "THE TOUGHNESS OF " << sub.name <<" SHOULD BE BETWEEN -3 AND 3" << endl;
						flag=0;
						v=0;
						getch();
						exit(0);
					}
				}
				else
				{
					if(v <=15 && v >=-15)
					{
						sub.tough = v;
						v=0;
					}
					else
					{
						cout << "THE TOUGHNESS OF " << sub.name <<" SHOULD BE BETWEEN -15 AND 15" << endl;
						v=0;
						getch();
						exit(0);
					}
				}
		}
		else if(n>comma[1] && n<colon)
		{
			int value = line[n];
			if(value==45)
			{
				flag=1;
				//cout << "v: " << v << endl;
			}
			else
			{
				int a = line[n] - '0';
				v = concat(v,a);
				//cout << "a: " << a << " , v: " << v << endl; getch();
			}
		}
		else if(n==colon)
		{
				if(flag==1)
				{
					int f = -v;
					if(f <=3 && f >=-3)
					{
						sub.var = -v;
						flag = 0;
						v=0;
						//break;
					}
					else
					{
						cout << "THE VARIABILTY OF " << sub.name <<" SHOULD BE BETWEEN -3 AND 3" << endl;
						flag=0;
						v=0;
						getch();
						exit(0);
						//break;
					}
				}
				else
				{
					if(v <=3 && v >=-3)
					{
						sub.var = v;
						v=0;
						//break;
					}
					else
					{
						cout << "THE VARIABILTY OF " << sub.name <<" SHOULD BE BETWEEN -3 AND 3" << endl;
						v=0;
						getch();
						exit(0);
						//break;
					}
				}
		}
		else
		{
			//cout << "v: " << v << endl;getch();
			int j=n;
			int number = 0;
			while(j<size-1)
			{
				int val = line[j];
				if(val == 44)
				{
					v=0;
					j++;
				}
				else
				{
					int a = line[j] - '0';
					v = concat(v,a);
					//cout << line[j];
					sub.sublist[number]= v;
					//cout << "Subject List Number: " << number << endl;
					j++;
					number++;
				}
			}
		sub.sub_no= number;
		break;
		}

	}

return sub;




}



void printstudent (struct student s[], int l)
{
	for(int n=0;n<l;n++)
	{
		cout << s[n].name << '\t';
		int size = sizeof(s[n].code)/sizeof(s[n].code[0]);
		for(int j=0;j<size;j++)
			cout << s[n].code[j];
		cout << '\t';
		cout << s[n].ability << '\t';
		cout << s[n].cons << '\t';
		cout << s[n].pname << '\t';
		cout << "SUBJECT LIST: " ;
		for(int k=0;k<s[n].sub_no;k++)
		{
			cout << s[n].sublist[k] << '\t';
		}
		cout << "Total Subjects: "<< s[n].sub_no << endl;
		cout << endl;
		getch();
	}
}

void printsubject (struct subject s[], int l)
{
	for(int n=0;n<l;n++)
	{
		cout << s[n].name << '\t';
		cout << s[n].dif << '\t';
		cout << s[n].var << '\t';
		cout << endl;
		getch();
	}
}

void printteacher (struct teacher s[], int l)
{
	for(int n=0;n<l;n++)
	{
		cout << s[n].name << '\t';
		cout << s[n].tough << '\t';
		cout << s[n].var << '\t';
		cout << "SUBJECT LIST: " ;
		for(int k=0;k<s[n].sub_no;k++)
		{
			cout << s[n].sublist[k] << '\t';
		}
		cout << endl;
		getch();
	}
}
