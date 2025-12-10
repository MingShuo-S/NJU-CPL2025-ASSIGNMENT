#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int find_and_replace(char *targ, char *A, char typeA, char *B, char typeB) {
  static char ubuf[1000006];
  char *seg1 = targ, *seg2 = NULL;
  // 使用拼接的方式进行替换。即，将“前面的部分”、“替换的串”、“后面的部分”根据指令的要求拼接
  // AAAAxBB  .[x]^[CCC]  ->  "CCC" + "AAAA"         + "BB"
  // AAAAxBB  .[x].[CCC]  ->          "AAAA" + "CCC" + "BB"
  // AAAAxBB  .[x]$[CCC]  ->          "AAAA"         + "BB" + "CCC"
  // 稍后我们会让 seg2 指向“后面的部分”的起始，即 "BB" 的起始。
  // 这是通过先找到 "x" 的开始，再向后移动 strlen("x") 实现的。 
  int lenA = strlen(A), lenT = strlen(targ);
  if (typeA == '.')
    seg2 = strstr(targ, A);
  if (typeA == '^')
    if (strncmp(targ, A, lenA) == 0)
      seg2 = targ;
  if (typeA == '$')
    if (strncmp(targ + lenT - lenA, A, lenA) == 0)
      seg2 = targ + lenT - lenA;
  // 如果没有找到，直接返回
  if (seg2 == NULL) return 0;
  // 在 "x" 的开头写一个 \0，这样 "AAAA" 就会被这个 \0 结束而不会变成 "AAAAx..."
  *seg2 = '\0';
  seg2 += lenA;
  // 接下来是拼接部分。参考上面的描述即可
  ubuf[0] = '\0';
  if (typeB == '^') strcat(ubuf, B);
  strcat(ubuf, seg1);
  if (typeB == '.') strcat(ubuf, B);
  strcat(ubuf, seg2);
  if (typeB == '$') strcat(ubuf, B);
  strcpy(targ, ubuf);
  return 1;
}

int main() {
  int n;
  char *opts[402];
  char buf[1000006];
  char *stA[402], *stB[402];
  // 对于每条指令，先读入到 buf 中，再分配一段内存并将其复制过去。用 opts 来记录这段内存。
  // 为了代码更短，不单独将需要替换的子串构造出来，而是用 sta 和 stb 标记子串的开头
  // 用 strtok 来同时实现 “找到子串开头” 和 “在子串末尾写\0” 这两件事情
  // 例如：读入一个 ".[abc]^[ba]" 指令时，会对其进行两次 strtok，并且修改这个字符串：
  // 读入： .  [  a  b  c  ]  ^  [  b  a  ]  \0
  // 处理： .  [  a  b  c  \0 ^  [  b  a  \0 \0
  //             ^(stA)            ^(stB)
  // 在后面的替换时，直接把 stA 和 stB 用作指令的（替换用）子串，可以方便地利用库函数完成代码。
  // 注1：在上面的例子中，使用 printf 输出 stA stB 对应的两个字符串，就会分别输出 "abc" "ba"
  //     由此可见确实实现了寻找子串的功能
  // 注2：strtok 函数的功能是：给定一个字符串（字符集）delim，从给定的位置开始，寻找第一段
  //      不包含在 delim 里的子串，并向这个子串后面写一个 \0 并返回其开始位置。
  //      （若第一个参数为 NULL，则从上一次调用找到的子串结尾向后找。具体描述见 reference。）
  //      故，下面的调用会分别找到 "[abc" 和 "[ba" 的开头，并分别加一指向 "abc" 和 "ba" 的开头。
  //      找左方括号是出于替换子串可能为空的考量。如果为空，这样的操作至少还是能找到一个 '['。
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", buf);
    opts[i] = malloc(sizeof(char) * (strlen(buf) + 1));
    strcpy(opts[i], buf);
    stA[i] = strtok(opts[i], ".^$]") + 1;
    stB[i] = strtok(NULL, ".^$]") + 1;
  }
  scanf("%s", buf);
  for (int i = 1; i <= n; i++)
    if (find_and_replace(buf, stA[i], *(stA[i] - 2), stB[i], *(stB[i] - 2)))
      i = 0;
  // 没用的小技巧：在循环内将 i 设为 0，那么下一轮循环的时候 i 就从 1 开始递增了
  // 等价于 while (replaced) { replaced = 0; for (...) if (replace(...)) replaced = 1; }
  printf("%s\n", buf);
}