#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//����
int FindByName(Contact* pc, char name[]) {
	int i = 0;
	for (i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name,name)== 0) {
			return i;
		}
	}
	return -1;
}
void InitContact(Contact *pc) {
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
//���ͨѶ¼��Ա
void AddContact(Contact* pc) {
	assert(pc);
	if (pc->count == 100) {
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("����������\n");
	scanf("%s", pc->data[pc->count].name);
	printf("����������\n");
	scanf("%d", &pc->data[pc->count].age);
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰\n");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ\n");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
}
//��ӡͨѶ¼
void ShowContact(Contact* pc) {
	assert(pc);
	int i = 0;
	printf("%20s\t%3s\t%5s\t%12s\t%30s\n", "����","����", "�Ա�", "�绰", "��ַ");
	
	for (i = 0; i < pc->count; i++) {
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n", pc->data[i].name,
			                                   pc->data[i].age,
			                                   pc->data[i].sex,
			                                   pc->data[i].tele,
			                                   pc->data[i].addr);
	}
}
//ɾ��ͨѶ¼��Ա
void DelContact(Contact* pc) {
	assert(pc);
	char name[MAX] = { 0 };
	int i = 0;
	int j = 0;
	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}

	printf("������Ҫɾ���ĳ�Ա����\n");
	scanf("%s", name);
	int ret = FindByName(pc,name);
	if (ret == -1) {
		printf("�Ҳ���\n");
		return;
	}
	for (j = ret; j < pc->count; j++) {
		pc->data[j] = pc->data[j + 1];
	}
	printf("��ɾ��\n");
}
void SearchContact(Contact* pc) {
	char name[MAX] = { 0 };
	int i = 0;
	printf("��������ҵ�����\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("�Ҳ���");
	}
	else {
		printf("%20s\t%3s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n", pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].tele,
			pc->data[ret].addr);
	}
}
//�޸�ͨѶ¼ָ����ϵ��
void ModifyContact(Contact* pc) {
	assert(pc);
	char name[MAX] = { 0 };
	int i = 0;
	int j = 0;
	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}

	printf("������Ҫ�޸ĵĳ�Ա����\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("����������\n");

	scanf("%s", pc->data[ret].name);
	printf("����������\n");
	scanf("%d", &pc->data[ret].age);
	printf("�������Ա�\n");
	scanf("%s", pc->data[ret].sex);
	printf("������绰\n");
	scanf("%s", pc->data[ret].tele);
	printf("�������ַ\n");
	scanf("%s", pc->data[ret].addr);
	printf("�޸ĳɹ�\n");
}
//������
int cmp_peo_by_name(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);

}

//������������
void SortContact(Contact* pc) {
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("�������\n");
}



