#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define STRINGSIZE 2000

// this function reads everything from the user
// until s/he enters CTRL + Z.
void readUntilEOF(char str[]);

int isPunctuations(char c);
char closBrackets(char c);
int isOpenBrackets(char c);
int isCloseBrackets(char c);
void speller(char *string);
int isVowel(char c);


int main()
{   // userStr: the string to read from the user
    // outputStr: the string to print out
    char userStr[STRINGSIZE]={},
         outputStr[STRINGSIZE] ={};

    readUntilEOF(userStr);
	
	int i = 0;
	int j = 0;
	int upperControl = 0;
	int bracketControl = 0;
	int indexStartBracket;
	
	while(userStr[i]!='\0'){
		
		if(upperControl == 0){
			outputStr[j] = userStr[i];
			if(isOpenBrackets(userStr[i])){
				bracketControl = 1;
				indexStartBracket = i;
			}
			else if(isCloseBrackets(userStr[i]))
				bracketControl = 0;
		}
			
		else if(upperControl == 1){
			outputStr[j] = toupper(userStr[i]);
			upperControl = 0;
		}
		
		if(isPunctuations(userStr[i])){		// if we run into a punctuation
			if(userStr[i] == '.'){			// if is a dot, make the next letter upper case
				if(userStr[i + 1] != ' '){
					outputStr[++j] = ' ';
				}
				else if(userStr[i + 1] == ' '){
					outputStr[++j] = userStr[++i];
				}
				upperControl = 1;
			}
			else if(userStr[i + 1] != ' '){	 // if no space after punctuation
				outputStr[++j] = ' ';
			}
		}
		
		
		i++;
		j++;
	}

	if(bracketControl == 1){
	    while(outputStr[j] == 10 || outputStr[j] == 0 || outputStr[j] == 32){
	       j--;
	    }   
		if(outputStr[j] == '.'){
			outputStr[j] = closBrackets(userStr[indexStartBracket]);
			outputStr[j + 1] = '.';
		}
		else{
		    outputStr[j+1] = closBrackets(userStr[indexStartBracket]);
		}
			
	}
	
	
	
	speller(outputStr);

    fprintf(stdout, outputStr);
    return 0;
}

void readUntilEOF(char str[])
{
    char ch;
    int i = 0;
    ch = getchar();//read the next char
    while(ch!=EOF)
    {
        // check whether the number
        // of chars we read is still
        // less than SIZEOFSTRING
        // if so, add it to our string
        // otherwise just discard until
        // the user presses EOF
        // FOR EOF: PRESS "ENTER CTRL + Z ENTER"
        if (i < STRINGSIZE -1)
        {
            str[i] = ch;
            i++;
        }
        ch = getchar();
    }
    str[i] = '\0';
}


int isPunctuations(char c){
	return (c == '.' || c == ',' || c == ':' || c == ';' || c == '?' || c == '!');
}

int isOpenBrackets(char c){
	return (c == '(' || c == '{' || c == '[');
}

int isCloseBrackets(char c){
	return (c == ')' || c == '}' || c == ']');
}

char closBrackets(char c){
	if(c == '(')
		return ')';
	
	else if(c == '{')
		return '}';
	
	else if(c == '[')
		return ']';
}

int isVowel(char c){
	c = tolower(c);
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

void speller(char *string){
	
	char tmp[STRINGSIZE];
	
	int i = 0;
	int j = 0;
	while(string[i]!='\0'){
		tmp[j] = string[i];
		
		if(isVowel(string[i])){
		    
			if(isVowel(string[i + 1]) && isalpha(string[i + 1])!=0){
				tmp[++j] = '-';
			
			}
			else if(isVowel(string[i + 2]) && isalpha(string[i + 2])!=0 && isalpha(string[i + 1])!=0){
				tmp[++j] = '-';
				
			}
			else if(isVowel(string[i + 3]) && isalpha(string[i + 3])!=0 && isalpha(string[i + 2])!=0 && isalpha(string[i + 1])!=0){
				tmp[++j] = string[++i];
				tmp[++j] = '-';
			
			}
			else if(isVowel(string[i + 4]) && isalpha(string[i + 4])!=0  && isalpha(string[i + 3])!=0 && isalpha(string[i + 2])!=0 && isalpha(string[i + 1])!=0){
				tmp[++j] = string[++i];
				tmp[++j] = string[++i];
				tmp[++j] = '-';
			
			}
		}

		i++,
	    j++;
	}
	
	strcpy(string,tmp);
	
}
