#include <stdio.h>
int rounding(float score)
{
	return ((int)(score + 0.5));
}
int adjust(int score)
{
	float i = 0;
	for (i = 0;; i = i + 0.5)
	{
		if (score * 100 < i * i)
			return rounding(i - 0.5);
		else if (score * 100 == i * i)
			return rounding(i);
	}
}
int main()
{
	int math[1000], eng[1000], prog[1000], aver[1000];
	int i = 0, total;
	int inputmath, inputeng, inputprog;
	float tempavermath = 0, tempavereng = 0, tempaverprog = 0;
	int avermath, avereng, averprog, averaver;
	int maxmath, maxeng, maxprog, maxaver;
	int minmath, mineng, minprog, minaver;
	while (scanf("%d %d %d", &inputmath, &inputeng, &inputprog) != EOF)
	{
		math[i] = adjust(inputmath);
		eng[i] = adjust(inputeng);
		prog[i] = adjust(inputprog);
		aver[i] = rounding((float)(math[i] + eng[i] + prog[i]) / 3);
		i++;
	}
	total = i;
	for (i = 0; i < total; i++)
		tempavermath = (float)(tempavermath * i + math[i]) / (i + 1);
	avermath = rounding(tempavermath);
	for (i = 0; i < total; i++)
		tempavereng = (float)(tempavereng * i + eng[i]) / (i + 1);
	avereng = rounding(tempavereng);
	for (i = 0; i < total; i++)
		tempaverprog = (float)(tempaverprog * i + prog[i]) / (i + 1);
	averprog = rounding(tempaverprog);
	averaver = rounding((avermath + avereng + averprog) / 3);
	maxmath = math[0];
	maxeng = eng[0];
	maxprog = prog[0];
	maxaver = aver[0];
	minmath = math[0];
	mineng = eng[0];
	minprog = prog[0];
	minaver = aver[0];
	for (i = 0; i < total; i++)
	{
		if (maxmath <= math[i])
			maxmath = math[i];
		if (maxeng <= eng[i])
			maxeng = eng[i];
		if (maxprog <= prog[i])
			maxprog = prog[i];
		if (maxaver <= aver[i])
			maxaver = aver[i];
		if (minmath >= math[i])
			minmath = math[i];
		if (mineng >= eng[i])
			mineng = eng[i];
		if (minprog >= prog[i])
			minprog = prog[i];
		if (minaver >= aver[i])
			minaver = aver[i];
	}
	printf("No      Math    English Prog    Average\n");
	printf("----------------------------------------\n");
	for (i = 0; i < total; i++)
		printf("%-3d\t%-3d\t%-3d\t%-3d\t%-3d\n", i, math[i], eng[i], prog[i], aver[i]);
	printf("----------------------------------------\n");
	printf("Avg\t%-3d\t%-3d\t%-3d\t%-3d\n", avermath, avereng, averprog, averaver);
	printf("Max\t%-3d\t%-3d\t%-3d\t%-3d\n", maxmath, maxeng, maxprog, maxaver);
	printf("Min\t%-3d\t%-3d\t%-3d\t%-3d\n", minmath, mineng, minprog, minaver);
	return 0;
}