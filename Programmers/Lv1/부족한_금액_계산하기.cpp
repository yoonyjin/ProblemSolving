using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    // 처음 풀이 
    for (int i = 1; i <= count; i++)
    {
        answer += price * i;
    }

    // 가우스 공식 활용
    // 3*1 + 3*2 + 3*3 + 3*4 = 3(1+2+3+4)
    // price * (count * (count+1) / 2)
    // 형변환 안 해주면 answer < money 일 경우 int로 반환돼서 틀림 
    //answer = (long long)price * (count * (count + 1) / 2);
    return answer > money ? answer - money : 0;
}
