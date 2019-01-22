#include<stdio.h>
#include<string.h>
int main(){
		char word[100],c;
		char maxword[100];
		int maxweight=0,weight=0;
		int	i=0,j=0,max=0;
		int totallen=0,totalword=0;
		while(1){
				i=0;
				maxweight=0;
				weight=0;
				
				
				while((c=getchar())!=EOF){    //讀入一個詞
						if(i==0&&(c<65||(c>90&&c<97)||c>122)) continue;
						else if((c>=65&&c<=90)||(c>=97&&c<=122)){
								word[i]=c;
								i++;
						}
						else break;
				}
				
				
				if(i==0) break;
				
				
				if(i>max){				                             //比較長度
						max=i;
						strcpy(maxword,word);
				}
				else if(i==max){									//比較重量	
						for(j=0;j<max;j++){
								maxweight=maxword[j]+maxweight;
								weight=word[j]+weight;
						}
						if(weight>maxweight) strcpy(maxword,word);
				}


				totallen=totallen+i;		//計算總長
				totalword++;				//計算字數
		}

		maxword[max]='\0';
        printf("The longest word: %s\n",maxword);
		printf("Average word length: %.2f\n",(float)totallen/totalword);
		return 0;
}
