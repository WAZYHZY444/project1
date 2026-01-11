#include <stdio.h>
#include <string.h>
#include <ctype.h>
void tolowerStr(char* str,int n)
{
	for(int i=0;i<n;i++){
		str[i]=tolower(str[i]);
	}
}
int main()
{
	char word[100];
	char article[1000000];
	int wordlen;
	int count=0,found=-1;  //found的作用是为了来标记第一次找到相同单词的位置，设置为-1是方便对应题目条件：如果单词在文章中没有出现，则直接输出一个整数-1
	int articlelen=0;
	
	fgets(word,sizeof(word),stdin);
	fgets(article,sizeof(article),stdin);
	
	//手动去除掉fgets带来的末尾的换行符'\n',如果不去除，word的'abc'会变成'abc\n'，这在文章中永远找不到
	for(int i=0;word[i]!='\0';i++){
        if(word[i]=='\n'){
            word[i]='\0';
            break;
        }
    }
    //word[strcspn(word,"\n")]='\0';
    
    for(int i=0;article[i]!='\0';i++){
        if(article[i]=='\n'){
            article[i]='\0';
            break;
        }
    }
	//article[strcspn(article,"\n")]='\0';
	
	wordlen=strlen(word);
	articlelen=strlen(article);
	tolowerStr(word,wordlen);
	tolowerStr(article,articlelen);
	
	int i=0;
	//跳过文章开头是空格
	while(i<articlelen){
		while(i<articlelen&&article[i]==' '){
			i++;
		}
		if(i<articlelen&&(article[i]>='a'&&article[i]<='z')){  //article[i]>='a'&&article[i]<='z'--->isalpha(article)
			int start=i;
			char temp_word[100];   //创建一个临时数组，将单词赋值给它
            int j=0;
            //提取单词直到遇见空格
            while (i<articlelen&&(article[i]>='a'&&article[i]<='z')){
                temp_word[j] = article[i];
                i++;
                j++;
            }
            temp_word[j]='\0';  //手动加上结束字符
            if(strcmp(temp_word,word)==0){
            	count++;        //计算相同单词的数量
            	if(found==-1){
            		found=start;
				}
			}
		}else{
			i++;    //如果遇到非字母非空格,跳过它
		}
	}
	if(count>0){
		printf("%d %d\n",count,found);
	}else{
		printf("-1\n");
	}
	return 0;
}