#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int res[k][2];
	for(int num=0;num<k;num++){
		int x,y;
		cin>>x>>y;
		string op;
		cin>>op;
		int dx=x,dy=y;
		for(int i=0;i<op.size();i++){
			if(op[i]=='f'&&(dy+1)<=n) dy+=1;
			if(op[i]=='b'&&(dy-1)>=1) dy-=1;
			if(op[i]=='l'&&(dx-1)>=1) dx-=1;
			if(op[i]=='r'&&(dx+1)<=n) dx+=1;
		}
		res[num][0]=dx;
		res[num][1]=dy;
			
//		if(dx>n||dy>n||dx<1||dy<1){
//			res[num][0]=x;
//			res[num][1]=y;
//		}else{
//			res[num][0]=dx;
//			res[num][1]=dy;
//		}
	}
	for(int i=0;i<k;i++){
		cout<<res[i][0]<<" "<<res[i][1]<<endl;
	}
	return 0;
}