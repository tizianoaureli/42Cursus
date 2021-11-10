#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	std::string namefile;
	std::string str1;
	std::string str2;
	std::string appogg;
	std::ifstream myfile;
	std::ofstream replfile;
	std::size_t found = 0;
	
	int i = 0;
	if (argv[1] && argv[2] && argv[3])
	{
		namefile.assign(argv[1]);
		str1.assign(argv[2]);
		str2.assign(argv[3]);
		myfile.open(namefile);
		if (myfile.is_open())
		{
			replfile.open(namefile + ".replace");
			while(std::getline(myfile, appogg))
			{
				found = appogg.find(str1);
				if (found != std::string::npos)
				{
					appogg.erase(found, found + str1.length());
					appogg.insert(found, str2);
				}
				if(replfile.is_open())
					replfile << appogg << std::endl;
			}
		}
		else
			std::cout << "Cannot open file" << std::endl;
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
	return 0;
}