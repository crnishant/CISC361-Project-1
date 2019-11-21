mp3: MP3.o
	gcc MP3.o -o mp3 -g
mp3.o: MP3.c MP3.h
	gcc -c MP3.c -o MP3.o -g
clean:
	rm *.o mp3
