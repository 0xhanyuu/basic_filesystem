#include <iostream>
#include <map>

typedef enum command
{
	nop = 0,
	mkdir,
	touch,
	stat,
	_exit
}
command;

void print_prompt()
{
        std::cout << "user@rfs $ ";
}

void f_mkdir(std::string directory_name) {}
void f_touch(std::string filename) {}
void f_stat(std::string filename) {}

void terminal()
{
	command current_command = nop;
	std::string user_input;

	while ( current_command != _exit )
	{
		print_prompt();
                // Get the entire line of user_input.
		std::getline(std::cin, user_input);
		// Analyse user input.
                // ...

		// ...
	}
	return;
}

int main(void)
{
	std::map<std::string, command> strenum_map
	{
		{"nop", nop}, {"mkdir", mkdir},
		{"touch", touch}, {"stat", stat},
		{"exit", exit}
	};

	terminal();

        return 0;
}
