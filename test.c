/*
 * Copyright (c) 2021-2022 Max Mruszczak <u at one u x dot o r g>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Create sine wave audio file in Sparc Audio fmt (s16be)
 */

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "snd.h"


int
main(void)
{
	int fd, i;
	short *data;
	size_t len;
	Sndhdr hdr;

	hdr.offset = SND_DEFAULT_OFFSET;
	hdr.encoding = LINEAR16;
	hdr.rate = 8000;
	hdr.chan = 1;

	len = hdr.rate * 5;
	data = malloc(sizeof(short)*len);
	for (i = 0; i < len; ++i)
		data[i] = 500 * sin(i);
	hdr.size = sizeof(short) * len;

	fd = open("test.au", O_WRONLY | O_CREAT);
	if (fd < 0) {
		perror("couldn't open file");
		return 1;
	}
	snd_write_hdr(fd, hdr);
	snd_write_16pcm(fd, data, len);
	close(fd);
	free(data);
	return 0;
}
