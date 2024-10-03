#include "Header.h"

int main() {

    BigInt b1, b2;
    Input("data.inp", b1, b2);
    cout << "== Data infomation ==" << endl;
    Display(b1.pHead);
    Display(b2.pHead);

    node p = b1.pHead;
    node q = b2.pHead;

    p = reverse(p);
    q = reverse(q);
    node sum = addTwoLists(p, q);
    sum = reverse(sum);
    cout << "== Sum ==" << endl;
    Display(sum);


    node sub = subtractLinkedList(p, q);
    cout << "== Minus ==" << endl;
    modify(p, q, sub);
    Display(sub);


    Node* mul = multiplyTwoLists(p, q);
    cout << "== Multify ==" << endl;
    Display(mul);
    cout << endl;
    return 0;
}