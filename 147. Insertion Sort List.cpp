

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
    void insert(ListNode *lastsorted, ListNode *Current, ListNode *prev)
    {
        prev->next = Current;
        lastsorted->next = Current->next;
        Current->next = lastsorted;
    }
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode sortedList = new ListNode();
        sortedList = head;
        ListNode *lastSorted = head;

        ListNode *prev = NULL;

        for (ListNode *i = lastSorted; i != nullptr; i = i->next)
        {
            ListNode *Current = lastSorted->next;
            for (ListNode *j = head; j != lastSorted; j = j->next)
            {
                if (Current->val >= lastSorted->val)
                {
                    lastSorted = Current;
                }
                else
                {
                    if (j->val < Current->val)
                    {
                        insert(lastSorted, Current, prev);
                    }
                    else
                    {
                        prev = j;
                    }
                }
            }
        }
        lastSorted->next;
    }
};