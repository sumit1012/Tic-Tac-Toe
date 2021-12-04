#include<stdio.h>
#include<stdlib.h>
void display(char game[10]);
int checkwin(char game[10]);
int checkdraw(char game[10]);
int main(){
    int arr[10];
    for(int i=1;i<9;i++){
        arr[i]=0;
    }
    char game[10] = {'o','1','2','3','4','5','6','7','8','9'};
    int j=1;
    int i=0;
    char p1[20]="player 1";
    char p2[20]="player 2";
    int n;
    while(j<10){
        
        display(game);
        if(i==0){
            printf("enter position at player 1 want's to apply --> x :");
        }
        else{
            printf("enter position at player 2 want's to apply --> o :");
        }
        scanf("%d",&n);
        if(n<1||n>9){
            system("cls");
            printf("this position is not possible, position should be greater than 0 and smaller than 10.\n");
        }
        else if(game[n]=='x'||game[n]=='o'){
            system("cls");
            printf("this position is occupied, position should be greater than 0 and smaller than 10.\n");
        }
        else{
            system("cls");
            if(i==0){
                game[n]='x';
                i=1;
            }
            else{
                game[n]='o';
                i=0;
            }
            int k=checkwin(game);
            if(k>0){
                break;
            }
            j++;
        }
    }
    system("cls");
    display(game);
    int q = checkdraw(game);
    if(q==1){
        printf("Game draw");
    }
    else{
        q=checkwin(game);
        if(q==1){
            printf("player 1 won");
        }
        else if(q==2){
            printf("player 2 won");
        }
    }
    return 0;

}
void display(char game[10]){
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n",game[1],game[2],game[3]);
    printf("\t\t|\t\t|\t\t\n");
    printf("__________________________________________________\n");
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n",game[4],game[5],game[6]);
    printf("\t\t|\t\t|\t\t\n");
    printf("___________________________________________________\n");
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n",game[7],game[8],game[9]);
    printf("\t\t|\t\t|\t\t\n");
    
}
int checkwin(char game[10]){
    // 0=no win,1=p1win,2=p2win
    if(game[1]==game[2]&&game[2]==game[3]){
        if(game[1]=='x'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(game[1]==game[5]&&game[5]==game[9]){
        if(game[1]=='x'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(game[1]==game[4]&&game[4]==game[7]){
if(game[1]=='x'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(game[2]==game[5]&&game[5]==game[8]){
        if(game[2]=='x'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(game[3]==game[6]&&game[6]==game[9]){
        if(game[3]=='x'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(game[3]==game[5]&&game[5]==game[7]){
        if(game[3]=='x'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(game[4]==game[5]&&game[5]==game[6]){
        if(game[4]=='x'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(game[7]==game[8]&&game[8]==game[9]){
        if(game[7]=='x'){
            return 1;
        }
        else{
            return 2;
        }
    }
    return 0;
}
int checkdraw(char game[10]){
    //1=withdraw;0=not;
    if(checkwin(game)!=0){
        return 0;
    }
    int x=0;
    for(int i=1;i<10;i++){
        if(game[i]=='x'||game[i]=='o'){
            x++;
        }
    }
    if(x==9){
        return 1;
    }
    return 0;
}