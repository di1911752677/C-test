#include<stdio.h>
//123
#define N 10

//交换
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

//输入	
void writein(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个数",i+1);
		scanf("%d",&arr[i]);
	}
}

//冒泡
void orderMP(int arr[],int n)
{
	int i;
	int j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

//选择
void orderXZ(int arr[],int n)
{
	int i;
	int j;
	int temp;
	for(i=0;i<n-1;i++)
	{
		temp=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[temp]>arr[j])
			{
				temp=j;
			}
		}
		if(temp!=i)
		{
			swap(&arr[temp],&arr[i]);
		}
	}
}

//插入
void orderCR(int arr[],int n) 
{
	int i;
	int j;
	int temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;arr[j]<temp;i--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
	}
}

//双向排序
void orderSXPX(int arr[],int n) 
{
	int i;
	int j;
	int max;
	for(i=0;i<n/2;i++)//次数
	{
		max=i;

		//选出最大数
		for(j=i+1;j<=n-1-i;j++)
		{
			if(arr[max]<arr[j])
			{
				max=j;
			}
		}
		if(max!=i)
		{
			swap(&arr[i],&arr[max]);
		}
		//选出第二大数		
		max=n-1-i;
		for(j=i+1;j<=n-1-i;j++)
		{
			if(arr[max]<arr[j])
			{
				max=j;
			}
		}
		if(max!=n-1-i)
		{	
			swap(&arr[n-1-i],&arr[max]);
		}	
	}
}
//输出
void printfArr(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%-4d",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[N]={0};

	writein(arr,N);
	orderSXPX(arr,N);
	printfArr(arr,N);

	return 0;
}
