#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
#define COST 1.0

struct Student
{
    int id;
    char class[20];
    char name[20];
    int starttime;
    int endtime;
    double cost;
    int computerid;

};

struct Student students[MAX];
int studentcount = 0;

void AddStudents()
{

        printf("请输入第%d名学生的学号: ", studentcount + 1);
        scanf("%d", &students[studentcount].id);
        printf("请输入班级: ");
        scanf("%s", students[studentcount].class);
        printf("请输入姓名: ");
        scanf("%s", students[studentcount].name);
        printf("请输入上机起始时间(分钟): ");
        scanf("%d", &students[studentcount].starttime);
        printf("请输入上机结束时间(分钟): ");
        scanf("%d", &students[studentcount].endtime);
        studentcount++;
        students[studentcount].computerid = studentcount + 1;
    
}

void InputStudents()
{

    while(1)
    {
    int input = 0 ;
    printf("请选择：    \n");
    printf("    1. 添加 \n");
    printf("    0. 退出 \n");
    scanf("%d",&input);
    
        switch(input)
        {
            case 1:
            AddStudents();
            break;
            case 0:
            return;
            default:
            printf("输入有误,请重新输入\n");
        }
    }
    
}

void Caculate()
{
    printf("计算完成\n");
    int i = 0;
    for(i = 0; i < MAX ; i++)
    {
        int time = (students[i].endtime - students[i].starttime) / 60;
        if((students[i].endtime - students[i].starttime) % 60 != 0)
        {
            time++;
        }
        students[i].cost = time * COST;
    }

}

void FindStudents()
{
    printf("请选择查询的方式\n");
    printf("    1.按照 班级 查找\n");
    printf("    2.按照 学号 查找\n");
    printf("    3.按照 姓名 查找\n");
    int choice = 0;
    scanf("%d",&choice);
    if(choice == 1)
    {
        printf("请输入 班级 \n");
        char inputclass[20];
        scanf("%s",inputclass);
        int i = 0;
        for(i = 0; i <studentcount ; i++)
        {
            if(strcmp(students[i].class,inputclass) == 0)
            {
                printf("学号: %d, 班级: %s, 姓名: %s, 上机时间: %d分钟 - %d分钟, 费用: %.2f元\n",
                students[i].id, students[i].class, students[i].name,
                students[i].starttime, students[i].endtime, students[i].cost);
                break;
            }
        }

    }
    else if(choice == 2)
    {
        printf("请输入 学号 \n");
        int inputid;
        scanf("%d",&inputid);
        int i = 0;
        for(i = 0; i < studentcount ; i++)
        {
            if(students[i].id == inputid)
            {
                printf("学号: %d, 班级: %s, 姓名: %s, 上机时间: %d分钟 - %d分钟, 费用: %.2f元\n",
                students[i].id, students[i].class, students[i].name,
                students[i].starttime, students[i].endtime, students[i].cost);
                break;
            } 
        }

    }
    else if(choice == 3)
    {
        printf("请输入 姓名 \n");
        char inputname[20];
        scanf("%s",inputname);
        int i = 0 ;
        for(i = 0; i < studentcount
        
         ; i++)
        {
            if(strcmp(students[i].name,inputname) == 0)
            {
                printf("学号: %d, 班级: %s, 姓名: %s, 上机时间: %d分钟 - %d分钟, 费用: %.2f元\n",
                students[i].id, students[i].class, students[i].name,
                students[i].starttime, students[i].endtime, students[i].cost);
                break;
            }   
        }

    }
    else
    {
        printf("输入有误\n");
        return;
    }

}

void DisplayComputer()
{
    int i = 0;
    for(i =0  ; i < studentcount ; i++)
    {
    printf("%d号机的使用时长为:",students[i].computerid);
    int time = students[i].endtime - students[i].starttime;
    printf("%d",time);
    printf("\n");
    }
}

int main()
{
    int choice = 0;
    while(1)
    {
    printf("\n机房收费管理系统\n");
    printf("1. 输入学生信息\n");
    printf("2. 计算上机费用\n");
    printf("3. 查询学生信息\n");
    printf("4. 显示机器使用情况\n");
    printf("5. 退出\n");
    printf("请选择功能: ");  
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
    {
        InputStudents();
        break;
    }
    case 2:
    {
        Caculate();
        break;
    }
    case 3:
    {
        FindStudents();
        break;

    }    
    case 4:
    {
        DisplayComputer();
        break;

    }    
    case 5:
    {
        exit(0);
    }    
    default:
    {
        printf("无效选择，请重新选择\n");
    }
    }
    }
    system("pause");
    system("cls");
    return 0;
}