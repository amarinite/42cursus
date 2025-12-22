#include <iostream>

int main(int argc, char* argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int ac = 1; ac < argc; ac++)
		{
			std::string input_text = argv[ac];
			for (size_t i = 0; i < input_text.length(); i++)
			input_text[i] = std::toupper(static_cast<unsigned char>(input_text[i]));
			std::cout << input_text ;
		}
	}
	return 0;
}