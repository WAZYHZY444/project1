//C++排序函数：sort
//必须包含头文件  #include <algorithm>
//传参必须传入两个参数，一个起始位置，一个结束位置
//对int、char、double、bool、字符串都适用

//int
vector<int> nums = {5, 2, 8, 1, 9};
sort(nums.begin(), nums.end()); 

//字符串
#include <string>
vector<string> names = {"Charlie", "Alice", "Bob"};
sort(names.begin(), names.end());  
//结果：{"Alice", "Bob", "Charlie"}（字典序）

//结构体
//方法一：
struct Student{
	string name;
	int score;
	int age;
	
	//重载小于运算符
	bool operator<(const Stuent& s) const{
		return score<s.score;
	}
};

vector<Student> students={
    {"Alice",90,20},
    {"Bob",85,19},
    {"Charlie",95,21},
    {"David",85,22}
};
    
sort(students.begin(),students.end());

//方法二：
struct Student {
    string name;
    int score;
    int age;
};

vector<Student> students={
    {"Alice",90,20},
    {"Bob",85,19},
    {"Charlie",95,21},
    {"David",85,22}
};

// 比较函数：按分数降序
bool compareByScoreDesc(const Student& a, const Student& b) {
    return a.score > b.score;   //降序
}

// 比较函数：按姓名升序
bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;    //升序
}

sort(students.begin(), students.end(), compareByScoreDesc);
sort(students.begin(), students.end(), compareByName);