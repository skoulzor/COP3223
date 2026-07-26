// Hailey Simpson
// July 19, 2026

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

void playlist_init(Playlist *pl) {
    pl->head = NULL;
    pl->tail = NULL;
    pl->count = 0;
}

void playlist_free(Playlist *pl) {
    Song *cur = pl->head;

    while (cur != NULL) {
        Song *next = cur->next;
        free(cur);
        cur = next;
    }
    pl->head = NULL;
    pl->tail = NULL;
    pl->count = 0;
}

int playlist_append(Playlist *pl, const char *title, const char *artist, int duration_sec) {
    Song *newSong = malloc(sizeof(Song));

    if (newSong == NULL) {
        fprintf(stderr, "Out of memory\n");
        return -1;
    }

    strncpy(newSong->title, title, sizeof(newSong->title) - 1);
    newSong->title[sizeof(newSong->title) - 1] = '\0';

    strncpy(newSong->artist, artist, sizeof(newSong->artist) - 1);
    newSong->artist[sizeof(newSong->artist) - 1] = '\0';

    newSong->duration_sec = duration_sec;
    newSong->next = NULL;
    newSong->prev = pl->tail;

    if (pl->tail == NULL) {
        pl->head = newSong;
        pl->tail = newSong;
    } 
    else {
        pl->tail->next = newSong;
        pl->tail = newSong;
    }

    pl->count++;

    return 0;
}

int playlist_prepend(Playlist *pl, const char *title, const char *artist, int duration_sec) {
    Song *newSong = malloc(sizeof(Song));

    if (newSong == NULL) {
        fprintf(stderr, "Out of memory\n");
        return -1;
    }

    strncpy(newSong->title, title, sizeof(newSong->title) - 1);
    newSong->title[sizeof(newSong->title) - 1] = '\0';

    strncpy(newSong->artist, artist, sizeof(newSong->artist) - 1);
    newSong->artist[sizeof(newSong->artist) - 1] = '\0';

    newSong->duration_sec = duration_sec;
    newSong->prev = NULL;
    newSong->next = pl->head;

    if (pl->head == NULL) {
        pl->head = newSong;
        pl->tail = newSong;
    } 
    else {
        pl->head->prev = newSong;
        pl->head = newSong;
    }

    pl->count++;

    return 0;
}

int playlist_insert_after(Playlist *pl, const char *after_title, const char *title, const char *artist, int duration_sec) {
    Song *cur = pl->head;

    while (cur != NULL) {
        if (strcmp(cur->title, after_title) == 0) {
            Song *newSong = malloc(sizeof(Song));

            if (newSong == NULL) {
                fprintf(stderr, "Out of memory\n");
                return -1;
            }

            strncpy(newSong->title, title, sizeof(newSong->title) - 1);
            newSong->title[sizeof(newSong->title) - 1] = '\0';

            strncpy(newSong->artist, artist, sizeof(newSong->artist) - 1);
            newSong->artist[sizeof(newSong->artist) - 1] = '\0';
            
            newSong->duration_sec = duration_sec;

            newSong->prev = cur;
            newSong->next = cur->next;

            if (cur->next != NULL) {
                cur->next->prev = newSong;
            } 
            else {
                pl->tail = newSong;
            }

            cur->next = newSong;

            pl->count++;

            return 0;
        }

        cur = cur->next;
    }

    return -1;
}

int playlist_remove(Playlist *pl, const char *title) {
    Song *cur = pl->head;

    while (cur != NULL) {
        if (strcmp(cur->title, title) == 0) {
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            } 
            else {
                pl->head = cur->next;
            }

            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            } 
            else {
                pl->tail = cur->prev;
            }

            free(cur);
            pl->count--;

            return 0;
        }

        cur = cur->next;
    }

    return -1;
}

// Move up is implemented by relinking adjacent nodes. 
int playlist_move_up(Playlist *pl, const char *title) {
    Song *cur = pl->head;

    while (cur != NULL && strcmp(cur->title, title) != 0) {
        cur = cur->next;
    }

    if (cur == NULL) {
        return -1;
    }

    if (cur->prev == NULL) {
        return 0;
    }

    Song *prev = cur->prev;
    Song *beforePrev = prev->prev;
    Song *next = cur->next;

    cur->prev = beforePrev;
    cur->next = prev;

    prev->prev = cur;
    prev->next = next;

    if (beforePrev != NULL) {
        beforePrev->next = cur;
    } 
    else {
        pl->head = cur;
    }

    if (next != NULL) {
        next->prev = prev;
    } 
    else {
        pl->tail = prev;
    }

    return 0;
}

void playlist_print(const Playlist *pl) {
    const Song *cur = pl->head;
    int i = 1;

    printf("= Playlist (%d songs) =\n", pl->count);

    while (cur != NULL) {
        int minutes = cur->duration_sec / 60;
        int seconds = cur->duration_sec % 60;

        printf("  %d. %s — %s [%d:%02d]\n",
               i,
               cur->title,
               cur->artist,
               minutes,
               seconds);

        cur = cur->next;
        i++;
    }
}

void playlist_print_reverse(const Playlist *pl) {
    const Song *cur = pl->tail;
    int i = 1;

    printf("= Playlist (%d songs) =\n", pl->count);

    while (cur != NULL) {
        int minutes = cur->duration_sec / 60;
        int seconds = cur->duration_sec % 60;

        printf("  %d. %s — %s [%d:%02d]\n",
               i,
               cur->title,
               cur->artist,
               minutes,
               seconds);

        cur = cur->prev;
        i++;
    }
}

int playlist_total_duration(const Playlist *pl) {
    int total = 0;
    const Song *cur = pl->head;

    while (cur != NULL) {
        total += cur->duration_sec;
        cur = cur->next;
    }

    return total;
}

int playlist_load(Playlist *pl, const char *path) {
    playlist_free(pl);
    playlist_init(pl);

    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        fprintf(stderr, "Could not open %s\n", path);
        return -1;
    }

    char title[64];
    char artist[64];
    int duration;

    while (fscanf(fp, " %63[^|]|%63[^|]|%d", title, artist, &duration) == 3) {
        if (playlist_append(pl, title, artist, duration) != 0) {
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);
    return 0;
}

int playlist_save(const Playlist *pl, const char *path) {
    FILE *fp = fopen(path, "w");

    if (fp == NULL) {
        return -1;
    }

    const Song *cur = pl->head;

    while (cur != NULL) {
        fprintf(fp, "%s|%s|%d\n",
                cur->title,
                cur->artist,
                cur->duration_sec);

        cur = cur->next;
    }

    fclose(fp);

    return 0;
}