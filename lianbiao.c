#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
	char id[9];
	char name[13];
	char sex;
	int age;
	struct Student *next;
};

void setStu(struct Student *p,char *id,char *name,char sex,int age);
void printLink(struct Student *);
void printStu(const struct Student *p);
struct Student *ordLink(struct Student *head,struct Student *pnew);

int main()
{
	struct Student *head=NULL;
	struct Student *pnew=NULL;
	char temp_id[9];
	char temp_name[13];
	char temp_sex;
	int temp_age;
	int sel;
	while(1)
	{
		printf("是否输入学生信息 1.输入 0.退出\n");
		scanf("%d",&sel);
		if(sel==0)
		{
			break;
		}
		printf("请输入学号：");
		scanf("%s",&temp_id);
		printf("请输入姓名：");
		scanf("%s",&temp_name);
		printf("请输入性别：");
		scanf(" %c",&temp_sex);
		printf("请输入年龄：");
		scanf("%d",&temp_age);
		pnew=(struct Student *)malloc(sizeof(struct Student));
		setStu(pnew,temp_id,temp_name,temp_sex,temp_age);
		//有序插入
		head=ordLink(head,pnew);
	}
	printLink(head);
	return 0;
}
//录入学生信息
void setStu(struct Student *p,char *id,char *name,char sex,int age)
{
	strcpy((*p).id,id);
	strcpy((*p).name,name);
	(*p).sex=sex;
	(*p).age=age;
}
//输出列表
void printLink(struct Student *head)
{
	struct Student *pnew=head;
	while(pnew!=NULL)
	{
		printStu(pnew);
		pnew=pnew->next;
	}
}

void printStu(const struct Student *p)
{
	printf("学号：%s  姓名：%s  性别： %c  年龄：%d\n",(*p).id,(*p).name,(*p).sex,(*p).age);
}

struct Student *ordLink(struct Student *head,struct Student *pnew)
{
	struct Student *p1=head;
	struct Student *p2=head;
	p2=p1=head;
	while(p1!=NULL&&strcmp(pnew->id,p1->id)>0)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1==p2)
	{
		head=pnew;
	}
	else
	{
		p2->next=pnew;
	}
	pnew->next=p1;

	return head;
}