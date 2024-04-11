# 합병 정렬 (merge sort)

- 출처 : C언어로 쉽게 풀어쓴 자료구조 (천인국 외 저)

### 합병 정렬 개념

- 분할 정복 기법을 바탕으로 두고 있는 알고리즘
    - 분할 정복 (divide and conquer) 기법
    : 문제는 작은 2개의 문제로 분리하고 각각을 해결한 다음 결과를 모아 원래의 문제를 해결하는 전략
        - 대개 순환 호출을 통해 큰 문제에서 작은 문제로 쪼개고 작은 문제에서 전체로 해결하는 구조를 가짐
- 하나의 리스트를 두개의 균등한 크기로 분할한 뒤 분할된 부분 리스트 정렬한다. 두개의 정렬된 부분 리스트 합쳐 전체 리스트의 정렬을 완료한다.
    1. 분할 (Divide) : 입력 배열을 같은 크기의 2개의 부분 배열로 분할
        
        > Q. 분할 포인트를 어떻게 잡을 것인가?
        > 
        > 
        > ⇒ 다양한 기준을 가질 수도 있겠지만 책에서는 배열의 전체 크기 (가장 작은 인덱스 ~ 가장 큰 인덱스)를 기준으로 함
        > 
    2. 정복 (Conquer) : 부분 배열을 정렬한다. 부분 배열의 크기가 충분히 작지 않으면 순환 호출을 이용해 다시 분할 정복 기법을 적용
        
        > Q. 각각의 부분 배열들은 어떻게 정렬할 것인가?
        > 
        > 
        > ⇒ 합병 정렬을 순환적으로 적용하는 방식으로 진행
        > 
        > (합병 정렬 함수의 순환적 호출을 이용해 구현)
        > 
    3. 결합 (Combine) : 정렬된 부분 배열들을 하나의 배열에 통합
        - 분할 기준이 배열의 인덱스를 기준으로 했다면, 부분 배열의 가장 큰 우선순위부터 대소를 비교하며 전체 배열에 넣고 각 부분 배열의 인덱스를 증가시키는 방향으로 진행함

### 인덱스 크기 기반 합병 정렬 작성 코드

```c
#include <stdlib.h>
#include <stdio.h>

int merge_sort(int *list, int left, int right);
int merge(int *list, int left, int mid, int right);

int main(int argc, char *argv[])
{
	int *list;
	
	//  커맨드 라인의 인수를 담을 동적 할당 배열
	list = (int *)malloc((argc - 1) * sizeof(int));
	if (list == NULL)
	{
		printf("malloc failed");
		exit (1);
	}
	// 커맨드 라인의 인수는 문자열 형태이기에 정수형으로 변환 후 순차적으로 담아줌
	for (int idx = 0; idx < (argc-1); idx++)
		list[idx] = atoi(argv[idx + 1]);
	// 정렬이 필요한 경우 (인자가 2개 이상) merge_sort로 list를 정렬해줌
	if (argc > 2)
		return (merge_sort(list, 0, argc - 2);
}

int merge_sort(int *list, int left, int right)
{
	int mid;
	if (left < right)                      // 만약 나눠진 구간의 크기가 1 이상이면?
	{
		mid = (left + right) / 2;            // 중간 위치를 계산 (균등 분할)
		merge_sort(list, left, mid);         // 부분 배열 정렬을 위해 merge_sort 순환
		merge_sort(list, mid+1, right);      // 부분 배열 정렬을 위해 merge_sort 순환
		if (merge(list, left, mid, right))   // 부분 배열 통합해 정렬된 배열로 만듦
			exit (1);
	}
	return (0);
}

int merge(int *list, int left, int mid, int right)
{
	int *sorted;
	int idx_part_a, idx_part_b, idx_sorted;
	int idx_remain, idx_copy;
	
	sorted = (int *)malloc((right - left + 1) * sizeof(int));
	if (sorted == NULL)
	{
		printf("malloc failed");
		exit (1);
	}
	// 각각의 부분배열의 첫번째 인덱스부터 확인하며 정렬된 임시배열 sorted 만들기
	idx_part_a = left, idx_part_b = mid+1, idx_sorted = 0;
	while (idx_part_a <= mid && idx_part_b <= right)
	{
		sorted[idx_sorted++] = (list[idx_part_a] <= list[idx_part_b])
			? list[idx_part_a++]
			: list[idx_part_b++];
	}
	// 하나의 부분 배열의 정렬이 완료된 경우 순회하지 못한 부분 배열의 요소들을 그대로 sorted에 붙임
	if (idx_part_a > mid)
	{
		for (idx_remain = idx_part_b; idx_remain <= right; idx_remain++)
			sorted[idx_sorted++] = list[idx_remain];
	}
	else
	{
		for (idx_remain = idx_part_a; idx_remain <= mid; idx_remain++)
			sorted[idx_sorted++] = list[idx_remain];
	}
	// sorted의 배열 상태를 원본 배열 list에 복사
	idx_copy = left, idx_remain = 0;
	for (idx_copy = left; idx_copy <= right; idx_copy++)
	{
		list[idx_copy] = sorted[idx_remain];
		idx_remain++;
	}
	free(sorted);
	return (0);
}
```

> 코드 작성하다가 새롭게 알게 된 사실
> 
> 
> : 함수의 인자로 배열을 넣을 경우 list[]와 *list로 넣을 때 원본 배열의 변화가 존재하는가?
> 
> ⇒ call by value(값에 의한 전달)와 call by reference(참조에 의한 전달)에 대한 개념 미흡 및
> list[] 의 의미 (list[]와 *list)에 대한 개념 정의를 명확하지 않았다는 점에서 발생한 문제
> 
> - C와 C++ 같은 언어에서 함수에 전달되는 인자는 일반적으로 Call by Value 방식을 따르기 때문에 문자, 정수, 실수형 자료형을 인자로 넣을 경우 원본 자료형에는 변화가 없다. 함수 내부의 결과로 원본 자료형에 변화를 주기 위해서는 포인터를 통해 변수의 주소를 전달하고 이를 참조해 값을 변경하는 것이다.
>     - Call by Value : 함수에 전달되는 인자의 값이 복사되어 함수 내에 새로운 변수로 사용
>     (함수 내 인자의 값이 변경되어도 호출된 쪽에는 영향을 주지 않음)
>     - Call by Reference : 함수에 전달되는 인자의 주소가 전달되어 변수의 참조를 통해 값을 변경
>     (함수 내에서 인자의 값이 변경되면 호출된 쪽에도 영향을 줌)
> - list[]는 배열의 첫번째 요소를 가리키는 포인터 (첫번째 요소가 담긴 주솟값)을 전달하는 것이기에 *list와 동일한 역할을 하고, 함수의 인자로 사용되더라도 포인터가 전달되는 것이기에 C언어가 Call by Value 방식을 취하고 있다고 하더라도 두 형태 모두 포인터의 전달이기에 원본 자료형에 변화를 준다.

### 합병 정렬의 복잡도 분석

- 부분 배열을 합치는 merge() 함수 단계에서 비교 연산과 이동 연산이 수행된다.
    - merge() 함수는 순환호출의 깊이만큼 이뤄지며, 한번의 병합에서 최대 n번의 비교 연산이 이뤄짐
    ⇒ $n * \log_2(n)$
        - 순환호출의 깊이 > k = $\log_2(n)$
            
            : 순환 호출 구조로 되어 있는 합병 정렬에 대해서 레코드의 개수 n이 2의 거듭제곱이라고 가정할 때,
            
            - n = 2^3일 경우 부분 배열의 크기가 2^3 → 2^2 → 2^1 → 2^0 순으로 줄어듦
            호출의 깊이는 3
    - 한번의 병합에서 총 부분 배열에 들어 있는 요소의 개수가 n개인 경우 레코드의 이동 연산이 2n번 발생함
        
        ⇒ $2n * \log_2(n)$
        
- 결론적으로 합병 정렬은 $O(n\log_2(n))$의 정렬방법이다.

---

- 합병 정렬의 시간 복잡도가 최선, 평균, 최악의 경우가 별 차이가 없는 이유
    - 분할 과정의 일관성 : 입력 배열의 형태에 상관 없이 항상 동일한 방식 (입력 배열을 반으로 나눠 정렬 후 병합)으로 이뤄지기에 시간 복잡도에 큰 영향을 미치지 않는다.
    - 분할 및 정렬 과정에서 항상 균형 있는 분할을 수행하기에 최악의 경우에도 균등한 분할이 일어난다.
    - 분할과 병합 과정은 입력 크기에 따라 로그 시간의 복잡도를 갖고, 최선/평균/최악의 경우에도 분할 과정의 반복 횟수가 동일하다.
    
    ⇒ 정렬의 상태에 따라 병합이 이뤄지는 것이 아니고, 입력 크기에 따른 로그 시간의 복잡도를 갖는 것이기에 최선, 평균, 최악의 경우에 상관없이 항상 동일한 방식으로 정렬이 이뤄진다.
    (정렬의 상태가 정렬되지 않은 경우, 정렬된 경우 상관없이 입력 크기에 관계한 방식으로 동작하기에 거의 동일한 방식으로 동작한다)
    

### 합병 정렬의 특징

- 합병 정렬의 단점
    - 임시 배열이 필요하다.
    - 레코드의 크기가 큰 경우 이동 횟수가 많기에 시간적 낭비를 유발함
        
        단, 레코드를 연결 리스트로 구성해 합병 정렬을 할 경우 링크 인덱스만 변경되기에 데이터의 이동은 무시할 수 있을 정도로 작아진다.
        
        ⇒ 크기가 큰 레코드를 정렬하는 경우, 연결 리스트를 사용하면 퀵 정렬보다 효율적일 수 있음