#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//查找
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
//添加通讯录成员
void AddContact(Contact* pc) {
	assert(pc);
	if (pc->count == 100) {
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入姓名\n");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄\n");
	scanf("%d", &pc->data[pc->count].age);
	printf("请输入性别\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话\n");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址\n");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
}
//打印通讯录
void ShowContact(Contact* pc) {
	assert(pc);
	int i = 0;
	printf("%20s\t%3s\t%5s\t%12s\t%30s\n", "名字","年龄", "性别", "电话", "地址");
	
	for (i = 0; i < pc->count; i++) {
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n", pc->data[i].name,
			                                   pc->data[i].age,
			                                   pc->data[i].sex,
			                                   pc->data[i].tele,
			                                   pc->data[i].addr);
	}
}
//删除通讯录成员
void DelContact(Contact* pc) {
	assert(pc);
	char name[MAX] = { 0 };
	int i = 0;
	int j = 0;
	if (pc->count == 0) {
		printf("通讯录为空\n");
		return;
	}

	printf("请输入要删除的成员名字\n");
	scanf("%s", name);
	int ret = FindByName(pc,name);
	if (ret == -1) {
		printf("找不到\n");
		return;
	}
	for (j = ret; j < pc->count; j++) {
		pc->data[j] = pc->data[j + 1];
	}
	printf("已删除\n");
}
void SearchContact(Contact* pc) {
	char name[MAX] = { 0 };
	int i = 0;
	printf("请输入查找的姓名\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("找不到");
	}
	else {
		printf("%20s\t%3s\t%5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n", pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].tele,
			pc->data[ret].addr);
	}
}
//修改通讯录指定联系人
void ModifyContact(Contact* pc) {
	assert(pc);
	char name[MAX] = { 0 };
	int i = 0;
	int j = 0;
	if (pc->count == 0) {
		printf("通讯录为空\n");
		return;
	}

	printf("请输入要修改的成员名字\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("要修改的人不存在\n");
		return;
	}
	printf("请输入姓名\n");

	scanf("%s", pc->data[ret].name);
	printf("请输入年龄\n");
	scanf("%d", &pc->data[ret].age);
	printf("请输入性别\n");
	scanf("%s", pc->data[ret].sex);
	printf("请输入电话\n");
	scanf("%s", pc->data[ret].tele);
	printf("请输入地址\n");
	scanf("%s", pc->data[ret].addr);
	printf("修改成功\n");
}
//排序函数
int cmp_peo_by_name(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);

}

//按照名字排序
void SortContact(Contact* pc) {
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序完成\n");
}



