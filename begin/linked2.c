#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
    int val;
    struct ListNode *next;
} ;


struct ListNode* middleNode(struct ListNode* head) {
    int l = 0;
   struct ListNode *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n ", ptr->val);
        ptr = ptr->next;
        l++;
    }
    struct ListNode **array = (struct ListNode**)malloc(l * sizeof(struct ListNode));
    ptr = head;
    for (int i = 0; i < l; i++)
    {

        array[i] = ptr;
        ptr = ptr->next;

    }
    struct ListNode *middle = array[l/2];
    free(array);

    return middle;

}

int main()
{
    // Inicjalizacja tablicy liczb całkowitych
    int array[] = {1, 2, 3, 4, 5, 6};

    // Obliczenie rozmiaru tablicy
    int size = sizeof(array) / sizeof(int);
    // printf("%d \n", size);  // Można odkomentować, aby wydrukować rozmiar tablicy

    // Inicjalizacja wskaźnika do głowy listy
    struct ListNode *head = NULL;

    // Pętla do przekształcenia tablicy w listę jednokierunkową
    for (int i = 0; i < size; i++)
    {
        int number = array[i];  // Pobranie bieżącego elementu tablicy
        // printf("%d ", number);  // Można odkomentować, aby wydrukować każdy element

        // Alokacja pamięci dla nowego węzła listy
       struct ListNode *n = malloc(sizeof(struct ListNode));
        if (n == NULL)
        {
            // Zwraca błąd, jeśli alokacja pamięci się nie powiedzie
            return 1;
        }

        // Ustawienie wartości węzła i wskaźnika na następny węzeł
        n->val = number;
        n->next = NULL;

        // Jeśli lista jest pusta, nowy węzeł staje się głową
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            // Inaczej, dodajemy nowy węzeł na koniec listy
            for (struct ListNode *ptr = head; ptr != NULL; ptr = ptr->next)
            {
                if(ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }
    printf("\n");

    // Drukowanie wartości wszystkich węzłów w liście
    struct ListNode *ptr = head;
    int l = 0;
    while(ptr != NULL)
    {
        printf("%d %d\n ", ptr->val, l);
        ptr = ptr->next;
        l++;

    }
    printf("%d ", l);

    struct ListNode *wynik = middleNode(head);
    printf("srodkowy: %d\n", wynik->val);

    // Uwalnianie pamięci zajmowanej przez listę
    ptr = head;
    while (ptr != NULL)
    {
        struct ListNode *next = ptr->next;  // Zapisz wskaźnik do następnego węzła
        free(ptr);  // Zwolnij bieżący węzeł
        ptr = next;  // Przejdź do następnego węzła
    }

    return 0;
}
