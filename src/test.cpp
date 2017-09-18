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
	console.time(4);
	console.log("hehe");
	console.timeEnd('g');
	console.group("log type test");
	console.assert(true,"hehe");
	console.info("info message");
	console.log();
	console.warn();
	console.error("hehe","error");
	console.group("nothing");
	console.log("hehe");
	console.timeEnd(4);
	console.groupEnd();
	console.log("132");
	console.groupEnd();
	console.log("132");
	console.groupEnd();
	console.log("132");
	
	return 0;
}