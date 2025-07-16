//
// Created by TDG on 14/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SONGS 100

typedef struct Song {
   char title[100];
} Song;

typedef struct Queue {
   Song songs[MAX_SONGS];
   int front;
   int rear;
} Queue;

typedef struct Stack {
   Song songs[MAX_SONGS];
   int top;
} Stack;

// Khoi tao hang doi
void initQ(Queue *q) {
   q->front = -1;
   q->rear = -1;
}

// Khoi tao ngan xep
void initStk(Stack *s) {
   s->top = -1;
}

// Kiem tra hang doi trong
bool isQEmpty(Queue *q) {
   return q->front == -1;
}

// Kiem tra hang doi day
bool isQFull(Queue *q) {
   return (q->rear + 1) % MAX_SONGS == q->front;
}

// Kiem tra ngan xep trong
bool isStkEmpty(Stack *s) {
   return s->top == -1;
}

// Kiem tra ngan xep day
bool isStkFull(Stack *s) {
   return s->top == MAX_SONGS - 1;
}

// Them bai hat vao hang doi
void addQ(Queue *q, Song song) {
   if (isQFull(q)) {
      printf("Hang doi day!\n");
      return;
   }
   if (isQEmpty(q)) {
      q->front = 0;
   }
   q->rear = (q->rear + 1) % MAX_SONGS;
   q->songs[q->rear] = song;
}

// Xoa bai hat khoi hang doi
Song delQ(Queue *q) {
   Song emptySong = {""};
   if (isQEmpty(q)) {
      printf("Hang doi trong!\n");
      return emptySong;
   }
   Song song = q->songs[q->front];
   if (q->front == q->rear) {
      q->front = q->rear = -1;
   } else {
      q->front = (q->front + 1) % MAX_SONGS;
   }
   return song;
}

// Them bai hat vao ngan xep
void pushStk(Stack *s, Song song) {
   if (isStkFull(s)) {
      printf("Lich su day!\n");
      return;
   }
   s->top++;
   s->songs[s->top] = song;
}

// Xoa bai hat khoi ngan xep
Song popStk(Stack *s) {
   Song emptySong = {""};
   if (isStkEmpty(s)) {
      printf("Lich su trong!\n");
      return emptySong;
   }
   Song song = s->songs[s->top];
   s->top--;
   return song;
}

// Them bai hat vao hang doi
void addSong(Queue *q) {
   Song newSong;
   printf("Nhap ten bai hat: ");
   fgets(newSong.title, sizeof(newSong.title), stdin);
   newSong.title[strcspn(newSong.title, "\n")] = '\0';
   addQ(q, newSong);
   printf("Da them bai hat '%s'!\n", newSong.title);
}

// Phat bai hat tiep theo
void playNext(Queue *q, Stack *stk) {
   if (isQEmpty(q)) {
      printf("Ko co bai hat trong hang doi!\n");
      return;
   }
   Song song = delQ(q);
   pushStk(stk, song);
   printf("Dang phat: %s\n", song.title);
}

// Quay lai bai hat truoc
void playPrev(Queue *q, Stack *stk) {
   if (isStkEmpty(stk)) {
      printf("Lich su trong!\n");
      return;
   }
   Song song = popStk(stk);
   // Them bai hat vao dau hang doi
   if (isQEmpty(q)) {
      q->front = q->rear = 0;
      q->songs[0] = song;
   } else {
      q->front = (q->front - 1 + MAX_SONGS) % MAX_SONGS;
      q->songs[q->front] = song;
   }
   // Phat bai hat hien tai (neu con)
   if (!isStkEmpty(stk)) {
      printf("Dang phat: %s\n", stk->songs[stk->top].title);
   } else {
      printf("Da quay ve dau lich su!\n");
   }
}

// Hien thi lich su phat nhac
void showHist(Stack *stk) {
   if (isStkEmpty(stk)) {
      printf("Lich su trong!\n");
      return;
   }
   printf("\nLich su phat nhac:\n");
   for (int i = stk->top; i >= 0; i--) {
      printf("%d. %s\n", stk->top - i + 1, stk->songs[i].title);
   }
}

// Hien thi menu
void showMenu() {
   printf("\n=== MUSIC PLAYER ===\n");
   printf("1. Them bai hat\n");
   printf("2. Phat tiep theo\n");
   printf("3. Phat lai truoc\n");
   printf("4. Xem lich su\n");
   printf("5. Thoat\n");
}

// Ham main
int main() {
   Queue q;
   Stack stk;
   initQ(&q);
   initStk(&stk);
   int choice;
   while (1) {
      showMenu();
      printf("Nhap lua chon: ");
      scanf("%d", &choice);
      getchar(); // Xoa bo dem
      switch (choice) {
         case 1:
            addSong(&q);
            break;
         case 2:
            playNext(&q, &stk);
            break;
         case 3:
            playPrev(&q, &stk);
            break;
         case 4:
            showHist(&stk);
            break;
         case 5:
            printf("Thoat chuong trinh!\n");
            return 0;
         default:
            printf("Lua chon ko hop le!\n");
      }
   }
}