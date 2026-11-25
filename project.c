//file insertion system 
#include<stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#include<time.h>
//there are no useful comments, please dont read any
//errno a CHUD 
// 2 weeks later, might remove it
// toooujee fushigeeyo




//PLEASE CHANGE dIRECTORIES WHEN DOWNLOADING TO A NEW SYSTEM
#define sdir "C:/Users/DELL/Downloads/hangman_words_sorted.txt" //the GOAT //will be sent
#define tdir "C:/Users/DELL/Desktop/temporary_file.txt" //test file otherwise if ignored code SHOULDNT break // just initialize an empty txt file





void insertion(char inp[],int array[28]);
void pointer(char status,int array[28]);
int binarysearch(char inp[],int lower,int upper,char arr[][30],int *bub); // not exact bin searcg
void strain(char (*array)[30],int position,char letter,int blacklist[], int *num,int *start);
void read(char (*array)[30]);
char guesser(int blacklist_pos[27],char (*array)[30],int num,int size);
void lettercount(char (*array)[30],int position,char letter,int blacklist[], int *num,int *start,int instances);
void isnull(void *val);





/*TASKS -> 
            :)
            */
int blacklistl[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int main(){
    int blacklist[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int breaks[28]={215,1791,8368,22945,44395,66634,84526,
        97640,106446,111570,114491,116068,116767,117123,
        117262,117328,117349,117355,-1,117361,-1,-1,-1,-1,-1,117362};
    int twooplus;
    int temp,i=0;
    char v[30];
    char (*therray)[30] = calloc(150000,sizeof(char[30]));
    isnull(therray);

    int p = breaks[2];
    int q = breaks[1];
    read(therray);
    pointer('r',breaks);
    
    
    FILE *f;
    
    f = fopen(sdir,"r");
    isnull(f);
    

    
    

    fclose(f);
    printf("Welcome to the program!, youre tasked with thinking of a word thats preferably case sensitive and doesnt contain any names, please make sure its between 4-28 letters!\nIf the guessed letter is in the word,input its ammount and its postions!\nOtherwise,input '-1'\nCan you beat the computer?\n");
    










    //im NOT making an input function aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

    srand(time(NULL));
    char loserword[30],letter,buf;
    int len,start,num,letterpos,letterahh;
    printf("Enter length here: ");
    scanf("%d",&len);
    if(len<4 || len>28){
        printf("What the hell. Read the instructions, closing code");
        return 0;
    }

    
    pointer('r',breaks);
    read(therray);
    start = breaks[len-3];
    num = breaks[len-2];
    if(num==-1){
        printf("\nWhat was the word: ");
        scanf("%s",loserword);
        int flag = 0;
        for(i=start;i<num;i++){
            if(strcmp(loserword,therray[i])==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            insertion(loserword,breaks);
        }
        return 0;
    }
    int count = 0,lives=11;
    buf = guesser(blacklist,therray,num,len);
    printf("Computer guessed %c",buf);
    
    while(count<len && lives > 0){
        printf("\nEnter how many occurances of letter in word here: ");
        scanf("%d",&letterpos);
        if(letterpos==-1){
            strain(therray,-1,buf,blacklist,&num,&start);
            lives-=1;
        }
        else{
            for(int i=0;i<letterpos;i++){
                printf("\nEnter letter(s) position here: ");
                
                scanf("%d",&letterahh);
                if(letterahh<1 || letterahh>len){
                    perror("Invalid position,Restart");
                    return 0;
                }
                if(blacklist[letterahh-1]!=-1){
                    strain(therray,letterahh,buf,blacklist,&num,&start);
                }
                else{
                    perror("Error: Same Position Inputted twice. restart");
                    return 0;
                }
                
            }
            lettercount(therray,1,buf,blacklist,&num,&start,letterpos);
            count += letterpos;
            if (count>len){
                printf("something went wrong,restarting");
                return 0;
            }
        }
        buf = guesser(blacklist,therray,num,len);
        if(buf!='!')
            printf("Computer guessed %c",buf);
        else{
            break;
        }
    }
    if(count>=len){
        printf("\nwow you suck");
        printf("\nonly took a measely %d wrong guesses",11-lives);
    }
    else{
        printf("\nThen what was your word: ");
        scanf("%s",loserword);
        
        int flag = 0,iter= 0;
        while(loserword[iter]!='\0'){
            loserword[iter] = tolower(loserword[iter]);
            if(isalpha(loserword[iter])==0){
                perror("Invalid word!");
                return 0;
            }
            iter++;
        }
        for(i=start;i<num;i++){
            if(strcmp(loserword,therray[i])==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            if(strlen(loserword)!=len){
                perror("The word is invalid!");
                return 0;
            }
            insertion(loserword,breaks);
        }
        else{
            printf("Word found in dictionary");
        }
    }
    free(therray);













}
void insertion(char inp[],int array[28]){ // five.hundred.functions
    int x,i=0,rg,j=0,k,dex=0;
    char v[30];
    char (*charray)[30] = malloc(150000*sizeof(char[30]));
    char (*charray2)[30] =malloc(150000*sizeof(char[30]));
    isnull(charray);
    isnull(charray2);
    x = strlen(inp);
    FILE *f,*g;
    pointer('r',array);
    
    f = fopen(sdir,"r");
    isnull(f);
    while(fgets(charray[i],30,f)!=NULL){
        i+=1;
    }
    j=i;
    int lower=0,upper,q,le=0;
    while(inp[le]!='\0'){
        inp[le] = tolower(inp[le]);
        if(isalpha(inp[le])==0){
            perror("ysn You didn't enter the word correctly!, Restart!");
            exit(EXIT_FAILURE);
        }
        le++;

    }
    if(strlen(inp)-3==-1){
        lower = 0;
        upper = array[strlen(inp)-2];
    }
    upper = array[strlen(inp)-2];    
    lower = array[strlen(inp)-3];
    q =strlen(inp)-2;
    if(upper==-1){
        while(upper<0){
            q++;
            upper = array[q];
            
        }
        dex = array[q]-1;
    }
    else{  
    binarysearch(inp,lower,upper,charray,&dex);
    }
    
    int ki=0;
    for(i=0;i<=dex;i++){
        strcpy(charray2[ki++],charray[i]);
    }
    sprintf(charray2[ki++],"%s\n",inp); 
    
    
    for(i+1;i<=j;i++){
       strcpy(charray2[ki++],charray[i]); 
    }
    fclose(f);
    f =fopen(sdir,"w");
    for(i=0;i<=j;i++){
        fprintf(f,"%s",charray2[i]);
    }
    pointer('r',array);
    
    free(charray);
    free(charray2);
    
    fclose(f);

}
int binarysearch(char inp[],int lower,int upper,char arr[][30],int *bub){//perfect
    int mid;
    
    mid = lower + (upper-lower)/2;
    if((upper-lower)==1){
        *bub = lower;
        
        return mid;
        
    }
    else if( upper-lower==-1){
        *bub = lower;
        
        return mid;
         
    }
    else if(upper==lower){
        *bub = lower;

        return mid;
         
    }
    else if(strcmp(arr[mid],inp)>0){
            return binarysearch(inp,lower,mid-1,arr,bub);
        }
    else{
        return binarysearch(inp,mid+1,upper,arr,bub);
    }
    
}
void pointer(char status,int array[28]){
    char (*charray)[30] = calloc(150000,sizeof(char[30]));
    isnull(charray);
    FILE *f;
    int l;
    int i=0,j,prray[28],k=0;
    f = fopen(sdir,"r");
    isnull(f);
    for(l=0;l<28;l++){
        array[l]=-1;
    }
    if(status=='r'){
    while(fgets(charray[i],30,f)!=NULL){
        i++;
    }
    strcpy(charray[i+1],"");
    for(j=0;j<i;j++){
        if(strlen(charray[j])<strlen(charray[j+1]) || charray[j+1][0]=='\0'){
            
            k=strlen(charray[j])-3;
            array[k]=j;
            
            
        }
    }
    free(charray);
    fclose(f);
}

}
void strain(char (*array)[30], int position,char letter,int blacklist[],int *num,int *start){
    letter = tolower(letter);
    int al = letter;
    int i=0,j=0;
    char (*charray)[30] = malloc(100000 * sizeof(char[30]));
    isnull(charray);
    char *res;
    char temp,buf;
    
    if(position==-1){
        
        for(i=*start ;i<*num;i++){
            
            res = strchr(array[i],letter);
            if(res==NULL){
                array[i][strcspn(array[i],"\n")] = '\0';
                strcpy(charray[j],array[i]);
                j++;
            }

        }
        *num = j;
        for(i=0;i<j;i++){
            
            strcpy(array[i],charray[i]);
        }
    }
    else{
        blacklist[position-1]=-1;
        for(i=*start;i<*num;i++){
        temp = array[i][position-1];
        temp = tolower(temp);
        if(temp==letter){
            temp = tolower(array[i][position-1]);
            array[i][strcspn(array[i],"\n")] = '\0';
            strcpy(charray[j],array[i]);
            j++;
        }
    }
        *num = j;
        for(i=0;i<j;i++){
            
            strcpy(array[i],charray[i]);
        }
    }
    free(charray);
    *start = 0;
}
void read(char (*array)[30]){
    FILE *f; int i=0; char buffer[30];
    
    f = fopen(sdir,"r"); 
    isnull(f);
    while(fgets(buffer,30,f)!=NULL){
        
            strcpy(array[i],buffer);
            i++;
        
    }
    fclose(f);
}
char guesser(int blacklist_pos[27],char (*array)[30],int num,int size){
    int score[26],i,j=0,k,ran;
    char t,q;
     for(i=0;i<26;i++){
        score[i]=0;
     }
     k=0;
    for(i=0;i<num;i++){
        
        
        for(j=0;j<size;j++){
            if(blacklist_pos[j]!=-1){
            t=array[i][j];
        t = toupper(t);
            if(t>='A' && t<='Z'&&blacklistl[t-65]!=1){
                if(t=='A'||t=='E'||t=='I'||t=='N'||t=='S'||t=='R'){
                    score[t-65] += 11;
                }
                else if(t=='Q'&&blacklistl[20]!=0){
                    score[t-65] += 1;
                }
                else if(t=='U'||t=='T'||t=='L'||t=='C'||t=='D'||t=='O'||t=='P'){
                    score[t-65] += 7;
                }
                else if(t=='B'||t=='G'||t=='H'||t=='M'||t=='Y'||t=='B'||t=='K'||t=='W'){
                    score[t-65] += 4;
                }
                else{
                     score[t-65] += 3;
                }
                
        }
        
        }
        }
        
    }
    j=0;
    for(i=0;i<26;i++){
    
        k += score[i];
    }
    
    if(k!=0){
        ran = rand()%k;
    }
    else{
        return '!';
    }
    
    
    for(i=0;i<26;i++){
        if(ran<score[i]){
            q = i+65;
            
            blacklistl[i]=1;
            return q;
            
        }
        ran -= score[i];
    }
    return '.';
}
void lettercount(char (*array)[30],int position,char letter,int blacklist[], int *num,int *start,int instances){
    letter = toupper(letter);
    int al = letter;
    int i=0,j=0,k=0,c=0;
    char (*charray)[30] = malloc(100000 * sizeof(char[30]));
    isnull(charray);
    char *res;
    char temp;
    //yes i did copy paste from above due to almost similar functions
   
        
        for(k=*start ;k<*num;k++){
            while(array[k][i]!='\0'){
            
            if(array[k][i]==tolower(letter)){
                c++;
                
            }
            i++;
            }
            if(c==instances){
                array[k][strcspn(array[k],"\n")] = '\0';
                strcpy(charray[j],array[k]);
                j++;
            }
            c=0;
            i=0;

        }
        *num = j;
        for(i=0;i<j;i++){
            
            strcpy(array[i],charray[i]);
        }
    free(charray);
    *start = 0;
}
void isnull(void *val){
    if(val==NULL){
        perror("A Null pointer has been deteced, restart the code or change the file directory");
        exit(EXIT_FAILURE);
    }
}

