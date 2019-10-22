/*
Set 1 Challenge 2
Write a function that takes two equal-length buffers and produces their XOR combination.

If your function works properly, then when you feed it the string:
    1c0111001f010100061a024b53535009181c

... after hex decoding, and when XOR'd against:
    686974207468652062756c6c277320657965

Should produce: 
    746865206b696420646f6e277420706c6179


Convert string to raw byte "string" in python3:
    string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
    print("\\x"+"\\x".join([string[i:i+2] for i in range(0,len(string),2)]))
    Output:
        \x49\x27\x6d\x20\x6b\x69\x6c\x6c\x69\x6e\x67\x20\x79\x6f\x75\x72\x20\x62\x72\x61\x69\x6e\x20\x6c\x69\x6b\x65\x20\x61\x20\x70\x6f\x69\x73\x6f\x6e\x6f\x75\x73\x20\x6d\x75\x73\x68\x72\x6f\x6f\x6d        
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *fixedXOR(const char *str_a, const char *str_b, int len_str){
    char *xor_result = (char*) malloc(len_str+1);
    int i;
    
    for(i = 0; i < len_str; i++){
        xor_result[i] = str_a[i] ^ str_b[i];
        
    }
    
    xor_result[len_str] = '\0';
    
    return xor_result;
}

int main(){
    const char str_a[] = "\x1c\x01\x11\x00\x1f\x01\x01\x00\x06\x1a\x02\x4b\x53\x53\x50\x09\x18\x1c";
    const char str_b[] = "\x68\x69\x74\x20\x74\x68\x65\x20\x62\x75\x6c\x6c\x27\x73\x20\x65\x79\x65";
    int len_str = sizeof(str_a);

    char *result = fixedXOR(str_a,str_b, len_str);
    printf("%s\n", result);
    free(result);
    return 0;
}
