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

#define SND_DEFAULT_OFFSET 24

enum sndenc {
	LINEAR16 = 3
};

typedef struct {
	size_t offset, size, rate, chan;
	enum sndenc encoding;
} Sndhdr;

int snd_write_hdr(int, Sndhdr);
int snd_write_16pcm(int, const short *, size_t);
