/*
C语言学生管理系统 课程设计
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


struct student
{
	char sno[12];
	char name[9];
	
	char sex[5];
	struct score
	{
		double China;
		double shuxue;
		double English;
		double sum;
		double average;
	} fenshu;
	int age;
	struct student *next;
};
typedef struct student ID;//声明结构体同义词，方便使用
int total;//学生管理系统的实际人数
//各函数的声明
ID* Create(); //创建学生管理系统
void Save(ID *head); //保存学生信息文件
ID * Read(); //读取学生信息文件
void Display(ID * head); //显示学生信息文件
ID* Add(ID* head); //添加学生信息
ID* Change(ID* head); //修改学生信息
void Search(ID *head); //按照姓名或者类型查找学生
ID* Delete(ID *head); //删除学生信息
void Sort(ID *head);
/************************************************
*函数名： main(主函数)
*功能：显示主菜单
*返回值：NULL
*************************************************/
void main()
{
	ID*head=NULL;//链表头结点
	int choice;//用户菜单选择
	while(1)
	{
		system("cls");//清屏
		printf("\n");
		printf("*************简易学生管理系统*************\n\n");
		printf("\t1.创建简易学生管理系统\n\n");
		printf("\t2.显示学生文件信息\n\n");
		printf("\t3.添加新学生\n\n");
		printf("\t4.修改学生的信息\n\n");
		printf("\t5.查找学生\n\n");
		printf("\t6.删除学生\n\n");
		printf("\t7.排序学生\n\n");
		printf("\t8.退出简易学生管理系统\n\n");
		printf("\n\n");
		printf("请输入你的选择(1~8):");
		scanf("%d",&choice);//选择功能
		getchar();//吸收回车符
		switch(choice)
		{
			case 1: head=Create(); //创建学生管理系统子函数
			break;
			case 2: head=Read();   //读取学生管理系统文件子函数
			if(head!=NULL) 
				Display(head);  //显示学生管理系统
			break;
			case 3: head=Read();   //读取学生管理系统文件子函数
			if(head!=NULL) 
				head=Add(head); //添加新生
			break;
			case 4:  head=Read();  
			if(head!=NULL) 
				head=Change(head); //修改新生
			break;
			case 5:  head=Read();
			if(head!=NULL) 
				Search(head); //查找学生
			break;
			case 6:  head=Read();  
			if(head!=NULL) 
				head=Delete(head); //删除学生
			break;
			case 7: head=Read(); 
			if(head!=NULL) 
				Sort(head); //排序学生
			break;
			case 8: exit(0);       //退出
			break;
			default: printf("\n你输入错了，请你重新输入\n");
			getch();
		}
	}
}
/***********************************************
*函数名：Create（创建）
*功能：创建一个单链表，把数据放在链表里面，一旦需要保存，就调用save函数保存在文件中
*返回值：ID *（结构体链表头节点指针）
***********************************************/
ID* Create()
{   
	int k=0;
	
	FILE *fp;       //定义一个文件指针，接收fopen的返回值，用于最后的关闭文件
	ID *head,*p1,*tail,*p3; 
	
	
	if ((fp=fopen("student.txt","r"))==NULL)      //如果文件不存在就创建
	{
		head=p1=tail=NULL;
		while(1)                //这个循环可以实现多次添加新学生信息
		{
			bb1:  p1= (ID*)malloc(sizeof(ID)); //给p1分配一个动态存储空间
			p1->next=NULL;
			printf("请输入姓名(当你不想录入时，在姓名处输入*，结束录入):\n");
			fflush(stdin);
			scanf("%8s",p1->name);       //输入姓名
			p1->name[8]=0;
			if(strcmp(p1->name,"*")==0)   //判断输入的是否为*号，是则结束函数
			{
				if(total==0)                //当记录人数为0时不创建学生文件
				{
					printf("你输入了0条记录，单链表没有创建...\n");
					free(p1);                  //释放p1空间
					return (head);         //把head返回
				}
				else
				{
					break;                  //跳出while循环
				}
			}
			fflush(stdin);
			printf("请输入学号： \n");
			scanf("%11s",p1->sno);
			
			p3=head;      //让p3从头开始遍历
			while(p3!=NULL)       //当p3不为空时
			{
				if((strcmp(p1->name,p3->name)==0)&&(strcmp(p1->sno,p3->sno)==0))
				{
					free(p1);
					printf("你重复输入了。\n");
					goto bb1;
				}
				p3=p3->next;
			}
			//使得每个字段都能有效结束
			
			p1->sno[11]=0;
			
			fflush(stdin);
			printf("请输入学生性别:");
			scanf("%4s",p1->sex);
			fflush(stdin);
			printf("请输入学生年龄：");
			scanf("%d",&p1->age);
			fflush(stdin);
			printf("请输入学生科目成绩(语文，数学，英语)：");
			scanf("%lf%lf%lf",&p1->fenshu.China,&p1->fenshu.shuxue,&p1->fenshu.English);
			
			p1->fenshu.sum=p1->fenshu.China+p1->fenshu.shuxue+p1->fenshu.English;
			p1->fenshu.average=p1->fenshu.sum/3.0;
			if(head==NULL)
			{
				head=p1;                //head和p2都为p1
				tail=p1;
			}
			else
			{ 
				tail->next=p1;      //第二次以后的执行命令，目的就是p1向后移，而head的位置不变
				tail=p1;
			}
			
			total++;                //录入一个人后，总数就加1
		}
		tail->next=NULL;                     //尾指针域赋值为NULL
		free(p1);
		printf("\n新建简易学生管理系统成功，共有%d个学生\n ",total);
		getchar();      //这个getchar是吸收回车键的
		Save(head); //将新创建的学生链表保存到学生文件中
	}
	else  
	{
		printf("\n\t学生信息文件已经存在，不能重复创建！\n\n按任意键返回主菜单\n\n");
		getch();     //输入任意键进入下一步
	}  
	return head;        //返回头指针 
}
/*void Save(ID *head)
{
}*/




/************************************************
*函数名：Save（保存）
*功能：将链表（数据）保存在文件
*返回值：NULL
*参数：链表头节点
*************************************************/
void Save(ID *head) 
{
	FILE *fp; //定义一个文件指针，接收fopen的返回值，用于最后的关闭文件 
	ID* t ; //定义一个指针，从头到尾遍历一遍单链表，向文件中写入
	if ((fp=fopen("student.txt","w"))==NULL) //打开文件来写入
	{
		printf("打开文件失败！\n");
		getch();     //输入任意键进入下一步
		exit(0); //退出
	}
	t=head; //把头指针赋给t，让它从头开始
	while(t!=NULL) //只要t指针不为空，即等于链表没有结束
	{
		fwrite(t,sizeof(ID),1,fp); //把链表写入文件中
		t=t->next; //指针后移
	}
	fclose(fp); //把文件关闭
	printf("\n文件保存成功\n");
	printf("\n请按任意键返回主菜单\n");
	getch(); 
}




/************************************************
*函数名：Read（读取学生文件）
*功能：读取文件中的信息并将其放入单链表中，并且最后返回一个头指针
*返回值：ID *（结构体指针）
*************************************************/
ID * Read()
{
	FILE *fp; //定义一个文件指针，接收fopen的返回值，用于最后的关闭文件
	ID *t1,*t2,*head=NULL;
	
	if((fp=fopen("student.txt","r"))==NULL)      //判断文件是否存在
	{
		printf("打开文件失败！没有该文件\n\n");
		printf("请按任意键返回主菜单\n");
		getch();
		return 0;
	}
	rewind(fp);  //这个函数是把一个文件的位置指针从新移至开头，不然的话会出现一个组数据丢失
	t1=(ID *) malloc(sizeof(ID)); //申请动态空间
	head=t2=t1; //把t1赋给头结点
	while(!feof(fp)) //feof函数的功能是判断这个文件是不是结束了，如果结束了，返回一个非零值，否则返回一个0，
	{
		if(fread(t1,sizeof(ID),1,fp)!=1) //fread函数返回读出数据项的个数
			break;  //如果没有读取内容，则结束 
		t1->next=(ID *)malloc(sizeof(ID)); //把在申请动态空间的同时，把t1的next指向下一个结点
		t2=t1;     //t2是真正的尾节点
		t1=t1->next; //t1向后移一个结点
	}
	t2->next=NULL; 
	fclose(fp); //关闭文件
	return head; //返回一个头指针，因为在没有创建一个单链表和文件的时候，就是靠这个头指针进行一系列的操作的
}




/************************************************
*函数名： Display（显示学生文件）
*功能：显示联系人信息
*返回值：无返回值）
*************************************************/
void Display(ID * head)
{
	ID *t1=head;
	printf("\n学生姓名==学号=====性别===年龄==语文成绩==数学成绩==英语成绩==总分==平均分\n\n");
	while(t1!=NULL)
	{
		printf("%-8s%-11s  %-4s  %-4d  %-8.2f %-8.2f  %-8.2f  %-8.2f %-8.2f \n",t1->name,t1->sno,t1->sex,t1->age,t1->fenshu.China,t1->fenshu.shuxue,t1->fenshu.English,t1->fenshu.sum,t1->fenshu.average);
		t1=t1->next;
	}
	printf("\n\n简易学生管理系统成功显示\n");
	printf("\n请按任意键返回主菜单\n");
	getch();
	
	
}



/************************************************
*函数名： Add（添加）
*功能：添加人物信息
*返回值：ID *（结构体指针）
*************************************************/
ID* Add(ID* head)
{
	char saveflag; //存盘标志
	int k=0;
	
	ID *p1,*p2,*pa; //pa是用来放添加的信息的，p1，p2是用来临时移动的
	p1=p2=head; //先让它们都等于头指针
	system("cls"); //清屏
	while(p1->next!=NULL) //把p1移到尾节点
		p1=p1->next;
	
	
	bb2:pa=(ID*)malloc(sizeof(ID)); //申请动态存储空间
	printf("请输入添加人的姓名:\n");
	fflush(stdin);
	scanf("%8s",pa->name);
	fflush(stdin);
	printf("请输入学号: \n");
	scanf("%11s",pa->sno);
	p2=head;      //让p2从头开始遍历
	while(p2!=NULL)       //当p2不为空时
	{
		if((strcmp(pa->name,p2->name)==0)&&(strcmp(pa->sno,p2->sno)==0))
		{
			free(pa);
			printf("你重复输入了!\n");
			goto bb2;
		}
		
		p2=p2->next;
	}
	pa->name[8]=0;   //使得每个字段都能有效结束
	pa->sno[11]=0;
	
	fflush(stdin);
	printf("请输入学生性别:");
	scanf("%4s",pa->sex);
	pa->sex[4]=0;
	fflush(stdin);
	printf("请输入学生年龄：");
	scanf("%d",&pa->age);
	fflush(stdin);
	printf("请输入学生科目成绩(语文，数学，英语)：");
	scanf("%lf%lf%lf",&pa->fenshu.China,&pa->fenshu.shuxue,&pa->fenshu.English);
	pa->fenshu.sum=pa->fenshu.China+pa->fenshu.shuxue+pa->fenshu.English;
	pa->fenshu.average=pa->fenshu.sum/3.0;
	p1->next=pa; //尾节点p1的next添加pa
	pa->next=NULL;
	printf("新添加学生信息成功,是否存盘?(Y/N)\n");
	fflush(stdin);
	scanf("%c",&saveflag);//存盘？Y or N
	if(saveflag=='y'||saveflag=='Y')//当输入y Y的时候
		Save(head); //调用保存函数
	else
	{
		printf("请按任意键返回主菜单\n");
		getch(); 
	}
	free(pa);
	return(head); 
}





/************************************************
*函数名： Change（修改） 
*功能：修改人物信息
*返回值：ID *（结构体指针）
*************************************************/
ID* Change(ID* head)
{
	ID *p1,*p2; 
	char saveflag; 
	
	char n[10],t[12]; //存放待修改人的姓名和学号
	int flag=0; //修改标志
	system("cls"); //清屏
	p1=head; 
	printf("请输入要修改的学号：\n"); 
	scanf("%11s",t); 
	while(p1!=NULL) //这个while语句的作用是在遍历整个单链表
	{
		if(strcmp(p1->sno,t)==0)//判断是不是你输入的学号是不是和简易学生管理系统中的相同
		{
			flag=1; //当存在一样的名字时，
			printf("\n你要修改的学生信息为:\n");
			printf("\n学生姓名==学号=====性别===年龄==语文成绩==数学成绩==英语成绩==总分==平均分\n\n");
			printf("%-8s%-11s  %-4s  %-4d  %-8.2f %-8.2f  %-8.2f  %-8.2f %-8.2f \n",p1->name,p1->sno,p1->sex,p1->age,p1->fenshu.China,p1->fenshu.shuxue,p1->fenshu.English,p1->fenshu.sum,p1->fenshu.average);
			
			bb3:printf("\n请输入修改后的姓名:\n");
			fflush(stdin);
			scanf("%8s",n);
			
			
			p2=head; //让p2从头开始遍历
			while(p2!=NULL)//当p2不为空时
			{
				if((strcmp(n,p2->name)==0)&&(strcmp(t,p2->sno)==0))
				{
					printf("你重复输入了。\n");
					goto bb3;
				}
				p2=p2->next;
			}
			
			
			strcpy(p1->name,n);
			p1->name[8]=0;
			fflush(stdin);
			printf("请输入学生性别:");
			scanf("%4s",p1->sex);
			p1->sex[4]=0;
			fflush(stdin);
			printf("请输入学生年龄：");
			scanf("%d",&p1->age);
			fflush(stdin);
			printf("请输入学生科目成绩(语文，数学，英语)：");
			scanf("%lf%lf%lf",&p1->fenshu.China,&p1->fenshu.shuxue,&p1->fenshu.English);
			p1->fenshu.sum=p1->fenshu.China+p1->fenshu.shuxue+p1->fenshu.English;
			p1->fenshu.average=p1->fenshu.sum/3.0;
			printf("该学生信息已修改成功\n");
			printf("学生信息已经新建成功,是否进行保存? (Y/N)\n");
			fflush(stdin);
			scanf("%c",&saveflag);
			if(saveflag=='y'||saveflag=='Y')//当输入是的时候
				Save(head); //调用保存函数
			else
			{
				printf("请按任意键返回主菜单\n");
				getch(); 
			}
			break;
		}  
		p1=p1->next;  //p1指针向后移
	}
	if(flag==0) //没有这个名字的人，返回主菜单
	{
		printf("\n没有找到要修改的学生信息，请按任意键返回主菜单!\n");
		getch(); //按下任意键就进入下一条语句的函数
	}
	return(head);    
}
/************************************************
*函数名：Search（查询）
*功能：可以通过姓名查询,也可以通过类型查询
*返回值：NULL
*************************************************/
void Search(ID *head)
{
	int num; //子菜单选择
	int count=0;
	ID* p; 
	int flag; //flag是用来判断是否找到，
	char c[10],searchflag='y';//c是来存放姓名或者类型，
	char ch[12];
	while(1)
	{
		searchflag='y';
		printf("\n**************查找子菜单*******************\n");
		printf("\n\t 1.按姓名\n");
		printf("\n\t 2.按学号\n");
		printf("\n\t 3.返回主菜单\n");
		printf("\n*******************************************\n");
		fflush(stdin);
		printf("请输入您的选择:\n");
		scanf("%d",&num);//选择你想要查询的方式 
		switch(num) 
		{
			
			case 1: while(searchflag=='y'||searchflag=='Y') 
			{
				count=0;
				flag=0; //初始化为0
				printf("\n请输入待查找的姓名: \n");
				scanf("%8s",c);
				p=head; 
				while(p!=NULL)
				{
					if(strcmp(p->name,c)==0)
					{  
						count++;
						if(count==1)
							printf("\n学生姓名==学号=====性别===年龄==语文成绩==数学成绩==英语成绩==总分==平均分\n\n");
						printf("%-8s%-11s  %-4s  %-4d  %-8.2f %-8.2f  %-8.2f  %-8.2f %-8.2f \n",p->name,p->sno,p->sex,p->age,p->fenshu.China,p->fenshu.shuxue,p->fenshu.English,p->fenshu.sum,p->fenshu.average);
						
						flag=1; //flag赋值为1，表示为已经查到了数据了   
					}
					p=p->next; //p1指针向后移
				}
				if(flag==0) //表示没有找到相关数据
				{
					printf("\n未能找到符合条件的记录\n");
				}
				else
					printf("\n\n\######找到了%d个姓名为\"%s\"学生!#####\n\n",count,c);
				printf("\n查找完毕，是否需要重新查询？ (Y/N)\n");
				fflush(stdin);
				scanf("%c",&searchflag);//是否继续查询（Y/N） 
			}
			break;
			case 2: 
			while(searchflag=='y'||searchflag=='Y')
			{
				count=0;
				flag=0; //初始化为0,
				printf("\n请输入被查找人的学号： \n");
				scanf("%11s",ch);
				
				
				p=head; 
				while(p!=NULL)
				{
					if(strcmp(p->sno,ch)==0)
					{
						count++;
						if(count==1)
							printf("\n学生姓名==学号=====性别===年龄==语文成绩==数学成绩==英语成绩==总分==平均分\n\n");
						printf("%-8s%-11s  %-4s  %-4d  %-8.2f %-8.2f  %-8.2f  %-8.2f %-8.2f \n",p->name,p->sno,p->sex,p->age,p->fenshu.China,p->fenshu.shuxue,p->fenshu.English,p->fenshu.sum,p->fenshu.average);
						
						flag=1; //flag赋值为1，表示为已经查到了数据了   
					}
					p=p->next;  //p1指针向后移
				}
				if(flag==0) //表示没有找到相关数据
				{
					printf("\n对不起,未能找到符合条件的记录\n");
				}
				else
					printf("\n\n\######找到了该学生!#####\n\n");
				printf("\n查找完毕，是否需要重新查询？ Y/N\n");
				fflush(stdin);
				scanf("%c",&searchflag);//是否继续查询（Y/N）
			}
			break; 
			case 3:return;
			default :printf("你输入错了，请你输入任意键返回主菜单...\n");
			getch();
		}
	}
}


/************************************************
*函数名： Delete（删除）
*功能：通过查找学号来实现删除学生记录
*返回值：ID *（结构体指针）
*************************************************/
ID* Delete(ID *head)
{
	ID *p1,*p2; //p1是用来遍历整一个单链表定位要删除的结点，p2是用来定位p1的前结点的
	char saveflag='n', temp; //saveflag是否保存，temp是否删除
	
	
	char s[12]; //存放输入的学号 
	p1=p2=head; //把head赋给p1,p2  
	printf("\n请输入要删除的学号:\n");
	scanf("%11s",s);
	getchar();
	while(p1!=NULL)//这个while语句的作用是在遍历整个单链表时，当遇到一样的名字时把i赋值，引导下面的工作
	{
		if(strcmp(p1->sno,s)==0)//判断是不是你输入的名字是不是和学生信息中的相等
		{
			printf("你要删除的学生为:\n");
			printf("\n学生姓名==学号=====性别===年龄==语文成绩==数学成绩==英语成绩==总分==平均分\n\n");
			printf("%-8s%-11s  %-4s  %-4d  %-8.2f %-8.2f  %-8.2f  %-8.2f %-8.2f \n",p1->name,p1->sno,p1->sex,p1->age,p1->fenshu.China,p1->fenshu.shuxue,p1->fenshu.English,p1->fenshu.sum,p1->fenshu.average);
			printf("请确定是否要删除该记录？Y/N?\n");
			fflush(stdin);
			scanf("%c",&temp);//确定要删除吗？ 
			if(temp=='y'||temp=='Y')//当输入是的时候
			{
				if(p1==head)//判断是不是在头结点
					head=p1->next;//把头结点去掉
				else
					
					
					p2->next=p1->next;//删除p1结点（p2的next域指向p1的下个结点）
				printf("该学生信息已删除成功,是否存盘?Y/N?\n");
				fflush(stdin);
				scanf("%c",&saveflag);//确定要保存吗？
				if(saveflag=='y'||saveflag=='Y')//当输入是的时候
					Save(head); //调用保存函数
				else
				{
					printf("请按任意键返回主菜单\n");
					getch(); 
				}
			}
			else
			{
				printf("请按任意键返回主菜单\n");
				getch(); 
			}
			break;
		}
		p2=p1;
		p1=p1->next;  //p1指针向后移
	}
	if((p1->next)==NULL&&strcmp(p1->sno,s))
	{
		printf("没有找到要删除的学生学号，请检查你要删除的学号是否正确\n");
		printf("请按任意键返回主菜单\n");
		getch(); //按下任意键就进入下一条语句的函数 
		
	}
	return(head); //return一个已经完成修改的链表头指针   
}


/************************************************
*函数名： Swap（交换）
*功能：交换结点内数据
*返回值：无
*************************************************/
void Swap1(char t1[],char t2[])
{
	char t[20]={0};
	strcpy(t,t1);
	strcpy(t1,t2);
	strcpy(t2,t);
	
	
}
void Swap2(double s1,double s2)
{
	double s;
	s=s1;
	s1=s2;
	s2=s;
}
void Swap3(int r1,int r2)
{
	int r;
	r=r1;
	r1=r2;
	r2=r;
}
/************************************************
*函数名： Sort（排序）
*功能：按照类型排序通讯记录
*返回值：ID *（结构体指针）
*************************************************/
void Sort(ID *head)
{
	ID  *p1,*p2;
	char saveflag='y';
	p2=NULL;
	
	
	while( head != p2)
	{
		p1 = head;
		while( p1->next!= p2 )
		{  
			if( strcmp(p1->sno,p1->next->sno)>0)
			{
				Swap1(p1->name,p1->next->name);
				Swap1(p1->sno,p1->next->sno);
				
				Swap1(p1->sex ,p1->next->sex );
				Swap2(p1->fenshu.China,p1->next->fenshu.China);
				Swap2(p1->fenshu.shuxue,p1->next->fenshu.shuxue);
				Swap2(p1->fenshu.English,p1->next->fenshu.English);
				Swap2(p1->fenshu.sum,p1->next->fenshu.sum);
				Swap2(p1->fenshu.average,p1->next->fenshu.average);
				Swap3(p1->age,p1->next->age);
				
				
				
				
			} 
			p1 = p1->next;
		}
		p2= p1;
	}
	
	
	printf("学生已按照 学号类型 排序成功,是否存盘?Y/N?\n");
	fflush(stdin);
	scanf("%c",&saveflag);//确定要保存吗？
	if(saveflag=='y'||saveflag=='Y')//当输入是的时候
		Save(head); //调用保存函数
}
