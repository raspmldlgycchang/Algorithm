#include<stdio.h>
//1024������ ���ڸ� �־��شٰ� �����ϰ�
//������ 
#define MAX_MODULUS 10
int main(void)
{
	int num;
	int modulusArr[MAX_MODULUS] = {0,};
	int divNum;//ǥ���ϰ��� �ϴ� ����
	int i = 0;
	scanf_s("%d", &num);
	fputs((char*)"ǥ���ϰ��� �ϴ� ����?: ", stdout);
	rewind(stdin);
	scanf_s("%d", &divNum);
	//an(2^(n+1)���� ���� �� �������� ���ؼ� ������ �� modulusArr[n]�� ����� ��)�� ���Ϸ���
	//2^(n+1)���� ������ �ݺ��� �ε����� ���ƾ� �ϱ� ������ or�������� modulus[n-1]�� ����
	//an�� ���� �� �ְ� �ؾ��Ѵ�
	//do{
	// //ai == modulus[i]�� ���ϴ� �۾�
	//}while (modulusArr[i] || num /= divNum);
	//������ ���� �ڵ�� lvalue���� �Ұ� ������ �߹Ƿ�
	//�Ʒ�ó�� modulus�� ���ϴ� ������ �����Ѵ�
	//i�� �������Ѽ� ai�� ���ϱ� �� �׸����� num�� divNum���� �����ֱ���
	//while������ �ϰ� �� �۾����� �̸� ������ �� while�� �ȿ��� �� �۾��� ���ش�
	while(num%divNum!=0 || num/divNum!=0){
		modulusArr[i] = num % divNum;
		i++; num /= divNum;
	}
	//���� ��� �������� ǥ���� ���� ���� �ڸ��� ���� 2^(n+1)���� ���� �������� an�̹Ƿ�
	//���� ������ ���Һ��� ���
	//�̰��� ���ؼ� i�� ������ while�� �ۿ� �����߽��ϴ�
	//an�� ���ϱ� ���ؼ� num%divNum!=0�� while������ ������ �߾�� �߰�
	//do~while���� ���� ���ϰ� while���� �� �����Դϴ�
	//���� ���� while������ an�� ���� �� i++;�� while������ ���������Ƿ� 
	//i�� ���ҽ�ŵ�ϴ�
	for (int j = i - 1; j >= 0; j--) {
		printf("%d", modulusArr[j]);
	}
	printf("\n");
	return 0;
}