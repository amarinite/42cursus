#include "ex04.hpp"

std::string	replace_in_line(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::string result = line;

	for (size_t pos = 0; pos < result.length(); ++pos)
	{
		if ((result.length() - pos) >= s1.length())
		{
			std::string substring = result.substr(pos, s1.length());
			if (substring == s1)
			{
				result.erase(pos, s1.length());
				result.insert(pos, s2);
				pos += s2.length() - 1;
			}
		}
	}
	return result;
}

bool	open_files(const std::string &filename, std::ifstream &infile, std::ofstream &outfile)
{
	infile.open(filename.c_str());
	if (!infile.is_open())
		return (std::cerr << "Could not open file\n", false);

	std::string new_filename = filename + ".replace";
	outfile.open(new_filename.c_str());
	if (!outfile.is_open())
		return (std::cerr << "Could not create output file\n", false);

	return true;
}

int	replace_file(char **argv)
{
	std::string			filename = argv[1];
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];

	if (s1.empty())
		return (std::cerr << "Error: s1 cannot be empty\n", 1);

	std::ifstream	infile;
	std::ofstream	outfile;

	if (!open_files(filename, infile, outfile))
		return 1;

	std::string line;
	while(std::getline(infile, line))
	{
		line = replace_in_line(line, s1, s2);
		outfile << line << '\n';
	}

	return 0;
}
