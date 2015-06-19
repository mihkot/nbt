#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int arr[N][N], clr_tmp = 0, clr_key, choice = 1;

void dfs(int y, int x) {
    printf("\n->dfs ");
    arr[y][x] = clr_key;
    if (y - 1 >= 0 && arr[y - 1][x] == clr_tmp) {
        printf("->1 ");
        dfs(y - 1, x);
        printf("1-> ");
    }
    if (x + 1 < N && arr[y][x + 1] == clr_tmp) {
        printf("->2 ");
        dfs(y, x + 1);
        printf("2-> ");
    }
    if (y + 1 < N && arr[y + 1][x] == clr_tmp) {
        printf("->3 ");
        dfs(y + 1, x);
        printf("3-> ");
    }
    if (x - 1 >= 0 && arr[y][x - 1] == clr_tmp) {
        printf("->4 ");
        dfs(y, x - 1);
        printf("4-> ");
    }
    printf("dfs->\n");
}

int arr_prn(int arr[N][N]) {
    int clr_all = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[j][i]);
            if (arr[j][i] != clr_key)
                clr_all++;
        }
        printf("\n");
    }
    return clr_all;
}

int main() {
    srand(time(NULL));
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            arr[j][i] = (rand() % 6) + 1;
    while (1) {
        system("clear");
        if (arr_prn(arr) == 0) // печать поля
            break; // выход по "все одинаковые"?
        else
            printf("\n%d-й ход :", choice++); //подсчет кол-ва ходов
        scanf("%d", &clr_key); //ввод номера(цвета))
        if (clr_key == 0) // выход по "0" на любом ходе
            break;
        if (clr_key == arr[0][0] || clr_key > 6)
            continue; // повторить ввод если "тот-же цвет" или "цвет > 6"
        
        clr_tmp = arr[0][0];
        dfs(0, 0);
    }
    printf("\nитого %d\n", choice - 1);
    return 0;
}
