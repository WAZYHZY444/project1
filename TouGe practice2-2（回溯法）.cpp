#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int minCut=INT_MAX;  //最优切割次数

bool isHuistring(const string& s,int start,int end)
{
	while(start<end){
		if(s[start]!=s[end]) return false;
		start++;
		end--;
	}
	return true;
}

void backTrack(const string& s,int start,int cut)
{
	if(cut-1>=minCut) return;
	//到达末尾，处理完了
	if(start==s.size()){
		minCut=min(minCut,cut-1);  //cut-1因为最后一段不用切
		return;
	}
	for(int i=start;i<s.size();i++){
		if(isHuistring(s,start,i)){
			backTrack(s,i+1,cut+1);
		}
	}
}

int cut(string s)
{
	if(s.empty()) return 0;
	minCut=INT_MAX;
	backTrack(s,0,0);
	return minCut;
}

int main()
{
	int n;
	vector<int> v;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int res=cut(s);
		v.push_back(res);
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	return 0;
}