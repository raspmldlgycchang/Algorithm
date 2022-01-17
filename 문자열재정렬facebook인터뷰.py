#str을 변수명으로 사용시 str(정수형)함수 사용시 str is not callable에러
str_ = input()
result = []
value = 0

for k in range(len(str_)):
    #문자인 경우
    if (ord('A')<=ord(str_[k])<=ord('Z')):
        result.append(str_[k])
    else:
        value += int(str_[k])
'''
for i in range(len(result)):
    #버블정렬이용(시간복잡도 N^2)
    for j in range(len(result)-1, i, -1):
        if result[j]<result[j-1]:
            result[j-1], result[j] = result[j], result[j-1]
'''
'''
#퀵정렬
def quick_sort(array, start, end):
    if start >= end:#원소가 1개인 경우
        return
    pivot = start#피벗원소는 시작원소
    left = start+1
    right = end
    while(left<=right):
        #피벗을 잡고 만약 더 크면 바꾸고 둘 숫자간(왼쪽, 오른쪽)
        #피벗보다 큰 데이터 찾을 때까지 반복
        while(left<=end and array[left]<=array[pivot]):
            left+=1
        #피벗보다 작은 데이터 찾을 때까지 반복
        while(right>start and array[right]>=array[pivot]):
            right-=1
        if(left >= right):#만약 엇갈렸다면 작은수에 해당하는 array[right]와 피봇인덱스에 해당하는 원소 swap
            array[right], array[pivot] = array[pivot], array[right]#작은수와 피봇을 바꾸기
        else:#엇갈리지 않았다면
            array[left], array[right] = array[right], array[left]#왼쪽과 오른쪽 수
            #간에 바꾸기
    #엇갈렸다면 while문을 나와서 피봇 왼쪽, 오른쪽 배열에 대한 퀵정렬수행
    quick_sort(array, start, right-1)#왼쪽배열에 대해(피봇왼쪽) 퀵정렬
    quick_sort(array, right+1, end)#오른쪽배열에 대해(피봇오른쪽) 퀵정렬

quick_sort(result, 0, len(result)-1)
'''
result.sort()
if value!=0:
    integer= str(value)
    result.append(integer)
result = ''.join(s for s in result)
print(result)
