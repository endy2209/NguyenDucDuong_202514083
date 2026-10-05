//Recursive Hanoi Tower
//NguyenDucDuong_202514083
#include <stdio.h>
#include <math.h>

void hanoiTower(int n, char source, char target, char temp) {
    if (n == 1) {       //end condition
        printf("Move disk from %c to %c\n", source, target);
        return;
    }
    hanoiTower(n - 1, source, temp, target);        //(n-1) disks from source to temp using target as auxiliary
    printf("Move disk from %c to %c\n", source, target);
    hanoiTower(n - 1, temp, target, source);        //(n-1) disks from temp to target using source as auxiliary
}

int main() {
    int n; 
    printf("Hanoi Tower Problem with A as source, C as target, and B as temporary.\n");
    printf("Enter the number of disks: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of disks!\n");
        return 1;
    }
    hanoiTower(n, 'A', 'C', 'B'); 
    printf("Number of moves: %d\n", (int)pow(2, n) - 1); 
    return 0;
}