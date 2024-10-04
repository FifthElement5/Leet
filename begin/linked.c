#include <stdio.h>
#include <stdlib.h>

// Definicja struktury ListNode
struct ListNode {
    int val;
    struct ListNode *next;
};

// Funkcja znajdująca środkowy węzeł listy
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow = head;  // Wskaźnik do wolniejszego przechodzenia listy
    struct ListNode *fast = head;  // Wskaźnik do szybszego przechodzenia listy

    // Przesuwamy wskaźniki aż fast osiągnie koniec listy
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // slow przesuwa się o jeden węzeł
        fast = fast->next->next;    // fast przesuwa się o dwa węzły
    }

    // Na koniec pętli slow wskazuje na środkowy węzeł
    return slow;
}

// Funkcja pomocnicza do tworzenia listy (do testowania)
struct ListNode* createList(int* values, int size) {
    if (size == 0) return NULL;

    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = values[0];
    struct ListNode *current = head;

    for (int i = 1; i < size; i++) {
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = values[i];
    }

    current->next = NULL;
    return head;
}

// Funkcja pomocnicza do drukowania listy (do testowania)
void printList(struct ListNode* head) {
    struct ListNode *current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Funkcja main do testowania
int main() {
    int values[] = {1, 2, 3, 4, 5, 6};  // Przykładowe wartości
    int size = sizeof(values) / sizeof(values[0]);

    struct ListNode* head = createList(values, size);
    printList(head);

    struct ListNode* middle = middleNode(head);
    if (middle != NULL) {
        printf("Middle node value: %d\n", middle->val);
    }

    // Zwolnienie pamięci (należy zaimplementować)

    return 0;
}
