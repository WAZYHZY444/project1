#include <iostream>
#include <string>

using namespace std;

float revbolan(string s,int &i)
{
	while(s[i]==' ') i--;
	int len=0;
	while(s[i]>='0'&&s[i]<='9'||s[i]=='.'){
		i--;
		len++;
	}
	if(len>0){   //数字
		return stof(s.substr(i+1,len));
		//stof将字符串转化为float，补充stoi返回int类型，stol返回long类型
		//substr截取字符串，string substr(起始位置,截取长度)
	}
	
	char op=s[i];
	float x,y;
	x=revbolan(s,--i);  //递归确定子逆波兰表达式1
	y=revbolan(s,--i);  //递归确定子逆波兰表达式2
	if(op=='+') return y+x;
	else if(op=='-') return y-x;
	else if(op=='*') return y*x;
	else return y/x;
}

int main()
{
	string s;
	getline(cin,s);  //读整行，包含空格
	int i=s.length()-1;
	float res=revbolan(s,i);
	cout<<res<<endl;
	return 0;
}