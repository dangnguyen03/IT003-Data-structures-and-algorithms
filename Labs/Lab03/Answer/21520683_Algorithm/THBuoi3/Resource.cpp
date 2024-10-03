#include "Header.h"

node newNode(int data) {
    Node* temp = new Node;
    temp->info = data;
    temp->info = NULL;
    return temp;
}

void Init(BigInt& bi) {
    bi.pHead = bi.pTail = NULL;
}

void AddTail(BigInt& bi, Node* p) {
    if (bi.pHead == NULL)
        bi.pHead = bi.pTail = p;
    else {
        bi.pTail->next = p;
        bi.pTail = p;
    }
}

void Push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void Input(const char* filename, BigInt& bi1, BigInt& bi2) {
    Init(bi1);
    Init(bi2);
    ifstream ifs(filename);
    ifs.unsetf(ios_base::skipws);
    char c;
    while (ifs >> c && c != '\n') {
        int x = c - 48;
        Node* p = newNode(x);
        AddTail(bi1, p);
    }

    while (ifs >> c) {
        int x = c - 48;
        Node* p = newNode(x);
        AddTail(bi2, p);
    }
    ifs.close();
}

void RandomBigInt(int n, int m, const char* filename) {
    srand((unsigned)time(NULL));
    ofstream ofs(filename);
    for (int i = 1; i <= n; i++) {
        int info = rand() % 10;
        ofs << info;
    }
    ofs << '\n';
    for (int i = 1; i <= m; i++) {
        int info = rand() % 10;
        ofs << info;
    }
    ofs.close();
}

int getLength(Node* Node) {
    int size = 0;
    while (Node != NULL) {
        Node = Node->next;
        size++;
    }
    return size;
}

node paddZeros(node sNode, int diff) {
    if (sNode == NULL)
        return NULL;

    node zHead = newNode(0);
    diff--;
    node temp = zHead;
    while (diff--) {
        temp->next = newNode(0);
        temp = temp->next;
    }
    temp->next = sNode;
    return zHead;
}

node subtractLinkedListHelper(Node* l1, Node* l2, bool& borrow) {
    if (l1 == NULL && l2 == NULL && borrow == 0)
        return NULL;
    Node* previous = subtractLinkedListHelper(l1 ? l1->next : NULL, l2 ? l2->next : NULL, borrow);

    int d1 = l1->info;
    int d2 = l2->info;
    int sub = 0;

    if (borrow) {
        d1--;
        borrow = false;
    }

    if (d1 < d2) {
        borrow = true;
        d1 = d1 + 10;
    }

    sub = d1 - d2;

    node current = newNode(sub);

    current->next = previous;

    return current;
}

node subtractLinkedList(node l1, node l2) {
    if (l1 == NULL && l2 == NULL)
        return NULL;

    int len1 = getLength(l1);
    int len2 = getLength(l2);

    node lNode = NULL,  sNode = NULL;

    node temp1 = l1;
    node temp2 = l2;

    if (len1 != len2) {
        lNode = len1 > len2 ? l1 : l2;
        sNode = len1 > len2 ? l2 : l1;
        sNode = paddZeros(sNode, abs(len1 - len2));
    }

    else {
        while (l1 && l2) {
            if (l1->info != l2->info) {
                lNode = l1->info > l2->info ? temp1 : temp2;
                sNode = l1->info > l2->info ? temp2 : temp1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    if (lNode == NULL && sNode == NULL) {
        return newNode(0);
    }
    bool borrow = false;
    return subtractLinkedListHelper(lNode, sNode, borrow);
}

void modify(Node* l1, Node* l2, Node* res) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);
    if (len1 < len2)
        res->info = -res->info;
}

void Display(node nod) {
    while (nod != NULL) {
        cout << nod->info;
        nod = nod->next;
    }
    cout << endl;
}

node addTwoLists(node first, node second) {
    node res = NULL;
    node temp=new Node,  prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->info : 0) + (second ? second->info : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = newNode(sum);
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;

        prev = temp;

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    return res;
}

node reverse(node head) {
    if (head == NULL || head->next == NULL)
        return head;
    node rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

node make_empty_list(int size) {
    node head = NULL;
    while (size--)
        Push(&head, 0);
    return head;
}

int reverse1(node* head_ref)
{
    node prev = NULL;
    node current = *head_ref;
    node next;
    int len = 0;
    while (current != NULL) {
        len++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return len;
}

node multiplyTwoLists(node first, node second) {
    int m = reverse1(&first), n = reverse1(&second);
    node result = make_empty_list(m + n + 1);
    node second_ptr = second,  result_ptr1 = result,  result_ptr2,  first_ptr;

    while (second_ptr) {
        int carry = 0;
        result_ptr2 = result_ptr1;

        first_ptr = first; 

        while (first_ptr) {
            int mul = first_ptr->info * second_ptr->info + carry;
            result_ptr2->info += mul % 10;
            carry = mul / 10 + result_ptr2->info / 10;
            result_ptr2->info = result_ptr2->info % 10;
            first_ptr = first_ptr->next;
            result_ptr2 = result_ptr2->next;
        }

        if (carry > 0) {
            result_ptr2->info += carry;
        }

        result_ptr1 = result_ptr1->next;
        second_ptr = second_ptr->next;
    }

    reverse1(&result);
    reverse1(&first);
    reverse1(&second);

    while (result->info == 0) {
        node temp = result;
        result = result->next;
        free(temp);
    }
    return result;
}



