# 리스트

### 정의

- 순서가 있는 데이터의 모음으로, 각 요소는 특정 위치 (인덱스)에 저장됨

- 여러개의 자료(데이터)를 위치에 따라 구분해 순서대로 저장하고 관리하는데 사용되는 기본적인 자료 구조

### 특징

- 자료구조 스택과 큐도 리스트에 포함되는 개념임

- 각 요소는 고유한 인덱스 번호를 갖고 있으며, 이는 검색 또는 수정 (특정 위치에 값 변경, 추가, 삭제)에 사용됨

- 하나의 리스트 내에는 같은 요소가 여러번 포함될 수 있음

- 리스트에는 요소 추가, 삭제, 검색, 정렬 등의 다양한 연산이 가능함

### 리스트 ADT 연산

- 삽입 연산

- 삭제 연산

- 탐색 연산 (전체, 특정 요소)

- 리스트 길이 / 리스트 비어있는지 여부 확인 / 리스트 가득 차있는지 여부

### 집합과의 비교

- 공통점 : 여러 항목을 모아서 저장하는 구조

- 요소 중복 여부 : 리스트는 중복 가능 / 집합은 중복 불가능

- 요소 순서 여부 : 리스트는 인덱스 할당해 순서를 기억함 / 집합은 요소의 순서를 보장하지 않고 정렬 및 추가된 순서를 기억하지 않음

- 데이터 접근 방식 : 리스트는 인덱스를 사용해 요소에 접근 / 집합은 검색을 통해 데이터 접근 (존재 여부 확인에는 효율적임)

	---

- 리스트는 요소의 위치를 유지하고 싶을 때, 중복을 허용하는 상황에서 유용함

- 집합은 중복된 요소를 허용하지 않고, 특정 요소의 존재 여부만을 확인하는 것이 주 목적일 때 사용 & 집합 연산(교집합, 합집합, 차집합 등)에 유용

### 리스트 구현

: 리스트는 '배열', '연결 리스트'를 이용해 구현할 수 있음

- 배열을 통한 구현 : 순차적인 표현 방법

	- 장점 1. 가장 간단한 방식의 구현 방법

	- 장점 2. 탐색 속도가 빠름 => O(1)

	- 단점 1. 크기가 고정되기에 크기의 동적 증가(요소 추가) 및 감소(요소 삭제)할 때 힘듦 => 리스트 중간에 데이터 삽입, 삭제 시 기존 데이터의 위치 이동이 필요함

	- [배열을 통한 구현](./list_by_array.md)

- [연결 리스트](./linked_list.md)를 통한 구현 : 비순차적인 표현 방법

	- 장점 1. 크기의 제한이 없어 중간 삽입 및 삭제가 간편한 등 비교적 유연한 형태를 가짐

	- 단점 1. 구현이 복잡합 (오류가 발생할 지점이 많음, 데이터와 포인터 값을 저장해야 하기에 메모리 공간을 많이 사용함)

	- 단점 2. 탐색 속도가 배열보다 오래 걸림 (첫번째 데이터부터 순차적으로 접근해야 함)

	- [연결 리스트를 통한 구현](./list_by_linked_list.md)