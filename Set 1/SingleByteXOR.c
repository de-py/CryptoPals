/*
Set 1 Challenge 3
The hex encoded string:

1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736

... has been XOR'd against a single character. Find the key, decrypt the message.

You can do this by hand. But don't: write code to do it for you.

How? Devise some method for "scoring" a piece of English plaintext. Character frequency is a good metric. Evaluate each output and choose the one with the best score.


You now have our permission to make "ETAOIN SHRDLU" jokes on Twitter.


Convert string to raw byte "string" in python3:
    string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
    print("\\x"+"\\x".join([string[i:i+2] for i in range(0,len(string),2)]))
    Output:
        \x49\x27\x6d\x20\x6b\x69\x6c\x6c\x69\x6e\x67\x20\x79\x6f\x75\x72\x20\x62\x72\x61\x69\x6e\x20\x6c\x69\x6b\x65\x20\x61\x20\x70\x6f\x69\x73\x6f\x6e\x6f\x75\x73\x20\x6d\x75\x73\x68\x72\x6f\x6f\x6d        
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Tuple {
    int byte_val;
    char *result_val;
};



char *single_byte_xor(const char *input_string, char xor_byte, int len_str){
    char *result = (char*) malloc(len_str);
    int i = 0;
    while (i < len_str){
        result[i] = input_string[i] ^ xor_byte;
        if (result[i] < 32 || result[i] > 126){
            return "BAD";
        }
        i++;

    }
    result[len_str-1] = '\0';
    return result;

}


int letter_score(int letter){

    switch(tolower(letter)){
        case 'e': return 12;
        case 't': return 11;
        case 'a': return 10;
        case 'o': return 9;
        case 'i': return 8;
        case 'n': return 7;
        case 's': return 6;
        case 'h': return 5;
        case 'r': return 4;
        case 'd': return 3;
        case 'l': return 2;
        case 'u': return 1;
        defaut: return 0;
    }
    return 0;
}

int calculate_score(char *test_case, int len_str){
    int score = 0;
    int i = 0;
    int temp;
    while (i < len_str){
        temp = letter_score(test_case[i]);
        score += temp;
        i++;
    }
    return score; 
}

struct Tuple rank_xor(const char *input_string, int len_str){
    char *test_case = (char*) malloc(len_str);
    char *high_case = (char*) malloc(len_str);
    char high_byte;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int high_score = 0;
    int temp_score = 0;
    int i = 0;
    struct Tuple winners;
    while (i < strlen(alphabet)){
        test_case = single_byte_xor(input_string, alphabet[i], len_str);
        temp_score = calculate_score(test_case, len_str);
        if (temp_score > high_score){
            high_score = temp_score;
            high_case = test_case;
            high_byte = alphabet[i];
        }
        
        i++;

    }
    free(test_case);
    winners.byte_val = high_byte;
    winners.result_val = high_case;
    return winners;
}


int main(){
    const char single_xor[] = "\x1b\x37\x37\x33\x31\x36\x3f\x78\x15\x1b\x7f\x2b\x78\x34\x31\x33\x3d\x78\x39\x78\x28\x37\x2d\x36\x3c\x78\x37\x3e\x78\x3a\x39\x3b\x37\x36";
    int str_len = sizeof(single_xor);
    struct Tuple winners;
    winners = rank_xor(single_xor, str_len);
    printf("Winning String:\n%s\n\n", winners.result_val);
    printf("Winning Byte: %c\n", winners.byte_val);
    free(winners.result_val);

    return 0;
}
