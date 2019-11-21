#ifndef MP3_H_
#define MP3_H_

typedef struct mp3
{
	char *artist;
	char *title;
	int year;
	int runtime;
	struct mp3 *next;
	struct mp3 *prev;
} mp3_t;

void add(mp3_t **head, mp3_t **tail);

void deleteMP3(mp3_t **head, mp3_t **tail);

void printBegToEnd(mp3_t *head);

void printEndToBeg(mp3_t *tail);

void exit_mp3(mp3_t *head);

#endif // MP3_H_
