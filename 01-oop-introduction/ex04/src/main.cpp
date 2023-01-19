#include <iostream>
#include <fstream>
#include <string>

void replace_string(std::string &fileName, std::string &s1, std::string &s2)
{
	std::ifstream	inpFile(fileName);
	std::ofstream	outFile(fileName.append(".replace"));
	std::string		line;
	size_t			i = 0;

	if (!inpFile || !outFile)
	{
		std::cerr << "File error" << std::endl;
		exit (1);
	}
	while (std::getline(inpFile, line))
	{
		while (1)
		{
			i = line.find(s1);
			if (i == std::string::npos)
			{
				outFile << line;
				break;
			}
			else
			{
				outFile << line.substr(0, i) << s2;
				line = line.substr(i + s1.size());
			}
		}
		outFile  << std::endl;
	}
	inpFile.close();
	outFile.close();
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace <fileName> s1 s2" << std::endl;
		return 1;
	}
	std::string	fileName = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	replace_string(fileName, s1, s2);

	return (0);
}
