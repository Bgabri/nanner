typedef struct ListNode* List;

struct ListNode {
    char *str;
    List next;
};

List addItem(List list, char *str);
void freeList(List list);
