#include <stdio.h>
#include <string.h>
int rounding(float score){ //四捨五入函數
		return ((int)(score+0.5));
}
int adjust(int score){  //調分函數
		float i=0;
		for(i=0;;i=i+0.5){
				if(score*100 < i*i) return rounding(i-0.5);
				else if(score*100 == i*i) return rounding(i);
		}
}
int main(){
		char name[1000][6];
		int math[1000],eng[1000],prog[1000],aver[1000];
		int i=0,j=0,total;
		int inputmath,inputeng,inputprog;
		float tempavermath=0,tempavereng=0,tempaverprog=0;
		int avermath,avereng,averprog,averaver;
		int maxmath,maxeng,maxprog;
		int minmath,mineng,minprog;
		char temp[6];  //for bubble-sort
		int temp1,temp2,temp3,temp4; //for bubble-sort
		while(scanf("%s %d %d %d",name[i],&inputmath,&inputeng,&inputprog)!=EOF){
				math[i]=adjust(inputmath);
				eng[i]=adjust(inputeng);
				prog[i]=adjust(inputprog);
				aver[i]=rounding((float)(math[i]+eng[i]+prog[i])/3);
				i++;
		}
		total=i;
		for(i=0;i<total;i++) tempavermath=(float)(tempavermath*i+math[i])/(i+1);
		avermath=rounding(tempavermath);
		for(i=0;i<total;i++) tempavereng=(float)(tempavereng*i+eng[i])/(i+1);
		avereng=rounding(tempavereng);
        for(i=0;i<total;i++) tempaverprog=(float)(tempaverprog*i+prog[i])/(i+1);
        averprog=rounding(tempaverprog);
        averaver=rounding((avermath+avereng+averprog)/3);
        for(i=0;i<total-1;i++)  //bubble-sort
        		for(j=0;j<total-1-i;j++){
        				if(aver[j]<aver[j+1]){
        						temp1=aver[j]; aver[j]=aver[j+1]; aver[j+1]=temp1;
        						temp2=math[j]; math[j]=math[j+1]; math[j+1]=temp2;
								temp3=eng[j];  eng[j]=eng[j+1];   eng[j+1]=temp3;
								temp4=prog[j]; prog[j]=prog[j+1]; prog[j+1]=temp4;
								strcpy(temp,name[j]); strcpy(name[j],name[j+1]); strcpy(name[j+1],temp);
						}
				}
        maxmath=math[0]; maxeng=eng[0]; maxprog=prog[0];
		minmath=math[0]; mineng=eng[0]; minprog=prog[0];
		for(i=0;i<total;i++){
        		if(maxmath<=math[i]) maxmath=math[i];
			    if(maxeng<=eng[i])   maxeng=eng[i];
			    if(maxprog<=prog[i]) maxprog=prog[i];
        		if(minmath>=math[i]) minmath=math[i];
			    if(mineng>=eng[i])   mineng=eng[i];
			    if(minprog>=prog[i]) minprog=prog[i];
		}
        printf("Name\tMath\tEnglish\tProg\tAverage\n");
        printf("----------------------------------------\n");
        for(i=0;i<total;i++)
        printf("%s\t%d\t%d\t%d\t%d\n",name[i],math[i],eng[i],prog[i],aver[i]);
		printf("----------------------------------------\n");
		printf("Avg\t%d\t%d\t%d\t%d\n",avermath,avereng,averprog,averaver);
		printf("Max\t%d\t%d\t%d\t%d\n",maxmath,maxeng,maxprog,aver[0]);
		printf("Min\t%d\t%d\t%d\t%d\n",minmath,mineng,minprog,aver[total-1]);
		return 0;
}
