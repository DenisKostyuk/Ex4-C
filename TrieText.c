#include "TrieText.h"
#include <stdio.h>

void lexUp(node **head, int ind, char *word){
    int ans = 0;//-> 0 false 1 true
    for(int i= 0 ; i <NUM_LETTERS && ans == 0 ; i++){
        if((*head)->child[i]!=NULL){
            ans = 1;
        }
    }
    if (ans == 0){
        *(word+ind)='\0';
        if((*head)->finish){
            printf("%s ", word);
            printf("%d\n", (*head)->counterOfSameWords);
        }
        ind--;
        *(word+ind)='\0';
        return;
    }
    for(int i = 0;i<NUM_LETTERS;i++){
        if((*head)->child[i] != NULL) {
            *(word+ind) = i+'a';
            lexUp(&((*head)->child[i]), ind+1,word);
        }
    }
}

void lexDown(node **head,int ind, char *word) {  
    int ans = 0;//-> 0 false 1 true
    for(int i= 0 ; i <NUM_LETTERS && ans == 0 ; i++){
        if((*head)->child[i]!=NULL){
            ans = 1;
        }
    }
    if (ans == 0){
        *(word+ind)='\0';
        if((*head)->finish){
            printf("%s ", word);
            printf("%d\n", (*head)->counterOfSameWords);
        }
        ind--;
        *(word+ind)='\0';
        return;
    } 
    for (int j = NUM_LETTERS-1; j >=0; j--)  {  
        if((*head)->child[j]!=NULL){
           *(word+ind)=j+'a';
            lexDown(&((*head)->child[j]), ind+1, word);
        }
    }
    if((*head)->finish){
        *(word+ind)='\0';
        printf("%s ", word);
        printf("%d\n", (*head)->counterOfSameWords);
    }
}

void freethetrie(node **head){
    for(int i = 0;i<NUM_LETTERS;i++){
        if((*head)->child[i] != NULL) freethetrie(&((*head)->child[i]));
    }
    free(*(head));
}

node* newNode(){
    struct node *nod=(node*)malloc(sizeof(node));
    if(nod){
        nod->counterOfSameWords = 0;
        nod->finish = false;
        nod->tag = 0;
        for(int i =0;i<NUM_LETTERS;i++){
            nod->child[i]=NULL;
        }
    }
    return nod;
}

void addNode(node **root, char *str){
    node *runner = *root;
    int index = 0;
    while(*(str+index) != '\0'){
        if((runner)->child[*(str+index) - 'a'] == NULL ){
            (runner)-> child[*(str+index) - 'a'] = newNode();
            (runner)-> c = *(str+index);
        }
        (runner) = (runner)->child[*(str+index) - 'a'];
        index++;
    }
    (runner)->finish = true;
    (runner)->counterOfSameWords++;
}