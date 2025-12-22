#ifndef EX04_H
#define EX04_H

#include <iostream>
#include <fstream>
#include <string>

std::string	replace_in_line(const std::string &line, const std::string &s1, const std::string &s2);
bool		open_files(const std::string &filename, std::ifstream &infile, std::ofstream &outfile);
int			replace_file(char **argv);
void		execute_tests(void);

#endif