# include <stdio.h>
# include <getopt.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>

# define NIL (void *) 0

//main function declarations
bool scanInput();
bool handleArgs(int, char **, char **, char**);
bool verifyFilenames(char *, char **);

int main(int argc, char **argv)
{
    char *infile = NIL;
    char *outfile = NIL;

    // get user's input file name
    if (!scanInput(&infile, &outfile)){ return 1;};

    // make sure the user put a filename for the input
    // and if they didn't provide an output, overwrite
    // the original file
    if (!verifyFilenames(infile, &outfile)){ return 1;}

    printf("input: %s\noutput: %s\n", infile, outfile);
    return 0;
}



void printGreeting()
{
    printf("Welcome to Cory's file compressor!\n");
    printf("made   with   love");
    printf("\n\
      *   *\n\
    *********\n\
     *******\n\
       ***\n\
        *\n");

}
/**
 * get filenames from scanning ather than
 * from command line arguments
 *
 * @param pointer to infile pointer
 * @param pointer to outfile pointer
 */
bool scanInput(char **input, char **output)
{
    *input = malloc(sizeof(char) * 30);
    *output = malloc(sizeof(char) * 30);
    printf("enter file to compress: ");
    scanf("%s", *input);
    printf("enter output file (O to overwrite): ");
    scanf("%s", *output);
    return true;
}

/**
 * handle command line arguments
 *
 * @param number of arguments
 * @param arrary of arguments
 * @param pointer to infile pointer
 * @param pointer to outfile pointer
 * @return array containing infile and outfile
 */
bool handleArgs(int argc, char **argv, char **infile, char **outfile)
{
    //filenames as strings
    int option;

    //recieve file to encode as string
    while ((option = getopt(argc, argv, "i:o:")) != -1)
    {
        switch (option)
        {
            case 'i': *infile = optarg;
                break;
            case 'o': *outfile = optarg;
                break;
            default: printf("ERROR\n");
                return false;
        }
    }
    return true;
}

/**
 * ensure that an input file was given
 * and if there's no outfile given overwrite
 * the inputfile
 *
 * @param file to encode validation
 * @param file to write out validation (double pointer to set parameter)
 * @return was the infile valid?
 */
bool verifyFilenames(char *infile, char **outfile)
{
    // make sure the inputfile is valid
    if (infile == NIL)
    {
        printf("please enter an input file\n");
        return false;
    }
    // if there's no specified outfile, overwrite the infile
    if (strcmp(*outfile, "O") == 0)
    {
        //TODO make these the same pointer
        *outfile = infile;
    }
    return true;
}
