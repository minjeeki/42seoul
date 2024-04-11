# 퀵 정렬 (quick sort)

### 퀵 정렬의 개념

- 분할-정복법 (divide and conquer)에 근거해 전체 리스트를 2개의 부분 리스트로 분할하고 각각의 부분 리스트를 다시 퀵 정렬하는 방식을 사용
- 분할-정복법을 사용한다는 점에서 합병 정렬과 동일하지만 리스트를 비균등하게 분할한다는 점에서 차이를 보인다.
    - 리스트 요소 중 하나를 피벗(pivot)으로 선택한 후 피벗을 기준으로 작을 경우 피벗의 왼쪽으로, 클 경우 피벗의 오른쪽으로 옮긴다.
    - 각각의 부분 리스트에 대해 퀵 정렬을 순환호출해서 부분 리스트를 정렬한다 (부분 리스트에서도 피벗을 선택한 후 피벗을 기준으로 분할이 불가능할 때까지 나눔)
- 평균적으로 매우 빠른 수행 속도를 자랑하는 정렬 방법

### 퀵 정렬 알고리즘

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

void quick_wort(int list[], int left, int right);
int partition(int list[], int left, int right);

int main(void)
{
	n = MAX_SIZE;
	srand(time(NULL));
	for (int i=0; i<n; i++)
		list[i] = rand() % 160;
	
	quick_sort(list, 0, n-1);
	return(0);
}

void quick_sort(int list[], int left, int right)
{
	// 정렬할 범위가 2개 이상이라면
	if (left < right)
	{
		// partition 함수를 호출해 리스트를 피벗을 기준으로 분할
		// partition 함수 반환값으로는 피봇의 위치로 설정
		int pivot = partition(list, left, right);
		// left ~ (pivot-1)까지의 범위에 대해 퀵 정렬 순환 호출
		quick_sort(list, left, pivot-1);
		// (pivot+1) ~ right까지의 범위에 대해 퀵 정렬 순환 호출
		quick_sort(list, pivot+1, right);
	}
}

int partition(int list[], int left, int right)
{
	int pivot, tmp;
	int low, high;
	
	low = left;
	high = right + 1;
	// 피봇 설정은 코드의 편의성을 위해 임의로 배열 첫 인덱스로 설정
	pivot = list[left];
	do
	{
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		if (low < high)
			SWAP(list[low], list[high], tmp);
	} while (low < high);
	
	SWAP(list[left], list[high], tmp);
	return (high);
}
```

### 퀵 정렬의 복잡도 분석

- O(n * \log_2(n))의 평균 복잡도를 가지는 알고리즘을 가짐
    - 분할 정복의 개념을 사용하기 때문에 레코드 리스트는 크기가 1이 될 때까지 n/2^k 크기로 나눠지기에, k = \log_2(n)의 순환 호출이 이뤄진다.
    - 각각의 순환 호출에서 n번의 비교가 발생하기에 비교 연산은 총 n*\log_2(n)번 실행된다.
- 최악의 경우 O(n^2)의 시간 복잡도를 가진다.
    - 퀵 정렬이 가질 수 있는 최악의 경우는 피벗 설정으로 부분 리스트를 나누지 못하고 불균등하게 나눠지는 상황에서 발생한다.
    - 총 n번의 패스가 실행되고 각각의 패스에서 n번의 비교가 이뤄지기에 n * n의 비교 연산이 발생한다.