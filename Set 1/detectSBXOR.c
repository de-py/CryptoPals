/*
Set 1 Challenge 4
One of the 60-character strings in 4.txt has been encrypted by single-character XOR.

Find it.

(Your code from #3 should help.)



Convert string to raw byte "string" in python3:
    string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
    print("\\x"+"\\x".join([string[i:i+2] for i in range(0,len(string),2)]))
    Output:
        \x49\x27\x6d\x20\x6b\x69\x6c\x6c\x69\x6e\x67\x20\x79\x6f\x75\x72\x20\x62\x72\x61\x69\x6e\x20\x6c\x69\x6b\x65\x20\x61\x20\x70\x6f\x69\x73\x6f\x6e\x6f\x75\x73\x20\x6d\x75\x73\x68\x72\x6f\x6f\x6d        
*/ 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto_pal_libs.h"


char *convert_bytes(char *hex_string, int len_of_string){
    
    char *hex_bytes = (char *) malloc(len_of_string/2);
    int string_counter = 0;
    int byte_counter = 0;
    char byte_holder[2];
    while (string_counter < len_of_string){
        byte_holder[0] = hex_string[string_counter];
        byte_holder[1] = hex_string[string_counter+1];
        hex_bytes[byte_counter] = strtol(byte_holder, NULL, 16);
        string_counter += 2;
        byte_counter++;
        
    }



    return hex_bytes;
    
}




int main(){
    FILE *challenge_file;
    int str_length = 61;
    int hex_length = 31;
    char *check = (char*) malloc(str_length);
    char *new_check = (char*) malloc(hex_length);
    struct Tuple victors;
    struct Tuple high_victors;
    int counter = 0;

    challenge_file = fopen("4.txt", "r");

    while ( fgets ( check, str_length, challenge_file ) != NULL ){
        
        new_check = convert_bytes(check, str_length);
        victors = rank_xor(new_check, hex_length);
        if (victors.high_score > high_victors.high_score){
            high_victors = victors;
        }


        counter++;

    }

    fclose(challenge_file);
    printf("Winning String:\n%s\n", high_victors.result_val);
    printf("Winning Byte: %c\n", high_victors.byte_val);
    printf("Winning Score:\n%d\n", high_victors.high_score);    
    printf("\n");

    return 0;

}
