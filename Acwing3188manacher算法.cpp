#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2*1e8+10;
string b,a;
int len[N]; //以每个字符为中心的回文长度的一半，向下取整