#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct student
{
	char name[20];
	int age;
}stu;

int stu_cmp_byage(const void* e1, const void* e2)
{
	if (((stu*)e1)->age > ((stu*)e2)->age)//->���ȼ�����
		return 1;
	else if (((stu*)e1)->age < ((stu*)e2)->age)
		return -1;
	else
		return 0;
}

//char*���͵�ֻ�ܷ���һ���ֽڣ���ѭ��width��ʵ��ÿ���ֽڵĽ���
void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		//ÿ�˽�������
		for (j = 0; j < sz - 1 - i; j++)
		{
			//ǿ��ת��Ϊchar*���ڼ��Ͽ�ȵı���
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
		}
	}
}

int main()
{
	stu sarr[3] = { {"zhangsan",30},{"lisi",20},{"wangwu",10} };
	int sz = sizeof(sarr) / sizeof(sarr[0]);

	bubble_sort(sarr, sz, sizeof(sarr[0]), stu_cmp_byage);
	return 0;
}