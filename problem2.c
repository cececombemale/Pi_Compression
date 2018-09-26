
//Cecilia Combemale 
//this problem compresses pi using half the storage space, storing two digits per byte
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Template for problem 1.
 */


int main ( int argc, char ** argv ) { 
    if (argc < 4){
        printf("ERROR: this program needs three command line arguments\n");
        printf("\tUsage: %s e|d input_file_path output_file_path\n\n", argv[0] ); 
        exit(1); 
    }

    //open the file for reading
    FILE * in_file = fopen (argv[2], "r" ); 
    
    //open the file for writing 
    FILE * out_file = fopen (argv[3], "w" );
    
    int c1 = '\0';
    int end_in_newline = 0; 
    //variables I will be using
    int counter = 0;
    char compressed = c1; 
    char one;
    char two;
    char decompress1;
    char decompress2;
    char final;
    //read digits one by one and write them to the output file
    if(strcmp(argv[1],"c") == 0){
    while ( EOF != (c1 = fgetc(in_file)) ) {
        //if newline is found before the end of file, it is not a valid input file
            if (end_in_newline){ 
                printf("ERROR: invalid character detected: only one newline "
                    "allowed at the end of a file\n");
                exit(1);
            }
        //if newline found, the next char should be end of file (EOF)
            if (c1 == '\n') {
                if (one != 0){ //if there is an odd number of digits
                    final = one<<4; //shift over for to fit in high order bits
                    final = final | 0x0F; //compress with 15 in low order bits
                        //to signal odd on decompression
                    fputc(final,out_file); //output
                        

                }
            end_in_newline = 1; 
                continue;
            }  
            if (c1 <'0' || c1 >'9') {
                printf("ERROR: invalid character detected c1: %c \n\n", c1);
                exit(1);

            }
                //the counter is used so that the first number taken in during the while
            //loop doesnt change to the second number during the second iteration. 
            //the first number "one" takes in c1 only if the counter is an even number,
            //and the second number "two" only takes in c1 if the counter is odd
            //once the counter is odd and "one" and "two" have values, we compress the digits
            //into one character 
                if ((counter%2) == 0){
                    one = c1 - '0'; //offset the char so its stored as the actual digit in bin rep
                    //not the ascii value for the digit
                    
                }   
                else 
                {
            
                    two = c1 - '0';//offset the char so its stored as the actual digit in bin rep
                    //not the ascii value for the digit

                    final = one << 4; //compress, bit shift the first num so it takes up the higher
                    //four places in the byte
                    final = final| two; //fill the lower four places with the second num
                    fputc(final, out_file); //output the file
                    one = 0; //to check if odd numbers of pi
                    
               } 
             

                counter ++; //increase counter
            }

        }
        
        
        else if(strcmp(argv[1],"e") == 0){
            while ( EOF != (c1 = fgetc(in_file)) ) {
        //if newline is found before the end of file, it is not a valid input file
            if (end_in_newline){ 
                printf("ERROR: invalid character detected: only one newline "
                    "allowed at the end of a file\n");
                exit(1);
            }
        //if newline found, the next char should be end of file (EOF)
            if (c1 == '\n') {
            end_in_newline = 1; 
                continue;
            }  
            

            compressed = c1; //get the compressed character
            

            decompress1 = ((compressed & 0b11110000)>>4) + '0'; //mask to get the high order
            //bits and then bit shift bacl so they are in their propper place, and then offset
            // back so that we have the ascii representation of the number to then put into 
            //the decompressed file 
            decompress2 = (compressed & 0b00001111); //get second value
            //unsigned int decom = decompress2; // this is meant to get the last value if its 
            //odd so we have have the number as an int
            char decompress2f = decompress2 + '0'; //same offset so that we have ascii rep to 
            //output to the decompressed file 
            //char decompress2c = decompress2 ;
             
            fputc(decompress1, out_file); 
            
            if(decompress2 != 0b00001111){ //if its not an odd number of pi then print 
                //second decompressed number
        
                fputc(decompress2f, out_file);
                } 
            

        }
           
        }
    

     

    
    if (end_in_newline){ 
        fputc('\n',out_file);
    }
    
    //close both files 
    fclose ( in_file); 
    fclose ( out_file); 
    
}



