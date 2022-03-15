//#include "map.hpp"
#include "vector.hpp"
//#include "stack.hpp"
#include <fstream>
#include <sstream>

#define namespace	ft

int main()
{
	std::ofstream fileout ("myTESTosterone.txt");
	fileout << "************** TESTING VECTOR **************\n" << std::endl;

	namespace::vector<int> vec1(5,100);
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	namespace::vector<int> vec2(arr, arr+10);

	fileout << "Printing content: \n";
	namespace::vector<int>::iterator it1;
	fileout << "size : " << vec1.size() << std::endl;
	fileout << "max_size : " << vec1.max_size() << std::endl;
    fileout << "capacity : " << vec1.capacity() << std::endl;

	for(it1 = vec1.begin(); it1 != vec1.end(); ++it1)
		fileout << "[vec1] : " << *it1 << std::endl;

	fileout << std::endl;
	fileout << "size : " << vec2.size() << std::endl;
	fileout << "max_size : " << vec2.max_size() << std::endl;
	for(it1 = vec2.begin(); it1 != vec2.end(); ++it1)
		fileout << "[vec2] : " << *it1 << std::endl;

    fileout << std::endl;
    fileout << "************** TESTING RESIZE **************\n" << std::endl;
    vec1.resize(20, 100);
    fileout << "size : " << vec1.size() << std::endl;
	fileout << "max_size : " << vec1.max_size() << std::endl;
    fileout << "capacity : " << vec1.capacity() << std::endl;

	for(it1 = vec1.begin(); it1 != vec1.end(); ++it1)
		fileout << "[vec1] : " << *it1 << std::endl;
    fileout << std::endl;

    fileout << "************** TESTING RESERVE **************\n" << std::endl;
    vec1.reserve(50);
    fileout << "capacity : " << vec1.capacity() << std::endl;
    return 0;
}