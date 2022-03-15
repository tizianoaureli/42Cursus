#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>

#define namespace	std

int main()
{
	std::ofstream fileout ("originalSTL.txt");
	fileout << "************** TESTING VECTOR **************\n" << std::endl;

	namespace::vector<int> vec1(5,100);
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	namespace::vector<int> vec2(arr, arr+10);

	fileout << "Printing content: \n";
	namespace::vector<int>::iterator it1;
	fileout << "size : " << vec1.size() << std::endl;
	fileout << "max_size : " << vec1.max_size() << std::endl;

	for(it1 = vec1.begin(); it1 != vec1.end(); ++it1)
		fileout << "[vec1] : " << *it1 << std::endl;

	fileout << std::endl;
	fileout << "size : " << vec2.size() << std::endl;
	fileout << "max_size : " << vec2.max_size() << std::endl;
	for(it1 = vec2.begin(); it1 != vec2.end(); ++it1)
		fileout << "[vec2] : " << *it1 << std::endl;
	
	fileout << "\n\nTESTING COPY COSTRUCTOR\n" << std::endl;

	namespace::vector<int> vec3(vec2);
	fileout << "Printing content: \n";
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "max_size : " << vec3.max_size() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;

	
	fileout << "\n\nTESTING ASSIGN\n" << std::endl;
	vec2.assign(20, 20);
	fileout << "Printing content: \n";
	fileout << "size : " << vec2.size() << std::endl;
	fileout << "max_size : " << vec2.max_size() << std::endl;
	for(it1 = vec2.begin(); it1 != vec2.end(); ++it1)
		fileout << "[vec2] : " << *it1 << std::endl;

	fileout << "\n\nTESTING ERASE\n" << std::endl;
	vec3.erase(++(++(++vec3.begin())), --(--(--vec3.end())));
	fileout << "Printing content: \n";
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "max_size : " << vec3.max_size() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;

	
	fileout << "\n\nTESTING INSERT\n" << std::endl;
	vec3.insert(++(++(++vec3.begin())), vec2.begin(), vec2.begin()+4);
	fileout << "Printing content: \n";
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "max_size : " << vec3.max_size() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;


	fileout << "\n\nTESTING OPERATORS\n" << std::endl;
	fileout << "vec3 at(5) = " << vec3.at(5) << std::endl;
	fileout << "vec3 [9] = " << vec3[9] << std::endl;
	fileout << "vec3 front = " << vec3.front() << std::endl;
	fileout << "vec3 back = " << vec3.back() << std::endl;

	fileout << "\n\nTESTING SWAP\n" << std::endl;
	vec2.swap(vec3);
	fileout << "Printing content: \n";
	fileout << "size : " << vec2.size() << std::endl;
	fileout << "max_size : " << vec2.max_size() << std::endl;
	for(it1 = vec2.begin(); it1 != vec2.end(); ++it1)
		fileout << "[vec2] : " << *it1 << std::endl;
	fileout << "\n\n";
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "max_size : " << vec3.max_size() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;


	fileout << "\n\n************** TESTING STACK **************\n" << std::endl;
	namespace::stack<int, namespace::vector<int> > stack1 (vec2);

	fileout << "Printing content: \n";
	fileout << "size : " << stack1.size() << std::endl;
	while(stack1.size() != 0)
	{
		fileout << "[stack1] : " << stack1.top() << std::endl;
		stack1.pop();
	}

	fileout << "\n\n************** TESTING MAP **************\n" << std::endl;
	namespace::map<int, std::string> map1;
	map1.insert(namespace::pair<int, std::string>(1, "a"));
	map1.insert(namespace::pair<int, std::string>(2, "b"));
	map1.insert(namespace::pair<int, std::string>(3, "c"));
	map1.insert(namespace::pair<int, std::string>(4, "d"));
	map1.insert(namespace::pair<int, std::string>(5, "e"));
	map1.insert(namespace::pair<int, std::string>(6, "f"));
	map1.insert(namespace::pair<int, std::string>(7, "g"));
	fileout << "Printing content: \n";
	fileout << "size : " << map1.size() << std::endl;
	fileout << "max_size : " << map1.max_size() << std::endl;
	namespace::map<int, std::string>::iterator it;
	for(it = map1.begin(); it != map1.end(); ++it)
		fileout << "[map1] key = " << it->first << "  value = " << it->second << std::endl;


	fileout << "\n\n TESTING OPERATOR[] \n" << std::endl;
	map1[6] = "changed";
	map1[2] = "changed";
	map1[10] = "added with operator[]";
	for(it = map1.begin(); it != map1.end(); ++it)
		fileout << "[map1] key = " << it->first << "  value = " << it->second << std::endl;


	fileout << "\n\n TESTING COPY COSTRUCTOR \n" << std::endl;
	namespace::map<int, std::string> map2(map1);
	fileout << "Printing content: \n";
	fileout << "size : " << map2.size() << std::endl;
	fileout << "max_size : " << map2.max_size() << std::endl;
	for(it = map2.begin(); it != map2.end(); ++it)
		fileout << "[map2] key = " << it->first << "  value = " << it->second << std::endl;

	fileout << "\n\n TESTING ERASE \n" << std::endl;
	map1.erase(map1.begin(), ++(++(map1.begin())));
	fileout << "Printing content: \n";
	fileout << "size : " << map1.size() << std::endl;
	fileout << "max_size : " << map1.max_size() << std::endl;
	for(it = map1.begin(); it != map1.end(); ++it)
		fileout << "[map1] key = " << it->first << "  value = " << it->second << std::endl;
}
