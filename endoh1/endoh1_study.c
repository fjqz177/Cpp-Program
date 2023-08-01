#include <stdio.h>
#include <unistd.h>
#include <complex.h>

#define MAX_FLUID_SIZE 97687
#define MAX_CANVAS_SIZE 6856
#define MAX_X 79
#define MAX_Y 23
#define GRAVITY 1
#define PRESSURE 4
#define VISCOSITY 8
#define SLEEP_TIME 12321

double complex fluid[MAX_FLUID_SIZE], *p, *q, *r = fluid, w = 0, d;
int x, y;
char canvas[MAX_CANVAS_SIZE] = "\x1b[2J"
                               "\x1b"
                               "[1;1H     ";
char *output = canvas, *temp;

int main() {
    // 读取标准输入，初始化流体数组
    for (; 0 < (x = getc(stdin));) {
        w = x > '\n' ? ' ' < x ? 4 [ *r++ = w, r] = w + 1, *r = r[5] = x == '#', r += 9 : 0, w - I : (x = w + 2);
        /*
        if (x > '\n') {
            if (' ' < x) {
                w = 4 [ *r++ = w, r] = w + 1, *r = r[5] = x == '#', r += 9;
            } else {
                w= w - I;
            }
        } else {
            w = (x = w + 2);
        }
        */
    }
    for (;; puts(output), output = canvas + 4) {
        // 计算流体元素之间的压力
        for (p = fluid; p[2] = p[1] * 9, p < r; p += 5) {
            for (q = fluid; w = cabs(d = *p - *q) / 2 - 1, q < r; q += 5) {
                // p[2] += (x = 1 - w) > 0 ? w * w : 0;
                x = 1 - w;
                if (x > 0) {
                    p[2] += w * w;
                }
            }
        }
        // 计算流体元素之间的粘性
        for (p = fluid; p[3] = GRAVITY, p < r; p += 5) {
            for (q = fluid; w = cabs(d = *p - *q) / 2 - 1, q < r; q += 5) {
                // p[3] += (x = 1 - w) > 0 ? w * (d * (3 - p[2] - q[2]) * PRESSURE + p[4] * VISCOSITY - q[4] * VISCOSITY) / p[2] : 0;
                x = 1 - w;
                if (x > 0) {
                    p[3] += w * (d * (3 - p[2] - q[2]) * PRESSURE + p[4] * VISCOSITY - q[4] * VISCOSITY) / p[2];
                }
            }
        }
        // 清空画布
        for (x = 9; 2011 > x++;)
            canvas[x] = 0;

        // 将流体状态映射到字符画布上
        for (p = fluid; p < r; p += 5) {
            x = *p * I;
            y = *p / 2;
            temp = canvas + 10 + x + 80 * y;
            *p += p[4] += p[3] / 10 * !p[1];
            if (0 <= x && x < MAX_X && 0 <= y && y < MAX_Y) {
                1 [1 [ *temp |= 8, temp] |= 4, temp += 80] = 1;
                *temp |= 2;
            }
        }

        // 更新画布字符
        for (x = 9; 2011 > x++;) {
            canvas[x] = " '`-.|//,\\"
                        "|\\_"
                        "\\/\x23\n"[x % 80 - 9 ? x[canvas] : 16];
        }

        // 延时操作
        usleep(SLEEP_TIME);
    }
    return 0;
}
