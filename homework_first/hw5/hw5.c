#include <stdio.h>
#include <string.h>
char max[20],word[20];
void weight(int len){  //count the two words' weight,len=wordlen
		int maxweight=0,wordweight=0,i;
		for(i=0;i<len;i++){
				maxweight=maxweight+max[i];
				wordweight=wordweight+word[i];
		}
		if(maxweight<wordweight) strcpy(max,word);
}
int getword(void){ //get a word,put in word[20],put the word's length in wordlen
		int i=0;
		while((word[i]=getchar())!=EOF){
				if(word[0]<65||(word[0]>90&&word[0]<97)||word[0]>122) continue;
				else if(word[i]<65||(word[i]>90&&word[i]<97)||word[i]>122) break;
				else i++;
		}
		return i;
}
int main(void){
		int wordcount=0,maxlen=0,wordlen=0;
		float wordavg=0;
		while((wordlen=getword())!=0){
				if(maxlen<wordlen){
						maxlen=wordlen;
						strcpy(max,word);
				}
				else if(maxlen==wordlen) weight(wordlen);
				wordavg=(wordavg*wordcount+wordlen)/(wordcount+1);
				wordcount++;
		}
		max[maxlen]='\0';
		printf("The longest word: %s\n",max);
		printf("Average word length: %.2f\n",wordavg);
		return 0;
}
