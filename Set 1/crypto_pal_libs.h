#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Tuple {
    int byte_val;
    char *result_val;
    int high_score;

};



char *single_byte_xor(char *input_string, char xor_byte, int len_str){
    char *result = (char*) malloc(len_str);
    int i = 0;
    while (i < len_str){
        result[i] = input_string[i] ^ xor_byte;
        i++;

    }
    result[len_str-1] = '\0';
    return result;

}


int letter_score(int letter){

    switch(tolower(letter)){
        case ' ': return 13;
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
        default: return 0;
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

struct Tuple rank_xor(char *input_string, int len_str){
    char *test_case = (char*) malloc(len_str);
    char *high_case = (char*) malloc(len_str);
    char high_byte;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz123456789";
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
    winners.high_score = high_score;
    return winners;
}
