#include "MP3.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define BUFFER 128

/*main creates a head and a tail. Then, the user is prompted to enter an a to add
a song, b to delete a songs with a particular artist, c to list the songs from 
beginning to end, d to list the songs from end to beginning, and e to exit the 
program. */
int main(int argc, char *argv[])
{
	mp3_t *head=NULL;
	mp3_t *tail=NULL;
	char buffer[BUFFER];
	char response[3];
	printf("Enter: \n'a' to add a song, \n'b' to delete songs with a particular artist, \n'c' to print the list from beginning to end, \n'd' to print the list from end to beginning, \n'e' to exit:\n");
	if(fgets(buffer, BUFFER, stdin) != NULL)
	{
		strcpy(response, buffer);
		response[1]=0;
	}
	while(strcmp(response, "e") != 0)
	{
		if(strcmp(response, "a") == 0){
			add(&head, &tail);
		}
		else if(strcmp(response, "b") == 0){
			deleteMP3(&head, &tail);
		}
		else if(strcmp(response, "c") == 0){
			printBegToEnd(head);
		}
		else if(strcmp(response, "d") == 0){
			printEndToBeg(tail);
		}
		printf("Enter: \n'a' to add a song, \n'b' to delete songs with a particular artist, \n'c' to print the list from beginning to end, \n'd' to print the list from end to beginning, \n'e' to exit\n");
		if(fgets(buffer, BUFFER, stdin) != NULL)
		{
			strcpy(response, buffer);
			response[1]=0;
		}
	}
	if(strcmp(response, "e") == 0){
		exit_mp3(head);
	}
}
/*add takes in a double-pointer head mp3_t node and a double-pointer tail mp3_t
node. It checks if there is a head. If there is, it addss a node to tail->next.
If no head, then it creates a head, and points tail to it. Then, it prompts the
user to enter the artist name, the title of the song, the year it was made, and
the runtime.*/
void add(mp3_t **head, mp3_t **tail)
{
	if(*head)
	{
		(*tail)->next = (mp3_t*) malloc(sizeof(mp3_t));
		(*tail)->next->prev = *tail;
		(*tail)->next->next = NULL;
		(*tail) = (*tail)->next;
	}
	else
	{
		*head = (mp3_t*) malloc(sizeof(mp3_t));
		(*head)->next=(*head)->prev=NULL;
		*tail = *head;
	}
	char buffer[BUFFER];
	printf("Enter the artist name:\n");
        if(fgets(buffer, BUFFER, stdin) != NULL)
        {
		int len=strlen(buffer);
		buffer[len-1]=0;
		(*tail)->artist=malloc(len);
                strcpy((*tail)->artist, buffer);
        }
        printf("Enter the title of the song:\n");
        if(fgets(buffer, BUFFER, stdin) != NULL)
        {
                int len = strlen(buffer);
		buffer[len-1]=0;
		(*tail)->title=malloc(len);
		strcpy((*tail)->title,buffer);
        }
        printf("What year was it made?:\n");
	if(fgets(buffer,BUFFER,stdin)!=NULL){
		sscanf(buffer, "%d",&((*tail)->year));
	}
        printf("What is the runtime?:\n");
	if(fgets(buffer,BUFFER,stdin)!=NULL){
		sscanf(buffer,"%d",&((*tail)->runtime));
	}
}
/*deleteMP3 takes in a double-pointer head mp3_t node and a double-pointer tail
mp3_t node. If there is no head, it prompts the user to do something other than
delete. Otherwise, it asks them to enter the name of the artist who they don't 
want to listen to. It then removes all songs from the playlist with that artist.*/
void deleteMP3(mp3_t **head, mp3_t **tail)
{
	if(!*head){
		printf("There is nothing to delete\n");
	}
	else{
		printf("Name an artist that you don't want any songs from:\n");
		char buffer[BUFFER];
		char *userArtist;
		if(fgets(buffer, BUFFER, stdin)!= NULL)
		{
			int len = strlen(buffer);
			buffer[len-1]=0;
			userArtist=malloc(len);
			strcpy(userArtist,buffer);
		}
		mp3_t *current = *head;
		while(current != NULL){
			if(current == *head && strcmp(current->artist,userArtist)==0){
				*head = current->next;
				if(current->next){
					current->next->prev = NULL;
				}
				free(current->artist);
				free(current->title);
				free(current);
				current = *head;
			}
			else if(current == *tail && strcmp(current->artist,userArtist)==0){
				*tail = current->prev;
				current->prev->next = NULL;
				free(current->artist);
				free(current->title);
				free(current);
				current=NULL;
			}
			else if(strcmp(current->artist,userArtist)==0){
				current->prev->next = current->next;
				current->next->prev = current->prev;
				free(current->artist);
				free(current->title);
				mp3_t* tmp=current;
				current=current->next;
				free(tmp);
			}
			else{
				current = current->next;
			}
		}
		free(userArtist);
	}
}
/*printBetToEnd takes the head pointer and prints the entire list from beginning
to end.*/
void printBegToEnd(mp3_t *head)
{
	mp3_t *current = head;
	while(current != NULL)
	{
		printf("Title: %s\nArtist: %s\nYear: %d\nRuntime: %d\n\n", current->title, current->artist, current->year, current->runtime);
		current = current->next;
	}
}
/*printEndToBeg takes the tail pointer and prints the entire list from end to 
beginning.*/
void printEndToBeg(mp3_t *tail)
{
	mp3_t *current = tail;
	while(current != NULL)
	{
		printf("Title: %s\nArtist: %s\nYear: %d\nRuntime: %d\n\n", current->title, current->artist, current->year, current->runtime);
		current = current->prev;
	}
}
/*exit_mp3 takes in a head pointer, then traverses the list and frees any memory 
allocated to each node.*/
void exit_mp3(mp3_t *head)
{
	mp3_t *current = head;
	while(current!=NULL){
		free(current->artist);
		free(current->title);
		head=current->next;
		free(current);
		current=head;
	}
}
