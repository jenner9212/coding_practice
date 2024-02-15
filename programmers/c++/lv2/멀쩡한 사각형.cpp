using namespace std;

long long gcd(int x, int y){
    if(y == 0) return x;

    return gcd(y, x % y);
}

long long solution(int w,int h) {
    long long answer = 1;

    long long total_square = (long long)w * h;

    long long s_gcd = gcd(w, h);
    long long wgcd = (long long)w / s_gcd;
    long long hgcd = (long long)h / s_gcd;

    long long tcount = wgcd + hgcd - 1;

    answer = total_square - s_gcd * tcount;

    return answer;
}