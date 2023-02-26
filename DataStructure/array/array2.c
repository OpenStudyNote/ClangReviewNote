#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
	数组练习题
	1.求一个数组的数据和与平均值
	2.求一个数组中最大与最小值
	3.对数组元素进行排序(排序算法)重点
	4.求一个数组中第二大的数（用一重循环）
*/
void sumToaverger(void) { //求一个数组的数据和与平均值
	int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 105};
	int sum = 0;
	int length;
	float average = 0;
	length  = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	printf("sum = %d \r\n", sum);
	average = sum / length;
	printf("average = %.2f \r\n", average);

}
//求最值大 小假设某一个成员（第一个成员为最值），然后依次比较
void max_min(void) {
	int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 105};
	int length;
	int max = arr[0];
	int min = arr[0];
	length  = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < length; i++) {
		if (arr[i] > max) {
			max = arr[i];//赋值运算
		}
		if (arr[i] < min) {
			min = arr[i];//赋值运算
		}
	}
	printf("max = %d\r\n", max);
	printf("min = %d\r\n", min);
}
/*
	排序算法  需要交换 
	1.冒泡排序
	冒泡排序原理很容易理解，就是重复地走访过要排序的元素列，
	依次比较两个相邻的元素，顺序不对就交换，直至没有相邻元素需要交换，也就是排序完成。
	冒泡排序是一种稳定排序算法。
	时间复杂度:最好情况(初始情况就是正序)下是o(n),平均情况是o(n²)
	2.选择排序
	选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理是每一次从待排序的数据元素中选出最小（或最大）的一个元素.
	存放在序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾.
	以此类推，直到全部待排序的数据元素排完。
	选择排序的交换操作介于 0 和 (n - 1） 次之间。
	选择排序的比较操作为 n (n - 1） / 2 次之间。选择排序的赋值操作介于 0 和 3 (n - 1） 次之间。
	比较次数O(n²），比较次数与关键字的初始状态无关，总的比较次数N=(n-1）+(n-2）+...+1=n*(n-1）/2。交换次数O(n），
	最好情况是，已经有序，交换0次；最坏情况交换n-1次，逆序交换n/2次。交换次数比冒泡排序少多了，
	由于交换所需CPU时间比比较所需的CPU时间多，n值较小时，选择排序比冒泡排序快
	3.插入排序
	直接插入排序
	插入排序的基本操作就是将一个数据插入到已经排好序的有序数据中，从而得到一个新的、个数加一的有序数据，
	算法适用于少量数据的排序，
	插入排序的基本思想是：每步将一个待排序的记录，按其关键码值的大小插入前面已经排序的文件中适当位置上，直到全部插入完为止。
	4.二分插入排序
	由于在插入排序过程中，待插入数据左边的序列总是有序的，针对有序序列，就可以用二分法去插入数据了，
	也就是二分插入排序法。适用于数据量比较大的情况。
	算法的基本过程：
	（1）计算 0 ~ i-1 的中间点，用 i 索引处的元素与中间值进行比较，如果 i 索引处的元素大，
	说明要插入的这个元素应该在中间值和刚加入i索引之间，反之，就是在刚开始的位置 到中间值的位置，这样很简单的完成了折半；
	（2）在相应的半个范围里面找插入的位置时，不断的用（1）步骤缩小范围，不停的折半，
	范围依次缩小为 1/2 1/4 1/8 .......快速的确定出第 i 个元素要插在什么地方；
	（3）确定位置之后，将整个序列后移，并将元素插入到相应位置。
	5.希尔排序(Shell's Sort)
	希尔排序插入排序的一种又称“缩小增量排序”（Diminishing Increment Sort），
	是直接插入排序算法的一种更高效的改进版本。
	希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，
	每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组，排序完成。
	6.快速排序（Quicksort）
	快速排序（Quicksort）是对冒泡排序的一种改进。
	它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，
	然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
	7.堆排序（HeapSort）
	是指利用堆这种数据结构所设计的一种排序算法。堆是一个近似完全二叉树的结构，并同时满足堆积的性质：
	即子结点的键值或索引总是小于（或者大于）它的父节点
	在堆的数据结构中，堆中的最大值总是位于根节点（在优先队列中使用堆的话堆中的最小值位于根节点）。
	堆中定义以下几种操作：
	最大堆调整（Max Heapify）：将堆的末端子节点作调整，使得子节点永远小于父节点
	创建最大堆（Build Max Heap）：将堆中的所有数据重新排序
	堆排序（HeapSort）：移除位在第一个数据的根节点，并做最大堆调整的递归运算
*/
#define EXCHANGE(num1, num2)  { num1 = num1 ^ num2;\
num2 = num1 ^ num2;\
num1 = num1 ^ num2;}
void buddleSort(int num[],int count)
{
	for (int i = 0; i < count - 1; i++) {
		
		for (int j = 0; j < count - i - 1; j++) {
			
			if (num[j] > num[j + 1]) 
				EXCHANGE(num[j], num[j + 1])
		}
	}
}
void selectSort(int num[],int count)
{
	for (int i = 0; i < count; i++) {
		
		int min = i;
		
		for (int j = i; j < count; j++) {
			
			if (num[j] < num[min])  min = j;
		}
		
		if (i != min)   
			EXCHANGE(num[i], num[min]);//可以看出，最多交换count - 1次
	}
}
void insertSort2(int num[],int count)
{
	int i,j;
	
	for (i = 1; i < count; i++) {
		
		if (num[i] < num[i - 1]) {
			
			int temp = num[i];
			
			for (j = i; j > 0; j--) {
				
				if (num[j - 1] > temp) num[j] = num[j - 1];
				
				else break;
			}
			
			num[j] = temp;
		}
	}
}

void shellSort(int num[],int count)
{
	int shellNum = 2;
	int gap = round(count/shellNum);
	
	while (gap > 0) {
		for (int i = gap; i < count; i++) {
			int temp = num[i];
			int j = i;
			while (j >= gap && num[j - gap] > temp) {
				num[j] = num[j - gap];
				j = j - gap;
			}
			num[j] = temp;
		}
		gap = round(gap/shellNum);
	}
}

void quickSort(int num[],int count,int left,int right)
{
	if (left >= right){
		
		return ;
	}
	int key = num[left];
	int lp = left;           //左指针
	int rp = right;          //右指针
	while (lp < rp) {
		if (num[rp] < key) {
			int temp = num[rp];
			for (int i = rp - 1; i >= lp; i--) {
				num[i + 1] = num[i];
			}
			num[lp] = temp;
			lp ++;
			rp ++;
		}
		rp --;
	}
	quickSort(num,count,left,lp - 1);
	quickSort(num,count,rp + 1,right);
}

void maxHeapify(int num[], int start, int end) {
	//建立父节点指标和子节点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子节点指标在范围内才做比较
		if (son + 1 <= end && num[son] < num[son + 1]) //先比较两个子节点大小，选择最大的
			son++;
		if (num[dad] > num[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
			return;
		else { //否则交换父子内容再继续子节点和孙节点比较
			EXCHANGE(num[dad], num[son])
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heapSort(int num[], int count) {
	int i;
	//初始化，i从最後一个父节点开始调整
	for (i = count / 2 - 1; i >= 0; i--)
		maxHeapify(num, i, count - 1);
	//先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
	for (i = count - 1; i > 0; i--) {
		EXCHANGE(num[0], num[i])
		maxHeapify(num, 0, i - 1);
	}
}
/*
排序算法  数组内部的元素需要进行交换
如果按照从小到大的排序
第一个元素与后面所有的元素进行大小比较，如果后面元素比第一个元素大，不交换，如果后面元素比第一个小则交换，先所有的走一篇。
*/
void sort(void)
{
	int arr[] = {161, 242, 33, 454, 355, 664, 177, 188, 999, 1905};
	int length;
	length  = sizeof(arr) / sizeof(arr[0]);
	printf("对数组元素进行排序(从大到小): \r\n");
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			int tmp;//比较大小，需要交换
			if(arr[i]>arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		
	}
	for(int i = 0; i<10; i++)
	{
		printf("%d\t ",arr[i]);
		
	}
	printf(" \r\n");
	printf("对数组元素进行排序(从小到大): \r\n");
	
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			int tmp;
			if(arr[i]<arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		
	}
	for(int i = 0; i<10; i++)
	{
		printf("%d\t",arr[i]);
	}
	
}
/*
求一个数组中第二大的数
这道题看上去非常简单，对面试者的要求也不高，但仔细看，也隐藏了一些考察思维的点

判断数组是否为空 
判断数组是否只有一个元素 
一次循环，找出第二大的数 
有些人会进行排序操作，那就顺带考察一下排序算法 
初值问题，有人会先设置max1 = max2 = 0，最后直接return max2，该情况下会出现问题：数组所有数都是一样的值
*/
void max_second(void)
{
	int arr[] = {161, 242, 33, 454, 355, 664, 177, 188, 999, 1905};
	int length;
	length  = sizeof(arr) / sizeof(arr[0]);
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			int tmp;//比较大小，需要交换
			if(arr[i]>arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		
	}
	printf("max_second =%d \r\n",arr[1]);
	
}

const int MINNUMBER = -32767 ;
int find_sec_max( int data[], int count)
{
	int maxnumber = data[0] ;
	int sec_max = MINNUMBER ;
	
	for (int i = 1 ; i < count ; i++)
	{
		if ( data[i] > maxnumber )
		{
			sec_max = maxnumber ;
			maxnumber = data[i] ;
		}
		else
		{
			if ( data[i] > sec_max && data[i] != maxnumber)
				sec_max = data[i];
		}
	}
	
	return sec_max ;
}

int findSecondNumber(const int arr[], int size)
{
	int BiggestNumber = 0;
	int SecondNumber = 0;
	if(size < 2)
	{
		printf("ERROR!\n");
		return 0;
	}
	else
	{
		BiggestNumber = arr[0] > arr[1] ? arr[0] : arr[1];
		SecondNumber = arr[0] < arr[1] ? arr[0] : arr[1];		
	}
	
	for(int i = 2; i < size; i++)
	{
		if(arr[i] > BiggestNumber)
		{
			SecondNumber = BiggestNumber;			
			BiggestNumber = arr[i];
		}
		else
		{
			if(arr[i] > SecondNumber)
			{
				SecondNumber = arr[i];
			}
		}		
	}
	
	return SecondNumber;
}

int main() 
{
	printf("1.求一个数组的数据和与平均值: \r\n");
	sumToaverger();
	printf("2.求一个数组中最大与最小值: \r\n");
	max_min();
	printf("3.对数组元素进行排序(排序算法): \r\n");
    sort();
	printf("4.求一个数组中第二大的数（用一重循环）\r\n");
	max_second();
	int arr[] = {161, 242, 33, 454, 355, 664, 177, 188, 999, 1905};
	int length = sizeof(arr) / sizeof(arr[0]);
	int res = find_sec_max(arr, length);
    int max_num2= findSecondNumber(arr,length);
//	buddleSort(arr,length);
	selectSort(arr,length);
	printf("find_sec_max = %d \r\n", res);
	printf("findSecondNumber = %d \r\n", max_num2);
	for(int i = 0; i<length; i++)
	{
		printf("%d\t",arr[i]);
	}
	
}
