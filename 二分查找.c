#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)

#define Max 1000

typedef int datatype;
typedef struct{
	datatype a[100];
}seqlist;

void Create(seqlist *l){
	srand((int)time(0));
	int i; 
	for(i=0;i<100;i++)
		l->a[i]=random(1000);
}
void Print(seqlist *l){
	int i;
	for(i=0;i<100;i++)
		printf("%d ",l->a[i]);
}

void Bubble_sort(seqlist *l){
	int j,i;
	for(i=1;i<100;i++)
		for(j=0;j<100-i;j++)
			if(l->a[j]>l->a[j+1]){
				int temp;
				temp = l->a[j];
				l->a[j] = l->a[j+1];
				l->a[j+1] = temp;
			}
}

void Binary_search(seqlist *l){
	int a=-1,i;
	int start=0;
	int end=99;
	int mid;
	for(i=0;i<50;i++){
		mid = (start+end)/2;
		if(l->a[mid] == 72)
			a=mid;
		else if(l->a[mid] > 72)
			end=mid-1;
		else start=mid+1;
		
		if(a>-1) break;
	}
	if(a>-1)
	printf("\n数字72的位置为：%d",a);
	else	printf("\n没有72这个数");
} 

int main(){
	seqlist L;
	Create(&L);

	Bubble_sort(&L);
	printf("排序后的顺序表为：");
	Print(&L);
	
	Binary_search(&L);
}

