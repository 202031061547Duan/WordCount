#include<stdio.h>
#include<string.h>
int main() {
	char input[20];
	char txt[20];
	char c;
	int i;
	gets_s(input);
	c = input[1];
	int lenth = strlen(input);
	for (i = 3; i < lenth; i++) {
		txt[i - 3] = input[i];
	}
	txt[i - 3] = '\0';

	errno_t err;
	FILE* fp;
	char buffer[256] = { 0 };
	err = fopen_s(&fp, txt, "r");
	if (err != 0) {
		printf("打开文件失败");
	}
	else {
		fread(buffer, sizeof(buffer), 1, fp);
		int wn = 0, cn = 0, nn = 0;
		for (i = 0; i < strlen(buffer); i++) {
			char ch = buffer[i];
			if (ch == '\n')
				nn++;
			if (ch == ' ' || ch == '\n' || ch == '\t')
				cn++;
			if (ch == ' ' || ch == ',' || ch == ',')
				wn++;
		}
		if (c == 'c')
			printf("%d\n", cn);
		if (c == 'w')
			printf("%d\n", wn - nn);
		fclose(fp);
	}
	return 0;
 }