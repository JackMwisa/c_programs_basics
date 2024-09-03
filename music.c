#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    char artist[100];
    int duration; // duration in seconds
    struct Song* next;
} Song;

typedef struct Playlist {
    Song* head;
    Song* tail;
    Song* current;
} Playlist;

// Function to create a new song node
Song* createSong(const char* title, const char* artist, int duration) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->next = NULL;
    return newSong;
}

// Function to initialize the playlist
void initPlaylist(Playlist* playlist) {
    playlist->head = NULL;
    playlist->tail = NULL;
    playlist->current = NULL;
}

// Function to add a song to the end of the playlist
void addSong(Playlist* playlist, const char* title, const char* artist, int duration) {
    Song* newSong = createSong(title, artist, duration);
    if (playlist->tail == NULL) {
        playlist->head = newSong;
        playlist->tail = newSong;
        playlist->current = newSong;
    } else {
        playlist->tail->next = newSong;
        playlist->tail = newSong;
    }
    printf("Added song: %s by %s\n", title, artist);
}

// Function to remove a song by index
void removeSong(Playlist* playlist, int index) {
    if (playlist->head == NULL) {
        printf("The playlist is empty. No song to remove.\n");
        return;
    }
    
    Song* temp = playlist->head;
    Song* prev = NULL;
    int i;

    for (i = 0; i < index && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("No song found at index %d.\n", index);
        return;
    }

    if (prev == NULL) { // Removing the head
        playlist->head = temp->next;
        if (playlist->current == temp) {
            playlist->current = playlist->head;
        }
    } else {
        prev->next = temp->next;
        if (playlist->current == temp) {
            playlist->current = prev->next;
        }
    }

    if (temp == playlist->tail) {
        playlist->tail = prev;
    }

    free(temp);
    printf("Removed song at index %d.\n", index);
}

// Function to play the current song
void playSong(Playlist* playlist) {
    if (playlist->current == NULL) {
        printf("No song to play. The playlist is empty.\n");
        return;
    }
    printf("Now playing: %s by %s [%d seconds]\n", playlist->current->title, playlist->current->artist, playlist->current->duration);
}

// Function to navigate to the next song
void nextSong(Playlist* playlist) {
    if (playlist->current != NULL && playlist->current->next != NULL) {
        playlist->current = playlist->current->next;
        playSong(playlist);
    } else {
        printf("You are at the end of the playlist.\n");
    }
}

// Function to navigate to the previous song
void previousSong(Playlist* playlist) {
    if (playlist->current == playlist->head) {
        printf("You are at the start of the playlist.\n");
        return;
    }
    
    Song* temp = playlist->head;
    while (temp != NULL && temp->next != playlist->current) {
        temp = temp->next;
    }
    if (temp != NULL) {
        playlist->current = temp;
        playSong(playlist);
    }
}

// Function to display the entire playlist
void displayPlaylist(Playlist* playlist) {
    Song* temp = playlist->head;
    int index = 0;
    while (temp != NULL) {
        printf("%d. %s by %s [%d seconds]\n", index, temp->title, temp->artist, temp->duration);
        temp = temp->next;
        index++;
    }
}

// Main function to demonstrate the playlist
int main() {
    Playlist playlist;
    initPlaylist(&playlist);

    addSong(&playlist, "Song1", "Artist1", 210);
    addSong(&playlist, "Song2", "Artist2", 180);
    addSong(&playlist, "Song3", "Artist3", 240);

    printf("\nPlaylist:\n");
    displayPlaylist(&playlist);

    printf("\nPlaying current song:\n");
    playSong(&playlist);

    printf("\nNext song:\n");
    nextSong(&playlist);

    printf("\nPrevious song:\n");
    previousSong(&playlist);

    printf("\nRemove song at index 1:\n");
    removeSong(&playlist, 1);
    
    printf("\nPlaylist after removal:\n");
    displayPlaylist(&playlist);

    return 0;
}
