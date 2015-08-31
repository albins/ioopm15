#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int64_t fib(const int n, int64_t *memo)
{
  if (n == 0)   return 0;
  if (n == 1)   return 1;

  if (!memo[n])
    {
      memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    }

  return memo[n];
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    {
      puts("Usage: ./fib <n>");
    }
  else
    {
      const int n = atoi(argv[1]);
      int64_t memo[128];
      assert(0 <= n && n < 128);
      
      printf("fib(%d) = %zd\n", n, fib(n, memo));
    }

  return 0; 
}