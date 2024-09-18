#include <windows.h>
#pragma warning(disable : 4996)
#include <stdio.h>

#define NUMBER_OF_THREADS 5
typedef struct {
	int sleep;
	int tid;
} threadData_t;
DWORD WINAPI ThreadFunction(threadData_t*tdata) {
	printf("%d start\n",tdata->tid);
	Sleep(tdata->sleep);
	printf("%d stopped\n",tdata->tid);
	free(tdata);
	return 0;
}
int main() {
	HANDLE threadlds[NUMBER_OF_THREADS];
	restart:
	for (int i = 0; i < NUMBER_OF_THREADS; ++i) {
		threadData_t* tdata = malloc(sizeof(threadData_t));
		int duration;
		scanf("%d", &duration);
		tdata->tid = i + 1;
		tdata->sleep = duration * 1000;
		threadlds[i] = i + 1;
		threadlds[i] = CreateThread(NULL, 0, ThreadFunction, tdata , 0, NULL);
	}
	DWORD wStatus = WaitForMultipleObjects(5, threadlds, TRUE, INFINITE);
	gt:
	int c = getchar();
	if (c == 'r') { goto restart; }
	else if (c == 'x') { ExitProcess(0); }
	else { goto gt; }
}