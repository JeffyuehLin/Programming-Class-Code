#include <stdio.h>
#include <ctype.h>
int main(){
		char c;
		float arr[5],max=0.0;
		int t;
		float a=0.0,e=0.0,i=0.0,o=0.0,u=0.0,space=0.0,digit=0.0,total=0.0;
		while((c=getchar())!=EOF){
				total++;
				c=tolower(c);
				if(c=='a') a++;
				else if(c=='e') e++;
                else if(c=='i') i++;
                else if(c=='o') o++;
                else if(c=='u') u++;
                else if(c==' '||c=='\n'||c=='\t') space++;
                else if(c>=48&&c<=57) digit++;
		}

		if(total==0) printf("a:0\ne:0\ni:0\no:0\nu:0\ndigit:0\nspace:0\n");
		else{
				a=a/total; e=e/total; i=i/total; o=o/total; u=u/total; space=space/total; digit=digit/total;
                if(a==0) printf("a:0\n");
		        else printf("a:%f\n",a);
		        if(e==0) printf("e:%f\n",e);
		        else printf("e:%f\n",e);
		        if(i==0) printf("i:0\n");
		        else printf("i:%f\n",i);
		        if(o==0) printf("o:0\n");
		        else printf("o:%f\n",o);
		        if(u==0) printf("u:0\n");
		        else printf("u:%f\n",u);
		        if(digit==0) printf("digit:0\n");
		        else printf("digit:%f\n",digit);
		        if(space==0) printf("space:0\n");
		        else printf("space:%f\n",space);
		}

        arr[0]=a; arr[1]=e; arr[2]=i; arr[3]=o; arr[4]=u;
        for(t=0;t<5;t++){
        		if(max<=arr[t]){
        				max=arr[t];
				}
				else if(max>arr[t]) continue;
		}

		printf("The most common vowel:");
		if(max!=0){
				if(max==arr[0]){
						printf("a");
						if(max==arr[1]) printf(",e");
				        if(max==arr[2]) printf(",i");
				        if(max==arr[3]) printf(",o");
				        if(max==arr[4]) printf(",u");
				}
				else if(max==arr[1]){
						printf("e");
						if(max==arr[2]) printf(",i");
						if(max==arr[3]) printf(",o");
						if(max==arr[4]) printf(",u");
				}
				else if(max==arr[2]){
						printf("i");
						if(max==arr[3]) printf(",o");
						if(max==arr[4]) printf(",u");
				}
				else if(max==arr[3]){
						printf("o");
						if(max==arr[4]) printf(",u");
				}
				else if(max==arr[4]) printf("u");
		}
        printf("\n");
		return 0;
}
