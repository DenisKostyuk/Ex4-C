#include "TrieText.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc , char *argv[]){
    int counter = 0;
    char c;
    int i = 0;
    int ind = 0;
    int size = 0;
    node *head = newNode();
    char *word = (char*)malloc(sizeof(char));
    char *arr = (char*)malloc(10*sizeof(char));
    while(scanf("%c",&c) != EOF){
        if(c != '\0'){
            if((c >= 'a' && c <= 'z') || (c==' ' || c=='\t' || c==',' || c=='.')){
                *(arr + i) = c;
                arr = realloc(arr, i+3); 
                counter++;
            }
            else if ((c >= 'A' && c <= 'Z')) {
                *(arr + i) = c + 32;
                arr = realloc(arr, i+3);
                counter++;
            }
            i++;        
        }
    }
    *(arr+counter+1) = '\0';
    char ch = *(arr);
    int runner = 0;
    while(runner < counter+1){
        if(ch!=' ' && ch!='\n' && ch!='\t' && ch!='\0' && ch!=',' && ch!='.'){
            *(word+ind) = *(arr+runner);
            size++;
            ind++;
            runner++;
            ch = *(arr+runner);
            word = realloc(word, ind+3);
        }else{
            word[ind] = 0;
            if(ind > 0) addNode(&head, word);
            memset(word,0,sizeof(char)*ind);
            *word = 0;
            ind = 0;
            runner++;
            ch = *(arr+runner);
        }
    }
    free(arr);
    if(ind > 0) addNode(&head, word);
    free(word);
    char *temp=(char*)malloc(size*sizeof(char));
    if(argc == 1) {
        lexUp(&head, 0, temp);
        freethetrie(&head);
    }else if(argc != 1){
        lexDown(&head, 0 , temp);
        freethetrie(&head);
    }
    free(temp);
    return 0; 
}
