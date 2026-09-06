#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<string> v;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1=="Rock"&&s2=="Scissors") v.push_back("Player1");
		else if(s2=="Rock"&&s1=="Scissors") v.push_back("Player2");
		else if(s1=="Paper"&&s2=="Rock") v.push_back("Player1");
		else if(s2=="Paper"&&s1=="Rock") v.push_back("Player2");
		else if(s1=="Scissors"&&s2=="Paper") v.push_back("Player1");
		else if(s2=="Scissors"&&s1=="Paper") v.push_back("Player2");
		else v.push_back("Tie");
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	return 0;
}