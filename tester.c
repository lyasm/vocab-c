#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define Read_VOCAB_SIZE =

int random_num(int max);
int count_occurrence(const char file[]);

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			printf("Usage: %s [options] -t TYPE\n", argv[0]);
			printf("Options:\n");
			printf("  -h, Display this help message\n");
			printf("  -t TYPE, request of type TYPE\n");
			printf("           Possible Values: verb, indefinido, partizip, ...");
			return 0;
		} else if (strcmp(argv[i], "-t") == 0) {
			char type[sizeof(argv[i + 1])];
			strcpy(type, argv[i + 1]);
			printf("%s",type);
		}}
	const char vocab_path[] = "./verb.data";
	int count = count_occurrence(vocab_path);
	printf("%d",count);
	random_num(100);
	return 0;
}

int random_num(int max){
	int res;
	
	struct timespec current_time;
	if (clock_gettime(CLOCK_REALTIME, &current_time) != 0) {
		perror("clock_gettime");
	}
	srandom(current_time.tv_nsec);
	res = random() % max;
	printf("\nrand: %d\n",res);
	return res;
}

int count_occurrence(const char file[])
{
	int count;
	char line[30];
	char *found;
	FILE *fptr;
	fptr = fopen(file, "r");
	printf("%s", file);
	char delimeter[] = ":";
	if (fptr == NULL ){
		printf("\nError: Couldn´t open File\n");
		printf("tried opening: %s", file);
		return -1;
	}
	while(fgets(line, 30, fptr)!= NULL) {
		found = strstr(line, delimeter);
		if (found != NULL) {
			count++;
		}
	}
	fclose(fptr);
	return count;;
}
