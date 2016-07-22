# PSet 3

## Debugging
### Agenda:
- theory, techniques
- CS50 IDE features to assist

### Example:
- C program that deivides a number by 2
- only returns an int... and discards any remainder/decimals
- The difficulty would be to identify *where* the error has occurred, especially once the division algorithm is included in a larger program.

### Using `printf` as a way to output breadcrumbs while writing the code...
- you can flag things at very specific points in the program
- if you already have an idea of the issue... this can work
- you'll need to be very precise in where you place the flags
- you'll *also* need to remember to pull them all out after the fact... easy to forget!
- `printf` is **not** a dynamic debugging tool
- it's balls-tedious

### Gnu Debugger (GDB)
- execute: `$: gdb [program name]`
- IDE provides a GUI for gdb...
- use the "Debug button" at top of IDE
    - the debug tab compiles the program for you as well
    - doesn't require that you declare gdb in the c file
    - the button sets the `ggdb3` flag for clang as well, which creates information for gdb, such as number of functions, line information for each declaration etc, symbols and variables...
    - it also calls a specialized terminal window in the IDE

#### Pausing execution in GDB
will allow you to better understand where the program is in its logic, and where things are going wrong.

- to create a breakpoint, in the IDE click to the left of a specific line number. A red dot will appear to indicate the breakpoint.
- breakpoints will only come into play if the function that contains it is called to execution.
- multiple breakpoints can be set...
- now when we recall the Debug operation, it highlights the line with the breakpoint, and pauses execution just before that line.
- OTHER BUTTONS:
    - Step Over: execute a single line of code, and move to next line, pausing again
    - Step Into: allows you to step into another funciton as it is called (if applicable)
- Other Sections:
    - Call Stack: gives current location in program
    - Local Variables: shows all vars, will appear even before they are defined, even if super-local. Values will be random until initialized.
- Breakpoints can be adjusted on the fly...
- You can change variable values in the right panel during execution. It updates once you step over