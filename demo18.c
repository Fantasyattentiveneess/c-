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

        printf("�������%d��ѧ����ѧ��: ", studentcount + 1);
        scanf("%d", &students[studentcount].id);
        printf("������༶: ");
        scanf("%s", students[studentcount].class);
        printf("����������: ");
        scanf("%s", students[studentcount].name);
        printf("�������ϻ���ʼʱ��(����): ");
        scanf("%d", &students[studentcount].starttime);
        printf("�������ϻ�����ʱ��(����): ");
        scanf("%d", &students[studentcount].endtime);
        studentcount++;
        students[studentcount].computerid = studentcount + 1;
    
}

void InputStudents()
{

    while(1)
    {
    int input = 0 ;
    printf("��ѡ��    \n");
    printf("    1. ��� \n");
    printf("    0. �˳� \n");
    scanf("%d",&input);
    
        switch(input)
        {
            case 1:
            AddStudents();
            break;
            case 0:
            return;
            default:
            printf("��������,����������\n");
        }
    }
    
}

void Caculate()
{
    printf("�������\n");
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
    printf("��ѡ���ѯ�ķ�ʽ\n");
    printf("    1.���� �༶ ����\n");
    printf("    2.���� ѧ�� ����\n");
    printf("    3.���� ���� ����\n");
    int choice = 0;
    scanf("%d",&choice);
    if(choice == 1)
    {
        printf("������ �༶ \n");
        char inputclass[20];
        scanf("%s",inputclass);
        int i = 0;
        for(i = 0; i <studentcount ; i++)
        {
            if(strcmp(students[i].class,inputclass) == 0)
            {
                printf("ѧ��: %d, �༶: %s, ����: %s, �ϻ�ʱ��: %d���� - %d����, ����: %.2fԪ\n",
                students[i].id, students[i].class, students[i].name,
                students[i].starttime, students[i].endtime, students[i].cost);
                break;
            }
        }

    }
    else if(choice == 2)
    {
        printf("������ ѧ�� \n");
        int inputid;
        scanf("%d",&inputid);
        int i = 0;
        for(i = 0; i < studentcount ; i++)
        {
            if(students[i].id == inputid)
            {
                printf("ѧ��: %d, �༶: %s, ����: %s, �ϻ�ʱ��: %d���� - %d����, ����: %.2fԪ\n",
                students[i].id, students[i].class, students[i].name,
                students[i].starttime, students[i].endtime, students[i].cost);
                break;
            } 
        }

    }
    else if(choice == 3)
    {
        printf("������ ���� \n");
        char inputname[20];
        scanf("%s",inputname);
        int i = 0 ;
        for(i = 0; i < studentcount
        
         ; i++)
        {
            if(strcmp(students[i].name,inputname) == 0)
            {
                printf("ѧ��: %d, �༶: %s, ����: %s, �ϻ�ʱ��: %d���� - %d����, ����: %.2fԪ\n",
                students[i].id, students[i].class, students[i].name,
                students[i].starttime, students[i].endtime, students[i].cost);
                break;
            }   
        }

    }
    else
    {
        printf("��������\n");
        return;
    }

}

void DisplayComputer()
{
    int i = 0;
    for(i =0  ; i < studentcount ; i++)
    {
    printf("%d�Ż���ʹ��ʱ��Ϊ:",students[i].computerid);
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
    printf("\n�����շѹ���ϵͳ\n");
    printf("1. ����ѧ����Ϣ\n");
    printf("2. �����ϻ�����\n");
    printf("3. ��ѯѧ����Ϣ\n");
    printf("4. ��ʾ����ʹ�����\n");
    printf("5. �˳�\n");
    printf("��ѡ����: ");  
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
        printf("��Чѡ��������ѡ��\n");
    }
    }
    }
    system("pause");
    system("cls");
    return 0;
}