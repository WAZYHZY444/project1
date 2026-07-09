#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNext(int next[],string pattern,int len)
{
	int i=1,j=0;
	next[0]=0;
	while(i<len){
		if(pattern[i]==pattern[j]){
			j++;
			next[i]=j;
			i++;
		}
		else{
			if(j!=0) j=next[j-1];
			else next[i++]=0;
		}
	}
}

vector<int> KMP_Match(string text,string pattern)
{
	vector<int> res;  //存储所有匹配的起始位置
	
	int len1=text.size();
	int len2=pattern.size();
	if(len2==0){
		res.push_back(0);
		return res;
	}
	
	int next[len2];
	getNext(next,pattern,len2);
	
	int i=0,j=0;
	while(i<len1){
		if(text[i]==pattern[j]){
			i++;
			j++;
		}
		if(j==len2){
			res.push_back(i-len2);
			//继续匹配时，让j退回到next[j-1]以查找重叠匹配
			j=next[j-1];
		}
		else if(i<len1&&text[i]!=pattern[j]){
			if(j!=0) j=next[j-1];
			else i++;
		}
	}
	return res;
}

int main()
{
	string text;
	string pattern;
	cin>>text>>pattern;
	vector<int> result=KMP_Match(text,pattern);
	if(result.empty()){
		cout<<"未找到匹配"<<endl;
	}else{
		for(int s:result){
			cout<<s+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}