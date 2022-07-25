

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *lastsorted = head;

        while (current != NULL)
        {
            if (lastsorted->next->val >= lastsorted->val)
            {
                lastsorted = lastsorted->next;
                continue;
            }
            ListNode *current = lastsorted->next;
            lastsorted->next = current->next;
            if (current->val < head->val)
            {
                current->next = head;
                head = current;
                continue;
            }
            ListNode *insert = head;
            while (insert != NULL)
            {
                if (current->val < insert->next->val)
                {
                    current->next = insert->next;
                    insert->next = current;
                }
                else
                {
                    insert = insert->next;
                }
            }
        }
        return head;
    }
};