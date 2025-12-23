#include <stdio.h>
int main()
{
	char* c[]={"ENTER","NEW","POINT","FIRST"};
	char** cp[]={c+3,c+2,c+1,c};
	char*** cpp=cp;
	printf("%s\n",**++cpp);
	printf("%s\n",*-- * ++cpp +3);  //1.++cp 2.*++cp 3.--*++cp 4.*--*++cp 5.*--*++cpp +3
	printf("%s\n",*cpp[-2]+3);      //cpp[-2]--> *(cpp-2)
	printf("%s\n",cpp[-1][-1]+1);  //cpp[-1][-1]--> *(*(cpp-1)-1)
	return 0;
}