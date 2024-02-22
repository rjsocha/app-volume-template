/*
 * Based on https://gist.githubusercontent.com/eatnumber1/f97ac7dad7b1f5a9721f/raw/5c5193f20142511a5fc7069a539f4e5aba0ea470/renameat2.c
 *
 *
 * Copyright (c) 2023 Russell Harmon
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#define _GNU_SOURCE
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

#ifndef RENAME_NOREPLACE
#define RENAME_NOREPLACE (1 << 0) /* Don't overwrite target */ // from include/uapi/linux/fs.h
#endif

#ifndef RENAME_EXCHANGE
#define RENAME_EXCHANGE (1 << 1) /* Exchange source and dest */ // from include/uapi/linux/fs.h
#endif

#ifndef SYS_renameat2
#if defined(__x86_64__)
#define SYS_renameat2 314 // from arch/x86/syscalls/syscall_64.tbl
#elif defined(__i386__)
#define SYS_renameat2 353 // from arch/x86/syscalls/syscall_32.tbl
#else
#error Architecture unsupported
#endif
#endif // ifndef SYS_renameat2

int main(int argc, char *argv[]) {
  int flags = RENAME_EXCHANGE;
  if (argc != 3) {
    fprintf(stderr,"Usage: %s SOURCE DEST\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if (syscall(SYS_renameat2, AT_FDCWD, argv[1], AT_FDCWD, argv[2], flags) != 0) {
    perror(argv[0]);
    exit(EXIT_FAILURE);
  }
}
