#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct student
{
	char name[20];
	int age;
}stu;

int stu_cmp_byage(const void* e1, const void* e2)
{
	if (((stu*)e1)->age > ((stu*)e2)->age)//->优先级更高
		return 1;
	else if (((stu*)e1)->age < ((stu*)e2)->age)
		return -1;
	else
		return 0;
}

//char*类型的只能访问一个字节，故循环width次实现每个字节的交换
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
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		//每趟交换次数
		for (j = 0; j < sz - 1 - i; j++)
		{
			//强制转换为char*，在加上宽度的倍数
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