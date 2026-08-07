#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<double> v;
	v.push_back(2/1*1.0);
	double p1=1.0,q1=2.0;
	for(int i=1;i<n;i++){
		double pn,qn;
		qn=q1+p1;
		pn=q1;
		v.push_back(qn/pn);
		p1=pn;
		q1=qn;
	}
	double sum=0.0;
	for(int i=0;i<v.size();i++){
		sum+=v[i];
	}
	printf("%.4f\n",sum);
	return 0;
}