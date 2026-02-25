 typedef struct BiTNode
 {
 	int data;
 	struct BiTNode* LeftChild;
 	struct BiTNode* RightChild;
 }BiTNode;
 
 //全局变量
 BiTNode* p;            //p指向目标节点
 BiTNode* pre=NULL;     //指向当前节点的前驱
 BiTNode* result=NULL;  //用来保存找到目标节点的前驱
 
 void FindPre(BiTNode* T) //T是指向二叉树的根节点的指针
 {
 	if(T!=NULL){
 		FindPre(T->LeftChild);
 		Visit(T);        //注意：这里没有&，T在函数里是指向节点的指针
 		FindPre(T->RightChild);
	 }
 }
 
 //访问当前节点
 void Visit(BiTNode* q){
 	if(q==p){
 		result=pre;
	 }else{
	 	pre=q;     //pre指向当前访问的节点
	 }
 }