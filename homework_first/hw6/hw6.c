#include <stdio.h>
#include <math.h>
void bubblesort(int *arr,int total){		          //bubble-sort: sort the arr[]
		int i,j,temp;
		for(i=0;i<total;i++)
				for(j=0;j<total-1-i;j++)
						if(arr[j]<arr[j+1]){
								temp=arr[j];
								arr[j]=arr[j+1];
								arr[j+1]=temp;
						}
}
float rounding(float input){		                  //rounding: 如果小數點第二位>=5，加0.05，output float
		if((int)(input*100)%10>=5) 	input+=0.05;	  //注意!!!output並不是四捨五入後的最終結果
		return input;
}
void avg(float *avg,int *arr,int total){              //count the average of the arr[]
		int i;
		for(i=0;i<total;i++) *avg=(*avg*i+arr[i])/(i+1);
}
void sd(float *sd,int *arr,int total,float avg){      //count the sd
		int i=0;
		float all=0;
		for(i=0;i<total;i++) all=all+(arr[i]-avg)*(arr[i]-avg);
		*sd=sqrt(all/total);
}
int main(void){
		int arr[100],i=0,alltotal,part;
		float mid,allsd,partsd,allavg=0,partavg=0;
		while(scanf("%d",&arr[i])!=EOF) if(arr[i]>=0&&arr[i]<=9999) i++;
		alltotal=i;
		bubblesort(arr,alltotal);
		if(alltotal%2==1) mid=arr[(alltotal+1)/2-1];  //count the mid value
		else mid=(float)(arr[alltotal/2-1]+arr[alltotal/2])/2;
		avg(&allavg,arr,alltotal);                    //count the all avg
		part=(int)(alltotal*5/100+0.5);               //count the 5% into part
		avg(&partavg,arr+part,alltotal-part*2);       //count the 90% avg
		sd(&allsd,arr,alltotal,allavg);		          //count the all sd
		sd(&partsd,arr+part,alltotal-part*2,partavg); //count the 90% sd
		printf("Top 10 value\n");		              //printf all answer
		for(i=0;i<10&&i<alltotal;i++) printf("%d\n",arr[i]);
		printf("Max value:%d\n",arr[0]);
		printf("Min value:%d\n",arr[alltotal-1]);
		printf("Mid value:%.1f\n",rounding(mid));
		printf("Avg value:%.1f\n",rounding(allavg));
		printf("SD value:%.1f\n",rounding(allsd));
		printf("90%%Avg value:%.1f\n",rounding(partavg));
		printf("90%%SD value:%.1f\n",rounding(partsd));
		return 0;
}
