#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node* next;
} Node;
Node* head = NULL;

void add(char* name, int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = newNode;
}

void delete(char* name) {
    if (head == NULL) return;
    if (strcmp(head->name, name) == 0) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }
    Node* cur = head;
    while (cur->next != NULL) {
        if (strcmp(cur->next->name, name) == 0) {
            Node* tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
            return;
        }
        cur = cur->next;
    }
}

void print_list() {
    Node* cur = head;
    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

void quit() {
    Node* cur = head;
    while (cur != NULL) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    head = NULL;
}

int main() {
    char cmd[20];
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "add") == 0) {
            char name[50];
            int score;
            scanf("%s %d", name, &score);
            add(name, score);
        }
        else if (strcmp(cmd, "delete") == 0) {
            char name[50];
            scanf("%s", name);
            delete(name);
        }
        else if (strcmp(cmd, "print") == 0) {
            print_list();
        }
        else if (strcmp(cmd, "quit") == 0) {
            quit();
            break;
        }
    }

    return 0;
}
