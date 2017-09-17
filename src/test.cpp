#include"cppjsconsole.h"
#include<map>
int main(){
	console.clear();
	console.time("loop");
	std::map<int,int> m;
	for(int i=0;i<80000;i++){
		m[i]=i;
	}
	console.time('g');
	console.timeEnd("loop");
	//cout<<"orz"<<endl;
	console.log("hehe");
	console.timeEnd('g');
	console.assert(false,"hehe");
	return 0;
}