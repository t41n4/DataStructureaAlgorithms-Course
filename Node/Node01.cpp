#include <iostream>

using namespace std;

void _append(node *&h, node *&t, int data)
{
    node *temp;
    temp = new node;
    temp->data = data;
    temp->link = NULL;

    if (h == NULL and t == NULL)
    {
        h = temp;
        t = temp;
    }
    else
    {
        t->link = temp;
        t = temp;
    }
}


node *_get_tail(node *q)
{
    while (q != NULL && q->link != NULL)
        q = q->link;
    return q;
}



pair<node *, node *> quick_sort(node *head, node *tail)
{
    // Kiểm tra bài toán cơ sở của chia để trị
    if (head == tail)
        return make_pair(head, tail);

    // Tiến hành chia bài toán con ban đầu thành hai bài toán con nhỏ hơn: left và right
    int pivot_value = head->data;
    node *left_head, *left_tail, *pivot_head, *pivot_tail, *right_head, *right_tail;
    left_head = left_tail = pivot_head = pivot_tail = right_head = right_tail = NULL;

    node *p = head;

    // Chia bài toán con ban đầu thành left và right, và giữ lại các node có data bằng pivot
    while (p != NULL)
    {
        if (p->data < pivot_value)
        {
            _append(left_head, left_tail, p->data);
        }
        else if (p->data == pivot_value)
        {
            _append(pivot_head, pivot_tail, p->data);
        }
        else if (p->data > pivot_value)
        {
            _append(right_head, right_tail, p->data);
        }

        node *t = p;
        p = p->link;
        delete t;
    }

    // Giải các bài toán con
    pair<node *, node *> left_sorted = quick_sort(left_head, left_tail);
    pair<node *, node *> right_sorted = quick_sort(right_head, right_tail);

    // Tổng hợp bài toán con
    node *head_sorted = pivot_head, *tail_sorted = pivot_tail;
    if (left_sorted.first != NULL)
    {
        head_sorted = left_sorted.first;
        left_sorted.second->link = pivot_head;
        tail_sorted = pivot_tail;
    }

    if (right_sorted.first != NULL)
    {
        tail_sorted->link = right_sorted.first;
        tail_sorted = right_sorted.second;
    }

    return make_pair(head_sorted, tail_sorted);
}

node *_quick_sort(node *head, node *tail)
{
    pair<node *, node *> result = quick_sort(head, tail);
    return result.first;
}

node *_sort(node *head)
{
    node *tail = _get_tail(head);
    return _quick_sort(head, tail);
}
int main()
{
    node *head;

    head = NULL;

    int n, temp_val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp_val;
        _addatbeg(&head, temp_val);
    }
    head = _sort(head);
    _display(head);
    system("pause");
    return 0;
}
