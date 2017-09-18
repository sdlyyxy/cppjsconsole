#include "cppjsconsole.h"
#include <map>
int main()
{
	console.clear();
	console.time("loop");
	std::map<int, int> m;
	for (int i = 0; i < 80000; i++)
	{
		m[i] = i;
	}
	console.timeEnd("loop");
	console.group("Languages:");
	char *s[] = {"Chinese", "English", "Spanish", "Linyi Hua"};
	for (int i = 0; i < 4; i++)
	{
		console.log(s[i]);
	}
	console.groupEnd();
	console.assert(true, "hehe");
	console.info("Will exit,", 88, '!');

	return 0;
}