#include<stdio.h>
#include<conio.h>
static int n=0;
struct STUDENT
{
	int age,roll_no,maths,physics,science,total;
	char name[10];
	float avg;
};
int main()
{
	void add();
	void password();
	void displayAll();
	void record();
	void del();
	void marksheet();
	void modify();
	void changePassword();
	int i,count=0,a,n=0,r,m,ms;

		while(1)
		{
        printf("\n\t\t==================================================\n");
        printf("\n\t\t\t   Student Data Management System\n");
        printf("\n\t\t==================================================\n");
		printf("\n\t\t----------------------");
		printf("\n\t\tSelect an option:");
		printf("\n\t\t----------------------");
		printf("\n\t\t1.Create Student Record");
		printf("\n\t\t2.Delete Student Record");
		printf("\n\t\t3.Modify Student Record");
		printf("\n\t\t4.Generate Student Mark");
		printf("\n\t\t5.Search Record");
		printf("\n\t\t6.Display Records");
		printf("\n\t\t7.Exit");
		printf("\n\t\t----------------------\n");
		printf("\t\tEnter your choice: ");
		scanf("%d",&a);
		switch (a)
		{
			case 1:
			{
				password();
				system("cls");
				add();
				break;
			}
			case 2:
			{
				password();
				system("cls");
				del();
				break;
			}
			case 3:
			{
				password();
				system("cls");
				modify();
				break;
			}
			case 4:
			{
			    system("cls");
				marksheet();
				break;
			}
			case 5:
			{
			    system("cls");
				record();
				break;
			}
			case 6:
			{
			    system("cls");
				displayAll();
				break;
			}
			case 7:
			{
				exit(0);
			}

		}
	}
}
void add()
{
        system("cls");
		int i;
		struct STUDENT s;
		int size;
		FILE *fp;
		size=sizeof(s);
		fp=fopen("student_data.dat","ab");
 		printf("\n\t\tEnter Roll No: ");
		scanf("%d",&s.roll_no);
		printf("\t\tEnter Name: ");
		scanf("%s",s.name);
		printf("\t\tEnter Age: ");
		scanf("%d",&s.age);
		printf("\t\tEnter Math marks: ");
		scanf("%d",&s.maths);
		printf("\t\tEnter Physics marks: ");
		scanf("%d",&s.physics);
		printf("\t\tEnter Science marks: ");
		scanf("%d",&s.science);
		s.total=s.maths+s.physics+s.science;
		s.avg=s.total/3;
		fwrite(&s,size,1,fp);
		fclose(fp);
		printf("\n\t\tRecord Successfully added");
}

void password()
{
	FILE *fp;
	int i=0,count=0;
	printf("\n\t\tEnter password: ");
	char ch[6],c[6],a,b;
	fp=fopen("password.txt","r");
	while((b=getc(fp))!=EOF)
		{
		c[i]=b;
		i++;
		}
	for(i=0;i<6;i++)
	{
	a=getch();
	ch[i]=a;
	printf("*");
	if(ch[i]==c[i])
	{
		count++;
	}
	}
	if(count==6)
	{
		printf("\n\t\tLogin Success");
	}
	else
	{
		printf("\n\t\tLogin Failed");
		password();
	}
	fclose(fp);
}
void displayAll()
{
FILE *fp;
struct STUDENT s;

fp=fopen("student_data.dat","rb");

printf("\n\t========================================================\n\n");
printf("\t\t\t All Student Details\n\n");
printf("\t========================================================\n\n");


while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
		printf("\n\tRoll No:%d",s.roll_no);
		printf("\tName:%s",s.name);
		printf("\tAge:%d",s.age);
		printf("\tTotal:%d\n",s.total);
}
printf("\t========================================================\n\n");

fclose(fp);
}
void record()
{
FILE *fp;
struct STUDENT s;
int id,found=0;
fp=fopen("student_data.dat","rb");
printf("\n\t\tEnter the student roll no:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);
if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
printf("\n\t========================================================\n\n");
printf("\t\t\t Student Record of %d\n\n",s.roll_no);
printf("\t========================================================\n\n");

		printf("\tRoll No:%d ",s.roll_no);
		printf("\tName:%s ",s.name);
		printf("\tAge:%d ",s.age);
		printf("\tTotal:%d \n",s.total);

printf("\t========================================================\n\n");
}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}
void del()
{
FILE *fp,*fp1;
struct STUDENT s,s1;
int id,found=0;

fp=fopen("student_data.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\n\t\tEnter Student Roll No you want to Delete: ");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
}
else
{
fwrite(&s,sizeof(s),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("\t\tSorry No Record Found\n\n");
}
else
{
fp=fopen("student_data.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&s,sizeof(s),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&s,sizeof(s),1,fp);
}
}
fclose(fp);
fclose(fp1);
}
void marksheet()
{
FILE *fp;
struct STUDENT s;
int id,found=0;
fp=fopen("student_data.dat","rb");
printf("\n\t\tEnter Student Roll No: ");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);
if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
printf("\n\t========================================================\n\n");
printf("\t\t\t Student Marksheet of %d\n\n",s.roll_no);
printf("\t========================================================\n\n");

		printf("\tRoll No:%d\t",s.roll_no);
		printf("\tName:%s\n",s.name);
		printf("\tMaths:%d\t",s.maths);
		printf("\tPhysics:%d\t",s.physics);
		printf("\tScience:%d\t\n",s.science);
		printf("\tTotal:%d\t",s.total);
		printf("\tAverage:%2f\n",s.avg);

printf("\t========================================================\n\n");
}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}
void modify()
{
FILE *fp,*fp1;
struct STUDENT s;
int id,found=0;

fp=fopen("student_data.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\n\t\tEnter Student Roll No you want to Modify: ");
scanf("%d",&id);

while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
		printf("\t\tEnter new Roll No: ");
		scanf("%d",&s.roll_no);

		printf("\t\tEnter new Name: ");
		scanf("%s",s.name);
		printf("\t\tEnter new Age: ");
		scanf("%d",&s.age);
		printf("\t\tEnter new math marks: ");
		scanf("%d",&s.maths);
		printf("\t\tEnter new physics marks: ");
		scanf("%d",&s.physics);
		printf("\t\tEnter new science marks:");
		scanf("%d",&s.science);
		s.total=s.maths+s.physics+s.science;
		s.avg=s.total/3;
fwrite(&s,sizeof(s),1,fp1);
}
else
{
fwrite(&s,sizeof(s),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("\t\tSorry No Record Found\n\n");
}
else
{
fp=fopen("student_data.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&s,sizeof(s),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&s,sizeof(s),1,fp);
}

}
fclose(fp);
fclose(fp1);
}
void changePassword()
{
	FILE *fp;
	int i;
	char ch[6],c[6],count=0;
	fp=fopen("password.txt","w");
	printf("\nenter new password with 6 character: ");
	scanf("%s",ch);
	printf("\nre-enter password: ");
	scanf("%s",c);
	for(i=0;i<6;i++)
	{
		if(ch[i]==c[i])
		count++;
	}
	if(count==6)
	{
	fprintf(fp,"%s",ch);
	printf("\npassword successfully changed");
	}
	else
	{
		printf("\nnot matching");
		changePassword();
	}
	fclose(fp);
}




