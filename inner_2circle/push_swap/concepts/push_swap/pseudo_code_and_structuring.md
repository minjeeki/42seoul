# push_swap() 과제 살펴보기

## 과제 핵심 및 개념 키워드

### 과제 핵심

* int 값, 2개의 스택, 스택 명령어 집합을 이용해 정해진 스택 명령어를 가능한 적게 사용해서 정렬 후 사용된 명령어를 표준 출력 (명령어는 \n으로만 구분되어 출력되어야 함)

### 과제 키워드 및 필요 작업

* 스택 구현
	* 자료구조 (stack, queue, deque, array, linked list)
		* 사람들이 많이 사용하는 구조는 양방향 연결 리스트를 이용한 deque
		* 내가 시도할 방법 : argc-1 크기만큼의 배열 2개로 front, rear의 두개의 정수값을 가진 구조체 형태
	* 인자 파싱 및 예외 처리
		* 예외 처리 : "error\n" 표준 출력 후 exit(1); 로 프로그램 중단
		1. ft_error() 함수 구현 : 에러처리 문자 출력 후 프로그램을 중단시키는 함수
		2. ft_strtol() 함수 구현
			* 숫자가 아닌 문자열이 들어올 경우 ft_strtol() 함수 내부에서 ft_error() 함수 호출
		3. argv 배열에서 하나씩 값 받아오면서 ft_strtol() 함수로 결과 도출
			* 정수 범위를 넘는 값이 들어올 경우 ft_error() 함수 호출
		4. 자료 구조에 넣기 전 정수 크기만큼의 배열 준비 (INT_MAX + 1 = -1과 같이 처리)
			* 초기 배열은 0 값을 가짐
			* 값에 해당하는 인덱스 위치의 값이 0일 경우 1로 값을 바꾸고 만들어둔 자료 구조에 담음
			* 값에 해당하는 인덱스 위치의 값이 1일 경우 중복된 것을 의미하기에 ft_error() 함수 호출

* 스택 명령어 구현

	> 명령어는 push, pop 함수를 구현한 후 명령어에 맞춰서 진행할 수도 있음

	* swap(배열) : 배열 인덱스 front와 front+1의 값 변경
	* push(배열_from, 배열_to) : from 배열 인덱스 기존 front에 있는 것을 to 배열 front-1 후 front로 붙임
	* rotate(배열) : 배열 front의 위치를 +1 하고, 기존 front 인덱스의 값을 복사해 rear +1 후 rear에 붙임
	* reverse_rotate(배열) : 배열 rear 위치를 -1 하고, 기존 rear 인덱스 값을 front -1 gn front에 붙임

* 정렬 알고리즘 : merge sort, quick sort, radix sort 등이 큰 범위의 데이터 값 정렬에 주로 사용

* 복잡도 (complexity) : 알고리즘의 효율성을 나타내는 지표

### 파일 구조

* 만들어야 하는 파일 : Makefile, *.h, *.c (기존에 만들어둔 libft 파일 사용 가능)

	* main.c : main() / ft_error() / ft_validate_arg()
	* commands.c : swap() / push(from, to) / rotate()
	* sort.c : 정렬 알고리즘에 필요한 함수
	* semi_libft.c : strtol()과 같이 표준 라이브러리 함수와 거의 유사한 기능을 하는 것