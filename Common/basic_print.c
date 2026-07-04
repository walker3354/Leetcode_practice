// Q1(猜的)
printf("[%5d]\n", 12);   //   12
printf("[%-5d]\n", 12);  // 不確定
printf("[%05d]\n", 12);  // 00012
printf("[%5d]\n", -12);  //  -12
printf("[%05d]\n", -12); // 00-12

// Q2
int a = 0x10;
int b = 0x0F;
int c = 0x80;
int d = 0xFF;

printf("%d %d %d %d\n", a, b, c, d); // 16 15 128 255

// Q3
unsigned char x = 0b00001100; // 0000 1100
x |= (1 << 1);                // 0000 1110
x &= ~(1 << 3);               // 0000 0110
x ^= (1 << 2);                // 0000 0010

// Q4
unsigned char x = 0xAB; // 1010 1011

unsigned char high = (x >> 4) & 0x0F; // 0000 1010 & 0000 1111 -> 0000 1010
unsigned char low = x & 0x0F;         // 1010 1011

printf("%x %x\n", high, low); // 不確定%x

// Q5外部函數?內部函數?
int arr[10];

printf("%zu\n", sizeof(arr));                  // 40
printf("%zu\n", sizeof(arr[0]));               // 4
printf("%zu\n", sizeof(arr) / sizeof(arr[0])); // 10

// Q6
void f(int arr[]) { printf("%zu\n", sizeof(arr)); }

int main(void) {
    int a[10];
    f(a);
}
// 輸出8，因為作為參數會decay成pointer

// Q7
int a = -1;
unsigned int b = 1;

if (a < b)
    printf("less\n");
else
    printf("greater\n");
// 不確定是從int->unsign還是unsign->int，我猜測是int->unsign所以是greater

// Q8
char c = 127;
c = c + 1;

printf(
    "%d\n",
    c); // 我忘記溢出會怎麼了，但是我猜測會重新變成0，而不是進位，話說如果是unsign
// char temp = c+1U會怎樣?

// Q9
#define SQUARE(x) x* x

int a = 3;
int b = SQUARE(a + 1);

printf("%d\n", b); // 3+1*3+1 =>7，最好修成SQUARE(x) (x)* (x)

//Q10

//不是thread safe，假設今天我是一個while(temp != 0)，然後我可能有一個外部的ISR向是timer interrupt，我今天在ISR裡面把temp++，但是編譯器可能看到temp在迴圈裏面沒有修改值，這樣的話它可能會很貼心地去幫我們省力，不會每次都去記憶體撈資料