#include<stdio.h> // Used for fget(), stdin
#include<string.h> //Used for stringlen()

void encryption(char* text, int k); // This is the fucntion for encrypting the text
void decryption(char* text, int k); // This is the fucncton for decrypting the text

int main(void){ 	
	int k = 1; //Key value for rotational cipher
	char text[100];	//array for text
	
	    fgets(text, sizeof(text), stdin);//collects variables given by user and stores the value
	
	    printf("The encrypted text is : ");//Print the ciphered text
	    encryption(text, k);
		printf("The decrypted text is : ");//Print the deecrypted text
	    decryption(text, k);
    }   
// Encryption function, which will print the text
void encryption(char* text, int k){
	
	int i=0;
	int value;
	char cypher;
	
	while( text[i] != '\0' && strlen(text)-1 >= i){
		value = ((int)text[i] -65 + k) % 26 + 65; //use of -65 as characters are defined by their ASCII value, 'A' starting at 65 hence -65
		cypher = (char)(value); //turns values back to characters
		
		printf("%c", cypher); //prints values in characters 
		i++; //counter 
	}
	printf("\n");
}
// Decryption function, which prints the text
void decryption(char* text, int k){
    	int i=0;
	int value;
	char cypher;
	
	while( text[i] != '\0' && strlen(text)-1 >= i){
		value = ((int)text[i] +65 - k) % 26 + 65; //works same as encryption but since moving back a value of 'k' it is -k and +65.
		cypher = (char)(value);
		
		printf("%c", cypher);
		i++;
	}
	printf("\n");
}
