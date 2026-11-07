#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> res;

bool isValid(const string& s,int l,int r)
{
	int len=r-l+1;
	if(len<=0||len>3) return false;
	if(len>1&&s[l]=='0') return false;  //前导有0
	int num=0;
	for(int i=l;i<=r;i++){
		if(s[i]<'0'||s[i]>'9') return false; 
		num=num*10+(s[i]-'0');  //测试用例好像混入负号的情况
	}
	return num<=255;
}

//i表示当前处理的索引位置，count表示已经切割好的段数（不超过4），当前已经拼接好的段
void backTrack(const string& s,int i,int count,string str)
{
	int len=s.size();
	if(count==4){
		if(i==len) res.push_back(str);
		return;
	}
	int rest=len-i;
	if(rest<1*(4-count)||rest>3*(4-count)) return;
	
	for(int k=1;k<=3&&i+k<=len;k++){
		int r=i+k-1;  //i后面加上k个字符的右索引
		if(!isValid(s,i,r)) continue;  //检测i后面加上k个字符所形成的字符串是否合法，直到合法
		
		string part=s.substr(i,k);  //将s串从索引为i的位置截取长度为k
		string result=(count==0)?part:str+"."+part;
		backTrack(s,i+k,count+1,result);
	}
}

int main(){
	int n;
	cin>>n;
	vector<string> result;
	while(n--){
		string s;
		cin>>s;
		res.clear();  //每一组开始前要清空res
		backTrack(s,0,0,"");
		if(res.empty()) result.push_back("-1");
		else{
			for(int i=0;i<res.size();i++){
				result.push_back(res[i]);
			}
		}
	}
	for(int i=0;i<result.size();i++){
		cout<<result[i];
		cout<<endl;
	}
	return 0;
}