#include <iostream>

typedef enum command
{
	nop = 0,
	mkdir,
	touch,
	stat,
	_exit
}
command;

typedef struct lexer_array
{
	std::string arg0;
	std::string arg1;
	// Assume arg1 exists due to unary commands.
	// Nullary commands do not require arg1, and will be marked otherwise.
	bool arg1_exists = true;
}
lexer_array;

lexer_array lexer(std::string user_input)
{
	lexer_array user_input_contents;

        // Initial loop to analyse a presence of an arg1.
        // Assume nullary command.
        bool space_presence = false;
        int i = 0;

        for ( ; i < user_input.length(); i++ )
        {
                if ( user_input[i] == ' ' ) { space_presence = true; break; } 
        }

        // Re-initialization of 'i' in order to go back to the start of the string.
        i = 0;

        // Control path dependent on space presence in user_input:
        //
        // If user_input does not contain a space, assume it is nullary.
        // This allows to push_back arg0, instantiate arg1 as empty,
        // -declare it does not exist, and return the contents.
        //
        // If user_input contains a space, another loop is required for arg1.

        if ( space_presence == true )
        {
                // Iterate and populate arg0 until a space is hit.
                for ( ; user_input[i] != ' '; i++ )
                {
			user_input_contents.arg0.push_back(user_input[i]);
                }

                // Increment to go to the start of arg1.
                i++;

                // Iterate from start of arg1 until end.
                for ( ; i < user_input.length(); i++ )
                {
                        if ( user_input[i] == ' ' )
                        {
                                std::cout << "Too many arguments. Aborting."
                                          << std::endl;
                                exit(2);
                        }
                        user_input_contents.arg1.push_back(user_input[i]); 
                }

                return user_input_contents;
        }
        else if ( space_presence == false )
        {
                for ( ; i < user_input.length(); i++ )
                {
			user_input_contents.arg0.push_back(user_input[i]);
                }

                user_input_contents.arg1 = "";
                user_input_contents.arg1_exists = false;

                return user_input_contents;
        }
}

void sanity_check_print_lac(lexer_array contents)
{
	std::cout << "arg0: " << contents.arg0 << std::endl;
	std::cout << "arg1: " << contents.arg1 << std::endl;
	static_cast<int>(contents.arg1_exists) ? std::cout << "Unary\n" : std::cout << "Nullary\n";
	std::cout << std::endl;
}

void print_prompt()
{
        std::cout << "user@rfs $ ";
}

command strtoenum(std::string input_string)
{
        command enum_out;

        // ...

        return enum_out;
}

void terminal()
{
	command current_command = nop;
	std::string user_input;

	while ( current_command != _exit )
	{
		print_prompt();
                // Get the entire line of user_input, using 'cin' as input stream.
		std::getline(std::cin, user_input);
		// Analyse user's input and grab tokens to be able to analyze the command.
		lexer_array contents = lexer(user_input);

		// Debugging purposes: Printing out the contents of the lexer.
		sanity_check_print_lac(contents);

                // Take the user input and convert it into an enum.
                current_command = strtoenum(contents.arg0);

		// Take the command enum and call the corresponding cmd with arg1 - if it exists / is necessary.
	}
	return;
}

int main(void)
{
        /*
	std::map<std::string, command> strtoenum_map
	{
		{"nop", nop}, {"mkdir", mkdir},
		{"touch", touch}, {"stat", stat},
		{"exit", exit}
	};
        */

	terminal();

        return 0;
}
