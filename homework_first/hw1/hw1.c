#include <stdio.h>
#include <string.h>
int main()
{
	char input[100];
	while (1)
	{
		printf("輸入一個水果的英文:");
		scanf("%s", input);
		if (strcmp(input, "0") == 0)
		{
			printf("See you again~~~\n");
			break;
		}
		else if (strcmp(input, "fruit") == 0)
			printf("%s 的中文意思是 系統\n", input);
		else if (strcmp(input, "apple") == 0)
			printf("%s 的中文意思是 蘋果\n", input);
		else if (strcmp(input, "banana") == 0)
			printf("%s 的中文意思是 香蕉\n", input);
		else if (strcmp(input, "berry") == 0)
			printf("%s 的中文意思是 莓果\n", input);
		else if (strcmp(input, "blackberry") == 0)
			printf("%s 的中文意思是 黑莓\n", input);
		else if (strcmp(input, "blueberry") == 0)
			printf("%s 的中文意思是 藍莓\n", input);
		else if (strcmp(input, "breadfruit") == 0)
			printf("%s 的中文意思是 麵包果\n", input);
		else if (strcmp(input, "cantaloupe") == 0)
			printf("%s 的中文意思是 哈密瓜\n", input);
		else if (strcmp(input, "carambola") == 0)
			printf("%s 的中文意思是 楊桃\n", input);
		else if (strcmp(input, "chestnut") == 0)
			printf("%s 的中文意思是 栗子\n", input);
		else if (strcmp(input, "cherry") == 0)
			printf("%s 的中文意思是 櫻桃\n", input);
		else if (strcmp(input, "ciku") == 0)
			printf("%s 的中文意思是 人參果\n", input);
		else if (strcmp(input, "tangerine") == 0)
			printf("%s 的中文意思是 柑橘\n", input);
		else if (strcmp(input, "coconut") == 0)
			printf("%s 的中文意思是 椰子\n", input);
		else if (strcmp(input, "cranberry") == 0)
			printf("%s 的中文意思是 蔓越莓\n", input);
		else if (strcmp(input, "currant") == 0)
			printf("%s 的中文意思是 醋栗\n", input);
		else if (strcmp(input, "date") == 0)
			printf("%s 的中文意思是 椰棗\n", input);
		else if (strcmp(input, "citron") == 0)
			printf("%s 的中文意思是 柚子\n", input);
		else if (strcmp(input, "dragon fruit") == 0)
			printf("%s 的中文意思是 火龍果\n", input);
		else if (strcmp(input, "durian") == 0)
			printf("%s 的中文意思是 榴槤\n", input);
		else if (strcmp(input, "fig") == 0)
			printf("%s 的中文意思是 無花果\n", input);
		else if (strcmp(input, "grape") == 0)
			printf("%s 的中文意思是 葡萄\n", input);
		else if (strcmp(input, "grapefruit") == 0)
			printf("%s 的中文意思是 葡萄柚\n", input);
		else if (strcmp(input, "green apple") == 0)
			printf("%s 的中文意思是 青蘋果\n", input);
		else if (strcmp(input, "guava") == 0)
			printf("%s 的中文意思是 芭樂\n", input);
		else if (strcmp(input, "kiwi") == 0)
			printf("%s 的中文意思是 奇異果\n", input);
		else if (strcmp(input, "kumquat") == 0)
			printf("%s 的中文意思是 柑桔\n", input);
		else if (strcmp(input, "lemon") == 0)
			printf("%s 的中文意思是 檸檬\n", input);
		else if (strcmp(input, "longan") == 0)
			printf("%s 的中文意思是 龍眼\n", input);
		else if (strcmp(input, "loquat") == 0)
			printf("%s 的中文意思是 枇杷\n", input);
		else if (strcmp(input, "lychee") == 0)
			printf("%s 的中文意思是 荔枝\n", input);
		else if (strcmp(input, "mango") == 0)
			printf("%s 的中文意思是 芒果\n", input);
		else if (strcmp(input, "medlar") == 0)
			printf("%s 的中文意思是 枸杞\n", input);
		else if (strcmp(input, "Melon") == 0)
			printf("%s 的中文意思是 香瓜\n", input);
		else if (strcmp(input, "mulberry") == 0)
			printf("%s 的中文意思是 桑椹\n", input);
		else if (strcmp(input, "olive") == 0)
			printf("%s 的中文意思是 橄欖\n", input);
		else if (strcmp(input, "orange") == 0)
			printf("%s 的中文意思是 柳橙\n", input);
		else if (strcmp(input, "papaya") == 0)
			printf("%s 的中文意思是 木瓜\n", input);
		else if (strcmp(input, "passion fruit") == 0)
			printf("%s 的中文意思是 百香果\n", input);
		else if (strcmp(input, "peach") == 0)
			printf("%s 的中文意思是 桃子\n", input);
		else if (strcmp(input, "peanut") == 0)
			printf("%s 的中文意思是 花生\n", input);
		else if (strcmp(input, "pear") == 0)
			printf("%s 的中文意思是 梨子\n", input);
		else if (strcmp(input, "persimmon") == 0)
			printf("%s 的中文意思是 柿子\n", input);
		else if (strcmp(input, "pineapple") == 0)
			printf("%s 的中文意思是 鳳梨\n", input);
		else if (strcmp(input, "plum") == 0)
			printf("%s 的中文意思是 梅子\n", input);
		else if (strcmp(input, "pomegranate") == 0)
			printf("%s 的中文意思是 石榴\n", input);
		else if (strcmp(input, "starfruit") == 0)
			printf("%s 的中文意思是 楊桃\n", input);
		else if (strcmp(input, "strawberry") == 0)
			printf("%s 的中文意思是 草莓\n", input);
		else if (strcmp(input, "sugarcane") == 0)
			printf("%s 的中文意思是 甘蔗\n", input);
		else if (strcmp(input, "walnut") == 0)
			printf("%s 的中文意思是 胡桃\n", input);
		else if (strcmp(input, "watermelon") == 0)
			printf("%s 的中文意思是 西瓜\n", input);
		else if (strcmp(input, "jambu air") == 0)
			printf("%s 的中文意思是 蓮霧\n", input);
		else if (strcmp(input, "rambutan") == 0)
			printf("%s 的中文意思是 紅毛丹\n", input);
		else if (strcmp(input, "pistachio") == 0)
			printf("%s 的中文意思是 開心果\n", input);
		else if (strcmp(input, "raspberry") == 0)
			printf("%s 的中文意思是 覆盆子\n", input);
		else if (strcmp(input, "shaddock") == 0)
			printf("%s 的中文意思是 文旦\n", input);
		else if (strcmp(input, "tomato") == 0)
			printf("%s 的中文意思是 番茄\n", input);
		else
			printf("李公蝦毀!?\n");
	}
	return 0;
}
