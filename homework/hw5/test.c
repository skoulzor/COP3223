// Hailey Simpson
// July 19, 2026

#include <stdio.h>
#include <string.h>
#include "playlist.h"

int main(int argc, char *argv[])
{
    Playlist playlist;
    char line[256];

    // Check command-line arguments 
    if (argc != 2) {
        printf("Usage: %s <playlist file>\n", argv[0]);
        return 1;
    }

    // Initialize playlist 
    playlist_init(&playlist);

    // Load file 
    playlist_load(&playlist, argv[1]);

    // Command loop 
    while (1)
    {
        printf("> ");

        // Read one line from stdin 
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        // Remove trailing newline 
        line[strcspn(line, "\n")] = '\0';

        // p -> print playlist 
        if (strcmp(line, "p") == 0) {
            playlist_print(&playlist);
        }

        // r -> reverse print 
        else if (strcmp(line, "r") == 0) {
            playlist_print_reverse(&playlist);
        }

        // t -> total duration */
        else if (strcmp(line, "t") == 0) {
            int total = playlist_total_duration(&playlist);

            if (total >= 3600) {
                printf("Total: %d:%02d:%02d\n",
                    total / 3600,
                    (total % 3600) / 60,
                    total % 60);
            }
            else {
                printf("Total: %d:%02d\n",
                    total / 60,
                    total % 60);
            }
        }

        // a title|artist|sec 
        else if (strncmp(line, "a ", 2) == 0) {
            char title[64];
            char artist[64];
            int duration;

            if (sscanf(line + 2,
                       "%63[^|]|%63[^|]|%d",
                       title,
                       artist,
                       &duration) == 3)
            {
                if (playlist_append(&playlist,
                                    title,
                                    artist,
                                    duration) != 0)
                {
                    printf("Failed to add song.\n");
                }
            }
            else {
                printf("Invalid command format.\n");
            }
        }

        // pre title|artist|sec 
        else if (strncmp(line, "pre ", 4) == 0) {
            char title[64];
            char artist[64];
            int duration;

            if (sscanf(line + 4,
                       "%63[^|]|%63[^|]|%d",
                       title,
                       artist,
                       &duration) == 3)
            {
                if (playlist_prepend(&playlist,
                                     title,
                                     artist,
                                     duration) != 0)
                {
                    printf("Failed to add song.\n");
                }
            }
            else {
                printf("Invalid command format.\n");
            }
        }

        // ins after|title|artist|sec 
        else if (strncmp(line, "ins ", 4) == 0) {
            char after[64];
            char title[64];
            char artist[64];
            int duration;

            if (sscanf(line + 4,
                       "%63[^|]|%63[^|]|%63[^|]|%d",
                       after,
                       title,
                       artist,
                       &duration) == 4)
            {
                if (playlist_insert_after(&playlist,
                                          after,
                                          title,
                                          artist,
                                          duration) != 0)
                {
                    printf("Not found: \"%s\"\n", after);
                }
            }
            else {
                printf("Invalid command format.\n");
            }
        }

        // del title 
        else if (strncmp(line, "del ", 4) == 0) {

            if (playlist_remove(&playlist, line + 4) != 0) {
                printf("Not found: \"%s\"\n", line + 4);
            }
        }

        // up title 
        else if (strncmp(line, "up ", 3) == 0) {

            if (playlist_move_up(&playlist, line + 3) != 0) {
                printf("Not found: \"%s\"\n", line + 3);
            }
        }

        // q -> save and quit 
        else if (strcmp(line, "q") == 0) {

            if (playlist_save(&playlist, argv[1]) != 0) {
                fprintf(stderr, "Error saving playlist.\n");
            }

            playlist_free(&playlist);
            break;
        }

        // Unknown command 
        else {
            printf("Unknown command. Type 'p' to print.\n");
        }
    }

    return 0;
}