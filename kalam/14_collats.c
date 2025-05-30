#include <stdio.h>

#define LIMIT 1000000

int main() {
 long long_chan = 0;
long start_num = 0;

for (long i = 1; i < LIMIT; i++) {
long n = i;
    long chan_len = 1;
    while (n != 1) {
if (n % 2 == 0)
  n = n / 2;
  else
  n = 3 * n + 1;
    chan_len++;
        }

if (chan_len > long_chan) {
 long_chan = chan_len;
 start_num = i;
        }
    }

    printf("chain is: %ld\n", start_num);
    return 0;
}
