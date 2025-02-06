# Universal 42 C Project Makefile

This repository contains a versatile Makefile designed for C projects in the 42 Common Core curriculum. It provides a standardized build system that can be used across different projects while maintaining the norm requirements.

## Features

- Automatic source file discovery
- Separate directories for source files and headers
- Standard compilation with norm-required flags
- Support for both library and executable outputs
- Organized main function separation
- Clean and efficient rebuild system

## Project Structure

Your project should follow this directory structure:

project directory/
├── includes/          # Header files (.h)
├── srcs/             # Source files (.c)
├── main/             # Files containing main function
├── Makefile          # This universal Makefile
└── README.md         # Project documentation

## Usage

### Basic Commands

- make: Compiles the project
- make clean: Removes object files
- make fclean: Removes object files and executables
- make re: Performs a clean rebuild
- make run: Compiles and runs the program

### Setting Up a New Project

1. Copy this Makefile to your project directory
2. Modify the `NAME` variable to match your project:
	NAME = your project name
3. Create the required directories:
	mkdir srcs includes main
4. Place your source files in the appropriate directories:
- Main function goes in main/
- Other functions go in srcs/
- Header files go in includes/

## Compilation Flags

The Makefile uses the following flags as required by the 42 norm:
- -Wall: Enable all common warnings
- -Wextra: Enable extra warnings
- -Werror: Treat warnings as errors

## Customization

### Adding More Source Directories

If your project grows, you can organize source files into subdirectories within srcs/:

			   srcs/
			   ├── utils/
			   ├── core/
			   └── algorithms/
			   
The Makefile will automatically find all .c files in these subdirectories.

### Linking External Libraries

To link additional libraries, add them to the CFLAGS variable:

	CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR) -lm

## Common Issues and Solutions

1. **Missing Header Files**: Ensure all headers are in the includes/ directory
2. **Undefined References**: Check if all source files are in srcs/ or its subdirectories
3. **Multiple Main Functions**: Keep only one main function in the `main/` directory

## Best Practices

1. Always include header guards in your .h files
2. Keep the main function simple and focused on program flow
3. Organize related functions into separate source files
4. Use meaningful names for source files and functions

## Compatibility

This Makefile is tested and compatible with:
- MacOS (42 lab computers)
- Linux systems
- WSL (Windows Subsystem for Linux)

## Norm Compliance

This Makefile follows the 42 norm requirements:
- Uses tabs for indentation
- Contains required rules (all, clean, fclean, re)
- Uses appropriate compilation flags
- Relinks only when necessary

## Contributing

Feel free to suggest improvements or report issues. This Makefile is designed to be a living document that can evolve with the needs of 42 students.

## License

This Makefile is free to use and modify for any 42 project. Attribution is appreciated but not required.
