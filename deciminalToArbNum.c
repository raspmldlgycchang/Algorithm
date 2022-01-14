#include<stdio.h>
//1024이전의 숫자를 넣어준다고 가정하고
//이진수 
#define MAX_MODULUS 10
int main(void)
{
	int num;
	int modulusArr[MAX_MODULUS] = {0,};
	int divNum;//표현하고자 하는 진법
	int i = 0;
	scanf_s("%d", &num);
	fputs((char*)"표현하고자 하는 진법?: ", stdout);
	rewind(stdin);
	scanf_s("%d", &divNum);
	//an(2^(n+1)으로 나눌 때 나머지를 구해서 저장할 때 modulusArr[n]에 저장될 것)을 구하려면
	//2^(n+1)으로 나누는 반복문 인덱스도 돌아야 하기 때문에 or조건으로 modulus[n-1]이 들어가서
	//an도 구할 수 있게 해야한다
	//do{
	// //ai == modulus[i]를 구하는 작업
	//}while (modulusArr[i] || num /= divNum);
	//하지만 위의 코드는 lvalue수정 불가 에러가 뜨므로
	//아래처럼 modulus를 구하는 과정을 수행한다
	//i를 증가시켜서 ai를 구하기 전 그리고나서 num을 divNum으로 나눠주기전
	//while문에서 하게 될 작업들을 미리 점검한 뒤 while문 안에서 이 작업을 해준다
	while(num%divNum!=0 || num/divNum!=0){
		modulusArr[i] = num % divNum;
		i++; num /= divNum;
	}
	//예를 들어 이진수로 표현시 가장 높은 자리의 값이 2^(n+1)으로 나눈 나머지인 an이므로
	//가장 마지막 원소부터 출력
	//이것을 위해서 i를 위에서 while문 밖에 선언했습니다
	//an을 구하기 위해서 num%divNum!=0을 while문에서 점검을 했어야 했고
	//do~while문을 쓰지 못하고 while문을 쓴 이유입니다
	//따라서 위의 while문에서 an을 구할 때 i++;의 while문안을 수행했으므로 
	//i를 감소시킵니다
	for (int j = i - 1; j >= 0; j--) {
		printf("%d", modulusArr[j]);
	}
	printf("\n");
	return 0;
}