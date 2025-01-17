/*
..._____......._____.............._..................._____.....
../.____|.....|..__.\............|.|.................|.---.|....
.|.|...______.|.|__).|_..._..___.|.|_................|└---┘|....
.|.|..|______||.._../|.|.|.|/.__||.__|...............|+  .'|....
.|.|____......|.|.\.\|.|_|.|\__.\|.|_................| //  |....
..\_____|.....|_|..\_\\__,_||___/.\__|...............|_____/....
.__......__._..._...______................_.....................
.\.\...././|.\.|.|.|..____|..............(_)....................
..\.\.././.|..\|.|.|.|__...._.__....__._.._.._.__....___........
...\.\/./..|...`.|.|..__|..|.'_.\../._`.||.||.'_.\../._.\.......
....\../...|.|\..|.|.|____.|.|.|.||.(_|.||.||.|.|.||..__/.......
.....\/....|_|.\_|.|______||_|.|_|.\__,.||_||_|.|_|.\___|.......
....................................__/.|.......................
...................................|___/........................
*/

#include <stdio.h>
#include <unistd.h>

#define MAX_LINES 1000

char    anyKey;

// Make sure your sprites print properly in the terminal
// By padding the lines if needed
const   char* sprite1 =
"1st sprite/CG ASCII art line 1\n"  
"1st sprite/CG ASCII art line 2\n";

const   char* sprite2 =
"2nd sprite/CG ASCII art line 1\n"  
"2nd sprite/CG ASCII art line 2\n";

/* Dialog box template (//x ; x = current game line)
printf("##########################################################\n"//x
"###                                                    ###\n"                                                                                                                            
"##########################################################\n");
*/

char game_lines[MAX_LINES][1000] = {
"##########################################################\n"//1
"### Game line 1                                        ###\n"
"##########################################################\n",
"### Game line 2                                        ###\n"//2
"###                                                    ###\n"
"##########################################################\n",
// Add more lines as needed
};

// Add more lines to the game_lines array  as needed

int current_line = 0;

void    ft_print_game_line()
{
    printf("%s", game_lines[current_line]);
    current_line = (current_line + 1) % MAX_LINES;
/*    char    ch;
    if (scanf(" %c", &ch) == 1 && ch == ' ')
        {
            printf("##########################################################\n"
"###                                                    ###\n"
"##########################################################\n");
        }*/
}

// function to print the CG/sprite art, reiterated in main
// as input is received to cater to the shell in a good
// game design; uses else if (current_line < x) to handle
// CG switch
void ft_print_game_char()
{
    if (current_line < 17)
    {
        printf("%s", sprite1);
    } 
    else if (current_line < 200)
    {
        printf("%s", sprite2);
    }
}


// Game action reminder, Credit logic not yet added. Choice
// handling not perfected.
void    ft_print_game_action()
{
    printf("### ENTER > continue / 'Q' > quit / 'C' > credit       ###\n"
"##########################################################\n");
    printf("%d\n", current_line);

    if (current_line > 25 && current_line < 27)
    {
        printf("### ENTER 'A'. Choice A                                ###\n"
"### ENTER. Choice B                                    ###\n"
"##########################################################\n");
        scanf("%c", &anyKey);

        if (anyKey = 'A')
        {
            printf("##########################################################\n"//26
"###                                                    ###\n"
"###                                                    ###\n"
"##########################################################\n");
        }
        if (anyKey == '2')
        {
            return;
        }
    } 
}

/*int main(void)
{
    ft_print_game_char();
    ft_print_game_action();
    char anyKey;
    ft_print_game_line(); // Print the first line

    // Wait for the space bar input
    while (1) {
        scanf("%c", &anyKey);    
        ft_print_game_line(); // Print the next line
        }
    }
    return 0;
}*/

void    ft_print_game_char();
void    ft_print_game_line();
int main(void)
{
    // Call functions to print initial game elements
    ft_print_game_char();

    // Print the first line
    ft_print_game_line();
    ft_print_game_action();
    // Wait for any key input and print subsequent lines
    while (1)
    {
        scanf("%c", &anyKey);

        if (anyKey == 'Q')
        {
            break; // Exit the loop if 'q' is pressed
        }
    ft_print_game_char(); // Print game characters above each line
    ft_print_game_line(); // Print the next line
    ft_print_game_action();
    }
    return 0;
}
