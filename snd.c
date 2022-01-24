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
 * Sparc Audio (.au/.snd) file format utils
 */

#include <unistd.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "snd.h"


int
snd_write_hdr(int fd, Sndhdr hdr)
{
	uint32_t buf[5];
	int n = 0;

	n += write(fd, ".snd", 4);
	buf[0] = htonl((uint32_t)hdr.offset);
	buf[1] = htonl((uint32_t)hdr.size);
	buf[2] = htonl((uint32_t)hdr.encoding);
	buf[3] = htonl((uint32_t)hdr.rate);
	buf[4] = htonl((uint32_t)hdr.chan);
	n += write(fd, buf, 20);
	return n;
}

int
snd_write_16pcm(int fd, const short *src, size_t len)
{
	uint16_t buf;
	int n, i;

	n = i = 0;
	for (; i < len; ++i) {
		buf = htons((int16_t)src[i]);
		n += write(fd, &buf, 2);
	}
	return n;
}
