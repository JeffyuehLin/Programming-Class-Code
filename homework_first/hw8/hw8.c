#include <stdio.h>
void reversed(char *arr,int len){  //reverse the arr
        int i;
        char tmp;
        for (i = 0; i < len / 2; i++){
                tmp = arr[i];
                arr[i] = arr[len - 1 - i];
                arr[len - 1 - i] = tmp;
        }
}
int rmmid(char *arr, int len){ //remove the middle space
        int j = 0, k, num = 0, mark = 0;
        int s1 = 0, s2 = 0, s3 = 0; //'s' are the statement of space
        while(mark != len){
                for(j = mark; j < len; j++){
                        if (arr[j] != ' ')
                                s2 = 0;    //s2 is the current statement of the space
                        else
                                s2 = 1;
                        if (s1 == 0 && s2 == 0)
                                continue;
                        else if (s2 == 1)
                                num++;
                        else if (s1 == 1 && s2 == 0){
                                for (k = j; k < len;k++){
                                        if(arr[k] == ' ' && s3 == 0){
                                                mark = k;
                                                s3 = 1;    //s3 is the times of space
                                        }
                                        arr[k - (num - 1)] = arr[k];
                                }
                                len = len - num + 1;
                                if(s3 == 0)
                                        mark = len;
                                else
                                        mark = mark - num + 1;
                                break;
                        }
                        s1 = s2;			//s1 is the last statement of the space
                }
                s1 = s2 = s3= 0;
                num = 0;
        }
        return len;
}
int removed(char *arr){
        int i = 0,len = 0;
        while((arr[i] = getchar()) != EOF){
                if(arr[0] == ' ')
                        continue;
                else if(arr[i]=='\n')
                        break;
                else
                        i++;
        }
        len = i;
        for (i = len - 1; i >= 0; i--){
                if(arr[i]==' ')
                        continue;
                else
                        break;
        }
        len = i + 1;
        len = rmmid(arr, len);
        reversed(arr, len);
        if(len==0 && arr[0]=='\n')
                len = 0;
        else if (len==0)
                len = -1;
        return len;
}
int main(void){
        char arr[1001];
        int length,i;
        while ((length=removed(arr))!=-1){
                for (i = 0; i < length; i++)
                        printf("%c", arr[i]);
                printf("\n");
        }
        return 0;
}
