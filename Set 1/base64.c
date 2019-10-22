/*
Set 1 Challenge 1
Convert hex to base64

The string: 
    49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d

Should produce: 
    "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"

Rules: 
    "Always operate on raw bytes, never on encoded strings. Only use hex and base64 for pretty-printing."

Convert string to raw byte "string" in python3:
    string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
    print("\\x"+"\\x".join([string[i:i+2] for i in range(0,len(string),2)]))
    Output:
        \x49\x27\x6d\x20\x6b\x69\x6c\x6c\x69\x6e\x67\x20\x79\x6f\x75\x72\x20\x62\x72\x61\x69\x6e\x20\x6c\x69\x6b\x65\x20\x61\x20\x70\x6f\x69\x73\x6f\x6e\x6f\x75\x73\x20\x6d\x75\x73\x68\x72\x6f\x6f\x6d        
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int length_conversion(int original){
    return 4 * ceil(original/3.0);
}

char* base64_encode(const char *raw, const char *b64_alphabet){
    int raw_len = strlen(raw);
    int size_after = length_conversion(raw_len); /* formula for base64 length conversion. +1 for null pointer. */
    char *final_result = (char*) malloc(size_after+1);  
    int position = 0; 
    int difference; 
    int i = 0;
    final_result[size_after] = '\0'; 

    while ( raw_len - i >= 3 ){

        final_result[position] = b64_alphabet[raw[i] >> 2];
        final_result[1+position] = b64_alphabet[((raw[i] & 0x03) << 4) | (raw[i+1] >> 4)];
        final_result[2+position] = b64_alphabet[((raw[i+1] & 0x0f) << 2) | (raw[i+2] >> 6)];
        final_result[3+position] = b64_alphabet[raw[i+2] & 0x3f];
        position += 4;
        i += 3;
        
        
    }

    if (raw_len-i == 0){
        return final_result;
    }

    final_result[position] = b64_alphabet[raw[i] >> 2];
    position++;

    
    
    if (raw_len-i == 1){
        
        final_result[position] = b64_alphabet[(raw[i] & 0x03) << 4];
        position++;
        final_result[position] = b64_alphabet[64];
    }
    else{
        
        final_result[position] = b64_alphabet[((raw[i] & 0x03) << 4) | (raw[i+1] >> 4)];
        position++;
        final_result[position] = b64_alphabet[(raw[i+1] & 0x0f) << 2];

        
    }

    position++;
    final_result[position] = b64_alphabet[64];

    return final_result;
}

int main(){
    const char b64_alphabet[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    const char raw_string[] = "\x49\x27\x6d\x20\x6b\x69\x6c\x6c\x69\x6e\x67\x20\x79\x6f\x75\x72\x20\x62\x72\x61\x69\x6e\x20\x6c\x69\x6b\x65\x20\x61\x20\x70\x6f\x69\x73\x6f\x6e\x6f\x75\x73\x20\x6d\x75\x73\x68\x72\x6f\x6f\x6d\x41\x41\x41";

   
    char *x = base64_encode(raw_string, b64_alphabet);
    printf("%s\n", x);
    return 0;
}
